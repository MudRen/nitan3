//Room: beian-daokou.c

inherit ROOM;

void create ()
{
        set ("short", "��������");
        set("long", @LONG
�������Թ��Ƿ���ʤ�أ�Ϊ�����ʳ�����֮�أ���Ϊ���̴�����ۼ�����
�������¡�����������һ����ͨ�˴��·�ڣ���������ͨ������֣������ǳ���
�����ţ��Ϸ���һ����·ͨ���ʻʹ��Ľ�ˮ�š� 
LONG );
        set("exits",([//sizeof() == 4
        	"south" : "/d/changan/beian-dadao",
        	"north" : "/d/changan/bei-chengmen",
        	"west" : "/d/changan/qixiang3",
        	"east" : "/d/changan/qixiang4",
        	"southeast" : "/d/changan/bingying1",
        	"southwest" : "/d/changan/bingying2",
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
