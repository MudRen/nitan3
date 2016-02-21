inherit ROOM;

void create()
{
        set("short", "ʮ����̨");
        set("long", @LONG
�������䵱������ʮ����̨��̨��̨֮����������������
�̾�������Զ����������ڡ�վ����̨��������������ǧҶ��
��֮�ϣ�ǧ�����ֶ��ڽ��¡������������߰�����Ļ�ɽ����
����ˮ�������塢��һ�������۵ס�
LONG);
        set("exits", ([
                "east" : __DIR__"jinding",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        set("honglian",1);
	set("coor/x", -360);
	set("coor/y", -420);
	set("coor/z", 180);
	setup();
}
void init()
{
      add_action("do_find","find");
}

int do_find()
{
      object obj;
      object me = this_player();

      if (me->query("jingli") < 50)
            return notify_fail("���ҵ�������ʹ����û�з���ʲô�ö�����\n");

      me->add("jingli",-10);

      if (!query("honglian"))
            return notify_fail("�����˰��죬ʲô��û���ҵ���\n");

      add("honglian",-1);
      obj = new("/d/wudang/obj/honglian");
      obj->move(me);
      tell_object(me,"�����˰��죬ͻȻ����һ�ź�ɫС�ݣ�����һ�伫��������С����\n");
      return 1;
}

void reset()
{
      ::reset();
      set("honglian",1);
}
