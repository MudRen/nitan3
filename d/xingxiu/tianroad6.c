inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���塣����������Χ��ȥ�����׶���ԭ�ķ��
�����۵ס�����һ��С·������ɽ��ɽ����������Ϊǿ������
���޷�վ����
LONG);
        set("exits", ([
            	"eastdown" : __DIR__"tianroad5",
        ]));
        set("outdoors", "xingxiu");
        set("resource/quarry", ([
            "/clone/quarry/can" :  50,//��
            "/clone/quarry/tiancan" :  10,//���
            "/clone/quarry/he" :  50,//������
            "/clone/quarry/he2" :  10,//ѩ�ף�û�ҵ��ɺ�
            "/clone/quarry/hou" :  50,//����
            "/clone/quarry/niao" :  50,//���
            "/clone/quarry/ying" :  50,//ͺӥ
        ]));
        setup();
}
