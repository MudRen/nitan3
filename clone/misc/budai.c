inherit ITEM;
void create()
{
     set_name("����", ({ "budai", "dai", "bag" }));
        set_weight(100);
        set_max_encumbrance(1000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
         set("long", "һֻ���鲼֯�ɵĴ��ӣ����񽫶����������档\n");
                set("value", 100);
                set("no_give", 1);
                         }
}

int is_container() { return 1; }

int no_limit_amount() { return 1; }

