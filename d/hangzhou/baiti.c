// baiti.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�׵�");
        set("long", @LONG
�׵̺ᵣ���ϣ��������ֳ������������������������������ҡ�ÿ�괺����
��������˿���̣��������մ�Ц�����׾������С��һ����������ۣ�ǳ�ݲ���û
���㡣������в��㣬���������ɳ�̡�������������ľ�ɫ���������߹���
�����ű��ǡ�ƽ�����¡����������Ƕ��š�
LONG );
        set("exits", ([
            "southwest" : "/d/hangzhou/pinghuqiuyue",
            "east"      : "/d/hangzhou/duanqiao",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
