inherit ROOM;

void create()
{
      set("short", "�䵱����");
      set("long", @LONG
�㴩����һƬï�ܵİ����У���ɭ���䣬��ʯ��ᾣ�����
û�ˡ���ʱ�������Ӵ������߷��ܶ�����
LONG);
      set("outdoors", "wudang");
      set("exits", ([
              "northdown": __DIR__"yuzhengong",
              "southup"  : __DIR__"haohanpo",
      ]));
      set("objects", ([
              "/clone/quarry/tu" : 2,
      ]));
	set("coor/x", -370);
	set("coor/y", -210);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}