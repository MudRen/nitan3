//Room: /d/dali/zhulou5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
        set("long", @LONG
�˼�����¥���㣬��һ����Ĵ��ݣ�����һ����̨��ʮ����ʯΧ��һȦ��
��������һ�����ƣ��ϻ汾�������ͼ����Ȧ�����м�����С�����ƣ���������
����������ţ���̨ǰ���Ʒ������ã�ʱ������ǰ������Ĥ�ݡ�
LONG );
	set("objects", ([
	   "/d/dali/npc/jisi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : "/d/dali/zhulou4",
	]));
	setup();
	replace_program(ROOM);
}
