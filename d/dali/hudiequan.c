//Room: /d/dali/hudiequan.c
//Date: June. 29 1998 by Java

inherit BUILD_ROOM;
void create()
{
	set("short","����Ȫ");
        set("long", @LONG
����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷����㼯�������£���
���У��������裬��ǧ����ֻ�ʵ�������һ����ʹ�����û��Ž��ء��ر�����
����Ȫ�ϣ�˳���ǵ���������������������һֻҧ��һֻ��β�����γ�ǧ�ٸ���
��������������Ͷʯ��ɢ���������˾�̾����ۡ�
LONG );
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/yuxuguanqian",
	    "east"   : "/d/dali/xiaodao1",
	]));
        set("max_room",4);
	set("no_clean_up", 0);
	setup();
}

