//Room: biaoju-dayuan.c

inherit ROOM;

void create()
{
        set("short", "�����ھִ�Ժ");
        set("long", @LONG
Ժ������ѷ���ʮ�����ò�ϯ���ŵĿ��ڳ�����ϯ�ϻ�����ѩ�����������
�£�б����һ�潴ɫ���ߵ����죬���紵���������죬ʹ�˼����ֱ治���ý�
����������������ϻ�������ʨ�ӡ���Ժ�ﲻʱ��ʦ������
LONG );
        set("exits", ([
        	"north" : "/d/changan/biaoju-damen",
        	"south" : "/d/changan/biaoju-dating",
        ]));
        set("objects", ([
        	"/d/changan/npc/biaotou" : 1,
        	"/d/changan/npc/tang" : 2,
        ]) );
    
        set("outdoors", "changan");
        set("coor/x", -380);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
