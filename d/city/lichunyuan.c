// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ���Ӿ�����
������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�������������������Ů�˷�
վ���Զ��㷢����Ц������Τ�����������¡�ǰǰ����к��ſ��ˡ���¥�ϴ���
������������ε�������
LONG );
	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                "/d/city/npc/wei" : 1,
                "/d/city/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"cannotsawtu" :
"                                      ��        ��          ��             
                                    ����        ��          ��
      ����������  ���С�����        ����      ����          ����
    ����������    ����������  ����������  ������ء�  �������ة�


   ��       ��    ������                 ��                  ��
   ��       ��    ������       ������  ����                  ��
   �� ���Щ���    �����ੴ   ��������������          ��С�����
   ��   ������    ��  ��                 ��            ��  ����
	\n"]));
	set("exits", ([
		"west"  : "/d/city/nandajie2",
		"up"    : "/d/city/lichunyuan2",
	]));

	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

