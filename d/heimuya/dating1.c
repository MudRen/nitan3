// dating1

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǡ�������̡��µ�һ���ã������õĴ�������Ŀ��ȥ�������صģ�����
����һ������(vote)��
LONG );
	
        set("exits", ([
            "south" : "/d/heimuya/grass2",
            "northdown" : "/d/heimuya/linjxd5",
        ]));
 
        set("objects",([
            "/d/heimuya/npc/jiaotu" : 2,
        ]));
        set("item_desc", ([
            "vote": "������̣��ĳ���£��󱻲�����\n"
        ]) );
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
