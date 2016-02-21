// equip.c

#include <dbase.h>
#include <weapon.h>

int wear()
{
        object owner;
        mapping armor_prop, special_prop, applied_prop;
        string *apply1, *apply2, type;
        int flag;

        if (! objectp(this_object())) return 0;
        // Only character object can wear armors.
        owner = environment();
        if (! owner || ! owner->is_character()) return 0;
        
        if (query("no_identify"))
                return notify_fail(this_object()->name() + "��Ҫ������ſ���ʹ�á�\n");
                
        // Does the consistence valid ?
        if (query("consistence") < 1)
                return notify_fail(this_object()->name() + "������̫�����ˣ����ܼ��������ˡ�\n");

        // If already worn, just recognize it.
        if (query("equipped")) return 1;

        // If handing it now, stop handing
        if (owner->query_temp("handing") == this_object())
                owner->delete_temp("handing");

        // Check if we have "armor_prop" defined.
        if (! mapp(armor_prop = query("armor_prop")) ||
            ! stringp(type = query("armor_type")))
                return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");

        if (owner->query_temp("armor/" + type))
                return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");

        owner->set_temp("armor/" + type, this_object());
        
        apply1 = keys(armor_prop);        
        applied_prop = owner->query_temp("apply");
        if (! mapp(applied_prop)) applied_prop = ([]);
        for(int i = 0; i<sizeof(apply1); i++)
                if (undefinedp(applied_prop[apply1[i]]))
                        applied_prop[apply1[i]] = armor_prop[apply1[i]];
                else
                        applied_prop[apply1[i]] += armor_prop[apply1[i]];
        
        flag = 0;                
        if (mapp(special_prop = query("enchase/spe_data")))
                apply2 = keys(special_prop);
        if (arrayp(apply2) && sizeof(apply2))
        for(int i = 0; i<sizeof(apply2); i++)
        {
                if (apply2[i] == "int" || apply2[i] == "str" ||
                    apply2[i] == "con" || apply2[i] == "add_skilllevel" ||
                    apply2[i] == "max_qi" || apply2[i] == "max_jing")
                        flag = 1;
                        
                if (undefinedp(applied_prop[apply2[i]]))
                        applied_prop[apply2[i]] = special_prop[apply2[i]];
                else
                        applied_prop[apply2[i]] += special_prop[apply2[i]];
        }
        
        owner->set_temp("apply", applied_prop);
        set("equipped", "worn");
        if (flag) CHAR_D->setup_char(owner); 
                
        return 1;
}

int wield()
{
        object owner, old_weapon;
        mapping weapon_prop, special_prop;
        //string *apply1, *apply2, type;
        string *apply1, *apply2;
        mixed no_wield;
        int flag, f;

        if (! objectp(this_object())) return 0;
        // Only character object can wear armors.
        owner = environment();
        if (! owner || ! owner->is_character()) return 0;

        if (query("no_identify"))
                return notify_fail(this_object()->name() + "��Ҫ������ſ���ʹ�á�\n");
                
        // Does the consistence valid ?
        if (query("consistence") < 1)
                return notify_fail(this_object()->name() + "������̫�����ˣ����ܼ���װ���ˡ�\n");

        // If already wielded, just recognize it.
        if (query("equipped")) return 1;

        // If the item can not wield, I will return the fail message
        if (no_wield = query("no_wield"))
        {
                // can not wield
                if (stringp(no_wield))
                        return notify_fail(no_wield);
                else
                        return notify_fail("���������޷�װ����");
        }

        // If handing it now, stop handing
        if (owner->query_temp("handing") == this_object())
                owner->delete_temp("handing");

        // Check if we have "weapon_prop" defined.
        if (! mapp(weapon_prop = query("weapon_prop")) ||
            ! stringp(query("skill_type")))
                return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");

        flag = query("flag");

        if (flag & TWO_HANDED)
        {
                if(owner->query_temp("secondary_weapon") ||
                   owner->query_temp("weapon") ||
                   owner->query_temp("handing"))
                        return notify_fail("�����ճ�˫�ֲ���װ����������\n");
                owner->set_temp("weapon", this_object());
        } else
        {
                // If we are are using any weapon?
                if (! (old_weapon = owner->query_temp("weapon")))
                        owner->set_temp("weapon", this_object());

                else // If we still have a free hand? 
                if (!owner->query_temp("secondary_weapon")
                &&  !owner->query_temp("handing"))
                {
                        // If we can wield this as secondary weapon?
                        if(flag & SECONDARY) {
                                owner->set_temp("secondary_weapon", this_object());
                        }            
                        // If we can switch our old weapon to secondary weapon ?
                        else if( (int)old_weapon->query("flag") & SECONDARY ) {
                                old_weapon->unequip();
                                owner->set_temp("weapon", this_object());
                                old_weapon->wield();

                        // We need unwield our old weapon before we can use this one.
                        } else 
                                return notify_fail("������ȷ�����Ŀǰװ����������\n");

                // We have both hands wearing something.
                } else
                        return notify_fail("�����ճ�һֻ����ʹ��������\n");
        }

        // add by doing to discard the secondary_weapon's prop
        if (owner->query_temp("secondary_weapon") != this_object())
        {
                apply1 = keys(weapon_prop);
                for(int i = 0; i<sizeof(apply1); i++)
                        owner->add_temp("apply/" + apply1[i], weapon_prop[apply1[i]]);
                        
                f = 0;
                if (mapp(special_prop = query("enchase/spe_data")))
                        apply2 = keys(special_prop);
                if (arrayp(apply2) && sizeof(apply2))
                for(int i = 0; i<sizeof(apply2); i++)
                {
                        if (apply2[i] == "int" || apply2[i] == "str" ||
                            apply2[i] == "con" || apply2[i] == "add_skilllevel" ||
                            apply2[i] == "max_qi" || apply2[i] == "max_jing")
                                f = 1;

                        owner->add_temp("apply/" + apply2[i], special_prop[apply2[i]]);
                }
        }

        owner->reset_action();
        set("equipped", "wielded");
        if (f) CHAR_D->setup_char(owner); 
        return 1;
}

