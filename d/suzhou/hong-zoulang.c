//Room: /d/suzhou/hong-zoulang.c
// by llm 99/06/12

inherit ROOM;

void create()
{
	set("short", "����ׯ����");
        set("long", @LONG
���������Ǻ����۵������������ߵʹ�����������ź�������������ź�
��Ĵ���̺���������������ǽ����������棬һ��ϲ���Ҹ�֮�����ĵ���Ȼ
������ǰ����һ�������������
LONG );
	set("exits", ([
		"west" : "/d/suzhou/hong-damen",
		"east" : "/d/suzhou/hongniang-zhuang",
   ]) );

   set("objects", ([
   	"/d/suzhou/npc/xiao-hongniang" : 1,
      ]) );
   set("coor/x", 220);
	set("coor/y", -200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

