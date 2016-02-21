// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (! arg)
		return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");

	if (arg == "none")
	{
		me->delete("nickname");
		write("��Ĵº�ȡ���ˡ�\n");
		return 1;
	}

	if (strlen(arg) > 80)
		return notify_fail("��Ĵº�ռ�õ���Դ���࣬���������á�\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "\"", "");

	if (strlen(filter_color(arg)) > 30)
		return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

	me->set("nickname", arg + NOR);
	write("��ȡ���˴ºš�\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���, �º�> | none
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ
�Σ������ϣ���ڴº���ʹ�� ANSI �Ŀ�����Ԫ
�ı���ɫ�����������µĿ����ִ���

 $BLK$ - �ڡ�ɫ            $NOR$ - ����ɫ
 $RED$ - [31m�졡ɫ[2;37;0m            $HIR$ - [1;31m����ɫ[2;37;0m
 $GRN$ - �̡�ɫ            $HIG$ - [1;32m����ɫ[2;37;0m
 $YEL$ - [33m����ɫ[2;37;0m            $HIY$ - [1;33m�ơ�ɫ[2;37;0m
 $BLU$ - [34m����ɫ[2;37;0m            $HIB$ - [1;34m����ɫ[2;37;0m
 $MAG$ - [35mǳ��ɫ[2;37;0m            $HIM$ - [1;35m�ۺ�ɫ[2;37;0m
 $CYN$ - [36m����ɫ[2;37;0m            $HIC$ - [1;36m����ɫ[2;37;0m
 $WHT$ - [37mǳ��ɫ[2;37;0m            $HIW$ - [1;37m�ס�ɫ[2;37;0m
 
��ֹ�� nick ��ʹ�� $BLINK$ - [5m[1;37m��[2;37;0m[5m[1;36m��[2;37;0m[5m[35m��[2;37;0m[5m[1;33m˸[2;37;0m
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP );
        return 1;
}
