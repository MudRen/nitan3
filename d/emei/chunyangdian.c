inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������һǧ���ף������ľ�Դ䣬�ľ����ˡ���ǰ��
һʯ��������ʯ����˵����������ɽʱ������������Ϣ������
�˿��ݹ۶�����壬�����𶥣������ͱڣ�������ߡ�������
������ˮ�֣������ǹ��Ƹ�
LONG);
        set("exits", ([
                "eastdown" : __DIR__"guiyunge",
                "westup"   : __DIR__"shenshuian",
        ]));
        set("outdoors", "emei");
        set("no_clean_up", 0);
	set("coor/x", -430);
	set("coor/y", -230);
	set("coor/z", 60);
	setup();
        replace_program(ROOM);
}