int unequip()
{
        object owner;
        mapping prop1 = 0, prop2 = 0, applied_prop;
        string *apply1, *apply2, equipped;
        int flag;

        if (! environment()) return 0;

        if (! (owner = environment())->is_character())
                return 0;

        if (! stringp(equipped = query("equipped")))
                return notify_fail("��Ŀǰ��û��װ������������\n");

        if (equipped == "wielded")
        {
                if ((object)owner->query_temp("weapon") == this_object())
                {
                        prop1 = query("weapon_prop");
                        prop2 = query("enchase/spe_data");
                        owner->delete_temp("weapon");
                } else
                if ((object)owner->query_temp("secondary_weapon") == this_object())
                {
                        owner->delete_temp("secondary_weapon");
                        prop1 = 0;
                        prop2 = 0;
                }
                owner->reset_action();
        } else
        if (equipped == "worn")
        {
                owner->delete_temp("armor/" + query("armor_type"));
                prop1 = query("armor_prop");
                prop2 = query("enchase/spe_data");
        }

        if (mapp(prop1))
        {
                apply1 = keys(prop1);
                applied_prop = owner->query_temp("apply");
                for (int i = 0; i<sizeof(apply1); i++)
                        // To support array apply, we cannot add_temp() here.
                        applied_prop[apply1[i]] -= prop1[apply1[i]];
        }
        
        flag = 0;      
        if (mapp(prop2))
        {
                apply2 = keys(prop2);
                applied_prop = owner->query_temp("apply");
                for (int i = 0; i<sizeof(apply2); i++)
                {
                        if (apply2[i] == "int" || apply2[i] == "str" ||
                            apply2[i] == "con" || apply2[i] == "add_skilllevel" ||
                            apply2[i] == "max_qi" || apply2[i] == "max_jing")
                                flag = 1;
                        // To support array apply, we cannot add_temp() here.
                        applied_prop[apply2[i]] -= prop2[apply2[i]];
                }
        }
        
        delete("equipped");
        
        if (flag) CHAR_D->setup_char(owner);
        
        return 1;
}

// hit the object as a weapon
mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed foo;

        foo = this_object()->weapon_hit_ob(me, victim, damage_bonus);

        ITEM_D->reduce_consistence(this_object());

        if (! mapp(query_temp("daub")))
                return foo;

        COMBAT_D->hit_with_poison(me, victim, this_object());
        return foo;
}

// other one hit me as an armor
mixed valid_damage(object me, object victim, int damage_bonus)
{
        ITEM_D->reduce_consistence(this_object());

        if (! mapp(query_temp("daub")))
                return;

        if (me->query_temp("weapon") || me->query_temp("remote_attack") ||
            me->query("not_living"))
        {
                // the attacker has weapon, or remote attack, or not living,
                // he won't be poisoned by my cloth or armor
                return;
        }

        COMBAT_D->hit_poison(me, victim, this_object());
        return;
}
