// By haiyan

inherit ROOM;

int is_chat_room() {return 1;}
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ�����ݵĶ�¥��������վ��¥��������ֻ�����ݴ������Ⱥ������
С���ӵĽ������������ּ�������˷�����ഩ�ſ����Ĺ��Ӹ��Ƶ�������ڶ�
��һ��װ�λ����Ĵ�Ժ����ʱ��������������ε�����������������¶�������
�����������
LONG );

        set("exits", ([
                "down" : "/d/city/chaguan",
        ]));

        set("no_fight", "1");
        setup();
        "/clone/board/player_b"->foo();
}

