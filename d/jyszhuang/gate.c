// Room: /d/jyszhuang/gate.c
// Modified by Lonely Nitan@Mud

#include <localtime.h>
#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_close_men();
int do_open_men(string arg);


void create()
{
        mixed *local;
        object *ob;
        local = localtime(time());

        set("short", HIY"����ɽׯ"NOR);
        set("long",
HIR"������ǽ����������˽�ǧ�꣬�����������صľ���ɽׯ����������\n"
"ֻ֪�������ɽׯ����һֱ����û����֪������λ�ã�Ҳû����֪������\n"
"ɽׯ��������˭�����������˶�֪��һ���¾��ǣ�����ɽׯ���ˣ�������\n"
"�����ˣ������ǻۡ�������ѧ���������Թ������κδ���ʦ���޷���֮��\n"
"��������ɽׯ�Թž��ǽ���������ʥ��������ջ�ĵط����������޵���\n"
"���µ���ѧ�ؼ���������Ů���ƽ𱦲أ��������ջ����˵����������\n"
"�˶���ͬ������ֻ��һ���Ļ�����ô���������ǣ�����ɽׯ�����ǻ���\n"
"������Ψһ���ˣ�\n"NOR
HIM"    ��˵������������׹���һ����ʯ�Ͽ̻���ɽׯ��λ�á�\n"NOR
CYN"    Ȼ�������������ҵ���ʯ���������ȴ���ֲ�����ʲô�취���޷�\n"
"����ɽׯ��������ÿ���µģ��������졣�����ǽ���ɽׯ�ڣ��������Ǿ�\n"
"�����ɽׯ�в����κ��ˣ����ܶ����Եļ������ɽׯ����û���ˣ�����\n"
"��ÿ���µģ���������ɽׯ����ͻȻ��ʧ���������ֵľ��ǣ�ÿ���µ�\n"
"�����Ž�ȥ���ˣ��ڣ�����ͻȻ�����Լ�����ɽׯ���ˡ����ﵽ���̲���\n"
"ʲô���ܣ�ɽׯ�ڵ�����Щʲô����������֪����\n"NOR

);

        set("no_fight", 1);

        set("objects", ([
	]));


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
		local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
		local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
		)
	{
  		set("exits", ([
			"south" : __DIR__"beidajie2",
			"enter" : __DIR__"square",
			]));
	}
	else
	{
  		set("exits", ([
			"south" : __DIR__"beidajie2",
			]));
	}

	setup();
 
}



int do_open_men(string arg)
{
	object ob, me = this_player();
	object room;

	if (query("exits/enter"))
		  return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");

        if (!arg || arg != "men" )
		  return notify_fail("��Ҫ��ʲô��\n");

        if ( (string)SECURITY_D->get_status(me) != "(arch)" &&(string)SECURITY_D->get_status(me) != "(admin)" )
		  return notify_fail("ʲô��\n");

	log_file("status_log", sprintf( "%s opened jysz door on %s.\n", me->query("id"), ctime(time()) ));

	set("exits/enter", "/d/jyszhuang/square");
	message_vision("$N����ָ���һ�㣬֨��һ������һ�����š�\n", this_player());

	return 1;
}

int do_close_men()
{
	if (!query("exits/enter"))
		  return notify_fail("�������Ѿ��ǹ��ϵġ�\n");

  	delete("exits/enter");
	message("vision", "���������ع����ˡ�\n", this_object());
     	return 1;
}


void init()
{

	add_action("do_open_men", "open");
	add_action("do_close_men", "close");
}

