// shanlu7.c
// Date: Nov.1997 by Venus

inherit BUILD_ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·���Ǻ���ͤ��������
��ĿԶ����Ⱥɽ���������۵ף���ȷ�����ӵú�ȥ������������ɽ��·��������
����ɽ��·��
LONG );
        set("exits", ([
            "eastdown": "/d/hangzhou/yuhuangsj",
            "westup"  : "/d/hangzhou/yuhuangsd",
        ]));
        set("outdoors", "hangzhou");
        set("max_room", 4);
        setup();
}
