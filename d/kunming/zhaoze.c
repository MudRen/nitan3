inherit ROOM;

void create()
{
        set("short", "�����Ե");
        set("long", @LONG
���������ܲ�����ɫ����������ǰ�߾������������������� 
�������������ﲻ�������ܲ������޳�û������������������ 
��һ˲����ʱ����Ķ���Ȫ������ԭʼɭ�����(Forest door)��
LONG
        );
        set("item_desc", ([
                "door" : "�������ڿ��Խ���ԭʼɭ���Թ�������(enter door)\n",
                "Forest door" : "�������ڿ��Խ���ԭʼɭ���Թ�������(enter door)\n",
                "forest door" : "�������ڿ��Խ���ԭʼɭ���Թ�������(enter door)\n",
        ]));

        set("exits",([
                "east" : __DIR__"yunnan1",
        ]));
        set("objects", ([ //sizeof() == 1
                "/d/maze/forest/forest_door" : 1,
        ]));
        setup();
        // replace_program(ROOM);
}

