//Room: baodian.c

inherit ROOM;

void create ()
{
        set ("short", "���۱���");
        set("long", @LONG
���۱����ڣ���ڻԻͣ����������������๲����������ŷ𣬹ŷ�֮����
��٤��������ıڻ������۱���Ϊ�����ʵ��м�ɮ�¡������������ڣ�����
����������������ͬ��������ׯ�����µķ���һ�㡣
LONG );
        set("exits", 
        ([ //sizeof() == 3
        	"north" : "/d/changan/baoxiangsi",
        	"west" : "/d/changan/piandian",
        	"east" : "/d/changan/fangzhangshi",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	"/d/changan/npc/xiangke" : 2,
        ]));
	
        set("coor/x", -410);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
