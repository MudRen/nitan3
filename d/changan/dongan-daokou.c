//Room: dongan-daokou.c

inherit ROOM;
void create ()
{
        set ("short", "��������");
        set("long", @LONG
�������Թ��Ƿ���ʤ�أ�Ϊ�����ʳ�����֮�أ���Ϊ���̴�����ۼ�����
�������¡�����������һ����ͨ�˴��·�ڣ�������һ����·ͨ����ڼ��������
�ǳ��������ţ��ϱ����������´���� 
LONG );
        set("exits",([//sizeof() == 5
        	"south" : "/d/changan/liande-dadao4",
        	"north" : "/d/changan/liande-dadao3",
        	"west" : "/d/changan/dongan-dadao",
        	"east" : "/d/changan/dong-chengmen",
        	"southwest" : "/d/changan/bingying6",
        ]));

        set("outdoors", "changan");
        set("coor/x", -360);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
        
