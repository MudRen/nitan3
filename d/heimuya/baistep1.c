//room: 
inherit ROOM;
void create()
{
  set("short","����");
        set("long", @LONG
�����ǰ׻��õĳ��ȡ�����һƬ�Ǽ��������Ӹձ�ϴ��һ������غ�ʬ����
���̶á�
LONG );
  set("exits",([
      "east" : "/d/heimuya/dating2",
      "south" : "/d/heimuya/baistep2",
  ]));
  set("objects",([
     "/d/heimuya/npc/jiaotu"   :1,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
