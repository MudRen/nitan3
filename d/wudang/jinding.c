inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
��е���������Ϯ����ԭ�����ѵ����䵱ɽ������������
�ľ�����ǰ��Ľ����ͭ���ɣ����Իƽ�ÿ�������ٿգ���
�������������������𶥡�������߸߶�����Ⱥ���ϣ�����
������ɽ����������壬�б�һɽ����¯����¯�壬��ɽǧ��
�����·���
LONG);
        set("exits", ([
                "northdown": __DIR__"santiangate",
                "south"    : __DIR__"zijincheng",
                "west"     : __DIR__"shierliantai",
                "eastup"   : __DIR__"guanyuntai",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -420);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}