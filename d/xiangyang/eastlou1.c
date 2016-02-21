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
                "down" : __DIR__"eastgate1",
                "up"   : __DIR__"eastlou2",  
        ]));
        set("coor/x", -250);
	set("coor/y", -90);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "east")
                return notify_fail("���ȥ��ʲô����������\n");

        return ::valid_leave(me,dir);
}

void init()
{
        object me = this_player();

        if (me->query_temp("guo_jianlou/mark_jianlou") == 2
        &&  ! me->query_temp("guo_shoucheng/start_job")
        &&  ! me->query_temp("guo_shoucheng/job_over")
        &&  ! me->query("guo_shoucheng/failed"))
        {
                me->set_temp("guo_shoucheng/start_job", 1);
                me->apply_condition("jobjianlou_limit", 40 + random(10));
        }
}

