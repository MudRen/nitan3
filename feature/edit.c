// edit.c

int edit(function callback, string text)
{
        if (! text) text = "";

        write("�����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��\n");
        write("����������������������������������������������������������\n");
        write(text);

        input_to("input_line", text, callback);
        return 1;
}

void input_line(string line, string text, function callback)
{
        if (line && this_player(1)->query_temp("big5"))
#ifdef LONELY_IMPROVED
                // line = big5togb(line);
                line = LANGUAGE_D->toGB(line); 
#else
                line = LANGUAGE_D->toGB(line);
#endif
        if (line == ".") 
        {
                (*callback)(text);
                return;
        } else 
        if (line == "~q") 
        {
                write("����ȡ����\n");
                return;
        } else 
        if (line == "~e") 
        {
        } else
                text += line + "\n";
        input_to("input_line", text, callback);
}


