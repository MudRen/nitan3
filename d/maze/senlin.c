inherit VRM_SERVER;

void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room( ROOM );

        //�Թ�������Ĺ��
        set_maze_npcs( ([
                "/clone/quarry/hu" :  1, 
                "/clone/quarry/lang" :  2, 
                "/clone/quarry/xiong" :  1, 
                "/clone/quarry/bao" :  1, 
                "/clone/quarry/zhu" :  1, 
                "/clone/quarry/zhu2" :  1, 
        ]) );
        
        // �Թ����ڵĹ��
        set_exit_npcs( ([
                "/d/maze/npc/hunter" : 1,
        ]) );
        // �Թ���ڵĹ��
        set_entry_npcs( "/d/maze/npc/hunter" );
        
        //�Թ��ĵ��߳�
        set_maze_long(10);

        //��ڷ���(�����ڶ���)
        set_entry_dir("east");

        //�������������ӷ���
        set_link_entry_dir("east");

        //�������������ӵ�����
        set_link_entry_room("/d/maze/zhaoze");

        //��������������ӷ���
        set_link_exit_dir("west");

        //��������������ӵ�����
        set_link_exit_room("/d/maze/zhaoze");

        //��ڷ��������
        set_entry_short("ɭ�����");

        //��ڷ�������
        set_entry_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ���� 
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹 
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽�� 
LONG);

        //���ڷ��������
        set_exit_short("ɭ�ֳ���");

        //���ڷ�������
        set_exit_desc(@LONG
����ǰһ������������˿��������������ǳ����ˡ�����С��
���������ͷ紵�����ֵ�ɳɳ����֯�������Ĵ���Ȼ�����ɡ�
LONG
);

        //�Թ�����Ķ�����
        set_maze_room_short("ԭʼɭ��");

        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
ԭʼɭ����Ҷ�Ժ���ǣ�������գ����������ſ�Ҷ���� 
����֬��ϵ�ζ�������ϵ�̦����Ҷ����ȥ������ģ����滹 
����Ұ�޵ĺۼ�������Ũ�ܵ�ɽ���������Էֱ淽�� 
LONG
);
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
        /*
        set_valid_rooms( ({
                "/d/maze/senlin1",
                "/d/maze/senlin1",
                "/d/maze/senlin2",
                "/d/maze/senlin3",
        }));
        */
        // create_maze();
}


string query_my_map(){  return read_file(__DIR__"senlin.map");}

