int do_rideyl()
{
        string hname;
        object ob = this_player();
	int i;
	string *yz_yl = ({
                HIC"�͵�"NOR,
                HIC"�����"NOR,
                HIC"����㳡"NOR,
                HIC"�����"NOR,
                HIC"�����"NOR,
                HIC"����"NOR,
                HIC"���Ŵ��"NOR,
                HIC"����������"NOR,
                HIC"����������"NOR,
                HIC"���"NOR,
                HIC"���"NOR,
                HIC"����ɽ"NOR,
                HIC"������"NOR,
                HIC"˿��֮·"NOR,
                HIC"˿��֮·"NOR,
                HIC"˿��֮·"NOR,
                HIC"˿��֮·"NOR,
                HIC"��ɽ����"NOR,
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
	for ( i = 0;i < sizeof(yz_yl);i++)
		tell_object(ob,yz_yl[i]+"\n");
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳��������ɽ���µ�������\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��塣\n",ob);
        ob->delete_temp("marks/horserent");
        return 1;
}

