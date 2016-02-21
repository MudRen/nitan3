// huaiyun.c
// updated by linux
// updated by Lonely

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int birth1(object me);
int birth2(object me);
int birth3(object me);

int update_condition(object me, int duration)
{
        if (duration < 1) return 0; 

        if (duration == 1200)
        {
                tell_object(me, HIY "�������Χ���˺�����͵͵���㣬����ò����ڣ�\n" NOR);
                message("vision", me->name() + HIY "��ɬ�ĵ���ͷ����Ū���Լ����½ǡ�\n" NOR,
                        environment(me), me);
        } else 
        if (duration == 800)
        {
                tell_object(me, HIY "�������Χ���˶�����֣�����ָָ��㣬�������ᣡ\n" NOR);
                message("vision", me->name() + HIY "�����㣬������Ƿ����ʲô�Ƶġ���\n" NOR,
                        environment(me), me);
        } else 
        if (duration == 400)
        {
                tell_object(me, HIY "�������Χ���˶���Ц�����Ŀ����㣬���������Ѿ����������㡭����\n" NOR);
                message("vision", me->name() + HIY "��һ���쳣�����Ŀ�⣬�����������Լ��Ķ��ӡ�\n" NOR,
                        environment(me), me);
        } else 
        if (duration == 200)
        {
                tell_object(me, HIY "�������Χ���������綼����������ã������ޱȵ��泩��\n" NOR);
                message("vision", me->name() + HIY "һ������˰������Ϣ���ǻ�����ĸ����Ŀ�ⲻʱɨ������Χ��\n" NOR,
                        environment(me), me);
        } else 
        if (duration == 20 || duration == 10)
        {
                tell_object(me, HIY "�������Χ���˶����ż�����е�Ŀ��ע�����㣬�ѵ��ǡ������ˣ�\n" NOR);
                message("vision", me->name() + HIY "�Ѿ��ж�ʮ�ֵĳٻ��ˣ���ʱ��ͣ����������\n" NOR,
                        environment(me), me);
        } else 
        if (duration == 1)
        {
                tell_object(me, HIY "��Χ���˶����ȵĺϲ�������ͣ�һ���Ǽ�����ʲô������飡\n"
                                "�����������Ͼ�Ҫ���ˣ���Ͻ��ͺ��ӵĸ���ȥ����ҩ�̵Ķ�¥�����������������Σ�յģ�\n" NOR);
                message("vision", me->name() + HIY "���Ŵ��Ķ��ӣ������˵��ϣ�����һ������ʹ������飡\n" NOR,
                        environment(me), me);
                remove_call_out("birth1");
                call_out("birth1", 100, me);
        }
        me->apply_condition("huaiyun", duration - 1);
        return 1;
}

int birth1(object me)
{
        object target;        
        
        if ((int)(me->query("age")) < 18)
        {
                message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ��������$N����̫С�����ʺ�������\n����$N�ĺ��������ˣ��ÿ�������\n" NOR, me);
                me->set("qi", 1);
                me->set("jing", 1);
                me->set("neili", me->query("neili") / 2);
                me->set("long", me->query("longbak"));
                me->delete("longbak");
                me->unconcious();
                return 1;
        } 
        
        if (base_name(environment(me)) != "/d/city/chanfang")
        {
                message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ������������Ļ���ʵ����̫�����ˣ�\n����$N�ĺ��������ˣ��ÿ�������\n" NOR, me);
                me->set("qi", 1);
                me->set("jing", 1);
                me->set("neili", me->query("neili") / 2);
                me->set("long", me->query("longbak"));
                me->delete("longbak");                
                me->unconcious();
                return 1;
        }
         
        target = find_player(me->query("couple/couple_id"));
        if (! target || environment(target) != environment(me))
        {
                message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ�������ڹؼ�ʱ���������û���غ�����ߣ�\n����$N�ĺ��������ˣ��ÿ�������\n" NOR, me);
                me->set("qi", 1);
                me->set("jing", 1);
                me->set("neili", me->query("neili") / 2);
                me->set("long", me->query("longbak"));
                me->delete("longbak");                
                me->unconcious();
                return 1;
        }
        
        if (! me->is_busy())
                me->start_busy(15);
        if (! target->id_busy())
                target->start_busy(15);
                
        message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me, target);
        remove_call_out("birth2");
        call_out("birth2", 15, me);
      
        return 1;
}

