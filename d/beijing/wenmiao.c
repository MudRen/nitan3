#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����������������п׷����������ʵ۶������������˼���������Լ�
�Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ���������ݡ�
�׷��ӽ��������˵����ԣ�Ҫ��Ϊһλ�������µĴ������⿿������������������
����Ҫ���㹻���ǻۡ����ٽ���������ǧ�ŵ�������ڳ��뽭��ʱ��������
�����﷢�����ԣ��ϵ�Ĥ��(mobai)�� �����Ҳ�����������ǩ(chouqian)��
��ȷһ���Լ����Ը�̤����������·��
LONG );

       set("no_fight",1);
        set("no_drift", 1);
        set("valid_startroom","1");
	set("exits", ([
		"south" : "/d/beijing/dong_3",
	]));

	set("coor/x", -10);
	set("coor/y", 330);
	set("coor/z", 0);
	setup();
}

/*
void init()
{
	add_action("do_mobai","mobai");
	add_action("do_chouqian","chouqian");
}

int do_mobai(string arg){
        int i;
        int points;
        int tmpstr, tmpint, tmpcon, tmpdex;
        object me;
        mapping my;
        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;
        if (me->is_busy()) return notify_fail("����æ���أ�Ĥ�ݻ�Ҫ���Ķ��⣿\n");
        if (me->query("can_not_change"))
                return notify_fail("�������ſ�����˫ϥ���£��ޱ��ϵ�Ĥ����λ����ʥ�ˣ����ò�����\n");
        write(HIC "����ſ�����Ϲ��Ͼ��Ĺ�����ȥ��˫�ֺ�ʮ��ʼĤ�ݡ�\n" NOR, me);
        tmpstr = tmpint = tmpcon = tmpdex = 13;
        tmpint = 23;
        points = 80 - (tmpstr + tmpint + tmpcon + tmpdex);
        for (i = 0; i < points; i++) {
                switch (random(4)) {
                case 0: 
                        if (tmpstr < 30) tmpstr++;
                        else i--; 
                        break;
                case 1: 
                        if (tmpint < 30) tmpint++;
                        else i--;
                        break;
                case 2: 
                        if (tmpcon < 30) tmpcon++;
                        else i--;
                        break;
                case 3:
                        if (tmpdex < 30) tmpdex++;
                        else i--;
                        break;
                }
        }
        my = me->query_entire_dbase();
        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;
        my["kar"] = 10 + random(21);
        my["per"] = 10 + random(21);
        write(HIC "ͻȻһ�����������������ͷ���𣺡������Ҹ�������ʣ���\n" NOR, me);
        write(sprintf(HIY "\n��ֻ�о�������һ��ʥ��������ת����ı��Ա仯�ˣ�\n"
                          "�������� " HIG "%d" HIY " �� "
                          "���ԣ��� " HIG "%d" HIY " �� "
                          "���ǣ��� " HIG "%d" HIY " �� "
                          "������ " HIG "%d" HIY " ��\n" NOR,
                      tmpstr, tmpint, tmpcon, tmpdex));
        me->start_busy(1);
        return 1;
}

int do_chouqian(string arg)
{
        object me;
        string *character = ({
		"�ĺ�����",
		"��������",
		"������",
		"���ռ�թ",
	 });
        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        if (time() - me->query("last_chouqian_time") < 1800)
                return notify_fail("��ôƵ���ĳ�ǩ����Ĳ�����ǩ���飬�����Сʱ�����ɡ�\n");

        write(HIC "���ϵĳ���һ��ǩ����Ŀ����һ�󣬲������۾���ǩ���������֡�\n" NOR, me);
        write(HIC "ǩ��д�ţ�" + CHOUQIAN->query_chouqian() + "��\n" NOR, me);
        me->set("last_chouqian_time",time());
        if (me->query("can_not_change")) return 1;
        me->set("character", character[random(sizeof(character))]);
        write(sprintf(HIY "\n����������һ�����������������%s���ķ���չ�ɡ�\n" NOR,me->query("character")));
        return 1;
}
*/