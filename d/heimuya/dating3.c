//ROM dating
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ǡ�������̡��µ������ã������õĴ�����ʮ�����ɣ��ֻ���һ������
ʱ��ʱ�֡���������һ����(bian)��
LONG );
        set("exits", ([
            "south"      : "/d/heimuya/chlang1",
            "northdown" : "/d/heimuya/guang",
        ]));
        set("item_desc", ([
            "bian": "����д����������գ��������졣ǧ�����أ�һͳ���� ��\n",
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
