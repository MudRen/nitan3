// itemmake.c ���Ƶ���

#include <dbase.h>
#include <ansi.h>
#include <name.h>
#include <move.h>
#include <command.h>

inherit F_OBSAVE;
inherit F_NOCLONE;

int is_item_make() { return 1; }

#define LEVEL1          5
#define LEVEL2          10
#define LEVEL3          30
#define LEVEL4          100
#define LEVEL5          300
#define LEVEL6          1000
#define LEVEL7          3000
#define LEVEL8          10000
#define LEVEL9          25000
#define MAX_LEVEL       LEVEL9
#define ULTRA_LEVEL     (LEVEL9 + 1)

nosave int *levels = ({ LEVEL1, LEVEL2, LEVEL3, LEVEL4,
                        LEVEL5, LEVEL6, LEVEL7, LEVEL8,
                        LEVEL9 });

nosave int performing  = 0;
nosave int attack_lvl  = 0;
nosave int defense_lvl = 0;

int is_stay_in_room() { return attack_lvl >= ULTRA_LEVEL; }

string chinese_s(mixed arg)
{
      if (! stringp(arg))return " ��";
      if (arg == "cold")return HIW " ��";
      if (arg == "fire")return HIR " ��";
      if (arg == "magic")return HIY " ħ";
      if (arg == "poison")return HIG " ��";
      if (arg == "lighting")return HIM " ��";
}

// ����������ID - ͨ���ļ����������ж�
string item_owner()
{
        string owner;
        if (sscanf(base_name(this_object()), ITEM_DIR "%*s/%s-%*s", owner))
                return owner;

        return 0;
}

// �жϸ������Ƿ񱻵�ǰĳ��������
int is_not_belong_me(object me)
{
        string user;

        user = query("user");
        if (! user || ! sscanf(user, "%*s(" + me->query("id") + ")"))
                return 1;

        return 0;
}

// ����װ���ĵȼ�
int weapon_level()
{
        mapping o;
        string *ks;
        mixed lvl;
        int i;

        lvl = 0;
        o = query("owner");
        if (mapp(o))
        {
                ks = keys(o);
                for (i = 0; i < sizeof(ks); i++)
                        lvl = count_add(lvl, o[ks[i]]);
        }

        lvl = count_div(lvl, 100);
        lvl = atoi(lvl);
        if (lvl > MAX_LEVEL) lvl = MAX_LEVEL;

        if (lvl == MAX_LEVEL && query("magic/power"))
                // ����ħ������
                lvl = ULTRA_LEVEL;
        return lvl;
}

// ����װ���ĵȼ�
int armor_level()
{
        // More to be added
        return 0;
}

