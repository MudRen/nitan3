inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������
������ҴҶ��������������һЩС��̯���ƺ��Ǽ��С�����
ͨ�����ݳǡ�������һ��Ƭ���֡�
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "south" : __DIR__"wdroad2",
                "west" : "/d/city/shulin1",
                "north" : "/d/city/nanmen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -280);
	set("coor/y", -130);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}