//ROM dating
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ǡ�������̡��µ��Ĵ��ã������õĴ�����ԶԶ��ȥ�������죬���Ʋ�
ʳ�˼��̻���������һ����(bian)��
LONG );
        set("exits", ([
                "west" : "/d/heimuya/road1",
                "east" : "/d/heimuya/chlang3",
                "southup" : "/d/heimuya/tian1",
        ]));
        set("item_desc", ([
            "bian": "����д����������---�������ʥ��ס�ء�\n",
       	]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
