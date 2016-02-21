// ���ڸ�ָ��Ǿ�����ʹ�ã����Բ�����ȫ�ֱ���
// ֻҪ����ͬʱ�����˻������ʹ�þͲ�Ӧ�ó�����
// �ߴ���ʤ��
// setcoor.c 

inherit F_CLEAN_UP;

#define SYNTAX        "syntax :setcoor x,y,z\n"

mapping map_dirs = ([
	"east"      :    ([ "x" : 10, "y" :  0, "z":  0 ]),
	"west"      :    ([ "x" :-10, "y" :  0, "z":  0 ]),
	"south"     :    ([ "x" :  0, "y" :-10, "z":  0 ]),
	"north"     :    ([ "x" :  0, "y" : 10, "z":  0 ]),
	"up"        :    ([ "x" :  0, "y" :  0, "z": 10 ]),
	"down"      :    ([ "x" :  0, "y" :  0, "z":-10 ]),
	"eastup"    :    ([ "x" : 10, "y" :  0, "z": 10 ]),
	"westup"    :    ([ "x" :-10, "y" :  0, "z": 10 ]),
	"southup"   :    ([ "x" :  0, "y" :-10, "z": 10 ]),
	"northup"   :    ([ "x" :  0, "y" : 10, "z": 10 ]),
	"eastdown"  :    ([ "x" : 10, "y" :  0, "z":-10 ]),
	"westdown"  :    ([ "x" :-10, "y" :  0, "z":-10 ]),
	"southdown" :    ([ "x" :  0, "y" :-10, "z":-10 ]),
	"northdown" :    ([ "x" :  0, "y" : 10, "z":-10 ]),
	"southeast" :    ([ "x" : 10, "y" :-10, "z":  0 ]),
	"northeast" :    ([ "x" : 10, "y" : 10, "z":  0 ]),
	"southwest" :    ([ "x" :-10, "y" :-10, "z":  0 ]),
	"northwest" :    ([ "x" :-10, "y" : 10, "z":  0 ])
]);

nosave mapping roomlist = ([]);
nosave int file_count;

int non_recur_do(object room, int x, int y, int z, string prefix);
void clear_old_coor(object room);
int help(object me);

int main(object me, string arg)
{
        int    x, y, z, i;
        int    single = 0, all = 0;
        object env = environment(me);
        string prefix, *file_name, file;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;
                
        if (! me->query("env/coor"))
                return notify_fail("Σ��ָ����ã����ã�\n");
        
	set_eval_limit(2100000000);
        reset_eval_cost();

        if (! arg) {
	        if (env->query("border")) {
                	write("���� " + base_name(env) + " �ѷǱ߽硣\n");
                	env->delete("border");
                	return 1;
                } else 
			return notify_fail("���ﱾ���Ͳ��Ǳ߽硣\n");
	}

        if (member_array(arg, keys(map_dirs)) != -1) {
                if (env->query("border/" + arg)) {
                	write("���� " + base_name(env) + " �ѷǱ߽硣\n");
                	env->delete("border");
                	return 1;
                } else {
	               	env->set("border/" + arg, 1);
        	       	write("���� " + base_name(env) + " ��" + arg + "��������Ϊ�߽硣\n");
               		return 1;
        	}
        }

        if (sscanf(arg, "-s %s", arg))
		single = 1;
		
        if (sscanf(arg, "-a %s", arg))
		all = 1;

        if (sscanf(arg, "%d,%d,%d", x, y, z) != 3)
               	return notify_fail(SYNTAX);

        seteuid(getuid());

	file_count = 0;
	file_name = explode(base_name(env), "/");
	prefix = "";
	
        if (! all) {
       	        for (i = 0; i < sizeof(file_name) - 1; i ++)
        		prefix += file_name[i] + "/";
        }

        if (env->query("coor") || single) {
                if (env->query("coor"))
        		clear_old_coor(env);
        		
                if (env->query("coor") != 0)
	                write("���� " + base_name(env) + " ���������趨�ɹ���\n");
	        else
	                write("���� " + base_name(env) + " �����趨�ɹ���\n");
                env->set("coor/x", x);
                env->set("coor/y", y);
                env->set("coor/z", z);
	        file = read_file(base_name(env) + ".c");
	        file = replace_string(file, "setup()",
		       sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
			        x, y, z));
                write_file(base_name(env) + ".c", file, 1);                
                file_count ++;
        } else {
                roomlist = ([]);
                non_recur_do(env, x, y, z, prefix);
        }

	write("����λ " + sprintf("%d", file_count) + " �����䡣\n");
        return 1;
}

