int do_rideem()
{
        string hname;
        object ob = this_player();
	int i;
	string *yz_em = ({
                HIC"�͵�"NOR,
                HIC"�����"NOR,
                HIC"����㳡"NOR,
                HIC"�ϴ��"NOR,
                HIC"�ϴ��"NOR,
                HIC"����"NOR,
                HIC"��ʯ���"NOR,
                HIC"��ʯ���"NOR,
                HIC"��ʯ���"NOR,
                HIC"��ʯ���"NOR,
                HIC"��ʯ���"NOR,
                HIC"С·"NOR,
                HIC"С·"NOR,
                HIC"С·"NOR,
                HIC"������"NOR,
                HIC"���"NOR,
                HIC"С·"NOR,
                HIC"С·"NOR,
                HIC"��ʯ��"NOR,
                HIC"��ʯ��"NOR,
                HIC"����"NOR,
	});
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
                return notify_fail("С���Ӳſ������������Ҫ��Ǯ��\n");
        switch (random(3))
        {
                case 1:
                        hname=MAG"������"NOR;
                        break;
                case 2:
                        hname=RED"�����"NOR;
                        break;
                default:
                        hname=HIY"������"NOR;
                        break;
        }
        message_vision(
"������ָ�$Nǣ��һƥ"+hname+"��$N����Ծ��������������������·������һ��
���: �����ޡ�\n"NOR , ob );
        message_vision("\nֻ��$N������һ�У�"+hname+"�����͵��ȥ��\n",ob);
	for (i = 0;i < sizeof(yz_em);i++)
		tell_object(ob,yz_em[i] + "\n");
        ob->move("/d/emei/majiu1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ɽ�š�\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��塣\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
