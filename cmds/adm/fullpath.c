// guilei.c
// by Smallfish

#include <ansi.h>
#include <armor.h>

inherit F_CLEAN_UP;

int guilei_dir(object me, string dir, int continueable, int *total);
int guilei_file(object me, string dir, string file);
nosave int all_num;	//判断多少文件给归类

int main(object me, string arg)
{
        //string dir,type,type_name;
        string dir;
        int continueable;
        int *total = ({0});

             if (! SECURITY_D->valid_grant(me, "(admin)")) 
                  return 0; 
        seteuid(geteuid(me));

        continueable = 1;
 	if (!arg) 
                return notify_fail("格式：fullpath <路径>\n");

        dir = arg;
        
       	dir = resolve_path(me->query("cwd"), dir);

        if (dir[strlen(dir) - 1] != '/')
                dir += "/";

	if (file_size(dir) != -2)
		return notify_fail("没有" + dir + "这个路径。\n");

	me->set("cwd", dir);

	message_system("整理整理房间档案中，请稍候...");
        if (! guilei_dir(me, dir, continueable, total))
                write(HIR "整理遇到错误中止。\n" NOR);

        if (total[0] > 0)
                write(HIC "总共有" + HIW + total[0] + HIC "个档案被成功整理！\n" NOR);
        else
                write(HIC "没有整理任何档案。\n" NOR);

        return 1;
}

int guilei_dir(object me, string dir, int continueable, int *total)
{
	int i;
        int l;
        int filecount, compcount;
        mixed *file;
        string filename;

        if (! is_root(previous_object()))
                return 0;

	file = get_dir(dir, -1);
	if (! sizeof(file))
	{
                if (file_size(dir) == -2)
                        write(dir + "这个目录是空的。\n");
		else
		        write("没有" + dir + "这个目录。\n");
                return 1;
	}

        write (HIY "开始检查目录" + dir + "下面的所有文件。\n" NOR);
	i = sizeof(file);
        compcount = 0;
        filecount = 0;
        all_num = 0;
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] != -2)
                {
                        filecount++;
                        filename = file[i][0];
                        l = strlen(filename);
                        if (filename[l - 1] != 'c' || filename[l - 2] != '.')
                                continue;

                        if (! guilei_file(me, dir, dir + filename) &&
                            ! continueable)
                                return 0;

                        compcount++;
                        total[0]++;
                        if ((compcount % 70) == 0)
                                write("\n");
                }

                // continue to compile next file
	}
        write(HIC "\n整理了目录" + dir + "下的" + HIW + filecount + HIC +
              "个文件\n，检查了其中" + HIW + compcount + HIC + 
              "个档案。\n，整理了其中" + HIW + all_num + HIC + "个档案。\n" + NOR );

	i = sizeof(file);
	while (i--)
        {
		reset_eval_cost();
		if (file[i][1] == -2)
                {
                        file[i][0] += "/";
                        write("\n");
                        if (! guilei_dir(me, dir + file[i][0], continueable, total) &&
                            ! continueable)
                                return 0;
                }
        }
	return 1;
}

int guilei_file(object me, string dir, string file)
{
       // string document,err,logfile,armor_type;
       string document;
        //mapping all_obj,bookskill;
       // string *ob_list,the_id,the_name,the_object,file_name;
       // int i,is_ok,num;
        //object obj,*inv;

        if (file == "/cmds/adm/fullpath.c")
                // 不自我读本指令文件
                return 0;

        write (".");
        
        document = read_file(file);
        if (strsrch(document,"__DIR__") != -1)
        {
                document = replace_string(document, "__DIR__\"","\"" + dir);
                write_file(file,document,1);
                all_num ++;
        }
        
        return 1;
}

