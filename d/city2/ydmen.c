inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "������");
        set("long",
"\n"
"                         s________________s
                        /LLLLLLLLLLLLLLLLLL\\
    []__[]             ^^||======||======||^^             []__[]
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_��"HIW"������"NOR"��__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_/        \\__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]\n\n" 
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north"    : __DIR__"hgdadao1",
                "south"    : __DIR__"center",
                "east" : __DIR__"ssfmen",
        ]));

        set("objects", ([
                __DIR__"npc/jinyiwei" : 3,   
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
       object *env,room;
       int i;

       room=this_object();
       if( userp(me) &&  me->query("degree_jungong") < 8 && dir=="north" )
       {
        me->add_temp("voilet_hg",1); 
        if( me->query_temp("voilet_hg") < 3 )
        {
         if( me->query("degree_jungong") )
         return notify_fail(
         "������һ����ס��������˹ٵ�λ��������ܹ�������ʥ��\n");
         else
         return notify_fail(
         "������һ����ס������������ĵ��񣬻���������ȥ�������ݹֵ������飡\n");
        } else
        {
         if( me->query_temp("voilet_hg") == 3 )
         { 
          me->apply_condition("tongji",100+me->query_condition("tongji"));
          env=all_inventory(room);
          for(i=0;i<sizeof(env);i++)
          {
           if( env[i]->query("id") == "jinyi wei" )
           env[i]->kill_ob(me);
          }
          return notify_fail(HIR"�����һ�ᣬ���������ʹ���\n"NOR); 
         }
        }
      }
      return ::valid_leave(me,dir);
}

