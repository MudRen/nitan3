inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
���������ݣ�������һλ�а��Ŷ����������ڴ˸�ľ��
ʯ���Զ����ˣ��ֽС���ɮ�ݡ���·����÷���£��ɼ�������
÷�綹������֦��Ҷ�ж������ˣ�������÷ֹ��֮���á�����
��ͨϴ��أ������׶�ƺ��
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "northdown" : __DIR__"xixiangchi",
          "southup"   : __DIR__"leidongping",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -560);
	set("coor/y", -250);
	set("coor/z", 170);
	setup();
      replace_program(ROOM);
}