//Room: huanggong.c

inherit ROOM;

void create ()
{
        set ("short", "�ʹ����");
        set("long", @LONG
�ʹ��������ȫ�����ģ�����������ƫ�����һ��Լ��ʮ�ɳ����ȵ�������
�����߷ɳ�������������������������Ϊ����
LONG );
        set("exits", ([
        	"south"   : "/d/changan/bridge2",
        	"north"   : "/d/changan/bridge1",
        	"east"   : "/d/changan/fudian1",
        	"west"   : "/d/changan/fudian2",
        ]));
        set("objects", ([
        	"/d/changan/npc/shiwei" : 4,
                "/clone/npc/walker"  : 1, 
        ]));

        set("coor/x", -400);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
