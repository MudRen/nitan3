//Room: /d/dali/northgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
        set("long", @LONG
������ǣ���������ǣ��Ǵ�����Ķ��ǡ�����گ�ڳ������������ϡ���
��͹��������ϡ������˹��������ϡ����������������������Ķ��ϵġ�����
���������Դ˳�Ϊ�����˴����Ǳ����ţ���÷ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ��
�����ݳɣ��߶����壬�����ɣ���������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ��
�����죬����һ��������·����ͨȥ��
LONG );
	set("objects", ([
	   "/d/dali/npc/bing": 4,
	   "/d/dali/npc/jiang": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"     : "/d/dali/paifang",
	    "north"     : "/d/dali/dalinorth",
	    "east"      : "/d/dali/chahuashan1",
	    "west"      : "/d/dali/shanlu3",
	]));
	setup();
	replace_program(ROOM);
}

