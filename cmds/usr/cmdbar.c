int main(object me,string arg)
{
        //Look  score  hp  search  say   chat  chann  I   fee  who  map  help  alias  icon  
        string *cmdbar;
        string *tmp = ({
                "�۲�=look","��Ʒ=i","���ۣӣ�=score","״̬�ȣ�=hp",
                "����ӣ�=cha","����ͷ��=face ...","��ѯ����=fee",
                "����Ƶ��=chann","����=search","����=who",
                "����=help ...","˵��=say ...","����=chat ...",});

        
        cmdbar=me->query("cmdbar");
        if(!arrayp ( cmdbar ) || sizeof(cmdbar)!=13)
                cmdbar = tmp;
        //me->set("cmdbar",cmdbar);//�Ժ��������һ�ӭ�Ļ��������������Լ���������ر��������к���Ч��
        write(TMI("cmdbar "+implode(cmdbar,";")+";"));
        return 1;
}
