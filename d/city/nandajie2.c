// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ������
�ģ�������һ�ҹ˿��ڶ�Ĳ�ݣ����̾�����ʿ��������̸��˵�ء����ߵ�����
�����ĺȻ��Ƶĵط���������Ժ������Ժ�����ſ���ȸ�����ǵ�������ȴ������
�Ƿ�����Լ���������������¥���ڴ�������Ů�ӵ���Ц����������ͷһ����
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : "/d/city/lichunyuan",
		"south" : "/d/city/nanmen",
		"west"  : "/d/city/chaguan",
		"north" : "/d/city/nandajie1",
	]));
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
        ]));
	set("coor/x", 0);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}