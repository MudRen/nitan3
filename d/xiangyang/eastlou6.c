inherit ROOM;

void create()
{
        set("short", "�Ƕ���¥");
        set("long", @LONG
���Ƕ���ͷ�ļ�¥�����沼����һ�ŵĶ�ڣ�һ�Ŵ��εļ���������
��ؼ����ų����һ��һ������ʱ׼����ǰ��͵Ϯ���ɹű���ӭͷʹ����
LONG );
        set("indoors", "xiangyang");
        set("no_clean_up", 0);
        set("site", "east_out");
        set("no_fly",1);     
        set("exits", ([
                "east" : __DIR__"east_out1",
                "up" : __DIR__"eastlou7",  
                "down" : __DIR__"eastlou5",  
        ]));
        set("coor/x", -250);
	set("coor/y", -90);
	set("coor/z", 60);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "east" )
        return notify_fail("���ȥ��ʲô����������\n");
        return ::valid_leave(me,dir);
}

