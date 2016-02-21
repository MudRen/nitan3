
/*
 * ����� ���о���(City Maker) V1.0
 * ���ߣ� ���� (Glacier@��ѩ�򣮺ڳ���)
 * ���ڣ� 2001/01/11
 * ��ע�� ES_Base_Code
 * �޸ģ� ����ģ���޸ĳ��򵼷�ʽ�������ͼ�������жϡ�
 *        �κ�ʱ������� "."�������Է����༭��
 *                            Glacier -- 2001.2.20
 *
 * �޸ģ� �����Լ��趨�ļ������ܡ��ļ���������ʽΪ��������_������.c
 *        ���г�����Ϊ��ͼ�ļ������ƣ��������ڵ�ͼ�ļ���һ���趨��
 *                            Lonely -- 2001.3.12 
 */
#pragma save_binary
inherit ITEM;
inherit F_AUTOLOAD;

#include <mudlib.h>
//#define _check_map
#define _show_map

mixed maps, icons, icons1;
mapping room_short = ([]),room_filename = ([]);
string city,current_path;
string *outdoors_room;
string outdoors;
int _Mrow, _Mcol, _size;
int set_path(string arg);
int set_outdoors_room(string arg);
int save_file(string yn, string file_name, string file);
int confirm_make(string yn);
void create()
{
        set_name("���о��� V1.1", ({ "citymaker", "maker" }) );
        set_weight(2000);
        set("unit", "��" );
        set("long", @LONG
    �����һ��������ʦ�����Ĺ��ߣ����Կ��ٽ�������������ṹ��
��ʹ�� help citymaker �����ϸ������
LONG
        );
        setup();
}

void init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_makecity", "make");
                add_action("do_help", "help");
        }
}

int process_map(string file)
{
        string input,*line;
        int i,j,v;
        int _Trow, _Tcol;
        if(file_size(file)>0)
        {
            input=read_file(file);
//���� line
            line=explode(input,"\n");
            icons1=explode(line[0]," ");
            for(i=0;i<sizeof(icons1);i++)
            {
                j=i+1;
                if (strsrch(icons1[i],"\t")!=-1 || strsrch(icons1[i],".")==-1)
                {
                write("[ Citymaker ]�������ʶλ���������ͼ��һ�б�ʶλ[ "+ j +" == "+icons1[i]+" ]����\n");
                write("[ Citymaker ]�������Ʊ������<�����ʶ.��������>֮�䲻���ָ��\".\"��\n");
                return 0;
                }            
            }
            icons=allocate(sizeof(icons1));
            for(i=0;i<sizeof(icons1);i++)
            {
                //icons[i]=allocate(2);
                icons[i]=allocate(3);
                icons[i]=explode(icons1[i],".");
            }
            for(i=0;i<sizeof(icons1);i++)
            {
                room_short[icons[i][0]] = icons[i][1];
                room_filename[icons[i][0]] = icons[i][2];
            }
//���� mapping room_short
            _Trow=sizeof(line);
            _Mrow=_Trow-1;
            _size=_Trow;
            for(i=1;i<(sizeof(line));i++)
            {
                _Tcol=sizeof(line[i]);
                if (_Mcol<_Tcol) {_Mcol=_Tcol;}
            }
            if (_size<_Mcol) {_size=_Mcol;}
//����ɾ���
            for(i=1;i<(sizeof(line));i++)
            {
                j=i+1;
                if (strsrch(line[i],"\t")!=-1)
                {
                write("[ Citymaker ]�������ʶλ���������ͼ��["+j+"]��[ "+line[i]+" ]����\n");
                write("[ Citymaker ]�������Ʊ����\n");
                return 0;
                }               
                for (_Tcol=sizeof(line[i]);_Tcol<_Mcol;_Tcol++)
                 {
                        line[i]+= " " ;
                 }
            }
                maps = allocate(_size);
//���� maps
                for(v=1;v<(sizeof(line));v++)
            {
            maps[v-1]=allocate(_size);
            maps[v-1]=explode(line[v],"");
            }
            return 1;
        } else return 0;
}



