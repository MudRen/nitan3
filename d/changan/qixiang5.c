//Room: qixiang5.c

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set("long", @LONG
������ǳ����Ǳ�һ��������Ĵ����������ྻ������ʮ�����֣�����
����������Ϣ����ֵ������̼��Ƽ������СС�ĵ��̱��ڶ�����������һ����
�ε꣬�ϱ߾��ǳ����������ĺ����ھ֡�
LONG );
        set("exits", 
        ([ //sizeof() == 4
		"south" : "/d/changan/biaoju-damen",
        	"north" : "/d/changan/shoushi-dian",
        	"west" : "/d/changan/qixiang4",
       		"east" : "/d/changan/qixiang6",
        ]));

        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
