//room: didao2.c
inherit ROOM;

void create()
{
  set("short","�ص�");
        set("long", @LONG
��������һ���ص�������������̫ƽ�����������Եļ�յ�͵ƣ��谵�綹��
�ǿ���ȥǰ�����й�������Ҫ�Ǿ��ú��£����ڻ�ͷ���ǿ��Եģ��������쳣��
�ľ�ȴҲ���󼤷�����ĺ����ģ����ɷ����ֺ�����أ����������ɼѡ�
LONG );

  set("exits",([
      "west" : "/d/heimuya/didao1", 
      "south" : "/d/heimuya/didao5",
  ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