int non_recur_do(object room, int x, int y, int z, string prefix)
{
        mapping exits;
        string *directions;
        string dir, file;
        object curr_room, next_room;
        int i, border = 0;

        // if (! file_count % 100)
                reset_eval_cost();
                        
        room->set("coor/x", x);
       	room->set("coor/y", y);
       	room->set("coor/z", z);
	file = read_file(base_name(room) + ".c");
	file = replace_string(file, "setup()",
		sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
			x, y, z));
        write_file(base_name(room) + ".c", file, 1);
       	file_count ++;       	
        write("���� " + base_name(room) + " �����趨�ɹ���\n");
        roomlist += ([base_name(room) : room]);

        if (room->query("border"))
                border = 1;
        
        curr_room = room;		        
        exits = curr_room->query("exits");
        if (! mapp(exits) || ! sizeof(exits))
                return 1;

        directions = keys(exits);
        for (i = 0; i < sizeof(directions); i ++) {

                reset_eval_cost();
	        	
                x = (int)curr_room->query("coor/x");
                y = (int)curr_room->query("coor/y");
                z = (int)curr_room->query("coor/z");

                dir = directions[i];
                if (! objectp(next_room = get_object(exits[dir])))
                        return 1;

	        if (map_dirs[dir]) {
		        x += map_dirs[dir]["x"];
			y += map_dirs[dir]["y"];
		        z += map_dirs[dir]["z"];
	        }
		              
	        if (undefinedp(roomlist[base_name(next_room)])
		        && (strsrch(base_name(next_room), prefix) != -1
		        || prefix == "" )) {
	                if (next_room->query("coor"))
		                clear_old_coor(next_room);		                
		        if (! border)
			        non_recur_do(next_room, x, y, z, prefix);
               	        else if (! curr_room->query("border/" + dir))
			        non_recur_do(next_room, x, y, z, prefix);
       	        }
        }
        return 1;
}

void clear_old_coor(object room)
{
	int x, y, z, i;
	string *file, result = "";
	
	x = room->query("coor/x");
	y = room->query("coor/y");
	z = room->query("coor/z");
	
	file = explode(read_file(base_name(room) + ".c"), "\n");
        for (i = 0; i < sizeof(file); i++) {    
                if (strsrch(file[i], "set(\"coor/") != -1) {
                        file[i] = 0; continue;
                }         
	        // file[i] = replace_string(file[i], 
	        //      sprintf("set(\"coor/y\", %d);\n", y), "");
        }
        file -= ({ 0 });
        result += implode(file, "\n");
        rm(base_name(room) + ".c");
	write_file(base_name(room) + ".c", result, 1);
}

int help(object me)
{
write(@HELP
ָ���ʽ :
        setcoor <����> x,y,z

�÷���
        setcoor            �����ǰ�������з���ı߽����ԡ�
        setcoor <����>     ���õ�ǰ����ĸ÷�����Ϊ�߽磬�����֮������
                           ���ø÷���Ϊ�߽硣
        setcoor x,y,z      ����ǰ�����Ѷ�λ�������µ����趨�õ�ǰ�����
                           ���ꣻ������������ֱ��ͬһĿ¼�����з��䶼
                           �������Ϊֹ��
        setcoor -a x,y,z   ͬ�ϣ�����ͬһĿ¼���ơ�
        setcoor -s x,y,z   ���۵�ǰ�����Ƿ��Ѷ�λ�����²���������÷��䡣
	
HELP
);
    return 1;
}
