inherit ROOM;

void create()
{
	set("short", "����ɽ´");
        set("long", @long
��������ɽ��ѩɽ���࣬���Ӵ�����Զ�����أ��������
�Ʋʼ����ɫ������ÿ�괺���Ժ󣬱�ѩ�ڻ������һ�ɹ���
��Ϫ�������볤�����ƺӡ�
long);
        set("exits",([
	        "northup" : __DIR__"shanmen",
                "east" : __DIR__"shankou",
                "southwest" : "/d/shenfeng/kunlun7",
        ]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
