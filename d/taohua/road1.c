inherit ROOM;
 
void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��С��������������Զ�����졣С��������ֲ��һЩ�һ�����
��ֻһƳ�ͷ��֣���Щ�һ�ȫ�ǰ�ɫ�ġ�
LONG );
        set("exits", ([
                "east"  : __DIR__"road2",
                "south" : __DIR__"mudi",
        ]));
        
        set("outdoors", "taohua");
 
        setup();
}
