// c_doc.c ���������ļ�

void doc_edit( string str );
int main( object me )
{
        if( !me->query("bunch" ) || me->query("bunch/level") < 7 )
                return 0;
                
        me->edit( (: doc_edit :) );
        return 1;
}

void doc_edit( string str )
{
        write_file( "/help/" + this_player()->query("bunch/bunch_name"), str, 1 );
        return;
}


int help( object me )
{
        write( "
        c_doc: ������д�����ļ���
        �����ļ����д���, ������ʷ, �����ϡ�
        ��� help <������������> �����Ķ������ļ���

");
        return 1;
}

