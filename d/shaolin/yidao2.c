inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ�
���֡���ʱ���п������߷ɳ۶���������һ·���������ϵ�
�˸������ž�װ���¼��������еĻ���������ŵ�����������
��ЩЩϰ��Ľ����ˡ���·��������������������֡�������
һ������С·����֪ͨ��η���
LONG);
	set("exits", ([
		"south" : __DIR__"yidao1",
		"north" : __DIR__"hanshui1",
                "east"  : "/d/room/xiaoyuan",
	]));
	set("outdoors", "nanyang");
	set("coor/x", 0);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

