// unique.c

// This function returns 1 if this_object() is not the unique clone in
// the mud. Note that calling this function on master copy always return
// 0.
#include <dbase.h>
#include <ansi.h>
#include <name.h>
inherit F_OBSAVE;

nomask int violate_unique()
{
        object *ob;

        if( !clonep(this_object()) ) return 0;

        // Find all the cloned instance of this_object()
        ob = filter_array( children(base_name(this_object())), (: clonep :) );

        return sizeof(ob) > 1;
}

// This function returns the replica of this_object() if any.
object create_replica()
{
        string replica;
        object obj;

        seteuid(getuid());
        if( stringp(replica = this_object()->query("replica_ob")) )
                obj = new(replica);
        else
                obj = 0;
        destruct(this_object());
        return obj;
}

int do_enchase(object me, object tessera)
{
        mapping *ins;
        mapping data, spe_data, ench;
        string  *apply;
        string  fn;
        object ob = this_object();

        if (tessera->query("can_be_enchased"))
                return notify_fail(tessera->name() + "ֻ����Ƕ������10lvl�����ϡ�\n");

        if (! mapp(tessera->query("enchase")))
                return notify_fail(tessera->name() + "���ܷ���ħ����"
                                   "û�б�Ҫ��Ƕ��" + name() + "���档\n");

        if (tessera->is_item_make())
                return notify_fail(tessera->name() + "����Ƕ��Ʒ�����ܱ���Ƕ��" + name() + "���档\n");

        if (me->query_skill("certosina", 1) < 200)
                return notify_fail("����������Ƕ���ջ�����"
                                   "��죬����óȻ���֡�\n");

        if (! query("enchase/flute"))
                return notify_fail(name() + "��û�а���������Ƕ��ʯ��\n");

        if ((int)query("enchase/used") >= query("enchase/flute"))
                return notify_fail(name() + "�ϵİ����Ѿ��������ˡ�\n");

        if (tessera->is_rune_ob() && query("enchase/rune" + tessera->query("enchase/SN")))
                return notify_fail(name() + "�ϵİ������Ѿ���Ƕ�˷���,����Ƕ�����ħ�Գ�ͻ��\n");

        ench = tessera->query("enchase");
        if (! undefinedp(ench["type"]))
        {
                if (ench["type"] != "all" &&
                    ench["type"] != query("skill_type") &&
                    ench["type"] != query("armor_type"))
                        return notify_fail(tessera->name() + "��ħ�����Բ��ʺ���Ƕ��" + name() + "�ϡ�\n");
        }

        if (me->query_skill("certosina", 1) / 3 + random(me->query_skill("certosina", 1)) < 180)
        {
                message_sort(HIM "���á�������һ����ֻ��" + tessera->name() + HIM "ײ��$n" +
                             HIM "�ϣ�ƬƬ�ѿ���\n" NOR, me, ob);
                tell_object(me, HIC "����Ƕ" + tessera->name() + CYN "ʧ���ˡ�\n" NOR);
                fn = base_name(tessera) + C_FILE_EXTENSION;
                if (sscanf(fn, "/data/enchase/%*s")) 
                        rm(fn);

                destruct(tessera);
                me->start_busy(1);
                return 1;
        }

        message_sort(HIM "���á�������һ����$N" HIM "��" + tessera->name() +
                     HIM "��Ƕ����$n" HIM "����İ����ֻ��" + tessera->name() + HIM
                     "�����ķ���һ������Ĺ�â��������$n" HIM "����Χ���漴���ƽ����\n" NOR, me, ob);
        tell_object(me, HIC "�����" + name() + HIC "������"
                    "���������ı仯��\n" NOR);

        if (query("skill_type"))
                spe_data = tessera->query("enchase/wspe_data");
        else
        if (query("armor_type"))
                spe_data = tessera->query("enchase/aspe_data");
        
        if (! mapp(spe_data)) spe_data = ([ ]);
        apply = keys(spe_data);
        data = query("enchase/spe_data");
        if (! mapp(data)) data = ([ ]);
        
        for(int i = 0; i<sizeof(apply); i++)
                if (undefinedp(data[apply[i]]))
                        data[apply[i]] = spe_data[apply[i]];
                else
                        data[apply[i]] += spe_data[apply[i]];

        set("enchase/spe_data", data);

        ins = query("enchase/inset");
        if (! ins) ins = ({ });
        ins += ({ (["name" : tessera->query("name"), "id" : tessera->query("id"),
                    "cur_firm" : tessera->query("enchase/cur_firm"), 
                    "SN" : tessera->query("enchase/SN"), 
                    "spe_data" : spe_data]) });

        set("enchase/inset", ins);
        add("enchase/used", 1);
        add("enchase/SN", tessera->query("enchase/SN"));
        if (tessera->is_rune_ob()) 
                set("enchase/rune" + tessera->query("enchase/SN"), 1); 
        // add_weight(tessera->query_weight());
        save();
        fn = base_name(tessera) + C_FILE_EXTENSION; 
        if (sscanf(fn, "/data/enchase/%*s")) 
                rm(fn);

        destruct(tessera);
        me->start_busy(1);
        return 1;
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{
        if (! mapp(data))
                return 0;

        if (data["enchase"])
                set("enchase", data["enchase"]);

        return 1;
}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;
        //object  user;

        data = ([ ]);

        if (query("enchase"))
                data += ([ "enchase" : query("enchase") ]);
                
        return data;
}

int save()
{
        //int res;

        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

        return ::save();
}

int remove()
{
        save();
}
