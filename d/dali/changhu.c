//Room: /d/dali/changhu.c
//Date: June. 29 1998 by Java

inherit BUILD_ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
�������ܳ�Լʮ�������������Σ������������ܵĴ����С�������һ��
���£��������л�ҫ�������ɰس��֣��Դ����Σ��������£�ɫ��Ҷ�ۣ�����ɽ
������׺��䡣��ˮ���̣���һ����΢���ж����Ľ��У��̵ľ�Ө���̵Ļ�Ծ��
�̵����ˡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southdown"  : "/d/dali/shilin",
	    "west"       : "/d/dali/shilin1",
	    "northeast"  : "/d/dali/shilin2",
	    "enter"      : "/d/dali/hole",
	]));
        set("max_room",8);
	set("no_clean_up", 0);
	setup();
}

