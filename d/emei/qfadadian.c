inherit ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
ǧ�����ڵ���߹���������ׯ�ϡ�������һ������ǧ��
���ƣ��������������ڵ��壬���з��������������У����ƾ�
���ޱȡ�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/hui" : 1,
           CLASS_D("emei") + "/wenyin" : 1,
      ]));
      set("exits", ([
          "out"  : __DIR__"qianfoan",
          "east" : __DIR__"qfachanfang",
      ]));
      set("coor/x", -470);
	set("coor/y", -240);
	set("coor/z", 100);
	set("coor/x", -470);
	set("coor/y", -240);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}