// ����װ���ĳ�����
string weapon_long()
{
        string  n;
        mapping c;
        int type;
        int k;
        int lvl;
        string tessera_name;
        string result;

        c = query("combat");
        n = query("unit") + name();
        if (! c)
                return "��" + n + "��Ȼ��û��������Ѫ�����洿����Ͼ��\n";
        k = c["MKS"] + c["PKS"];

        if (c["WPK_GOOD"] < k / 2 &&
            c["WPK_BAD"]  < k / 2)
                type = 0;
        else
        if (c["WPK_GOOD"] > c["WPK_BAD"] * 2)
                type = -1;
        else
                type = 1;

        if (c["MKS"] + c["PKS"] < 10)
                return "��" + n + "�����Ѿ��ù���Ѫ��������������Ѫ�ۡ�\n";

        attack_lvl = weapon_level();
        lvl = sizeof(levels);
        while (--lvl)
                if (attack_lvl >= levels[lvl])
                        break;
        lvl++;

        switch (type)
        {
        case 1:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIY "������ȥƽƽ������û�а�����⣬ֻ��"
                                 "���������˸е��ǲ��������ʡ�\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIY "������ȥ���˷����������޳羴��һ��"
                               "�Ȼ������Ȼ���棬�ľߵ����緶������\n"
                               "���£�������·�����ɷ���ѵ�����Ǵ�˵�в�"
                               "����ֵ�����֮" + name() + HIY "��\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIC "һ����ȥ��������������������ڷ��"
                               "���裬�������أ�����֮�����ƺ�Ҫ�ط�\n"
                               "�˼䡣���̲�סҪ��̾һ����������ħ��Ҳ�������١�\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIC "�����渽���Ų�֪�����׻꣬����а��"
                               "��ħ�������£�һ�ɰ�����Ȼ��ɢ������\n"
                               "�̲�ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIR "������ȥ���˾��Ķ��ǣ����������������" + name() + HIR
                               "��������ɷ�ʹ˱������ɾ��˼����塣\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIR "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ����ħ������" + name() + HIR "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIW "����ǽ��������������֮һ��" + name() + HIW
                               "�����׼���֮ͽ�������޲��ĳ���ҡ��\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIW "��" + n + HIW "��һ������ɢ�������������������׻겻�١�\n" NOR;
                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��������"
                               "������ɱ�˲����׶�֮ͽ��\n" NOR;
                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ�������׶�֮ͽ��\n" NOR;
                break;

        case -1:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIR "������ȥƽƽ������û�а�����⣬����"
                                 "��֪Ϊ��ȴ�������˸е���Щ������\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIR "������ȥ���˴��ĵ׷��������⣬��"
                               "��Ȼ�����ƺ�����������ԩ�꣬����ȫȻ\n����" + n + HIR
                               "�����ɱ�����ƣ��ѵ�����Ǵ�˵�вŻ���ֵ�а��֮" + name() + HIR
                               "��\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIC "һ����ȥ���������������ԩ��������"
                               "�����������أ�����֮�������̲�ס����\n"
                               "����ս�������ٿ��ڶ��ۡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIC "�����渽���Ų�֪����ԩ�꣬��������"
                               "�������£�һ��Թ��ֱ�������������̲�\n"
                               "ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIW "������ȥ���˾��Ķ��ǣ����������������" + name() + HIW
                               "����֪����Ӣ�۾ʹ����ޡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIW "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ�ĸ��ֶ�����" + name() + HIW "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIG "����ǽ���������������֮һ��" + name() + HIG
                               "��˭������ô��������ʿ�������¡�\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIG "��" + n + HIG "��һ������ɢ�������������������λ겻�١�\n" NOR;
                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��������������ɱ�˲����ˡ�\n" NOR;
                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ����������֮ʿ��\n" NOR;
                break;

        default:
                if (attack_lvl >= ULTRA_LEVEL)
                        result = HIC "������ȥƽƽ������û�а�����⣬ֻ��һ��"
                                 "ƽ��֮���ı������ѡ�\n" NOR;
                else
                if (attack_lvl >= MAX_LEVEL)
                        result = HIC "����Ȼ���⣬�ƺ���Ҫ�ڿն�ȥ������"
                               "���磬�������С���������·������\n"
                               "��������֮����ԩ�겻�衢Ⱥа���ף��޲�����" + n + HIC
                               "�Ϲ�����İ������ơ�\n" NOR;
                else
                if (attack_lvl >= LEVEL8)
                        result = HIM "һ����ȥ����������������λ�������"
                               "�����������أ�����֮�������ʱ������\n"
                               "�����ޱȣ���������ס��\n" NOR;
                else
                if (attack_lvl >= LEVEL7)
                        result = HIM "�����渽���Ų�֪�����λ꣬������а"
                               "����ɥ�����£�һ��Թ��������Ȼ������\n"
                               "�����̲�ס���˸���ս��\n" NOR;
                else
                if (attack_lvl >= LEVEL6)
                        result = HIR "������ȥ���˾��Ķ��ǣ����������������" + name() + HIR
                               "��������а���ֶ����Ӵ˽٣������ֻء�\n" NOR;
                else
                if (attack_lvl >= LEVEL5)
                        result = HIR "����������Ȼ͸��һ��Ѫ�⣬�������������"
                               "����������һʱ�ĸ��ֶ�������" + n + HIR "�µ��λꡣ\n" NOR;
                else
                if (attack_lvl >= LEVEL4)
                        result = HIW "����ǽ���������������֮һ��" + name() + HIW
                               "��˭���뵽��ô������������¡�\n" NOR;
                else
                if (attack_lvl >= LEVEL3)
                        result = HIW "��" + n + HIW "��һ��ɱ��ɢ�������������������λ겻�١�\n" NOR;

                else
                if (attack_lvl >= LEVEL2)
                        result = RED "��" + n + RED "��Ȼ͸��һ��ɱ����������ɱ�˲����ˡ�\n" NOR;

                else
                if (attack_lvl >= LEVEL1)
                        result = RED "ϸ��֮�£��п���һ˿Ѫ�ۣ��������ɱ�˲���"
                               "����Ѫ�ڴ˰ɣ�\n" NOR;
                else
                        result = CYN "���ó���" + n + CYN "����ɱ�������ˡ�\n" NOR;
                break;
        }

        if (attack_lvl == ULTRA_LEVEL)
        {
                if (stringp(tessera_name = query("magic/tessera")))
                        result += "��������Ƕ��" + tessera_name + "����˸������Ĺ�â��\n";
                if (query("ultimate/121"))
                        result += HIY + name() + HIY "�ĵȼ���̫����Ʒ  LV10\n" NOR;
                else
                if (query("ultimate/105"))
                        result += HIY + name() + HIY "�ĵȼ���Զ����Ʒ  LV10\n" NOR;
                else
                if (query("ultimate/87"))
                        result += HIY + name() + HIY "�ĵȼ����Ϲ���Ʒ  LV10\n" NOR;
                else        
                        result += HIY + name() + HIY "�ĵȼ���������Ʒ  LV10\n" NOR;
        } else
        if (lvl)
        {
                result += HIY + name() + HIY "�ĵȼ���" + lvl + "/9\n" NOR;

                if (query("magic/imbue_ok"))
                        result += HIM + name() + HIM "�Ѿ���ֵĽ����ˣ���Ҫ"
                                  "��Ƕ�Գ�ַ���������\n" NOR;
                else
                if ((n = query("magic/imbue")) > 0)
                        result += HIM + name() + HIM "�Ѿ��������������" +
                                  chinese_number(n) + "�Σ����ڼ�������Ǳ�ܡ�\n" NOR;
        }

        result += "-------------------------------------\n";
        result += HIW "��������� " + query("bless") + "\t    " NOR;
        result += HIW "������������" + query("bless") * 10 + "\n" NOR;
        result += HIW "ʥ�������� " + query("bless") + "\t    " NOR;
        result += HIW "ħ������ֵ��" + query("magic/power") + "\n" NOR;
        result += HIW "ħ�����ԣ�" + chinese_s(query("magic/type"))  + "\t    " NOR;
        result += HIW "�����ں϶ȣ�" + query("magic/blood") + "\n" NOR;

        return result;
}

