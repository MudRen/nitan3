// Room: /d/playertown/xuemeiting.c ѩ÷ͤ
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
        set("short", "ѩ÷ͤ");
        set("long",
"����һ���ǳ����µ�Сͤ�ӣ�����ɫ��ͤ�������������񳤵�������\n"
"���ڱ��̵ĺ�ˮ�ߣ�ͤ�ӵ���Χ���ż���÷������������ѩ��ʱ�򣬺�÷\n"
"��������ʱ�������ⶥ��ͤ��������������������ʱ���������ٴ���ᣬ\n"
"�����صİ���Ϸ��Ϊ��ԧ��ͤ����\n"
);
        set("outdoors", "playertown");
        set("exits", ([
                "west"  : __DIR__"road5",
        ]));
        setup();
        replace_program(ROOM);
}
