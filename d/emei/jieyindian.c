inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
�������ұ߱��£��ǽ���졣������һ���ʯ����״����
��������ʯ����������һʯ������ʮ���ɣ�������ʯ���ɴ���
�����ʼ��������֣����¾�����ʮ���̡���ϴ��ء�
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "northwest" : __DIR__"bashisipan3",
          "westup"    : __DIR__"wanxingan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -560);
	set("coor/y", -300);
	set("coor/z", 200);
	setup();
      replace_program(ROOM);
}