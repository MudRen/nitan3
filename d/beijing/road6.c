inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�������ԶԶ�ľͿ�
�����������ǡ�������ͨ����ɽ��
LONG );
	set("exits", ([
		"northwest" : "/d/beijing/road5",
		"southwest" : "/d/hengshan/jinlongxia",
		"southeast" : "/d/beijing/road7",
	]));
 	set("outdoors", "beijing");
	set("coor/x", 40);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}