// Modified by lonely@NT
int zuji_times; 
void zuji_begin(int num)
{
     object killer;
     object killer1;
     int n;

/*
     if( zuji_times < 1 )
     {
        remove_call_out("zuji_begin");
        return;
     }
*/

     if( zuji_times >= 8  )
     {
        remove_call_out("zuji_begin");
        remove_call_out("zuji_new");
        call_out("zuji_new",60,num);
        return;
     }

     zuji_times++;

     message("channel:rumor", MAG"�����´��š�ֻ���õĵ�����֮����һ��������ʿ�����ų�ì����������ָָ��㣬���������Ź��⡣\n"
        "��ͷ��������Ȼ��Щ�����˿��������Եģ�����������һ��Ҳ�����ã�\n"
        "���˵İ��������˳�ȥ�����ڡ�������ɵ�����׶����ÿ����ι�˾綾��\n"
        "ֻ���������˰������У��ҳ�һ�ţ�һ��붼ˤ��������\n"
        "����һӵ���ϡ�������ʩ��\n"NOR,users());
     for(n=0;n<num;n++)
     {
          killer=new("/quest/zuji/qidanb");
          killer->move("/d/yanmen/road");
          killer->change_ob();
/*
          killer1=new("/quest/zuji/songb");
          killer1->move("/d/yanmen/shance");
          killer1->change_ob();
*/
     }

     remove_call_out("zuji_begin");
     call_out("zuji_begin",30,num);
     return;
}
              
void zuji_new(int num) 
{
     object killer;
     int n;
/*
     if( zuji_times >= 4 )
     {
*/
          zuji_times=1;
   message("channel:rumor",MAG"�����´��š����Ź��⣬ֻ����ʱ���������������������˵��ȵ���ƥ������\n"
       "ֻ����Щ������ʿ���϶���Ƥ�ã����ó�ì�������䵶�����乭�������ͣ��ӥ���߸������\n"
       "��ͷ���һ����Х�����������ˣ����˵İ��������˳�ȥ�����ڡ�������ɵ�����׶����ÿ����ι�˾綾��\n"
       "ֻ���������˰������У��ҳ�һ�ţ�һ��붼ˤ��������\n"
       "����һӵ���ϡ�������ʩ��\n"NOR,users());

     for(n=0;n<num;n++)
     {
          killer=new("/quest/zuji/qidanb");
          killer->move("/d/yanmen/road");
          killer->change_ob();
     }
          remove_call_out("zuji_continue");
          call_out("zuji_continue",60,num);
     return;
}


void zuji_continue(int num)
{
          message("channel:rumor", HIR"�����´��š�����һ��ʱ�������"
            +HIR"����������ʣ�¼��˾���ɱ�ˣ�ûһ��������ߡ���\n"NOR,users()); 
          remove_call_out("zuji_over");
          call_out("zuji_over",30,num);
}
void zuji_over(int num)
{
     object killer,killer1;
     int n;
   message("channel:rumor",MAG"�����´��š�ֻ�������������������������������������������Ů���ˡ�\n"
        "�����˼�����һʮ������ʿ���ڵ��£���������ʱ��ɫʮ�����ͣ������˴������ʡ�\n"
        "���ˣ�$*@!@#$%^&*��\n"
        "���������۾���һ�����������ȵ���أ���ɹ��������������ӹ��������������Ӵ��˹�ȥ��\n"
        "�������ұ�������۶Ϸ������ұ۹ؽڣ������������������������˴�����һ��ˤ�ڵ��ԡ�\n"
        "���ˣ�#$%^&*$*@!@��\n"
        "����������һӵ���ϣ��������˹��˹�ȥ�������������������ٸ�������\n"
        "���ٸ�����һ����ն��һ���ֱۣ����ŵ�Ӥ�����µ��������ű㱻һ����ȥ�˰���Դ���\n"
        "ֻ�����������۾���ʱ���ˣ�������ɫ�ɲ�֮��������һ�����������\n"
        ".........\n"
        NOR+HIY"Ϧ����Ѫ���������˷�����.........\n"NOR,users());
/*
     for(n=0;n<num;n++)
     {
          killer=new("/quest/zuji/qidanb");
          killer->move("/d/yanmen/road");
          killer->change_ob();
     }
*/
          killer1=new("/quest/zuji/xiao");
          killer1->move("/d/yanmen/road");
          killer1->change_ob();
     return;
}
void zuji_close()
{
   string temp;
   int killer_rate,chousha_count;
   object *ulist;
   int k;

   ulist=users();
   k=sizeof(ulist);
   while (k--)
   {
      if( !environment(ulist[k]) || !ulist[k]->query_temp("zuji")) continue;
      ulist[k]->delete_temp("zuji");
      ulist[k]->delte_temp("apply/short");
      ulist[k]->add("combat_exp",20000);
      ulist[k]->add("potential",5000);
      ulist[k]->add("weiwang",20);
           tell_object(ulist[k],HIW"������"+HIR+chinese_number(20000) 
           +HIW"�㾭���"+HIR+chinese_number(5000)+HIW"��Ǳ�ܽ�����"+HIR+chinese_number(20)+HIW"����������\n"NOR);   
   }

  message("channel:rumor",MAG"�����´��š�ֻ���õ���һ�������������¶̵��������������ӵ�ʬ��Ͷ��ӣ��ߵ��±ߣ�\n"
       "ӿ����������������ȥ����Ȼ�䡰���ۡ�����Ӥ������ޣ�����ʯ���д������������ź�����һ�����´�\n"
       "���з��ϣ��ĵ�һ�����������õ������������ϡ�Ӥ�����֮��һֱ��ֹ�������Ǹ�Ӥ����\n"NOR,users());

   zuji_times=0;
   killer_rate=6;
   temp=sprintf("%d",killer_rate);
   write_file("/quest/chousha/killer_rate",temp,1);
   chousha_count=0;
   temp=sprintf("%d",chousha_count);
   write_file("/quest/chousha/chousha_count",temp,1);

   return;
}

void zuji_fail()
{
     remove_call_out("zuji_begin");
     remove_call_out("zuji_new");
     remove_call_out("zuji_continue");
     remove_call_out("zuji_over");
     remove_call_out("zuji_close");
     remove_call_out("remove_enemy");
     call_out("remove_enemy",1);
     return;
}
void remove_enemy()
{
   string temp;
        object *enemys;
        int i, chousha_count;
        mapping my = query_entire_dbase();

   chousha_count=0;
   temp=sprintf("%d",chousha_count);
   write_file("/quest/chousha/chousha_count",temp,1);
        if (arrayp(enemys = children("/quest/zuji/qidanb")))
        {
                for (i = 0; i < sizeof(enemys); i++)
                {
                        if (enemys[i]->is_fighting())
                        {
                                enemys[i]->remove_all_killer();
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "ͻȻ��ɫһ�䣬Ѹ�ٹ������У�����սȦת�����ˡ�\n");
                        }
                        else {
                                tell_room(environment(enemys[i]), HIW "ֻ��" + enemys[i]->name()
                                        + "��ֵһ�㣬ͻȻ��ɫ��䣬����ææ�������ˡ�\n");
                        }
                        destruct(enemys[i]);
                }
        }
        return; 
}

