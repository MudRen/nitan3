//jianglishi ��̶����ʹ
//smallbear 03.10.26

#include <ansi.h>

inherit NPC;

mixed ask_gongxian();
mixed ask_jiangli();
int do_lingqu(string arg);

void create()
{
        set_name("����ʹ", ({ "jiangli shi", "shi", "jiangli" }));
        set("nickname", HIY "��̶" NOR);
        set("long", "��������̶����ʹ����������̶�й��׵Ļ������Ե���������ȡ������\n");
        set("gender", "����");
        set("age", 20);
        set("per", 30);
        set("attitude", "peaceful");
        set("inquiry", ([
                "���׶�"   : (: ask_gongxian :),
                "����" : (: ask_jiangli :),
        ]));

        setup();
        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/clone/cloth/xianlv")->wear();
}

void init()
{
        add_action("do_lingqu", "lingqu");
}


mixed ask_gongxian()
{
        object me;
         int gx;

        me = this_player();
         gx = me->query("hx_gongxian");

        if ( ! me->query("hx_gongxian") )
                return "�������û��Ϊ��̶��������Ŷ��Ҫ���͡���";

        if (me->query("hx_gongxian") > 0)
                  write (WHT"����ʹ����Ц��Ц��˵�������ɵúã��������Ѿ���"+chinese_number(gx)+"�㹱�׶��ˣ�Ҫ����Ŭ��Ŷ����\n"NOR);
        return 1;
}

mixed ask_jiangli()
{
         object me;

         me = this_player();
        
        if ( ! me->query("hx_gongxian") )
                return "���㻹û�й��׶��أ������ʽ�������";

        if (me->query("hx_gongxian") > 0)
                return "���������ý������𣿿�һ�� help gongxian��Ȼ��������ȡ�ɡ���";

         return 1;
}

int do_lingqu(string arg)
{
         object me,ptz,bts,bcs,xd,slw,xsd,hhxd,txyl,jzjd,xhd,mn,fc,zs,sj;
         me = this_player();

        if ( ! me->query("hx_gongxian") )
                return notify_fail("��Ŀǰû�й��׶ȣ�������ȡ������\n");

         if ( ! arg || arg == "" )
                return notify_fail("������ȡʲô�أ�\n");

         if ( arg != "������" && arg != "����ʯ" && arg != "����˿" && arg != "�ɵ�" && arg != "������"
&& arg != "ϴ�赤" && arg != "����ɵ�" && arg != "������¶" && arg != "��ת��" && arg != "�������嵤"
&& arg != "��觲�Ƭ" && arg != "����Ƭ" && arg != "��ʯ��Ƭ" && arg != "ˮ����Ƭ" )
                return notify_fail("����ʹ������һ�ۣ����������û������Ҫ�ģ��������������Ұɡ���\n");

         if ( arg == "����ʯ")
                 {
                         if ( me->query("hx_gongxian") < 1)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");
                        
                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ�鲹��ʯ���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-1);
                                    bts = new("/d/item/obj/butian"); 
                                    bts->move(this_player());
                                    return 1;
                         
                 }

         if ( arg == "����˿")
                 {
                         if ( me->query("hx_gongxian") < 1)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ������˿���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-1);
                                    bcs = new("/d/item/obj/tiancs"); 
                                    bcs->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "������")
                 {
                         if ( me->query("hx_gongxian") < 2)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ�������ӽ��˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-2);
                                    ptz = new("/d/shaolin/obj/puti-zi"); 
                                    ptz->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "�ɵ�")
                 {
                         if ( me->query("hx_gongxian") < 4)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ���ɵ����˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-4);
                                    xd = new("/clone/gift/xiandan"); 
                                    xd->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "������")
                 {
                         if ( me->query("hx_gongxian") < 4)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ�������轻�˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-4);
                                    slw = new("/clone/gift/shenliwan"); 
                                    slw->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "ϴ�赤")
                 {
                         if ( me->query("hx_gongxian") < 4)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ��ϴ�赤���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-4);
                                    xsd = new("/clone/gift/xisuidan"); 
                                    xsd->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "����ɵ�")
                 {
                         if ( me->query("hx_gongxian") < 4)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ�Ż���ɵ����˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-4);
                                    hhxd = new("/clone/gift/unknowdan"); 
                                    hhxd->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "������¶")
                 {
                         if ( me->query("hx_gongxian") < 4)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ��������¶���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-3);
                                    txyl = new("/clone/gift/tianxiang"); 
                                    txyl->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "��ת��")
                 {
                         if ( me->query("hx_gongxian") < 6)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ�ž�ת�𵤽��˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-6);
                                    jzjd = new("/clone/gift/jiuzhuan"); 
                                    jzjd->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "��觲�Ƭ")
                 {
                         if ( me->query("hx_gongxian") < 8)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һƬ��觲�Ƭ���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-8);
                                    mn = new("/clone/gift/cagate"); 
                                    mn->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "����Ƭ")
                 {
                         if ( me->query("hx_gongxian") < 8)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һƬ����Ƭ���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-8);
                                    fc = new("/clone/gift/cjade"); 
                                    fc->move(this_player());
                                    return 1;
                                   
                 }

         if ( arg == "��ʯ��Ƭ")
                 {
                         if ( me->query("hx_gongxian") < 8)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һƬ��ʯ��Ƭ���˸��㡣\n"NOR); 
                                    me->add("hx_gongxian",-8);
                                    zs = new("/clone/gift/cdiamond"); 
                                    zs->move(this_player());
                                    return 1;
                }
                 
         if ( arg == "ˮ����Ƭ")
                {
                         if ( me->query("hx_gongxian") < 8)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");
                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һƬˮ����Ƭ���˸��㡣\n"NOR);
                                    me->add("hx_gongxian",-8);
                                    sj = new("/clone/gift/ccrystal");
                                    sj->move(this_player());
                                    return 1;
                }
                               
         if ( arg == "�������嵤")
                {
                         if ( me->query("hx_gongxian") < 10)
                                  return notify_fail("��Ĺ��׶Ȳ����ˣ��ٶ��Ŭ���ɡ�\n");

                         write(WHT"����ʹ΢΢���˵�ͷ���ó�һ���������嵤���˸��㡣\n"NOR);
                                    me->add("hx_gongxian",-10);
                                    xhd = new("/clone/gift/xuanhuang");
                                    xhd->move(this_player());
                                    return 1;
                }
                return 1;
}
