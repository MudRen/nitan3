//room: 
inherit ROOM;
void create()
{
  set("short","����");
        set("long", @LONG
�����ǰ׻��õĳ��ȡ�����һƬ�Ǽ��������Ӹձ�ϴ��һ������غ�ʬ����
���̶ġ�
LONG );
  set("exits",([
     "north" : "/d/heimuya/baistep1",
      "south" : "/d/heimuya/baihutang",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
