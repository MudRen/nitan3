//Room: qunyums.c

inherit ROOM;

void create()
{
        set("short", "Ⱥ��¥����");
        set("long", @LONG
�������沼�õü򵥶�������Ȥ������ܿ��������ż��軨���ݲݣ�����
��䣬�������£�����������Ŀ��������һ��ʮ�����С�������޸���ͣ���Ա�
վ���ĸ����֡�
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"south" : "/d/changan/qunyuys8",
        ]));
        set("objects", ([
        	"/d/changan/npc/dashou" : 4,
        	"/d/changan/npc/xiangxiang": 1,
        	"/d/changan/npc/huangyi": 1,   
        ]) );

	setup();
        replace_program(ROOM);
}
