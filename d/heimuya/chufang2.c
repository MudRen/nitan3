//chufang1.c
inherit ROOM;
void create()
{
  set("short","����");
        set("long", @LONG
���ǰ׻��õĳ�����һλ������Ů������Ц���������������֬��������ǽ
������һ����Ŀ������(note)��
LONG );
  set("exits",([
      "west" : "/d/heimuya/chitang",
  ]));
  set("item_desc",([
      "note" : "��������Ů�˸������ջ�ˮ��----->����Ⱥ��\n",
  ]));

  set("objects",([
      "/d/heimuya/npc/shinu" : 1,
      "/d/heimuya/obj/tea" : random(6),
      "/d/heimuya/obj/sherou"  : random(4),
  ]));
//  set("no_clean_up", 0);
  setup();
}
int valid_leave(object me, string dir)
{
	if (( present("tea", me)||present("she rou", me))
	&&objectp(present("shi nu", environment(me))) )
	return notify_fail
	("��Ů��Ŀһ�������ߣ�û�ţ�\n");
	return ::valid_leave(me, dir);
}

