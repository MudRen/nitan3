inherit  ROOM;

void  create  ()
{
        set("short",  "�����");
        set("long",  @LONG
    ����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮����
������������ֱ�ﳤ���ǡ�һ��������������չ����ʱ����������ҴҶ�����
LONG);
        set("exits",  ([
                "east"  :  "/d/luoyang/guandaow4",
                "west"  :  "/d/changan/hanguguan",
        ]));

        set("outdoors", "changan");
        set("coor/x", -290);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

