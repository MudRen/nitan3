// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
�������һ�������ҩʦ�ճ���ӻ�ĵط������ڳ���ʮ�ּ򵥡���
�ڹ���һЩ�����ֻ����м�һ��ī�����������(tiaofu)�����ǻ�ҩʦʱ
�����̵ġ�ˮ�������������Ƕ��һ���������������(bagua)��������
ɢ���ż�ֻ�豭��һ���������ʫ����һ�ŵ���ǩ����ֽ������֮����
�޳������ͱ������һ�����ȡ�
LONG );
	set("cost", 2);
	set("item_desc", ([
                "tiaofu" : "�Ŵ�ǧ���貨ȥ����Ϊ��ɽ���ˡ�����ˮ����������Ů���Ž���ע��������Ȼ��׳��ƫ\n"
		           "�У��껪��ĺ����������������ɹ��ѣ��Ͽ��Σ���������������δɨ�����˼�δ���\n"
		           "��ı�������������ã�������ȡ������Ὥ���������ˣ��������ࡣ���������������\n"
		           "������������ ����\n",
	        "bagua" : "��������������ŵ��������䣬����бб���ȷǷ���������ԣ�Ҳ������\n"
		          "������ԣ���֪����ʲô�ó���\n",
        ]));
	 
	set("exits", ([
                "west" : __DIR__"changlang2",
                "out" : __DIR__"jingshe",
                "north" : __DIR__"changlang",
        ]));
        set("objects", ([
                // __DIR__"obj/paper1" : 1,
	]));
	
	setup();
	replace_program(ROOM);
}
