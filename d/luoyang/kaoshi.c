inherit ROOM;

void create()
{
	set("short", "�ƾ��Գ�");
	set("long", @LONG
�����Ŀƾ��Գ������������ֵ�һ��������ÿ�³�һ��ȫ�����ص�ʿ
�Ӷ����˴��Ͽ���Ժ��������ʿ�����أ�Ҫ��д��ɲ��У�Χǽ��������
���ĸ�ʾ��
LONG);
        set("objects", ([
                "/d/kaifeng/npc/zhukao3" : 1,
                "/d/beijing/npc/shusheng1" : 2,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("exits", ([
  		"east" : __DIR__"nroad3",
	]));

	set("coor/x", -180);
	set("coor/y", 30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
