//Room: dongan-dadao.c

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set("long", @LONG
�����ǵ����ֶ��������Ϊ���֣����˱��ǵľ����⣬���в����������ÿ�
�����ˡ�����������򶫾��ǳ����ǵ����µ��ڡ������ţ������ǹʻʹ��ķ�ڼ
�����������Ǵ����������������ܲ��ˡ�
LONG );
        set("exits", 
        ([ //sizeof() == 2
		"west" : "/d/changan/fengxu3",
        	"east" : "/d/changan/dongan-daokou",
                "north" : "/d/changan/xym_zb",
        ]));

        set("outdoors", "changan");
        set("coor/x", -370);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
