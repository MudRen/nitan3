// yanzhidian.c ��֬��
// By Dumbness, 2003-5-24 19:23

inherit ROOM;

void create()
{
        set("short", "��֬��");
        set("long", @LONG
���治���������еĳ��趼�ǵ�ɫľ��Ʒ�����ּ�Լ�����¡�����������
һ����Լ��̴��ζ��������ϰڷŵĸ�ɫ��֬�����ۻ����ң���֬�ʺ���Ѫ��
�����˱ǡ�ÿ����������������������ڣ�ӳ����֬�ϣ�����һƬҫ�۵����졣
������ÿ��Ů�Ӷ���һ�����ʺ������������Լ�����֬��ֻ����Ҫ�ȴ���Ѱ�٣�
ʵ�ڲ����װ��������յ�ָ�ϣ�ɲ�Ƿ������� 
LONG
        );
        set("exits", ([
                "west"  : "/d/city/beimen",
        ]));
        set("objects", ([
                "/d/city/npc/yao" : 1,
                "/d/city/npc/jpl" : 1,
        ]) );
	set("coor/x", 10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
