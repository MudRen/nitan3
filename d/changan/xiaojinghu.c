//Room: xiaojinghu.c

inherit ROOM;

void create ()
{
        set ("short", "С����");
        set("long", @LONG
������ǳ����ǵ�С�����ˡ�С��������������Ǻܴ󣬵�̨ͤ¥�󣬼�ɽ
����ȴҲ���еġ����������ؼ򵥣������ݻ�����ˮ�������˵��������˵ķ���
�������ƺ�����ʧ�ˡ�Ϧ������ʱ���е��������ǵ�����ɢ��������С��
LONG );
        set("exits",([//sizeof() == 1
        	"south" : "/d/changan/huarui4",
        ]));
        
        set("resource", ([ /* sizeof() == 1 */
        	"water" : 1,
        ]));
        
        set("outdoors", "changan");
        set("coor/x", -390);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
