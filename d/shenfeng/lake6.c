
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
ֻ�����ߺ컨���£�����һ��ȫ����µ���Ů���������磬����
��һ��������������������˫�ţ����Ϸ��϶���ˮ�顣ֻ��������
���ڵ����ں��ߣ�����ʥ�࣬��̬���ɷ�����µ�ӳˮ�У��仨һ
��һ��ĵ�����ͷ�ϡ����ϡ�Ӱ���ϡ��ζ�ƽʱ����������磬��ʱ
�����ŵ�˵����������
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"conglin1",
                "east" : __DIR__"lake5",
]));
	set("objects", ([ /* sizeof() == 1 */
                "/d/hangzhou/honghua/huo" :1, 
        ]));
	set("outdoors", "shenfeng");
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
