// Room: /d/playertown/huayuan3.c ��԰
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long",
"������һ����שС���ϣ�����������������������������������м�\n"
"���洬���ڴ��棬����ǻ���س��Ÿ裬����һ��������������������\n"
"������һƬƬ���̵Ĳ�ƺ�����漸�Է����������ǣ���ͷ�����ţ�ż��\n"
"������һ��ɬЦ��\n"
);
        set("outdoors", "playertown");
//      set("no_clean_up", 0);
        set("exits", ([
                "west"	:	__DIR__"huayuan2",
                "south"	:	__DIR__"huayuan4",
        ]));
        setup();
        replace_program(ROOM);
}
