//Room: /d/dali/qiandian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ǰ��");
        set("long", @LONG
�����Ǵ�����ʹ���ǰ���ש���߽���ʮ�־��ɣ���������������������
��巺������ڴ˵��˴�����ƫ�����ϵ�С�������նԵ��������İ�������
�Էθ���ʮ����ϡ������͵�������԰, �����ǻʹ����š�
LONG );
	set("objects",([
	   "/d/dali/npc/taijian": 1,
	]));
	set("objects", ([
	    CLASS_D("duan")+"/duanzm": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : "/d/dali/yuhuayuan",
	    "south"  : "/d/dali/gongmen",
	]));
	setup();
}
