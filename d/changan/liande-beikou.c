//Room: liande-beikou.c

inherit ROOM;

void create ()
{
        set ("short", "���±���");
        set("long", @LONG
����ֵĶ���ͷ��һ�����ɶ�ߵ����֮�ϣ���������յ����ĵ�����ÿ��
ĺɫ���٣�����ƻ�ͨ����������һ�������������������Ϸ���������Ϸ�ͨ
�����´����
LONG );
        set("exits", 
        ([ //sizeof() == 3
        	"west" : "/d/changan/qixiang6",
        	"north" : "/d/changan/xiyuan",
        	"south" : "/d/changan/liande-dadao1"
        ]));

        set("outdoors", "changan");  
        set("coor/x", -360);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
