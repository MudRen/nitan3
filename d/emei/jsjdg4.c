inherit ROOM;

void create()
{
      set("short","��ʮ�ŵ���");
      set("long",@LONG
���������ġ���ʮ�ŵ��ա�����·��������ǧ�۰ٻء���
˵��ȥ���и�������ķ�ɮ���ˣ���һ������·��������������
�����ǵ�֪�˴��о�����û�󣬱������˸�������Ĳ�ľ����
�ԡ����ӡ���֮���ɴ˶�����ǧ���֣�������϶���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "eastdown" : __DIR__"jsjdg3",
          "west"     : __DIR__"jldongkou",
      ]));
	set("coor/x", -510);
	set("coor/y", -250);
	set("coor/z", 130);
	setup();
      replace_program(ROOM);
}