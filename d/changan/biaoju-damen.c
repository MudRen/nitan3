inherit ROOM;
void create()
{
        set("short", "�����ھ�");
        set("long", @LONG
һ��������ΰ��լ��֮ǰ����������ʯ̳�и���һ���������ߵ���ˣ����
��Ʈ�����졣�������ϻ�ɫ˿������һͷ������צ����̬���͵Ľ������������
��չ���Եý����������������������������������ھ֡��ĸ����֣�����������
�վ��Ƿ������Ŵ����ų��ʣ��������������ž�װ�ĺ��ӣ����������ͦ���Գ�
һ��Ӣ��֮����
LONG );
        set("exits", ([
        	"north" : "/d/changan/qixiang5",
        	"south" : "/d/changan/biaoju-dayuan",
        ]));
        set("objects", ([
        	"/d/changan/npc/biaoshi" : 1,
        	"/d/changan/npc/tang" : 2,
        ]) );

        set("coor/x", -380);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}
