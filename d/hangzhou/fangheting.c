// fangheting.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ź�ͤ");
        set("long", @LONG
ͤ����������÷����һ����ĩ������÷��ʢ�ţ�εȻ�ɹۡ���ͤ��Ϊ�˼���
��������ʫ���ֺ;����������ᰮ÷��������Ӱ��бˮ��ǳ�����㸡���»ƻ衻
��������ӽ÷���䡣�ݴ�˵��ʫ�˻�����һֻ��ȡ������������ÿ���Լ����ɢ
����ǡ�п�������ʱ��ͯ�ӾͿ����źף�ʫ�˼��ף���ؼҽӿͣ��������С�÷
�޺��ӡ��Ĺ��¡��������߱���ƽ�����¡����ϱ����ǹ�ɽ��
LONG );
        set("exits", ([
            "southwest" : "/d/hangzhou/gushan",
            "southeast" : "/d/hangzhou/pinghuqiuyue",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
