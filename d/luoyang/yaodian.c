inherit ROOM;

void create()
{
	set("short", "ͬ����ҩ��");
	set("long", @LONG
����һ�����ֺŵ�ҩ�ꡣδ��˴������µ�ҩ�����������ԡ�������
������ҩ��������Ŀ�������������֡���Щ�����������Ĺ�Ч��ҩ���е�
����Ҳʮ�ֿ��������α��ڿ�Ļ�Ʋ��ĸɸɾ�����ǽ�Ϲ����˱�������
��л�ҡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"west" : __DIR__"sroad2",
	]));
        set("objects", ([
                "/d/city/npc/huoji" : 1,
        ]));
	set("coor/x", -160);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
