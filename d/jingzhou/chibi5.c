inherit ROOM;

void create()
{
        set("short",  "��������" );
        set("long", @LONG
�����ǳ�����������ˮ������߻��������ʣ�ż�������
ɳ̲�Ϸ�����һЩ�е���ꪣ�ԭ�����߲�Զ���������Ĺ�ս��
��ڡ�
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
                "east" : __DIR__"chibi4",
		"west" : __DIR__"chibi6",                
        ]));

             
        set("coor/x", -360);
	set("coor/y", -230);
	set("coor/z", -20);
	setup();
        replace_program(ROOM);
} 
