void init()
{
        add_action("do_look","look");
        add_action("do_type","type");
}

int do_look(string arg)
{
        int i;
        string msg;
        mapping *bunch_quest,*bunch_zs;

        if (!arg || arg != "paizi")
                return 0;

	if (time() - (int)this_player()->query_temp("last_look_paizi") < 2)
	{
		tell_object(this_player(), "�𼷣���Ҷ�Ҫ������տ����ˣ���һ���ٿ��ɣ�\n");
		return 1;
	}

        bunch_zs = PARTY_QUEST_D->query_zhuisha_quest(TYPE);
        bunch_quest = PARTY_QUEST_D->query_city_quest(PLACE,TYPE);
        bunch_zs = sort_array(bunch_zs,(: sort_by_id :));
        bunch_quest = sort_array(bunch_quest,(: sort_by_id :));

        msg = HIC "----------------------------------------------------------------------------\n"NOR;
        msg += WHT BBLU "                                  ׷ɱ��                                    \n"NOR;
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += sprintf(HIR"%-10s%-50s%-10s%s\n"NOR,"���","����","�Ѷ�","����");
        if (sizeof(bunch_zs))
                for (i=0;i<sizeof(bunch_zs);i++)
                        msg += sprintf("%-10s%-50s%-10s%s\n",
                                          bunch_zs[i]["id"],
                                          "׷ɱ"+bunch_zs[i]["name"],
                                          bunch_zs[i]["difficult"],
                                          bunch_zs[i]["reward"],
                                      );
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += WHT BBLU "                                  �����                                    \n"NOR;
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += sprintf(HIR"%-10s%-50s%-10s%s\n"NOR,"���","����","�Ѷ�","����");
        if (sizeof(bunch_quest))
                for (i=0;i<sizeof(bunch_quest);i++)
                {
                        if (bunch_quest[i]["id"] == "xc" && !bunch_quest[i]["enable"]) continue;
                        msg += sprintf("%-10s%" + sprintf("%d", (50 + color_len(bunch_quest[i]["name"]))) + "-s%-10s%s\n",
                                          bunch_quest[i]["id"],
                                          bunch_quest[i]["name"],
                                          bunch_quest[i]["difficult"],
                                          bunch_quest[i]["reward"],
                                      );
                }
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        msg += HIC "����type <���>�鿴ÿ������ľ��������\n"NOR;
        msg += HIC "����choose <���>ѡ����Ҫ��ɵ����񣬷���������giveupָ�\n"NOR;

	this_player()->set_temp("last_look_paizi",time());
        this_player()->start_more(msg);
        return 1;
}

int do_type(string arg)
{
        string msg;
        mapping bunch_quest;

        if (!wizardp(this_player()) &&  
            (good_bunch(this_player()) || this_player()->query("shen") > 0))
                return notify_fail("��һ��������ʿ����������ʲô����\n");

        if (!wizardp(this_player()) && ! bad_bunch(this_player()))
                return notify_fail("���ȼ���ڵ����ˣ��ſ��Բ鿴�ڵ�������\n");

        if (!arg) 
                return notify_fail("����鿴�����������ϸ��Ϣ��ָ�type <���>\n");

        bunch_quest = PARTY_QUEST_D->query_zhuisha_quest(TYPE,arg);

        if (!bunch_quest)     
                bunch_quest = PARTY_QUEST_D->query_city_quest(PLACE,TYPE,arg);

        if (!bunch_quest)
                return notify_fail("������ѯ�ı��Ϊ"+arg+"�����񲢲����ڡ�\n");
        
        if (bunch_quest["id"] == "xc" && !bunch_quest["enable"]) 
                return notify_fail("�����Ѿ��е���ȥѲ���ˣ���ȸ���ɡ�\n");

        msg = HIC "\n----------------------------------------------------------------------------\n"NOR;
        msg += "�����ţ�" + bunch_quest["id"] + "\n";
        msg += "�������ͣ�" + bunch_quest["type"] + "\n";
        msg += "�������ƣ�" + bunch_quest["name"] + "\n";
        msg += "�����Ѷȣ�" + bunch_quest["difficult"] + "\n";
        msg += "��������" + bunch_quest["reward"] + "\n";
        msg += "������Ϣ: \n" + bunch_quest["msg"] + "\n";
        msg += HIC "----------------------------------------------------------------------------\n"NOR;
        this_player()->start_more(msg);
        return 1;
}

int sort_by_id(mapping quest1, mapping quest2)
{
          return strcmp(quest1["id"], quest2["id"]);
}
