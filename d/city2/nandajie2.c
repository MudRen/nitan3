inherit ROOM;

void create()
{
        set("short", "�Ͻֹ㳡");
        set("long",
"�������Ͻֹ㳡�ˣ����ڿ������������ģ������Ϊ������������һ\n"
"����Ժ����˵���ǵ�һ���ˡ���ʦʦ����������������ģ�����������Ц\n"
"֮�˷�ӵ����������֪�����Է���Ҳ�������Ǹ����ׯ�����澭Ӫ�ĸ���\n"
"��ƥ���ܴ�ٹ����ǵ�������\n"
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"center",
                "south" : __DIR__"nandajie1",
        ]));

        set("objects", ([

        ]));

        setup();
        replace_program(ROOM);
}

