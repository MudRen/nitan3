// Room:/d/changan/zhongnan.c

#include <room.h>
inherit BUNCH_ROOM; 

void create()
{
        set("short",  "����ɽ��");
        set("long", @LONG
����ɽ�ֳ�̫��ɽ���೤���ǰ�ʮ������С����������������֮˵����
����������ɽ�н�����������ٵ���Խ����ɽ�ڣ�����������ƣ�����ȴû��һ
��·������ɽ���������������Ĵ��������ǰ����ԭ��
LONG );
        set("exits",  ([  /*  sizeof()  ==  4  */
                "east"  :  "/d/changan/road2",
                "west"  :  "/d/changan/road3",
                "north"  :  "/d/changan/questroom",
        ]));
        set("outdoors", "changan");

        set("coor/x", -320);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}
