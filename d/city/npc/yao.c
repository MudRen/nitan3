// yao.c Ҧ����
// By Dumbness, 2003-5-24 19:26

inherit BUNCHER;
inherit F_DEALER;

void create()
{
        set_name("Ҧ����", ({ "yao yueling","yueling","yao" }));
        set("title", "��֬���ϰ�");
        set("shen_type", 1);
        set("gender", "Ů��");
        set("age", 25);
        set("per", 27);
        set("long", @LONG
һ������֬��Ů�ӣ��������԰ס������������������ڶ��ɫ�Ĵ�����˿˿��
�Ƶ�������ȥ������������ģ�������ܱ���Ǿ��µ���ٺ���������������
��������͸�ŷ糾�����ŵĻ����ζ�����ӵ�����һ���������˵ĸ�ɫ��֬����
������Ƿǣ��ֲ��ҽӽ��� 
LONG );
        set("attitude", "friendly");
        set("vendor_goods", ([ 
                "/d/city/npc/obj/yanzhi"       : 1000,
                "/d/city/npc/obj/baohuayou"    : 1000,
                "/d/city/npc/obj/huafendai"    : 1000,
                "/clone/gift/xiaobao"     : 200000, 
                "/clone/gift/dabao"       : 500000, 
                "/clone/gift/huirongwan"       : 500000,
        ]));
        
        setup();
        carry_object("/clone/cloth/female1-cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

