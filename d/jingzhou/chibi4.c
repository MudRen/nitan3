inherit ROOM;

void create()
{
        set("short",  "��������" );
        set("long", @LONG
�����ǳ�����������ˮ������߻��������ʣ���ʱ���Կ�
����ɽľ������Ư������ˮ�д��˸�Ȧ��������Ưȥ��
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
                "northup" : __DIR__"chibi3",
		"west" : __DIR__"chibi5",                
        ]));
        set("coor/x", -350);
	set("coor/y", -230);
	set("coor/z", -20);
	setup();
        replace_program(ROOM);
} 
