inherit ROOM;

void create()
{
        set("short", "���湬");
        set("long", @LONG
�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����
ǧ��ʳ�ޣ��ǽ���͵�һ��Ъ�Ŵ��������������ڴ˽���������
��˹��й������������������������˱չ��Ѿã����˲�֪
���Ƿ������˼䣬��䴫˵���ѵõ����ţ�����Ĥ�ݡ�
LONG);
        set("objects", ([
                CLASS_D("wudang") + "/zhixiang": 1,
        ]));
        set("outdoors", "wudang");
        set("exits", ([
                "northdown": __DIR__"shijie1",
                "southup"  : __DIR__"wdbl",
        ]));
	set("coor/x", -370);
	set("coor/y", -200);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}