// Room: /d/suzhou/wanjing.c
// Date: May 31, 98  Java

inherit BUILD_ROOM;

void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ɽ��������һ����Ȫ��ϵ�ϳ�������ɮ�������������䣬���һǧ�İٶ�
�ꡣ��˵Ȫ��ͨ��������������ӿȪ����ˮ������Ϊ�����µ���Ȫ����ʯ�̡���
��Ȫ�����֣�ϵ�������������⡣
LONG );
        set("resource/water", 1); 
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("exits", ([
                "eastdown"   : "/d/suzhou/wanjing",
        ]));
        set("max_room", 1);  
        set("coor/x", 170);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
}

