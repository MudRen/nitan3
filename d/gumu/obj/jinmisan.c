// ����ɢ(jinmi san)

#include <ansi.h>
#include "medicine.h"

void create()
{
	set_name(HIW "����ɢ" NOR, ({"jinmi san", "jinmi", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɢ����˵���Խ�����붾��\n");                
                set("base_unit", "��");
                set("base_value", 8000);
                set("base_weight", 80);
		set("only_do_effect", 1); 
                set("mixture", ([
                        "herb" : ([ "shanju"   : 1,
                                    "muxiang"  : 1,
                                    "chantui"  : 1,
                                    "niuhuang" : 1 ]),
                        "neili" : 300,
                        "jing"  : 50,
                        "time"  : 5,
                        "min_level" : 60,
                        "yunv-xinjing" : 60,
                ]));		
	}

    setup();
}

int do_effect(object me)
{
	if (! me->query_condition("yufengdu"))
	{
		tell_object(me,"�㲢û���з䶾����\n");
		return 1;
	}

        me->clear_condition("yufengdu");
	message_vision(HIY "$N������һ������ɢ�����д������д��࣬һ������������Ƣ��\n"NOR,me);
	tell_object(me,HIY "��о����ڵķ䶾��������ȥ��\n" NOR, me);

	destruct(this_object());
	return 1;
}
