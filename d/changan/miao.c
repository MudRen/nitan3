//Room: miao.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
����һ��������ˣ������Ͳ������ھ��Եø�С�ˣ�����С�޼���������
�����ա�û��������������һ�ǣ����Ҹպ����������ڵĵط���������������
��ɽ��������õġ���Ҳ��֪�Ǳ�����һλ�������ܵ�������������۾���
������öͭ�壬���һ����ڷ��⡣
LONG );
        set("exits", ([
        	"west"   : "/d/changan/yongtai-dadao4",
        ]));
        set("objects", ([
        	"/d/changan/npc/keeper"   : 1,
        ]));

        set("no_fight",1);
        set("coor/x", -430);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
