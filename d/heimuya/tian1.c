inherit ROOM;
 
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǻ�ľ�µĵ��Ĵ��á������á���һ���긾�˺�ü���ڵ��ء�
LONG );
        set("exits", ([
            "northdown"   : "/d/heimuya/dating4",
        ]));
        set("objects", ([
            CLASS_D("riyue") + "/shang": 1,
        ]));       
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