// ����װ���ĳ�����
string armor_long()
{
        string result = "";

        if (query("ultimate/87"))
                result += HIY + name() + HIY "�ĵȼ���Զ����Ʒ\n" NOR;
        else
        if (query("ultimate/69"))
                result += HIY + name() + HIY "�ĵȼ����Ϲ���Ʒ\n" NOR;
        else
        if (query("ultimate/37") || query("ultimate/39"))
                result += HIY + name() + HIY "�ĵȼ���������Ʒ\n" NOR;
                        
        result += "-------------------------------------\n";
        result += HIW "��������� " + query("bless") + "\t    " NOR;
        result += HIW "������������" + query("bless") * 2 + "\n" NOR;
        result += HIW "ʥ�������� " + query("bless") + "\t    " NOR;
        result += HIW "ħ������ֵ��" + query("magic/power") + "\n" NOR;
        result += HIW "ħ�����ԣ�" + chinese_s(query("magic/type"))  + "\t    " NOR;
        result += HIW "�����ں϶ȣ�" + query("magic/blood") + "\n\n" NOR;

        return result;
}

// ����ͨ����װ��
int is_weapon()
{
        return stringp(query("skill_type"));
}

// �ǿ�������װ��
int is_unarmed_weapon()
{
        return query("armor_type") == "hands";
}

// ���ߵĳ�����
string item_long()
{
        if (is_weapon() || is_unarmed_weapon())
                return weapon_long();

        return armor_long();
}

