inherit ROOM;

void create()
{
    set("short", "Ĺ��");
        set("long", @LONG
�����Ǻ�ľ��������̽��ڵ�Ĺ�ء�Ĺ����Χ����һЩ�����Ļ��������ϵ�
�׻����ǵ�㡣�׻��м���һ�ߴ��ʯ��(bei)������Ĺ�ظɸɾ�������Ȼ������
�˴�ɨ��
LONG );
	set("exits", ([
            "west"      : "/d/heimuya/grass1",
        ]));
	set("item_desc", ([
            "bei": "������ţ����������������\n"
	]));
        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
