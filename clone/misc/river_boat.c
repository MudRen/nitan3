// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG );
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
        set("no_fight", 1);
        set("no_magic", 1);
	setup();
	replace_program(ROOM);
}

