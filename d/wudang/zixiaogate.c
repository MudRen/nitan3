inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
�����ߵ���չ����£�ǰ������䵱ɽ��Ϊ���Ĺ�����
�����ˡ�������ɽ�������ߵʹ������¡���Χ��ľɭɭ������
���֣���ɫ���ġ��������䵱ʦͽ����Ҫ�������
LONG);
        set("exits", ([
                "northdown"  : __DIR__"shijie2",
                "southup"    : __DIR__"guangchang",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -280);
	set("coor/z", 80);
	setup();
        replace_program(ROOM);
}