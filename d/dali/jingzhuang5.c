//Room: /d/dali/jingzhuang5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
        set("long", @LONG
��״���������Ľǹ��л�ͭ�����ա���ֻ���գ��ڽ�����һö��ͷ�п׵�
ͭ�ܣ������н�����Ƭ���տڡ��վ����ո����ǿ��ġ�ÿ�����紵������������
ͭ�ܣ����ո��ڿ�����������㷢���ö������С�����ƾ�����յ��������գ�
�������ܹ��ɽ��ǵľ�տ���ա�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "up"    : "/d/dali/jingzhuang6",
	    "down"  : "/d/dali/jingzhuang4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

