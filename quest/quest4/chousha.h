mapping menpai1=([
"���ȴ�ʦ":   "������",
"��Զ��":     "�䵱��",
"���ʦ̫":   "������",
"���߹�":     "ؤ��",
"����Ⱥ":     "��ɽ��",
"���޼�":     "����",
"С��Ů":     "��Ĺ��",
"�𴦻�":     "ȫ���",
"�½���":     "������",
]);

mapping menpai2=([
"������":     "������",
"�鰲ͨ":     "������",
"������":     "�嶾��",
"ŷ����":     "����ɽ",
"Ľ�ݸ�":     "����Ľ��",
"���¹���":   "�ƻ���",  
"���Ǻ�":     "��ң��",
"��ɽͯ��":   "���չ�",
"��ҩʦ":     "�һ���",   
]);

string *master1=({
"���ȴ�ʦ",
"��Զ��",
"���ʦ̫",
"���߹�",
"����Ⱥ",
"���޼�",
"С��Ů",
"�𴦻�",
"�½���",
});

string *master2=({
"������",
"�鰲ͨ",
"������",
"ŷ����",
"Ľ�ݸ�",
"���¹���", 
"���Ǻ�",
"��ɽͯ��",
"��ҩʦ",   
});

private nosave string fam1;
private nosave string fam2;

int chousha_begin()
{
   int i,j,k;
   object *ulist;


   i=random(sizeof(master1));
   j=random(sizeof(master2));
   ulist=users();
   k=sizeof(ulist);

   fam1=menpai1[master1[i]];
   fam2=menpai2[master2[j]];

   message("channel:chat", HIB"��������ɱ��"+master1[i]+
   "��"+fam1+"���µ��������������һ��ʱ���ڽ�\n"
   +fam2+"���׻������Կ��������壡\n"NOR,users());

   message("channel:chat", HIB"��������ɱ��"+master2[j]+
   "��"+fam2+"���������������һ��ʱ���ڽ�\n"
   +fam1+"���׵�ƽ�������ǳ������ǵ�������\n"NOR,users());

   while (k-- )
   {
   if ( !environment(ulist[k]) ) continue;

   if (ulist[k]->query("family/family_name") == fam1)
      ulist[k]->set_temp("chousha/fam",fam2);
   else
   if (ulist[k]->query("family/family_name") == fam2)
      ulist[k]->set_temp("chousha/fam",fam1);
   else
   continue;
   }
   this_object()->set_temp("chousha/fam1",fam1); 
   this_object()->set_temp("chousha/fam2",fam2);
   write_file("/quest/chousha/fam1",fam1,1);
   write_file("/quest/chousha/fam2",fam2,1); 

   call_out("chousha_close",1800);
   return 1;
}


void chousha_close()
{
   object *ulist;
   int k;

   ulist=users();
   k=sizeof(ulist);

   while (k--)
   {
    if ( !environment(ulist[k]) ) continue;
    if (ulist[k]->query_temp("chousha"))
    {
    ulist[k]->delete_temp("chousha");
    tell_object(ulist[k], BLK"��Ȼ����������һ�����ĸо���"
    +"��ʼ�ɻ�������Ľ�����ɱ�к����壬\n"
    +"�㿴���Լ�մ����Ѫ���֣���ʼ���ϵ����Լ�Ϊʲô��Ϊʲô��.....\n"NOR);
    } else
    continue;
   }

   message("channel:rumor", HIB"��������ɱ����ʱ���µ�"+fam1+"��"+fam2
   +"֮��ĳ�ɱ���ڽ����ˣ�˫��������������\n"NOR,users());
   this_object()->delete("chousha");
   this_object()->delete_temp("chousha");

   return;
}