int makeroom(int _row, int _col)
{
        int i;
        string file_name,file,*exit_key,room;
        mapping exit=([]);
        room=maps[_row][_col];
                write("[ Citymaker ]��room("+_row+","+_col+") == "+room+" ");
  if (_row>1)                       {if (maps[_row-1][_col] == "|"   && maps[_row-2][_col]!=" ")     {exit["north"]=room_filename[maps[_row-2][_col]];}}
  if (_row>1 && _col<_Mcol-1)       {if (maps[_row-1][_col+1] == "/" && maps[_row-2][_col+2]!=" ")   {exit["northeast"]=room_filename[maps[_row-2][_col+2]];}}
  if (_col<_Mcol-1)                 {if (maps[_row][_col+1] == "-"   && maps[_row][_col+2]!=" ")     {exit["east"]=room_filename[maps[_row][_col+2]];}}
  if (_row<_Mrow-1 && _col<_Mcol-1) {if (maps[_row+1][_col+1] == "\\"&& maps[_row+2][_col+2]!=" ")   {exit["southeast"]=room_filename[maps[_row+2][_col+2]];}}
  if (_row<_Mrow-1)                 {if (maps[_row+1][_col] == "|"   && maps[_row+2][_col]!=" ")     {exit["south"]=room_filename[maps[_row+2][_col]];}}
  if (_row<_Mrow-1 && _col>1)       {if (maps[_row+1][_col-1] == "/" && maps[_row+2][_col-2]!=" ")   {exit["southwest"]=room_filename[maps[_row+2][_col-2]];}}
  if (_col>1)                       {if (maps[_row][_col-1] == "-"   && maps[_row][_col-2]!=" ")      {exit["west"]=room_filename[maps[_row][_col-2]];}}
  if (_row>1 && _col>1)             {if (maps[_row-1][_col-1] == "\\"&& maps[_row-2][_col-2]!=" ")   {exit["northwest"]=room_filename[maps[_row-2][_col-2]];}}
  //file_name=current_path++"_"+room_filename[maps[_row][_col]]+".c";
  file_name=current_path+room_filename[maps[_row][_col]]+".c";
  file=sprintf("/*\n * �ļ�    : %s (%s)\n",room_short[maps[_row][_col]],room_filename[maps[_row][_col]]);
        file+=sprintf(" * ����    : %s(%s@%s)\n * ����    : %s\n",this_player()->query("name"),this_player()->query("id"),MUD_NAME,ctime(time()));
        file+=@FILE_HEAD
 * ����    : Build with Citymaker@Glacier
 * �޸�    : Changed By Lonely@��̶
 */
#include <ansi.h>
inherit ROOM;
void create()
{
FILE_HEAD
;
        file+=sprintf("\tset(\"short\", \"%s\");\n",room_short[maps[_row][_col]]);
file+=@FILE_LONG
        set("long", @LONG
ҹ.��.��.��.��.˭.�ң�

LONG
);
        set("objects",([
        ]));
        set("exits",([
FILE_LONG;
;
        exit_key=keys(exit);
        for(i=0;i<sizeof(exit_key);i++) {
                file=sprintf("%s\t\"%s\" : __DIR__\"%s\",\n",file,exit_key[i],exit[exit_key[i]]);
        }
        file+=@FILE_2
        ]));
FILE_2
;
  if (member_array(lower_case(maps[_row][_col]),outdoors_room)==-1 )
{
        file+=@FILE_3
        setup();
//      replace_program(ROOM);
}
FILE_3
;
}
else {
        file+=sprintf("\tset(\"outdoors\",\"%s\");\n",city);
        file+=@FILE_3
        setup();
//      replace_program(ROOM);
}
FILE_3
;
}

return save_file("y", file_name, file);
}

