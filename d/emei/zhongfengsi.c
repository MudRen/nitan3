inherit ROOM;

void create()
{
      set("short", "�з���");
      set("long", @LONG
�з����ڰ��Ʒ��£�ʼ���ڽ�����ԭΪ���ۡ���˵���ڵ�
����ÿ�����������ն������ɽ��һ����������Ϊ�����ɡ���
���и�����������������ʦ��ɱ��������������ʿ��ʼ֪�ϵ���
�м����ѣ���Ը���ŷ�̣��Ӵ˸Ĺ�Ϊ�¡����������ɵ�����
�󣬶�������ˮ�֡�
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits", ([
          "west"     : __DIR__"qingyinge",
          "eastdown" : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
	set("coor/x", -450);
	set("coor/y", -230);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}