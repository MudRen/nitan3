// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����������԰�", ({ "board" }) );
        set("location", "/d/tangmen/chashi");
        set("board_id", "tangmen_b");
        set("long", "����һ���������������½��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