int do_makecity(string arg)
{
        int _row,_col;
        string file,room;
        if (!arg) return notify_fail ("[ Citymaker ]��makecity <��ͼ������>\n");
        if (strsrch(arg,".")!=-1 || strsrch(arg," ")!=-1) 
        {
        write("[ Citymaker ]�������ͼ��������ͼ���в��������\".\"����\" \"��\n ");
        write("              ��ֱ��ʹ�����뽨���ĳ�����Ϊ��ͼ������\n");
        return 1;
        }
        else
        {
        
                //city=;
                file=resolve_path(this_player()->query("cwd"), arg);
                if(process_map(file))
                {
                        write("[ Citymaker ]�����������ͼ��[ "+file+" ]...\n");
#ifdef _check_map
                        for(_row=0;_row<sizeof(maps);_row++)
                        {
                                for(_col=0;_col<sizeof(maps[_row]);_col++)
                                {
                                room=maps[_row][_col];
                                write("room("+_row+","+_col+") == "+room + "\n");
                                }
                        }
#endif
#ifdef _show_map
                        for(_row=0;_row<sizeof(maps);_row++)
                        {
                                for(_col=0;_col<sizeof(maps[_row]);_col++)
                                {
                                room=maps[_row][_col];
                                write(""+room + "");
                                }
                         write("\n");
                        }
                        write("[ Citymaker ]��_Mrow = "+_Mrow+" _Mcol = "+_Mcol+"\n");
#endif
                        write("[ Citymaker ]����ͼ��[ "+file+" ]�������!!\n");
                }
                else
                {
                        return notify_fail("[ Citymaker ]����ͼ��[ "+file+" ]����ʧ�ܡ�\n");
                }
        }       
          write("[ Citymaker ]�����趨�洢����Ŀ¼(Ĭ��Ϊ��ǰĿ¼)��");
          input_to ( "set_path" );

        return 1;
}

int save_file(string yn, string file_name, string file)
{
        if( strlen(yn)<1 || yn[0]!='y' ) return 1;
        
      if(file_name[0..2]!="/u/") return 0;
//ֻ������/u/Ŀ¼���潨���ļ�
        rm(file_name);
        write(" ���� " + file_name + "....");
        
        if( write_file(file_name, file,1)==1 ) {
                write("OK!\n");
                return 1;
        } else
                write("��û��д���������(" + file_name + ")��Ȩ����\n");
                return 0;
}

int set_path(string arg)
{
        string dir;
        if (arg == ".") { write ("[ Citymaker ]���������β�����\n"); return 1; }
        if (strsrch(arg," ")!=-1) 
        {
        write("[ Citymaker ]�������·�������趨�洢����Ŀ¼(Ĭ��Ϊ��ǰĿ¼)��");
        input_to ( "set_path" );        
        return 1;
        }
        if(!arg)
        {
                if(dir = this_player()->query("cwd"))
                {
                        current_path=dir;
                        write("[ Citymaker ]���Զ��趨�洢����Ŀ¼Ϊ��ǰĿ¼[ "+current_path+" ]��\n");
                        write("[ Citymaker ]�����趨���ⷿ������(���磺c,g ���ͼΪ c��g �ķ��佫���趨Ϊ����)��");
                        input_to("set_outdoors_room");
                        return 1;
                } else return notify_fail("[ Citymaker ]���޷��Զ��趨Ŀ¼������������\n");
        }
        else
        {
                dir = resolve_path(this_player()->query("cwd"), arg);
                if(file_size(dir)!=-2) { write("[ Citymaker ]��û�����Ŀ¼������������\n"); return 1; }                 
                if(dir[strlen(dir)-1]!='/') dir += "/";
                current_path=dir;
                write("[ Citymaker ]���趨�洢����Ŀ¼Ϊ[ "+current_path+" ]��\n");
                write("[ Citymaker ]�����趨���ⷿ������(���磺c,g ���ͼΪ c��g �ķ��佫���趨Ϊ����)��");
                input_to("set_outdoors_room");                
        }
                return 1;        
}
int set_outdoors_room(string arg)
{
        int  i;
        string *tmp,test,argt;
        argt=lower_case(arg);
        if (arg == ".") { write ("[ Citymaker ]���������β�����\n"); return 1; }     
        if (strsrch(argt," ")!=-1 )
        {
        write("[ Citymaker ]�����ⷿ�������趨���󣬲��������\" \"��\n");
        write("[ Citymaker ]�����趨���ⷿ������(���磺c,g ���ͼΪ c��g �ķ��佫���趨Ϊ����)��");      
        input_to ( "set_outdoors_room" );       
        return 1;
        }
        tmp=(explode(lower_case(arg),","));
        for (i=0;i<sizeof(tmp);i++)
        {
        test=tmp[i];
        if (strlen(test)>1) {
                write("[ Citymaker ]�����ⷿ���趨���󣬷����ʶ����ӦΪ�����ַ���\n");
                write("[ Citymaker ]�����趨���ⷿ������(���磺c,g ���ͼΪ c��g �ķ��佫���趨Ϊ����)��");
                input_to ( "set_outdoors_room" );       
                return 1;               
                }
        }
        if(!arg) 
        {
        write ("[ Citymaker ]���趨���з���Ϊ����...OK��\n");
        }
        outdoors_room=(explode(lower_case(arg),","));
        for (i=0;i<sizeof(outdoors_room);i++)
        {
        outdoors=outdoors_room[i];
        write("[ Citymaker ]���趨����[ "+outdoors+" ]Ϊ����...OK��\n");
        }
        write("[ Citymaker ]���趨��ɣ�Citymaker �������ɳ��е�������ȷ��(y/n)��");
        input_to("confirm_make");   
        return 1;
}
int confirm_make(string arg)
{
        int  _row,_col;
        int count=0;
        if( arg=="" ) 
        {
        write("[ Citymaker ]����Ҫȷ�ϣ���ȷ����(y/n)��");
        input_to("confirm_make");
        return 1;
        }       
        if( arg[0]!='y' && arg[0]!='Y' ) {write ("[ Citymaker ]���������β�����\n"); return 1;}
        write("[ Citymaker ]�����ڽ������� ... ...\n");    
        for(_row=0;_row<sizeof(maps);_row++)
        {
        for(_col=0;_col<sizeof(maps[_row]);_col++)
        {
                if (maps[_row][_col]!=" "
                 && maps[_row][_col]!="|"
                 && maps[_row][_col]!="/"
                 && maps[_row][_col]!="\\"
                 && maps[_row][_col]!="-" )
                {
                        makeroom(_row,_col);
                        count++;
                }
                }
        }
        write("[ Citymaker ]���������棬����[ " + count +" ]�����䣡\n");   
        return 1;
}

