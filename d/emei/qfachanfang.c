inherit ROOM;

void create()
{
      set("short", "����");
      set("long", @LONG
������һ�䰲����������������ǧ�����е��Ӵ�������
֮�������������������������š���λ����ʦ̫���׼�Ů��
���������붨��
LONG);
      set("exits", ([
          "west" : __DIR__"qfadadian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
      set("coor/x", -460);
	set("coor/y", -240);
	set("coor/z", 100);
	set("coor/x", -460);
	set("coor/y", -240);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}
