//Room: minju6.c

inherit ROOM;

void create ()
{
        set ("short", "���");
        set("long", @LONG
�������ӿ����������Ѿ��ܾ�û��ס�ˡ�����ʵ��Ŵ������ưܲ�������
Ŀ��˿��࣬ǽ�ϵ��µ������ǻҳ���һֻ����������ȥ��Ժ�����Ӳݴ�����լ
��ǽ������̦֩�����ԵüȻ�������ɭ��������һ��ĳ��š�
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/huarui6",
        ]));

        set("coor/x", -370);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
