inherit ROOM;

void create()
{
        set("short", "���ݶ���" );
        set("long", @LONG
������Ǿ������ţ������������Ǿ���Ҫ�أ���˳�ǽ��
ʵ�ޱȣ���¥�߸��������������˺ܶ࣬����Ҳ�Ǵ���ؽ���
��ԭ�ıؾ�֮·�����Ը�ɫ�˵Ȼ��ӣ��㻹��С��һ�㡣��ȥ
����ͨ�����ݵĽ�ͨҪ����
LONG);
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/d/beijing/npc/ducha" : 1,
        ]));
        set("exits", ([
        	"east" : __DIR__"guandao3",
        	"west" : __DIR__"dongdajie2",
        ]));
        set("outdoors", "jingzhou");

        set("coor/x", -430);
	set("coor/y", -200);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}

