inherit ROOM;

void create()
{
	set("short", "�Ϻ����");
	set("long", @LONG
�����Ϻ��ذ���ƫƧС�壬ϡϡ����ļ����˼ҡ��յ������ż�
��������������ǲ��κ����Ϻ��ˡ������ߺ����и���ۡ�����
��С���ɳ̲ɹ������
LONG );
        set("outdoors", "nanhai");
	set("exits", ([
		"north"   : __DIR__"xkroad3",
                "south"   : __DIR__"haibin",
		"east"    : __DIR__"xkroad5",
		"west"    : __DIR__"haigang",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("resource/quarry", ([
            "/clone/quarry/gui" :  50,
            "/clone/quarry/eyu" :  10,
            "/clone/quarry/haibei" :  10,
        ]));
	setup();
	replace_program(ROOM);
}

