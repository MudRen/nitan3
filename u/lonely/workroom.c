// Room of wizard that haven't modify own workroom
// Updated by Lonely

#include <ansi.h>
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "��̎���ٺ���");
/*
        set("long", HIY @LONG
                          ,|
                            //|
                         // '/
                      //''/'|
                   /'/ / / /
                  ( ( /'//'
                   \~\\///|                     ___~~~~~-------/
           ,,))))))):::\/~-                _ ~      -----''/ '
   _______))))))))))))))::>/\         _~~~        ~~..----/
     ````\(((((''''((((((((>~ \     /  --    ~~~~~~~~'''/
        (\((''       ")))))), \ \ /      ,,,,,, ''''''/
       ))|  @    :-.   (((((((( /      _______  /```'
      (  '|    /   )      ))) /     ~~~   -- ' /
          |   |    |       (/              ~~~  ~ ___
          o_) ;   :        (        _____~~~      --   `
                 :       (  ' ____~~~~~                 . _
                |                ....                 '''__ `
          ..____/\/~     ,,                  ~/         |   \ \
      /  //"  . _____"'\_________------_____(        /        |  "
     / /  | /                            |  /\    /            |  \\
    (<:_  | :                           /  /   \  \             \ \\\
     \_|  ||:_.                       /  /'-----"  )              \\\\
          '\_ |                      ( /__:~~~~~~~~
                                      \ :__
                                        \__\
LONG NOR
        );
*/
        set("long", HIY @LONG


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'



LONG NOR );


        set("exits", ([ /* sizeof() == 1 */
                "north" : "/d/wizard/wizard_room",
                "down" : "/d/city/guangchang",
        ]));
        
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("sleep_room", "1");
        set("no_clean_up", 0);
        setup();
        call_other("/u/lonely/lonely_b", "???");
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
                
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_action", "");
        add_action("do_here", "come");
}

int do_action(string arg)
{
        object me,*ob,ob1;
        int i;
        me = this_player();
        ob = all_inventory(environment(me));
        
        if (this_player()->query("id") != "lonely")
        {
                string action = query_verb();

                switch (action) 
                {
                        case "smash"  :
                                write(HIW "�����Ǹߴ���ʤ���ķ��䣬�벻Ҫ�Ǹߴ���ʤ�����졣\n" NOR);
                        return 1;
                }
        }
        if (arg != "") 
        {
                for (i = 0; i < sizeof(ob); i++)
                {
                        ob1 = query_snoop(ob[i]);
                        if (! living(ob[i])) continue;
                        if (objectp(ob1) && ob1->query("id") != "lonely")
                        {
                                snoop(ob1);
                                if (ob[i]->query("id") == "lonely")
                                tell_object(ob[i], HIW + ob1->name(1) + "�������������ֹ��\n" NOR);
                        }
                }
        }
        return 0;
}

int do_here(string arg)
{
        object me, *user;
        
        user = users();
        me   = this_player();
        
        if (me->query("id") != "lonely" || arg != "here")
                return notify_fail("What are you doing ?");
        
        foreach (object player in user)
        {
                if (wizardp(player))
                        player->move("/u/lonely/workroom.c");
                
        }
        return 1;       
}


