//Room: xian-daokou.c

inherit ROOM;
void create ()
{
        set ("short", "��������");
        set("long", @LONG
�������Թ��Ƿ���ʤ�أ�Ϊ�����ʳ�����֮�أ���Ϊ���̴�����ۼ�����
�������¡�����������һ����ͨ�˴��·�ڣ�������һ����·ͨ�������������
�ǳ��������ţ��ϱ���������̩����� 
LONG );
        set("exits",([//sizeof() == 5
        	"south" : "/d/changan/yongtai-dadao4",
        	"north" : "/d/changan/yongtai-dadao3",
        	"west" : "/d/changan/xi-chengmen",
        	"east" : "/d/changan/xian-dadao",
        	"southeast" : "/d/changan/bingying3",
        ]));

        set("outdoors", "changan");
        set("coor/x", -440);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
