inherit ROOM;
void create()
{
        set("short", "����յ�");
        set("long", @LONG
���ǳ���Ŀյأ�һЩ�ɹű��ļ�ϸ�ͼ��ֳ��������߮����Ѱ����
�Ǹ���Ȥ�������ʱ�м�ö�����ͷ��ವطɹ������˷���ʤ����
LONG );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);
        set("step",1);
        set("no_fly",1);
        set("exits", ([
               "east" : __DIR__"east_out2",
               "down" : __DIR__"east_out9", 
        ]));
        set("coor/x", -240);
	set("coor/y", -90);
	set("coor/z", 10);
	setup();
}

