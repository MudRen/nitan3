// Room: /d/xiangyang/jiangjungate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����������");
        set("long", @LONG
���ǽ������Ĵ��ţ��Ű岻֪����ʲô�����Ƴɣ�����ȥ���һƬ���ƺ���
Ϊ���أ��������������þ�����ͭ�����ڴ��ŵ��������и�����һ���ߴ��ľ��
�������顸���������������֣��ּ�����Ʈ�ݣ�ֻ����Щģ���ˣ������������
�µĺۼ���������һ���ϰأ����òԾ�ͦ�Σ�֦Ҷï�ܡ���ǰ�������߸�������
��������󵶵��α���
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : "/d/xiangyang/eastjie1",
		"north" : "/d/xiangyang/jiangjunyuan",
	]));
	set("objects", ([
		"/d/xiangyang/npc/bing" : 2,
	]));
	set("coor/x", -280);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
                objectp(present("song bing", environment(me))))
           return notify_fail("�α�����ȵ���ʲô�˵����ô��ر������ţ�\n");

        return ::valid_leave(me, dir);
}
