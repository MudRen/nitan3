//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
	set("short","��������");
        set("long", @LONG
����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ���һ����ң�
���顸�����������ĸ����֡��ſ�վ���������������Ž��£���ִ�ֵ���������
����
LONG );
	set("objects", ([
	   CLASS_D("dali")+"/chuwanli": 1,
	   "/d/dali/npc/weishi2": 1,
	   "/d/dali/npc/weishi1": 2,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : "/d/dali/wfdating",
	    "south"  : "/d/dali/wangfulu",
	]));
	setup();
	"/clone/board/dali_b"->foo();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (dir == "enter" && ob = present("chu wanli", this_object()))
                return ob->permit_pass(me, dir);

        return ::valid_leave(me, dir);
}
