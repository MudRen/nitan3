// Room: /city3/tidufu.c
// Date: Feb.14 1998
inherit ROOM;

void create()
{
        set("short", "�ᶽ��");
        set("long", @LONG
��������ᶽ���˰칫�µĵط�����ǰ�� (front)����ľ��������������
�ŵģ����ǳɶ��ᶽ����¡�����վ����˿�������������ױ��̴ӣ�����ȥ��ʮ
�ֱ뺷��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : "/d/city3/tidugate",
        ]));
        set("objects", ([ /* sizeof() == 1 */
             "/d/city3/npc/wutiande" : 1,
             "/d/city3/npc/shicong"  : 2,
             "/d/city3/npc/qinbing" : 4,
        ]));
        set("item_desc",([
            "front" : "
                ###########################
                #                         #
                #    ��   ��   ��   ��    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.�����̵�...�������...��������? ���ϵ���ү��? ...
                        #           #
             HHHH     #               #
             HHHH   #    n         n    #
          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
           ```````````````````````````````````````
                  ()                      ()
                 ()                        ()
                ()                          ()
               ()                            ()\n"
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -430);
	set("coor/y", -160);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
