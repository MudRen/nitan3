// haha
// f.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string item;
        string target;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg) return notify_fail("��Ҫ��ʲô��\n");

        if (sscanf(arg, "%s for %s", item, target) != 2)
                return notify_fail("��Ҫ��ʲô��������10lvl�أ�\n");
                
        if (! objectp(ob = present(item, me)))
                return notify_fail("����û�������Ʒ��\n");
        
        ob->set("combat/MKS", 2100);
        ob->set("owner/" + target, 21000000);
        ob->set("magic/imbue_ok", 1);
        ob->set("magic/blood", 21000);
        ob->save();
        
        tell_object(me, "����10lvl�ɹ���\n");
        return 1;
}
