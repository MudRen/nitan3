inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š�����
���ˣ���������Ȫ�������������������������޽�٣��ļ���
�ѡ�����һ�����ã�����һƬ���֡�����ɽϪ�����ʵ�����
�µ����档
LONG);
      set("exits", ([
          "eastdown" : __DIR__"milin2",
          "westup"   : __DIR__"guanyintang",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -230);
	set("coor/z", 30);
	setup();
      replace_program(ROOM);
}