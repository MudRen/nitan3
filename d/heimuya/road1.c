//road1.c ����·
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����һ����ʯ�����Сɽ�ڣ��򶫱���ͨ��ƽ���ݵ�С·����˵ǰ��������
Ұ�޳�û�����ɾ�����
LONG );
        set("outdoors", "heimuya");
        set("exits", ([
            "northeast" : "/d/heimuya/road2",
            "southwest" : "/d/heimuya/road4",
            "west"  : "/d/heimuya/linjxd1",
            "east"  : "/d/heimuya/dating4",
        ]));
        set("objects",([  
           "/d/heimuya/npc/laozhe" : 1 ,
        ])); 
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
