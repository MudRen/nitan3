inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ݵ��ϳ����ˡ����˳ǲ�Զ����һ��Ƭ�����֡���
˵�ϳ�����һ�����������˳�û������������صĹٱ��Ƚ϶�
���Գ��ﵹҲ̫ƽ���¡�
LONG);
        set("outdoors", "zhongzhou");
        set("exits", ([
  		"north" : __DIR__"wendingnan4",
  		"south" : __DIR__"nroad",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 4,
                "/d/beijing/npc/ducha" : 1,
                "/clone/npc/walker" : 1,
        ]));
        set("no_clean_up", 0);

        set("coor/x", -230);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
