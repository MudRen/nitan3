// riyue.h

int permit_recruit(object ob)
{
    object me;

    me = this_object();

    if (ob->query("name") == "��������" ||
        ob->query("name") == "������")
    {
        message_vision("$N��Ȼ��ŭ���ߣ���Ҳ�ҳ��ҵĻ�ţ�\n",me);
        return 0;
    }

    if (ob->query("detach/�������") ||
        ob->query("betrayer/times"))
    {
        message_vision("$N��ŭ���������������������Ҫ��������Ҫ�߱��ߣ�\n",me);
        return 0;
    }

    return 1;
}

