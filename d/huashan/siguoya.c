// siguoya.c
// Dec.11 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "˼����");
        set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ��������
�ܷ�֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ
����Ů�����ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮����
��Ҫ�Ǵ˴��޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ��
�����ţ��������͡�
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "northdown" : __DIR__"yunupath2",
                "enter"     : __DIR__"sgyhole1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        setup();
}
 
void init()
{
        object me = this_player();
        
        if (me->query_temp("xunshan")) 
                me->set_temp("xunshan/siguo", 1);
                
        add_action("do_say", "say");
        
        return;
}


void do_say(string arg)
{  
	//string name;
	object me = this_player();
	
	if (! arg || arg == "") return;
	
	if (arg == "������" && ! me->query_temp("marks/��") && random(30) == 5) 
	{
	        message_vision("ͻȻ$N������һ����̾�����ѵ������Ͼ�Ȼ������֪����ĳ�����֡���\n", me);
                message_vision("$N�ع�ͷ������ɽ����վ��һ�������������ߣ����������������ֽ��\n", me);
                me->set_temp("marks/��", 1);
	        if (me->query("shen") >= 10000) 
	        {      
	                message("vision","�������" + me->name() + "������˵�˼��仰��˵�ձ�ƮȻ��ɽ��\n", 
	                        environment(me), ({me})); 	
		        write( "�����������˵����������������ǰ����һ�������ؽ����۽�����\n");
		        write( "�ųơ���ħ�����߱���������һ���ֶ�����Ϊ��һ�ܶ����ã�һ��\n");
		        write( "�żš�������һ���������񽣡���ڣ�����غ���Ⱥ�����֣�������\n");
		        write( "�������౯�򣡾��š���ڣ�������ڵ���λ���������⸽�����Ĵ��\n");
		        write( "�⣬������֡����ڵ�������Ĵ���⣬�������֪��ϣ������Ѱ��\n");
		        write( "�������츣���֡�\n");
		        write( "������˵�գ���ƮȻ��ɽ��\n");
                }
                else 
                {	
          	        message_vision( "������˵�գ��ֶ�$Nһ����̾����ƮȻ��ɽ��ȥ��\n", me );
                }	
        }
	
	if (arg == "������" && me->query_temp("marks/��") ) 
	{
                write( "���ͻȻ���˳���˵���������Ǽ������������𣿻�����ȥ������������\n");
	}  
	
        return;
}		 
