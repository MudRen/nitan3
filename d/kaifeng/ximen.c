inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ�������������
��������С�̷������ŵ�������ߺ�ȡ��˵��򶫾��������
�ķ����أ����򱱹�ȥ��Զ�����ܼ�������۵Ĵ����ˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wroad",
                "southwest" : "/d/luoyang/guandaon4",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