// ����װ�����˺�ֵ
int apply_damage()
{
        int d;
        int p;

        attack_lvl = weapon_level();
        p = query("point");
        d = attack_lvl * p / MAX_LEVEL + query("bless") * 10; // Ǭ��ʥˮʥ��һ������ʮ�㹥��
        return d + p;
}

// ����װ������Чֵ
int apply_armor()
{
        int d;
        int p;

        defense_lvl = armor_level();
        p = query("point");
        // if (d > p * 3 / 2) d = p * 3 / 2 + query("bless") * 10;// Ǭ��ʥˮʥ��һ������10�����
        d = p * 3 / 2 + query("bless") * 2;// Ǭ��ʥˮʥ��һ������2�����
        return d + p;
}

// ���б������ݵĽӿں���
mixed save_dbase_data()
{
        mapping data;
        object  user;

        data = ([ "combat" : query("combat"),
                  "owner"  : query("owner"),
                  "magic"  : query("magic"),
                  "enchase"     : query("enchase"),
                  "ultimate"    : query("ultimate"),
                  "consistence" : query("consistence"),
                  "bless"       : query("bless"),
                  "stable"      : query("stable")]);

        if (! (user = environment()))
                data += ([ "user" : query("user") ]);
        else
        if (playerp(user))
                data += ([ "user" : user->name(1) + "(" + user->query("id") + ")" ]);

        return data;
}

// ���ܴ������ݵĽӿں���
int receive_dbase_data(mixed data)
{
        if (! mapp(data))
                return 0;

        if (mapp(data["combat"]))
                set("combat", data["combat"]);

        if (mapp(data["owner"]))
                set("owner", data["owner"]);

        if (mapp(data["magic"]))
                set("magic", data["magic"]);

        if (mapp(data["enchase"]))
                set("enchase", data["enchase"]);

        if (mapp(data["ultimate"]))
                set("ultimate", data["ultimate"]);

        if (stringp(data["user"]))
                set("user", data["user"]);

        if (! undefinedp(data["consistence"]))
                set("consistence", data["consistence"]);

        if (intp(data["bless"]))
                set("bless", data["bless"]);

        if (intp(data["stable"]))
                set("stable", data["stable"]);


        return 1;
}

// ��ȡ���̵�����
int restore()
{
        int r;

        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

        r = ::restore();
        set("no_sell", 1);
        set("stable", query("stable"));
        set("bless", query("bless"));
        return r;
}

// ��������
int save()
{
       // int res;

        if (base_name(this_object()) + ".c" == __FILE__)
                return 0;

        return ::save();
}

// 9/10��������������
mixed weapon_hit_ob(object me, object victim, int damage_bonus)
{
        //int ap;
        //int dp;
        //int damage;

        if (attack_lvl < MAX_LEVEL ||
            count_lt(query("owner/" + me->query("id")), count_mul(MAX_LEVEL, 80)))
                return;

        if (attack_lvl >= ULTRA_LEVEL &&
            mapp(query("magic")))
        {
                return ITEM_D->weapon10lv_hit_ob(me, victim, this_object(), damage_bonus);
        }

        return ITEM_D->weapon_hit_ob(me, victim, this_object(), damage_bonus);
}

// ���µĺ�����Ϊִ�е�Ƶ�Ȳ����ߣ����Ҿ��и߶��ظ������ʣ�
// ���Զ�����ITEM_D�е�ִ�г���

// ɱ�����Ժ�Ľ���
void killer_reward(object me, object victim)
{
        ITEM_D->killer_reward(me, victim, this_object());
}

// ������Ʒ
int receive_summon(object me)
{
        return ITEM_D->receive_summon(me, this_object());
}

// ������Ʒ
int hide_anywhere(object me)
{
        return ITEM_D->hide_anywhere(me, this_object());
}

// ׷Ѱ��Ʒ
int receive_miss(object me)
{
        if (! is_weapon() && ! is_unarmed_weapon())
        {
                write("���޷�׷Ѱ" + name() + "��\n");
                return 0;
        }

        if (attack_lvl < ULTRA_LEVEL)
        {
                write(name() + "��δͨ�飬����������ĸ�Ӧ��\n");
                return 0;
        }

        return ITEM_D->receive_miss(me, this_object());
}

