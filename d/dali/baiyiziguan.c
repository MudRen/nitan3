//Room: /d/dali/baiyiziguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����ֹ�");
        set("long", @LONG
�����������ƾõ���ʷ���������³�ʫ����ʫ�꡻���䶨ʯ�̡���گ������
»Ȱʯ�̡������¡����������İ������ס�������һ������������������д����
ë�ʻ���ǩд��ֽ��ײ��ϡ��������һ����ѧ��Ϊ�˴�д���ţ����ģ���Լ��
�ȡ�
LONG );
	set("exits",([ /* sizeof() == 1 */
	    "south"  : "/d/dali/dahejieeast",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

