inherit ROOM;

void create()
{
      set("short", "��ɼ��");
      set("long", @LONG
����Ƭ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ����
��һ�飬֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿
��Ҳ�ޡ������Ϻ��Ŀ�֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
      set("exits", ([
          "west"      : __DIR__"leidongping",
          "northdown" : __DIR__"lingyunti",
          "southup"   : __DIR__"lengsl2",
      ]));
      set("no_clean_up", 0);
      set("coor/x", -550);
	set("coor/y", -260);
	set("coor/z", 180);
	set("coor/x", -550);
	set("coor/y", -260);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
