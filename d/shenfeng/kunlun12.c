
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һƬï�ܵ����֣����з�����������Ӣ�ͷף�һ�㵭���ı���
���������Ĳ��㣬�����ڿ���֮�С�ż����һ�����������������Գ���
�������ֱ���һʯɽ��ɽ�������ҷ졣
LONG );
        set("outdoors", "kunlun");
        set("objects", ([ 
                __DIR__"obj/kuzhi" : 2,
        ]));
        set("exits", ([ 
                "south" : __DIR__"kunlun10",
        ]));
       
        set("item_desc", ([
                "�ҷ�" : "���ҷ�խ�����ֶ�������ȥ���Աߵ���ʯ����ʯ���ֵĿ��š����޼��񾭴�����\n", 
        ])); 
        setup();        
}
