//room: chengdedian.c
inherit ROOM;

void create()
{
  set("short","�ɵµ�");
        set("long", @LONG
�����������̽���ƽ�շ���ʩ��ĵط��������޴�����ڵ������λε���
�򣬴��˶˸���һ��������һ��Ӣ���������ˣ��������𽭺��Ķ������ܵ��
ͷ����ͤ�ˣ� 
LONG );

  set("valid_startroom", 1);
  set("exits",([
      "north" : "/d/heimuya/huoting",
      "westdown":"/d/heimuya/up4",
  ]));
  set("objects",([
      "/d/heimuya/npc/dizi" : 2,
      "/d/heimuya/npc/yang"    :1,
  ]));
//  set("no_clean_up", 0); 
  setup();
  replace_program(ROOM);
  "/clone/board/riyue_b"->foo();
}