int birth2(object me)
{        
        object target;
         
        target = find_player(me->query("couple/couple_id"));
        if (! target || environment(target) != environment(me))
        {
                message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ�������ڹؼ�ʱ���������û���غ�����ߣ�\n����$N�ĺ��������ˣ��ÿ�������\n" NOR, me);
                me->set("qi", 1);
                me->set("jing", 1);
                me->set("neili", me->query("neili") / 2);
                me->set("long", me->query("longbak"));
                me->delete("longbak");                
                me->unconcious();
                return 1;
        }  
              
        if (! me->is_busy())
                me->start_busy(15);
        if (! target->id_busy())
                target->start_busy(15);
                        
        message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n\nӤ���Ѿ�̽����ͷ������\n" NOR, me, target);
        remove_call_out("birth3");
        call_out("birth3", 15, me);
        return 1;
}

int birth3(object me)
{
        object target;
        object baby;
        
        target = find_player(me->query("couple/couple_id"));
        if (! target || environment(target) != environment(me))
        {
                message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�����һ�������ڹؼ�ʱ���������û���غ�����ߣ�\n����$N�ĺ��������ˣ��ÿ�������\n" NOR, me);
                me->set("qi", 1);
                me->set("jing", 1);
                me->set("neili", me->query("neili") / 2);
                me->set("long", me->query("longbak"));
                me->delete("longbak");                
                me->unconcious();
                return 1;
        }  
                
        message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n" +
                "\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n" NOR, me, target);
	me->set("long", "\n���������Ѿ���һ��������ٸ���Ŷ��\n"NOR);
	me->delete("longbak");

        me->set("neili", 0);
        me->set("qi", 1);
        me->set("jing", 1);
        
        baby = new("/clone/user/baby");
        if (random(2) > 0)
        {
                baby->set("gender", "����");
                baby->set_name("С" + target->query("name"), 
                               ({"xiao_" + target->query("id"), "baby"}));
                               
                baby->set("long", "����" + target->query("name") + "��" + me->query("name") + "�ĺ��ӡ����ĺ���" + target->query("name") + "����\n");
                message("shout", HIR "������ϲ�¡�" HIM "��ϲ " HIR + me->query("name") +"(" + me->query("id") +")" 
                        HIM " �� " HIR + target->query("name") + "(" + target->query("id") +")" HIM " ����һ������С�ӡ�\n" NOR,
                        users());
        } else
        {
                baby->set("gender", "Ů��");
                baby->set_name("С" + me->query("name"),
                               ({"xiao_" + me->query("id"), "baby"}));
                               
                baby->set("long", "����" + target->query("name") + "��" + me->query("name") + "�ĺ��ӡ����ĺ���" + me->query("name") + "����\n");
                message("shout", HIR "������ϲ�¡�" HIM "��ϲ " HIR + me->query("name") +"(" + me->query("id") +")" 
                        HIM " �� " HIR + target->query("name") + "(" + target->query("id") +")" HIM " ����һ��ǧ��С������\n" NOR,
                        users());                
        }
        
        baby->set("per", (me->query("per") + target->query("per")) / 2);
        baby->set("kar", (me->query("kar") + target->query("kar")) / 2);
        baby->set("int", (me->query("int") + target->query("int")) / 2);
        baby->set("str", (me->query("str") + target->query("str")) / 2);
        baby->set("con", (me->query("con") + target->query("con")) / 2);
        baby->set("dex", (me->query("dex") + target->query("dex")) / 2);
        baby->set("parents/father", target->query("id"));
        baby->set("parents/mother", me->query("id"));
        baby->save();
        
        me->set("couple/child_id", baby->query("id"));
        me->set("couple/child_name", baby->query("name"));
        target->set("couple/child_id", baby->query("id"));
        target->set("couple/child_name", baby->query("name"));
        me->save();
        target->save();
        
        if (! baby->move(environment(me)))
                baby->move(environment(environment(me)));
                
        return 1;
}

