
inherit ROOM;
void create()
{
	set("short", "�ͱ�");
	set("long", @LONG
�е���һ����ɽ֮�ֻ࣬����ɽ�����ͱ�֮�ϣ��������亣�����
�滨��������̣����ܶ��ǻ�ѩ������ӳ�̣�����Ϧ�����ӳ�գ����޻�
����������״���ŵ��������㣬���ͱ���Ʈ���������ǻ����Լ�ж�ʮ��
�ɣ���Ȼ��˷ҷ�������������֮Ũ�������ͱڣ�������Ȼ����������
ɭ�ϡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
                "northup"  : __DIR__"kunlun1",
                "eastdown" : __DIR__"conglin1",
        ]));
	set("no_new_clean_up", 0);
	set("outdoors", "shenfeng");

	setup();
	replace_program(ROOM);
}
