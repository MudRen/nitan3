// ��ɢ����ͽ����

void attempt_apprentice(object ob)
{
        mapping fam = ob->query("family");
        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0) 
        {
                command("say " + RANK_D->query_respect(ob) +
                        "������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ�������������̰벽��");
                return;
        }
                        
        if (! fam || fam["family_name"] != "����")
        {
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }

        if ((int)ob->query_skill("shenghuo-shengong", 1) < 70) 
        {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }        
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", this_object()->query("title") + "���½���");
}
