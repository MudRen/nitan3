inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
̫��ƺ�������ǹ�����ʦ������������ɽ����ɯ须�����
���źϳ�һ�䣬Ҷ���ڻ��⣬��������������׶�ʢ�ޣ�����
�����Ժ�֮�߹�Ʒ�ʡ��ɴ������ϱ����𶥣����������
LONG);
      set("objects", ([
           CLASS_D("emei") + "/jia" : 1,
      ]));
      set("outdoors", "emei");
      set("exits", ([
          "eastdown"  : __DIR__"jieyindian",
          "southup"   : __DIR__"jinding",
      ]));
      set("coor/x", -570);
	set("coor/y", -300);
	set("coor/z", 210);
	setup();
      replace_program(ROOM);
}
