//Room: /d/city/shuyuan2.c

#define STORY_TOC "/doc/legend/toc"
inherit ROOM;

void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
��������Ժ��ͼ��ݣ�����������һ����Ⱦ�����ϵ���� (shelf)��������
�е������ǵ���ѡ����¼�������еķ���������������ġ�ңԶĥ��ȥ�Ĵ�
˵��������Ķ�(read)����Щ���ϵĹ��¡�
LONG);
        set("item_desc", ([
            "shelf" : "�˴��Ѿ������Ų���ˡ�\n",
        ]));
        set("objects", ([
                "/d/room/roomnpc/teagirl":1,
        ]));
        set("exits", ([
            "down" : "/d/city/shuyuan",
        ]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
}
