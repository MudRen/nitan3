//Room: jiulou.c

inherit ROOM;

void create()
{
        set("short", "����¥");
        set("long", @LONG
����¥���ܱ��ߣ��ƻϸ������Ǹ�����¥��¥�����л��ȣ���������������
���š���������שǽƤ��������С����ɺ��ʮ�����š�¥�����У�����һ��
������ĺ��ң���������������֡�����¥�����Կ����ɣ������۾����鶯
���ɡ�
LONG );
        set("exits", ([
        	"south" : "/d/changan/qixiang1",
        	"up" : "/d/changan/jiulou2",
        ]));
        set("objects", ([
        	"/d/changan/npc/xiaoer2" : 1,
        ]));

        set("coor/x", -430);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
