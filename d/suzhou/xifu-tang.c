// Room: /suzhou/xifu-tang.c //�ٰ��������
// llm 99/07/09

inherit ROOM;
void create()
{
	set("short", "ϲ����");
        set("long", @LONG
������ӭ��¥�Ķ�¥�����ؿ��԰�����ʮ���Ű����������й��Ŵ��ĺ�
ɫϲ�֣����ڳ��������ڴ˾ٰ���磬����ĺ���Ҳ�ͳ������������ź��Ĵ�
���̺��һ��ϲ������ľ�����վ��¥���������ɿ����̲���ˮ����ɽ���롣
LONG );
	set("exits", ([
                "down" : "/d/suzhou/yingbin-lou1",
	]));

	set("coor/x", 190);
	set("coor/y", -220);
	set("coor/z", 10);
	setup();
   replace_program(ROOM);
}

