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
        set("step",2);
        set("no_fly",1);     
        set("exits", ([
               "east" : __DIR__"east_out6", 
               "west" : __DIR__"east_out4", 
        ]));
        set("coor/x", -200);
	set("coor/y", -90);
	set("coor/z", 10);
	setup();
}

