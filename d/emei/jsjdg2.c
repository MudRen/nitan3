inherit ROOM;

void create()
{
      set("short", "��ʮ�ŵ���");
      set("long", @LONG
���������ġ���ʮ�ŵ��ա�����·��������ǧ�۰ٻء���
˵��ȥ���и�������ķ�ɮ���ˣ���һ������·��������������
�����ǵ�֪�˴��о�����û�󣬱���Ҳ���˸�������Ĳ�ľ��
�ԡ����ӡ���֮���ɴ˶�����ǧ���֣�������϶���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "southwest" : __DIR__"jsjdg3",
          "eastdown"  : __DIR__"jsjdg1",
      ]));
      set("coor/x", -490);
	set("coor/y", -240);
	set("coor/z", 120);
	set("coor/x", -490);
	set("coor/y", -240);
	set("coor/z", 120);
	setup();
      replace_program(ROOM);
}
