
inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
�������ֺó������˰��ʱ����ʼ���꣬һ�����֣�ֻ����ǰ������
ѩ��ʹ�˸������Ķ��ǡ���ɫ���¹�ӳ����ɫ��ѩ�����˾�������Ҳ��
����֮�У��پ���ǧ���ޣ�һ����С�쳣��
LONG );
	set("no_new_clean_up", 0);
	set("outdoors", "kunlun");

	set("exits", ([ /* sizeof() == 3 */
                "westdown" : __DIR__"kunlun6",
                "south" : __DIR__"kunlun5",
                "eastdown" : __DIR__"kunlun3",
        ]));

	setup();
	replace_program(ROOM);
}
