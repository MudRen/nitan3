//room: didao5.c
inherit ROOM;

void create()
{
  set("short","�ص�");
        set("long", @LONG
�������棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ������е����˽��ˣ�
Խ��Խ���ˡ�
LONG );

  set("exits",([
      "east" : "/d/heimuya/didao3",
      "west" : "/d/heimuya/didao3",
      "north" : "/d/heimuya/didao2",
      "south" : "/d/heimuya/didao1",
  ]));
  set("objects",([
      "/clone/beast/dushe" : 4,
  ]));
  setup();
  replace_program(ROOM);
}
