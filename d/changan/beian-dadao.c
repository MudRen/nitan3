//Room: beian-dadao.c

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set("long", @LONG
�����ǵ����ֱ����������ֱ���������֣�����������ÿͺ����˶�����
���������������������򱱾��ǳ����ǵı����ţ��������ǹʻʹ��İ׻��֡�
LONG );
        set("exits", 
        ([ //sizeof() == 2
		"north" : "/d/changan/beian-daokou",
        	"south" : "/d/changan/baihu2",
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