int do_help(string arg)
{
        if(arg=="citymaker" ||arg== "maker")
        {
                write(@HELP_LONG
���о��� V1.1 ( 2001.2)            - By Glacier@��ѩ�򣮺ڳ���
                                     Email:wizard@game.com.cn
                                     
�����һ��Ϊ������ʦ�����ĳ��й��ߣ����Կ��ٽ�������������ṹ��

1.�༭��ͼ��, �������£�
-----------------------------------------------------------------
a.�ͷ�.kefang b.�᷿.xiangfang c.����.zoulang d.����.dating
e.����.chufang f.��԰.huayuan g.����.damen h.����.neishi
(ע�⣺������Ӧ�ϲ�Ϊһ�У����ڹ���Ϊ�˱�����ʾ�������������Ϊ����)
  g   b
  |  / \
b-c-b   b
  |  \ /
a-d-a b
  |
h-f-e
------------------------------------------------------------------
��ͼ˵����   ����ͼ�����ӱ߿�(---)��Ϊ���͵�ͼ���ã�ʵ�ʵ�ͼ��û�С�
             ��ͼ��һ��Ϊͼ��������<�����ʶ.��������.�����ļ���>��
             ��ʽ����a����ͷ�����ͼ������a��������ɿͷ��� �����
             ʶ���������ƺͷ����ļ���֮���ã�.���ָ
             �ã�-��\��/��|������ʾ���õĵİ���ͨ·(�����ǵ���)����
             west��east��northwest��southeast��northeast��southwest
             north��south��
ע�����   ���з����Ӧ�ڵ�һ����ͼ��˵���������޷��������ɷ��䡣
             ��ͼ�������ַ���Ϊ����ַ���ֻ������ֿո� ����������
             �����Ʊ�� \t ��Ϊ����������ϸ��챾��ͼ��������
2. ָ���ʽ��make <��ͼ��>  ( ��ðѳ�������Ϊ��ͼ�����ƣ� ������Ϊ
             Citymaker ������outdoors�����ʱ��ʹ�õ�ͼ������Ϊ����
             ���������С�)
3. Citymaker ��Ҫ�趨��ŵ�����·���� <Ŀ¼��> (Ĭ��Ϊ��ǰ����Ŀ¼)��
4. Citymaker ��Ҫ�趨����ķ��䣺<���ⷿ���ʶ,���ⷿ���ʶ,...
             ���趨�ķ��佫���趨Ϊ����(Ĭ��Ϊ����)��       
5. ��������趨����ȷ�Ϻ� Citymaker ���������ɳ��е�����(ȷ�Ϻ󱾳
             ��ֱ�Ӹ�д�����ļ���������ע�����������õĴ洢Ŀ¼��
6. ������ӭ�޸ģ����뱣��ԭ��������       

HELP_LONG);
                return 1;
        }
        return 0;
}

string query_autoload() { return "";}

void autoload(string param)
{return ;}

