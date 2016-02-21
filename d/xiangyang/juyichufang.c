// Room: /d/xiangyang/juyichufang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����Ǿ���ݵĳ�����һ��ֻ�а����м����շ�ʦ�����ջ���������Ӧ��se
rve����ʳ���������ϾͿ���������ˡ�
LONG );
	set("exits", ([
		"north" : "/d/xiangyang/juyihuayuan",
	]));
        set("objects", ([
                "/d/xiangyang/npc/shaofanshifu"   : 1,
        ]));
	set("no_fight", 0);
	set("ricewater", 30);
	set("coor/x", -320);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("�շ�ʦ������һ˫���ۣ��Բ���Ҫ�����߰���\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
        if(present("rice",this_player()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
        if(present("rice",this_object()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("�շ�ʦ����$Nһ������׷���һ��Ұ������\n",me);
		food=new("/d/xiangyang/obj/rice");
		water=new("/d/xiangyang/obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�շ�ʦ����$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
void reset()
{
        ::reset();
        set("ricewater",1);
}
