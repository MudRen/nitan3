//Room: fangzhangshi.c

inherit ROOM;

void create ()
{
        set ("short", "������");
        set("long", @LONG
�����Һ������أ����г���һ��ľ齺�һ������֮�⣬�پͱ����������
�Ϸ��ż������ڷ𾭵��鼮������һ���ƾɵ�ľ�㡣ľ��ϵ��м����޲�������
����ͨ�����۱��
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"west" : "/d/changan/baodian",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/huitong" : 1,
        ]));
        
        set("coor/x", -400);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
