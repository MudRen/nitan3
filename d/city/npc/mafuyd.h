int do_rideyd()
{
	string hname;
	object ob = this_player();
	int i;
	string *yz_yd = ({
                HIC"�͵�"NOR,
                HIC"�����"NOR,
                HIC"�����"NOR,
                HIC"����"NOR,
                HIC"�ݵ�"NOR,
                HIC"�ݵ�"NOR,
                HIC"����"NOR,
                HIC"����"NOR,
                HIC"���"NOR,
                HIC"���"NOR,
                HIC"���"NOR,
                HIC"�ƺӰ���"NOR,
                HIC"μ������"NOR,
                HIC"�ƺ�"NOR,
                HIC"����"NOR,
                HIC"������ԭ"NOR,
                HIC"�ƺ�"NOR,
                HIC"�ƺ�"NOR,
                HIC"����"NOR,
                HIC"�͵�"NOR,
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
	for ( i = 0;i < sizeof(yz_yd); i++)
		tell_object(ob,yz_yd[i] + "\n");
	ob->move("/d/huanghe/majiu");
	tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ǡ�\n");
	message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
