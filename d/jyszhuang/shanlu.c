// shanlu.c 
// by Lonely

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ����ֱ��ɽ·��ǰ�����죬һֱ��û������֮�У�
��֪��ô���������Խ��Խϡ�٣��㲻�������ֹ������ʲ
ô�°ɣ����������������ǰ���š�
LONG
        );

        set("outdoors", "jyszhuang");

        set("exits", ([ /* sizeof() == 3 */
               "west" : __DIR__"zhanchang/entry",
                "east" : __DIR__"kedian",
        ]));

        setup();
        replace_program(ROOM);
}

