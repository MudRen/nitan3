inherit  ROOM;

void  create  ()
{
        set("short",  "��ٵ�");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ�򺯹ȹأ�������
ֱ�ﳤ���ǡ�������һ��С·ͨ��ɽ�
LONG);
        set("exits",  ([
                "north"  :  "/d/village/hsroad1",
                "east"   :  "/d/changan/hanguguan",
                "west"   :  "/d/changan/zhongnan",
        ]));

        set("outdoors", "changan");
        set("coor/x", -310);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

