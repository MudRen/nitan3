//Room: lingyange.c

inherit ROOM;

void create()
{
        set("short", "���̸�");
        set("long", @LONG
խխ���ţ�խխ��¥�ݣ��������ŵķ��䣬�������ܿ��Ӵ��ڿ���ȥ����
����ɫ������ǰ��
LONG );
        set("exits", ([ /* sizeof() == 1 */
        	"west" : "/d/changan/fengxu4",
        ]));

	set("coor/x", -370);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
