//Room: tea-shop.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���跿�ǳ����������Ӿ۵ĳ���������������˵İڷ���һЩľ�Ƶ����Ρ�
һ��˵��������������ϲ����Ľ���ʲô��һЩ���һ��Ʒ�裬һ�����飬һ��
������ɫ��ͷ�Ӷ��������Ҫ����������ƹʺ�ҥ�ԣ�������׼û��
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"south" : "/d/changan/qixiang2",
        ]));
        set("objects", ([
        	"/d/changan/npc/teawaiter" : 1,
        	"/d/changan/npc/laoren" :1,
        ]) );

        set("coor/x", -420);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
