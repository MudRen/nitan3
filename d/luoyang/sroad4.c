inherit ROOM;

void create()
{
	set("short", "���Ƶ�");
	set("long", @LONG
���ƴ��λ��������������棬����������ضΣ���ʯ���̳ɵĽ�
�棬���������࣬һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц������������
�������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ����
��һ����������һ���ӻ��̣��ṩ�����ճ����������һЩ��Ʒ��������
һ����ϷԺ��������ǲʱ�����ã���ʱ�Ĵ�ϷԺ�ﴫ������кõ�������
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"xiyuan",
  		"south" : __DIR__"sroad5",
  		"north" : __DIR__"sroad3",
  		"west" : __DIR__"zahuopu",
	]));

	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
