// Cmds:/cmds/usr/chip.c
 
inherit F_CLEAN_UP;

#ifndef GAMBLE_D
#define GAMBLE_D          "/adm/daemons/gambled"
#endif

int main(object me, string arg)
{
        GAMBLE_D->do_chip(me);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : gmanage 

����ָ�����ڲ���Ͷע��

HELP );
    return 1;
}
