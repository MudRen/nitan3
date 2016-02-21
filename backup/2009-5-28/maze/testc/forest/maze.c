#include <ansi.h>
inherit VRM_SERVER; 
 
#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0

string *unique_rooms = ({
        "/d/maze/forest/unique_room/snakehole",
        "/d/maze/forest/unique_room/bearlair",
        "/d/maze/forest/unique_room/wolfcave",
        "/d/maze/forest/unique_room/tigerhill",
        "/d/maze/forest/unique_room/dragonland",
});

void create() 
{ 
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); 
                        
        //Ψһ����
        set_unique_room( unique_rooms ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/d/maze/forest/npc/toad": 1 + random(2),
                "/d/maze/forest/npc/rabbit": 1 + random(2),  
                "/d/maze/forest/npc/wolf_baby": 1 + random(2), 
                "/d/maze/forest/npc/wolf_big": 1 + random(5), 
                "/d/maze/forest/npc/wolf_king": 1 + random(2), 
                "/d/maze/forest/npc/tiger_baby": 1 + random(2), 
                "/d/maze/forest/npc/tiger_big": 1 + random(5), 
                "/d/maze/forest/npc/tiger_king": !random(10), 
                "/d/maze/forest/npc/bear_baby": 1 + random(2), 
                "/d/maze/forest/npc/bear_big": 1 + random(5), 
                "/d/maze/forest/npc/bear_king": 1 + random(2), 
                "/d/maze/forest/npc/snake_baby": 1 + random(2), 
                "/d/maze/forest/npc/snake_big": 1 + random(5), 
                "/d/maze/forest/npc/snake_king": 1 + random(2), 
                "/d/maze/forest/npc/dragon_baby": 1 + random(2), 
        ]) );                   
        
        //��������
        //set_true_death_room(1);

        //�Թ��ĵ��߳� 
        set_maze_long(8); 
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("east"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("east"); 
                        
        //�������������ӵ����� 
        set_link_entry_room(__DIR__"enter"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("west"); 
                        
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"out"); 
                        
        //�������������
        set_link_entry_room_x(ENTER_ROOM_X);
        set_link_entry_room_y(ENTER_ROOM_Y);
        set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short(HIG"ԭʼɭ��"NOR);
                        
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG); 

        //��ڷ�������� 
        set_entry_short(HIR"ԭʼɭ�����"NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);
                        
        //���ڷ�������� 
        set_exit_short(HIY"ԭʼɭ�ֳ���"NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ����
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽��
LONG);

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        set_outdoors(1);                                                

        // �Թ������Ƿ�ˢ����ˢ��ʱ������
        set_maze_refresh(180);
} 

string query_my_map(){  return read_file(__DIR__"maze.map");}

