#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
       if (! SECURITY_D->valid_grant(me, "(arch)"))
                return notify_fail("ARCH���ϵ���ʦ�ſ��Է���ϵͳ��ʾ��\n");
        if (!arg) return notify_fail("����Ҫ���ʲô?\n");
                                message_system(arg);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : syschat <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
HELP
    );
    return 1;
}
