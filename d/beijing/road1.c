inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ����̵ġ�����
�󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡����߾��Ǿ��Ƕ��š�
��������һ��С·��
LONG );

	set("exits", ([
		"west"      : "/d/beijing/chaoyangmen",
		"southeast" : "/d/beijing/road2",
		"northeast" : "/d/beijing/zhuang1",
	]));

	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));

 	set("outdoors", "beijing");
	set("coor/x", 40);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


