int a(string arg)
{
object ob;
object me = this_player();
int n;
      if ( ! n = 0 )
    tell_object(me, sprintf("�鿴�����ȷ\n"));
if (! ob = find_player(arg) )
     tell_object(me, sprintf("û���ҵ�" + arg + "\n"));
if (! (ob = find_player(arg)) )
     tell_object(me, sprintf("����û���ҵ�" + arg + "\n"));
return 1;
}
