//ROM dating
inherit ROOM;
void create()
{
        set("short", "�׻���");
        set("long", @LONG
���ǡ�������̡��µڶ����ã��׻��õĴ�������Ŀ��ȥ��һ�ض�����Ѫ��
��Ȼ����ǰ������һ����ս����������һ���ľ��(bian)�����ϱ������м���Ѫ
��(zi)��
LONG );
        set("exits", ([
            "west" : "/d/heimuya/baistep1",
            "east" : "/d/heimuya/linjxd6",
        ]));
        set("item_desc", ([
            "bian": "����д�����������գ��׻����죻
                     ǧ�����أ�һͳ���� ��\n",
            "zi" : "����д������ɽ���ӣ���ɱа�̡�\n" 
	]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
