inherit ROOM;
 
void create()
{
        set("short", "ʥ����");
        set("long", @LONG
�����Ǻ�ľ�µ�ʥ�����ڵء�ʥ���á�������������ޣ�ɷ��Ư��������һ
λ����Ů�ӣ�����С�䣬���޲��ɷ��
LONG );
        set("exits", ([
            "west"   : "/d/heimuya/chlang3",
        ]));
        set("objects", ([
            CLASS_D("riyue") + "/ren" : 1,
            "/d/heimuya/npc/shinu":2,
        ]));       
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
