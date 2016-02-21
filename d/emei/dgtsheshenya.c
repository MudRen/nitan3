//Room: dgtsheshenya.c �ù�̨������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
        set("short", "�ù�̨������");
        set("long", @LONG
�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�
�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����
�������࣬�������棬���������ã�������������Ͷ���ƺ��������������
�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���
̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������
�����г�������֮�⡣
LONG);
        set("outdoors", "emei");
        set("exits",([ /* sizeof() == 1 */
                "enter"    : __DIR__"woyunan",
                "east"     : __DIR__"duguangtai", 
        ]));
        
        set("coor/x", -570);
        set("coor/y", -340);
        set("coor/z", 220);
        
        setup();
}

void init()
{
        object me;

        if (interactive(me = this_player()))
        {
                remove_call_out("clone_ji");
                call_out("clone_ji", 2,me);
        }
        add_action("do_sheshen","sheshen");
}

void clone_ji(object me)
{
        object *ob, obj;
        int i;

        if (! objectp(me) || environment(me) != this_object())
                return;

        ob = all_inventory(environment(me));
        for (i = 0; i < sizeof(ob); i++)
        {
                if (ob[i]->query("id") == "ji xiaofu")
                return;
        }

        if (me->query("marks/ji"))
        {
                obj = new("/kungfu/class/emei/ji.c");
                obj->move(environment(me));
        }
}

int do_sheshen(object me)
{
        me = this_player();
        message_vision("$N���û���̫û��˼�ˣ�����������ʡ�\n", me);
        message_vision("$N��Ȼ���������£�������У������������쳹ɽ�ȣ�����$N�ĵ�����Ҳ��������������\n", me);
        if (me->query_skill("dodge", 1) >= 220)
        {
                me->move(__DIR__"st0");
                me->unconcious();
        } else
        {
                command("chat ����������������ɱ�ˡ�\n\n");
                me->move(__DIR__"st0");
                me->die();
        }
        return 1;
}

