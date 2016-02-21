// checkshop.c
// Smallfish@Huaxia

inherit F_CLEAN_UP;
#include <ansi.h>;

int main(object me,string arg)
{
        string msg;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        msg = SHOP_D->check_shop_status();

        tell_object(me,msg);

        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : checkshop

��ѯ���кڵ걾�쾭Ӫ״����
���ָ�openshop��closeshop��cshshop��setowner
HELP );
        return 1;
}
