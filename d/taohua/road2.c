inherit ROOM;
 
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG );
        set("exits", ([
                "west"  : __DIR__"road1",
                "north" : __DIR__"road3",
        ]));
        set("outdoors", "taohua");
 
        setup();
}