// ���ڵ���
int do_stab(object me)
{
        return ITEM_D->do_stab(me, this_object());
}

// ��������
int do_touch(object me)
{
        if (attack_lvl != ULTRA_LEVEL)
                return notify_fail("�����˰��죬����ûʲô��Ӧ��\n");

        return ITEM_D->do_touch(me, this_object());
}

// ʥ��
int do_san(object me)
{
        if ((is_weapon() || is_unarmed_weapon()) &&
            attack_lvl < MAX_LEVEL)
                return notify_fail("��������ȼ��������޷�ʥ����\n");

        return ITEM_D->do_san(me, this_object());
}

// ��͸��Ʒ
int do_imbue(object me, object imbue)
{
        return ITEM_D->do_imbue(me, this_object(), imbue);
}

// Add by Lonely
// ��Ƕ��Ʒ
int do_enchase(object me, object tessera)
{
        mapping *ins;
        mapping data, spe_data, ench;
        string  *apply;
        string fn;

        if (query("equipped"))
                return notify_fail("���Ƚ��" + name() + "��װ����˵��\n");

        if (tessera->query("can_be_enchased"))
                return ITEM_D->do_enchase(me, this_object(), tessera);

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

        if (! query("magic/power") && (query("skill_type") ||
            (query("armor_type") && query("armor_type") == "hands")))
        {
                if (query("enchase/used") + 1 >= query("enchase/flute"))
                        return notify_fail(name() + "�ϵ�ʣ�µ�Ψһ�İ�����������Ƕ10lvl������������Ʒ��\n");
        }

        if (query("enchase/used") >= query("enchase/flute"))
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

        if (me->query_skill("certosina", 1) / 3 + random(me->query_skill("certosina", 1)) < 170)
        {
                message_vision(HIM "���á�������һ����ֻ��" + tessera->name() + HIM "ײ��$n" +
                               HIM "�ϣ�ƬƬ�ѿ���\n" NOR, me, this_object());
                tell_object(me, HIC "����Ƕ" + tessera->name() + CYN "ʧ���ˡ�\n" NOR);
                fn = base_name(tessera) + C_FILE_EXTENSION; 
                if (sscanf(fn, "/data/enchase/%*s")) 
                        rm(fn); 
                destruct(tessera);
                me->start_busy(1);
                return 1;
        }

        message_vision(HIM "���á�������һ����$N" HIM "��" + tessera->name() +
                       HIM "��Ƕ����$n" HIM "����İ����\nֻ��" + tessera->name() + HIM
                       "�����ķ���һ������Ĺ�â��������$n" HIM "����Χ���漴���ƽ����\n\n" NOR, me, this_object());
        tell_object(me, HIC "�����" + name() + HIC "������"
                    "���������ı仯��\n" NOR);

        if (query("skill_type"))
                spe_data = tessera->query("enchase/wspe_data");
        else
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
        if (tessera->is_rune_ob())
        {
                if (! query("enchase/rune"))
                {
                        add("enchase/SN", tessera->query("enchase/SN")); 
                        set("enchase/rune", 1);
                }
                set("enchase/rune" + tessera->query("enchase/SN"), 1); 
        } else
                add("enchase/SN", tessera->query("enchase/SN"));

        // add_weight(tessera->query_weight());
        if (ENCHASE_D->identify_ultimate_ob(this_object()))
                tell_object(me, BLINK HBMAG + tessera->name() + BLINK HBMAG "��" + name() + 
                                BLINK HBMAG "��ħ������ں�����ʹ" + name() + 
                                BLINK HBMAG "�����˲���˼�����䡣\n\n" NOR);
        save();
        fn = base_name(tessera) + C_FILE_EXTENSION; 
        if (sscanf(fn, "/data/enchase/%*s")) 
                rm(fn);
        destruct(tessera);
        me->start_busy(1);
        return 1;
}

int query_autoload() { return (query("equipped") ? query("equipped") : "kept"); }

void autoload(string parameter)
{
        switch (parameter)
        {
        case "worn":
                this_object()->wear();
                break;

        case "wielded":
                this_object()->wield();
                break;
        }
}
