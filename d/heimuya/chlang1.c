//room: 
inherit ROOM;

void create()
{
  set("short","����");
        set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ�����վ����ʮ�������֣�����ɭ�ϣ�͸������ɱ����
LONG );

  set("exits",([
      "north" : "/d/heimuya/dating3",
      "south" : "/d/heimuya/chlang2",
  ]));
  set("objects",([
     "/d/heimuya/npc/jiaotu"   :1,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

