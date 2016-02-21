#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_attack(string arg);

void create()
{
        set("short", "��ǽ��");
        set("long", @LONG
������ǡ����Ρ���Ӫǰ��ǽ��
LONG
);

        set("no_magic", "1");
        set("exits", ([ /* sizeof() == 5 */
               "down" :   __DIR__"syuanmen1",
        ]));

        create_door("down", "����", "up", DOOR_CLOSED);
        setup();
}

void init()
{
	if (interactive(this_player()))
        add_action("do_attack", ({ "throw", "touzhi", "luoshi" }));
}
 
int do_attack(string arg)
{
        object me, ob, room, env;
        string dir, who;
        string zhen, craft;
        mapping exits;

        me = this_player();
        env = environment(me);

        if (! arg) return notify_fail("��Ҫָ�Ӳ��ӳ�˭���������\n");

        /*
        if (me->query("env/auto_war"))
                return notify_fail("���Ѿ�����Ϊ��ϵͳ�Զ�ָ����ս�������Լ����������޸����á�\n");
*/
	
        if (me->query_temp("warquest/attack"))
                return notify_fail("��Ķ������������������Ҫ�ҷ������ˣ�\n");

        if (! me->query("craft/siegecity/luoshi"))
                return notify_fail("��Ŀǰ��û��ͨ�����س�ϵ�������С���ʯ�����ֱ�����\n");
                
        if (! me->query_temp("warquest/train"))
                return notify_fail("��δ��һ��һ�䣬ָ�Ӹ�ʲôѽ��\n");

        if (me->query_temp("warquest/train") != "infantry")
        	return notify_fail("���ֲ������첽�������ʵʩ��ʯ��\n");
        
        if (me->query_temp("warquest/group") < 1)
                return notify_fail("��Ķ����Ѿ���ʧ�������޷��������ˣ�\n");

        if (WAR_D->query_stones(me) < 1)
                return notify_fail("��ľ�Ӫ���Ѿ�û���κ���ľ��ʯ���޷�ʵʩ��ʯ�ˣ�\n");
                                
        if (sscanf(arg, "%s on %s", who, dir) != 2)
                return notify_fail("ָ���ʽ�������� TZ <����> on <����> ָ����Ķ��飡\n");

	if (! mapp(exits = env->query("exits")) || undefinedp(exits[dir]))
        	return notify_fail("�޷��ҵ�Ŀ�꣬���� TZ <����> on <����> ָ����Ķ��飡\n");

	room = get_object(exits[dir]);
	if (! room) return notify_fail("�޷��ҵ�Ŀ�꣬���� TZ <����> on <����> ָ����Ķ��飡\n");

	if (room->query("no_fight"))
		return notify_fail("���ﲻ����˺ɱ����\n");

	if (! objectp(ob = present(who, room)))
    		return notify_fail("�޷��ҵ�Ŀ�꣬���� TZ <����> on <����> ָ����Ķ��飡\n");

	if (! ob->query_temp("warquest") || ob->query_temp("warquest/party") != "meng")
    		return notify_fail("������������ǲ�Ҫ���������Ƿǵĺã�\n");

	message_vision(HIY "$N�����б���һ�ӣ���ȵ�������Ӫ׼����о���ʯ����\n" NOR, me, ob);
	
	zhen = "��ͨ��";
	craft = "��ʯ";
 	me->set_temp("warquest/attack", 1);
	me->start_call_out((: call_other, WAR_D, "attack_over", me :), 10);
	WAR_D->do_attack(me, ob, zhen, craft, env, dir, room);
	return 1;
}
