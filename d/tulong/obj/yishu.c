
#include <ansi.h>; 
inherit ITEM;

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(CYN"��������"NOR, ({ "wumu yishu", "book", "yishu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", "����������������\n");
                set("long", "һ�������ľ���˿�������ɹ�ע������Ѫ����׫���ɡ�\n", );
        }
        setup();
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel, arlevel; 

        if (!(arg=="wumu yishu" || arg == "book" || arg == "yishu" ))
        return 0;
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        message("vision", me->name() + "��ר�ĵ��ж��������顣\n", environment(me), me);
        if( (int)me->query("jing") < 80 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        if( (int)me->query("qi") < 80 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        pxlevel = me->query_skill("craft-cognize", 1);
        arlevel = me->query_skill("array-cognize", 1);
        if( count_lt(me->query("combat_exp"), 100000) ) {
                write("���ʵս���鲻�㣬�޷��������������е����ݡ�\n");
                return 1;
        }
        if( count_lt(me->query("combat_exp"), count_div(count_mul(count_mul(pxlevel, pxlevel), pxlevel), 10)) ||
            count_lt(me->query("combat_exp"), count_div(count_mul(count_mul(pxlevel, pxlevel), pxlevel), 10)) ) {
                write("���ʵս���鲻�㣬�޷��������������е����ݡ�\n");
                return 1;
        }
        if( me->query_skill("craft-cognize", 1) > 399 &&
            me->query_skill("array-cognize", 1) > 399){
                write("�㷢�ֶ������������ϵı�������Ҫ���Ѿ���Ȼ���أ���ȫ�����ˡ�\n");
                return 1;
        }
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        if( pxlevel < 400 )
                me->improve_skill("craft-cognize", (int)me->query_skill("literate", 1)/5+1);
        if( arlevel < 400 )
                me->improve_skill("array-cognize", (int)me->query_skill("literate", 1)/5+1);
        write("����ϸ�ж����������б������󷨣������ĵá�\n");
        return 1;
}

