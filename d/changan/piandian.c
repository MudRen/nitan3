//Room: piandian.c

inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
        set("long", @LONG
ƫ����������������̨���������ΰ����Ű������ķ����������Ҳ�ǲ��ϣ�
��������һЩ���š�������������һ��Ҳ�������������������ݵ���ɮ��������
ɮ��ɫͨ�죬��������黨�����ֺ�ָ���죻������ɮȴ��ɫ���̣���������
�黨�����ֺ�ָ���졣��ɮ��ʽһģһ����ȴƫ�������෴�����ߵ���ͨ���
�۱��
LONG );

        set("exits", ([
        	"east"    : "/d/changan/baodian",
        ]));

        set("objects", ([
        	"/d/changan/npc/jingxuan" : 1,
        	"/d/changan/npc/jingming" : 1,
        ]));

        set("coor/x", -420);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
