// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң�����˶���
�ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡�Ŀ�ջ�����Ը��ص���
�ǽ�����������˵Ҳ�������ǵ��Ļ�ص㡣������һ��Ǯׯ������������������
�Ľ���������
LONG
        );
        set("outdoors", "city");
        set("objects", ([
                CLASS_D("ouyang") + "/ouyangke" : 1,
        ]));
        set("exits", ([
                "east"  : "/d/city/kedian",
                "south" : "/d/city/guangchang",
                "west"  : "/d/city/qianzhuang",
                "north" : "/d/city/beidajie2",
        ]));

	set("coor/x", 0);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
