inherit ROOM;			   
      
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǻ�ľ�µĵ������������õ������ҡ�������ש�̵ء�������һ����(b
ox1).
LONG );
        set("exits", ([	
	    "west"      : "/d/heimuya/qing",
	]));
	set("item_desc", ([
            "box1": "���Ǹ������Ƶĺ��ӣ������Ա��˴򿪣��տ���Ҳ ��\n",
       	]) );
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
