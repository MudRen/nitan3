int do_ridefs()
{
        string hname;
        object ob = this_player();
	int i;
	string *yz_fs = ({
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
                HIC"����·"NOR,
                HIC"����·"NOR,
                HIC"����·"NOR,
                HIC"������"NOR,
                HIC"��������"NOR,
                HIC"����·"NOR,
                HIC"�ּ���"NOR,
                HIC"����ɽ��"NOR,
                HIC"����ɽ��"NOR,
                HIC"��ɽ����"NOR,
                HIC"��ɽ���"NOR,
                HIC"��ɽ���"NOR,
                HIC"Ӣ��¥"NOR,
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
	for (i = 0;i < sizeof(yz_fs);i ++)
		tell_object(ob,yz_fs[i] + "\n");
        ob->move("/d/foshan/majiu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳�������ɽ��\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
