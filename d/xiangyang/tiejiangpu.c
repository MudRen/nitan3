// Room: /d/xiangyang/tiejiangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
        set("long", @LONG
����ԭ����һ�Ҽ����ª�������̡��������ɹŴ���Ŵν��������������
���̱��ٸ����ã���Ϊ�ٰ�������Ŀǰ��ģ�ܴ�һ������Ϊ�����ؾ��������ס�
�����ȣ�������������ﱸ�س����ʣ��������֮��Ҳ����һЩ��ǥ����������
ľ��ͷ�ȡ�ֻ����ʮ������������������æ����ͣ��
LONG );
	set("exits", ([
		"west" : "/d/xiangyang/southjie3",
	]));
	set("objects", ([
                "/d/city/npc/smith" : 1,
	]));
	set("coor/x", -280);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

