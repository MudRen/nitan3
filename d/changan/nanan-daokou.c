//Room: nanan-daokou.c

inherit ROOM;

void create ()
{
        set ("short", "�ϰ�����");
        set("long", @LONG
�������Թ��Ƿ���ʤ�أ�Ϊ�����ʳ�����֮�أ���Ϊ���̴�����ۼ�����
�������¡��ϰ�������һ����ͨ�˴��·�ڣ���������ͨ������֣������ǳ���
�ϳ��ţ�������һ����·ͨ���ʻʹ��Ľ�ˮ�š� 
LONG );
        set("exits",([//sizeof() == 4
        	"south" : "/d/changan/nan-chengmen",
        	"north" : "/d/changan/nanan-dadao",
        	"west" : "/d/changan/huarui3",
        	"east" : "/d/changan/huarui4",
        	"northeast" : "/d/changan/bingying4",
        	"northwest" : "/d/changan/bingying5",
        ]));

        set("outdoors", "changan");
        set("coor/x", -400);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
