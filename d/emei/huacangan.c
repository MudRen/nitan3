inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ǽ𶥵���Ҫ��������ģ�������������������
����𡣻����ֺ���Ƕù�̨���Ա��������֡�
LONG);
        set("outdoors", "emei");
        set("exits", ([
                "northwest" : __DIR__"jinding", 
                "southwest" : __DIR__"duguangtai",
                "enter"     : __DIR__"hcazhengdian",
        ]));

        set("no_clean_up", 0);
        set("coor/x", -560);
	set("coor/y", -320);
	set("coor/z", 220);
	setup();
        replace_program(ROOM);
}
