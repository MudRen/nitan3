// combine.c
// Updated by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mapping combine_list = ([
        // ��ʯ�ĺϳ�: 3����ͬ�ı�ʯ�ϳ�Ϊ��һ����ͬ�౦ʯ
        ({ "/data/enchase/BLKjewel1-1",
           "/data/enchase/BLKjewel1-2",
           "/data/enchase/BLKjewel1-3", }) : "/clone/enchase/BLKjewel2",

        ({ "/data/enchase/BLKjewel2-1",
           "/data/enchase/BLKjewel2-2",
           "/data/enchase/BLKjewel2-3", }) : "/clone/enchase/BLKjewel3",

        ({ "/data/enchase/BLKjewel3-1",
           "/data/enchase/BLKjewel3-2",
           "/data/enchase/BLKjewel3-3", }) : "/clone/enchase/BLKjewel4",

        ({ "/data/enchase/BLKjewel4-1",
           "/data/enchase/BLKjewel4-2",
           "/data/enchase/BLKjewel4-3", }) : "/clone/enchase/BLKjewel5",

        ({ "/data/enchase/BLKjewel5-1",
           "/data/enchase/BLKjewel5-2",
           "/data/enchase/BLKjewel5-3", }) : "/clone/enchase/BLKjewel6",

        ({ "/data/enchase/BLKjewel6-1",
           "/data/enchase/BLKjewel6-2",
           "/data/enchase/BLKjewel6-3", }) : "/clone/enchase/BLKjewel7",

        ({ "/data/enchase/BLUjewel1-1",
           "/data/enchase/BLUjewel1-2",
           "/data/enchase/BLUjewel1-3", }) : "/clone/enchase/BLUjewel2",

        ({ "/data/enchase/BLUjewel2-1",
           "/data/enchase/BLUjewel2-2",
           "/data/enchase/BLUjewel2-3", }) : "/clone/enchase/BLUjewel3",

        ({ "/data/enchase/BLUjewel3-1",
           "/data/enchase/BLUjewel3-2",
           "/data/enchase/BLUjewel3-3", }) : "/clone/enchase/BLUjewel4",

        ({ "/data/enchase/BLUjewel4-1",
           "/data/enchase/BLUjewel4-2",
           "/data/enchase/BLUjewel4-3", }) : "/clone/enchase/BLUjewel5",

        ({ "/data/enchase/BLUjewel5-1",
           "/data/enchase/BLUjewel5-2",
           "/data/enchase/BLUjewel5-3", }) : "/clone/enchase/BLUjewel6",

        ({ "/data/enchase/BLUjewel6-1",
           "/data/enchase/BLUjewel6-2",
           "/data/enchase/BLUjewel6-3", }) : "/clone/enchase/BLUjewel7",

        ({ "/data/enchase/CYNjewel1-1",
           "/data/enchase/CYNjewel1-2",
           "/data/enchase/CYNjewel1-3", }) : "/clone/enchase/CYNjewel2",

        ({ "/data/enchase/CYNjewel2-1",
           "/data/enchase/CYNjewel2-2",
           "/data/enchase/CYNjewel2-3", }) : "/clone/enchase/CYNjewel3",

        ({ "/data/enchase/CYNjewel3-1",
           "/data/enchase/CYNjewel3-2",
           "/data/enchase/CYNjewel3-3", }) : "/clone/enchase/CYNjewel4",

        ({ "/data/enchase/CYNjewel4-1",
           "/data/enchase/CYNjewel4-2",
           "/data/enchase/CYNjewel4-3", }) : "/clone/enchase/CYNjewel5",

        ({ "/data/enchase/CYNjewel5-1",
           "/data/enchase/CYNjewel5-2",
           "/data/enchase/CYNjewel5-3", }) : "/clone/enchase/CYNjewel6",

        ({ "/data/enchase/CYNjewel6-1",
           "/data/enchase/CYNjewel6-2",
           "/data/enchase/CYNjewel6-3", }) : "/clone/enchase/CYNjewel7",

        ({ "/data/enchase/GRNjewel1-1",
           "/data/enchase/GRNjewel1-2",
           "/data/enchase/GRNjewel1-3", }) : "/clone/enchase/GRNjewel2",

        ({ "/data/enchase/GRNjewel2-1",
           "/data/enchase/GRNjewel2-2",
           "/data/enchase/GRNjewel2-3", }) : "/clone/enchase/GRNjewel3",

        ({ "/data/enchase/GRNjewel3-1",
           "/data/enchase/GRNjewel3-2",
           "/data/enchase/GRNjewel3-3", }) : "/clone/enchase/GRNjewel4",

        ({ "/data/enchase/GRNjewel4-1",
           "/data/enchase/GRNjewel4-2",
           "/data/enchase/GRNjewel4-3", }) : "/clone/enchase/GRNjewel5",

        ({ "/data/enchase/GRNjewel5-1",
           "/data/enchase/GRNjewel5-2",
           "/data/enchase/GRNjewel5-3", }) : "/clone/enchase/GRNjewel6",

        ({ "/data/enchase/GRNjewel6-1",
           "/data/enchase/GRNjewel6-2",
           "/data/enchase/GRNjewel6-3", }) : "/clone/enchase/GRNjewel7",

        ({ "/data/enchase/MAGjewel1-1",
           "/data/enchase/MAGjewel1-2",
           "/data/enchase/MAGjewel1-3", }) : "/clone/enchase/MAGjewel2",

        ({ "/data/enchase/MAGjewel2-1",
           "/data/enchase/MAGjewel2-2",
           "/data/enchase/MAGjewel2-3", }) : "/clone/enchase/MAGjewel3",

        ({ "/data/enchase/MAGjewel3-1",
           "/data/enchase/MAGjewel3-2",
           "/data/enchase/MAGjewel3-3", }) : "/clone/enchase/MAGjewel4",

        ({ "/data/enchase/MAGjewel4-1",
           "/data/enchase/MAGjewel4-2",
           "/data/enchase/MAGjewel4-3", }) : "/clone/enchase/MAGjewel5",

        ({ "/data/enchase/MAGjewel5-1",
           "/data/enchase/MAGjewel5-2",
           "/data/enchase/MAGjewel5-3", }) : "/clone/enchase/MAGjewel6",

        ({ "/data/enchase/MAGjewel6-1",
           "/data/enchase/MAGjewel6-2",
           "/data/enchase/MAGjewel6-3", }) : "/clone/enchase/MAGjewel7",

        ({ "/data/enchase/REDjewel1-1",
           "/data/enchase/REDjewel1-2",
           "/data/enchase/REDjewel1-3", }) : "/clone/enchase/REDjewel2",

        ({ "/data/enchase/REDjewel2-1",
           "/data/enchase/REDjewel2-2",
           "/data/enchase/REDjewel2-3", }) : "/clone/enchase/REDjewel3",

        ({ "/data/enchase/REDjewel3-1",
           "/data/enchase/REDjewel3-2",
           "/data/enchase/REDjewel3-3", }) : "/clone/enchase/REDjewel4",

        ({ "/data/enchase/REDjewel4-1",
           "/data/enchase/REDjewel4-2",
           "/data/enchase/REDjewel4-3", }) : "/clone/enchase/REDjewel5",

        ({ "/data/enchase/REDjewel5-1",
           "/data/enchase/REDjewel5-2",
           "/data/enchase/REDjewel5-3", }) : "/clone/enchase/REDjewel6",

        ({ "/data/enchase/REDjewel6-1",
           "/data/enchase/REDjewel6-2",
           "/data/enchase/REDjewel6-3", }) : "/clone/enchase/REDjewel7",

        ({ "/data/enchase/WHTjewel1-1",
           "/data/enchase/WHTjewel1-2",
           "/data/enchase/WHTjewel1-3", }) : "/clone/enchase/WHTjewel2",

        ({ "/data/enchase/WHTjewel2-1",
           "/data/enchase/WHTjewel2-2",
           "/data/enchase/WHTjewel2-3", }) : "/clone/enchase/WHTjewel3",

        ({ "/data/enchase/WHTjewel3-1",
           "/data/enchase/WHTjewel3-2",
           "/data/enchase/WHTjewel3-3", }) : "/clone/enchase/WHTjewel4",

        ({ "/data/enchase/WHTjewel4-1",
           "/data/enchase/WHTjewel4-2",
           "/data/enchase/WHTjewel4-3", }) : "/clone/enchase/WHTjewel5",

        ({ "/data/enchase/WHTjewel5-1",
           "/data/enchase/WHTjewel5-2",
           "/data/enchase/WHTjewel5-3", }) : "/clone/enchase/WHTjewel6",

        ({ "/data/enchase/WHTjewel6-1",
           "/data/enchase/WHTjewel6-2",
           "/data/enchase/WHTjewel6-3", }) : "/clone/enchase/WHTjewel7",

        ({ "/data/enchase/YELjewel1-1",
           "/data/enchase/YELjewel1-2",
           "/data/enchase/YELjewel1-3", }) : "/clone/enchase/YELjewel2",

        ({ "/data/enchase/YELjewel2-1",
           "/data/enchase/YELjewel2-2",
           "/data/enchase/YELjewel2-3", }) : "/clone/enchase/YELjewel3",

        ({ "/data/enchase/YELjewel3-1",
           "/data/enchase/YELjewel3-2",
           "/data/enchase/YELjewel3-3", }) : "/clone/enchase/YELjewel4",

        ({ "/data/enchase/YELjewel4-1",
           "/data/enchase/YELjewel4-2",
           "/data/enchase/YELjewel4-3", }) : "/clone/enchase/YELjewel5",

        ({ "/data/enchase/YELjewel5-1",
           "/data/enchase/YELjewel5-2",
           "/data/enchase/YELjewel5-3", }) : "/clone/enchase/YELjewel6",

        ({ "/data/enchase/YELjewel6-1",
           "/data/enchase/YELjewel6-2",
           "/data/enchase/YELjewel6-3", }) : "/clone/enchase/YELjewel7",

        ({ "/clone/enchase/BLKjewel1-1",
           "/clone/enchase/BLKjewel1-2",
           "/clone/enchase/BLKjewel1-3", }) : "/clone/enchase/BLKjewel2",

        ({ "/clone/enchase/BLKjewel2-1",
           "/clone/enchase/BLKjewel2-2",
           "/clone/enchase/BLKjewel2-3", }) : "/clone/enchase/BLKjewel3",

        ({ "/clone/enchase/BLKjewel3-1",
           "/clone/enchase/BLKjewel3-2",
           "/clone/enchase/BLKjewel3-3", }) : "/clone/enchase/BLKjewel4",

        ({ "/clone/enchase/BLKjewel4-1",
           "/clone/enchase/BLKjewel4-2",
           "/clone/enchase/BLKjewel4-3", }) : "/clone/enchase/BLKjewel5",

        ({ "/clone/enchase/BLKjewel5-1",
           "/clone/enchase/BLKjewel5-2",
           "/clone/enchase/BLKjewel5-3", }) : "/clone/enchase/BLKjewel6",

        ({ "/clone/enchase/BLKjewel6-1",
           "/clone/enchase/BLKjewel6-2",
           "/clone/enchase/BLKjewel6-3", }) : "/clone/enchase/BLKjewel7",

        ({ "/clone/enchase/BLUjewel1-1",
           "/clone/enchase/BLUjewel1-2",
           "/clone/enchase/BLUjewel1-3", }) : "/clone/enchase/BLUjewel2",

        ({ "/clone/enchase/BLUjewel2-1",
           "/clone/enchase/BLUjewel2-2",
           "/clone/enchase/BLUjewel2-3", }) : "/clone/enchase/BLUjewel3",

        ({ "/clone/enchase/BLUjewel3-1",
           "/clone/enchase/BLUjewel3-2",
           "/clone/enchase/BLUjewel3-3", }) : "/clone/enchase/BLUjewel4",

        ({ "/clone/enchase/BLUjewel4-1",
           "/clone/enchase/BLUjewel4-2",
           "/clone/enchase/BLUjewel4-3", }) : "/clone/enchase/BLUjewel5",

        ({ "/clone/enchase/BLUjewel5-1",
           "/clone/enchase/BLUjewel5-2",
           "/clone/enchase/BLUjewel5-3", }) : "/clone/enchase/BLUjewel6",

        ({ "/clone/enchase/BLUjewel6-1",
           "/clone/enchase/BLUjewel6-2",
           "/clone/enchase/BLUjewel6-3", }) : "/clone/enchase/BLUjewel7",

        ({ "/clone/enchase/CYNjewel1-1",
           "/clone/enchase/CYNjewel1-2",
           "/clone/enchase/CYNjewel1-3", }) : "/clone/enchase/CYNjewel2",

        ({ "/clone/enchase/CYNjewel2-1",
           "/clone/enchase/CYNjewel2-2",
           "/clone/enchase/CYNjewel2-3", }) : "/clone/enchase/CYNjewel3",

        ({ "/clone/enchase/CYNjewel3-1",
           "/clone/enchase/CYNjewel3-2",
           "/clone/enchase/CYNjewel3-3", }) : "/clone/enchase/CYNjewel4",

        ({ "/clone/enchase/CYNjewel4-1",
           "/clone/enchase/CYNjewel4-2",
           "/clone/enchase/CYNjewel4-3", }) : "/clone/enchase/CYNjewel5",

        ({ "/clone/enchase/CYNjewel5-1",
           "/clone/enchase/CYNjewel5-2",
           "/clone/enchase/CYNjewel5-3", }) : "/clone/enchase/CYNjewel6",

        ({ "/clone/enchase/CYNjewel6-1",
           "/clone/enchase/CYNjewel6-2",
           "/clone/enchase/CYNjewel6-3", }) : "/clone/enchase/CYNjewel7",

        ({ "/clone/enchase/GRNjewel1-1",
           "/clone/enchase/GRNjewel1-2",
           "/clone/enchase/GRNjewel1-3", }) : "/clone/enchase/GRNjewel2",

        ({ "/clone/enchase/GRNjewel2-1",
           "/clone/enchase/GRNjewel2-2",
           "/clone/enchase/GRNjewel2-3", }) : "/clone/enchase/GRNjewel3",

        ({ "/clone/enchase/GRNjewel3-1",
           "/clone/enchase/GRNjewel3-2",
           "/clone/enchase/GRNjewel3-3", }) : "/clone/enchase/GRNjewel4",

        ({ "/clone/enchase/GRNjewel4-1",
           "/clone/enchase/GRNjewel4-2",
           "/clone/enchase/GRNjewel4-3", }) : "/clone/enchase/GRNjewel5",

        ({ "/clone/enchase/GRNjewel5-1",
           "/clone/enchase/GRNjewel5-2",
           "/clone/enchase/GRNjewel5-3", }) : "/clone/enchase/GRNjewel6",

        ({ "/clone/enchase/GRNjewel6-1",
           "/clone/enchase/GRNjewel6-2",
           "/clone/enchase/GRNjewel6-3", }) : "/clone/enchase/GRNjewel7",

        ({ "/clone/enchase/MAGjewel1-1",
           "/clone/enchase/MAGjewel1-2",
           "/clone/enchase/MAGjewel1-3", }) : "/clone/enchase/MAGjewel2",

        ({ "/clone/enchase/MAGjewel2-1",
           "/clone/enchase/MAGjewel2-2",
           "/clone/enchase/MAGjewel2-3", }) : "/clone/enchase/MAGjewel3",

        ({ "/clone/enchase/MAGjewel3-1",
           "/clone/enchase/MAGjewel3-2",
           "/clone/enchase/MAGjewel3-3", }) : "/clone/enchase/MAGjewel4",

        ({ "/clone/enchase/MAGjewel4-1",
           "/clone/enchase/MAGjewel4-2",
           "/clone/enchase/MAGjewel4-3", }) : "/clone/enchase/MAGjewel5",

        ({ "/clone/enchase/MAGjewel5-1",
           "/clone/enchase/MAGjewel5-2",
           "/clone/enchase/MAGjewel5-3", }) : "/clone/enchase/MAGjewel6",

        ({ "/clone/enchase/MAGjewel6-1",
           "/clone/enchase/MAGjewel6-2",
           "/clone/enchase/MAGjewel6-3", }) : "/clone/enchase/MAGjewel7",

        ({ "/clone/enchase/REDjewel1-1",
           "/clone/enchase/REDjewel1-2",
           "/clone/enchase/REDjewel1-3", }) : "/clone/enchase/REDjewel2",

        ({ "/clone/enchase/REDjewel2-1",
           "/clone/enchase/REDjewel2-2",
           "/clone/enchase/REDjewel2-3", }) : "/clone/enchase/REDjewel3",

        ({ "/clone/enchase/REDjewel3-1",
           "/clone/enchase/REDjewel3-2",
           "/clone/enchase/REDjewel3-3", }) : "/clone/enchase/REDjewel4",

        ({ "/clone/enchase/REDjewel4-1",
           "/clone/enchase/REDjewel4-2",
           "/clone/enchase/REDjewel4-3", }) : "/clone/enchase/REDjewel5",

        ({ "/clone/enchase/REDjewel5-1",
           "/clone/enchase/REDjewel5-2",
           "/clone/enchase/REDjewel5-3", }) : "/clone/enchase/REDjewel6",

        ({ "/clone/enchase/REDjewel6-1",
           "/clone/enchase/REDjewel6-2",
           "/clone/enchase/REDjewel6-3", }) : "/clone/enchase/REDjewel7",

        ({ "/clone/enchase/WHTjewel1-1",
           "/clone/enchase/WHTjewel1-2",
           "/clone/enchase/WHTjewel1-3", }) : "/clone/enchase/WHTjewel2",

        ({ "/clone/enchase/WHTjewel2-1",
           "/clone/enchase/WHTjewel2-2",
           "/clone/enchase/WHTjewel2-3", }) : "/clone/enchase/WHTjewel3",

        ({ "/clone/enchase/WHTjewel3-1",
           "/clone/enchase/WHTjewel3-2",
           "/clone/enchase/WHTjewel3-3", }) : "/clone/enchase/WHTjewel4",

        ({ "/clone/enchase/WHTjewel4-1",
           "/clone/enchase/WHTjewel4-2",
           "/clone/enchase/WHTjewel4-3", }) : "/clone/enchase/WHTjewel5",

        ({ "/clone/enchase/WHTjewel5-1",
           "/clone/enchase/WHTjewel5-2",
           "/clone/enchase/WHTjewel5-3", }) : "/clone/enchase/WHTjewel6",

        ({ "/clone/enchase/WHTjewel6-1",
           "/clone/enchase/WHTjewel6-2",
           "/clone/enchase/WHTjewel6-3", }) : "/clone/enchase/WHTjewel7",

        ({ "/clone/enchase/YELjewel1-1",
           "/clone/enchase/YELjewel1-2",
           "/clone/enchase/YELjewel1-3", }) : "/clone/enchase/YELjewel2",

        ({ "/clone/enchase/YELjewel2-1",
           "/clone/enchase/YELjewel2-2",
           "/clone/enchase/YELjewel2-3", }) : "/clone/enchase/YELjewel3",

        ({ "/clone/enchase/YELjewel3-1",
           "/clone/enchase/YELjewel3-2",
           "/clone/enchase/YELjewel3-3", }) : "/clone/enchase/YELjewel4",

        ({ "/clone/enchase/YELjewel4-1",
           "/clone/enchase/YELjewel4-2",
           "/clone/enchase/YELjewel4-3", }) : "/clone/enchase/YELjewel5",

        ({ "/clone/enchase/YELjewel5-1",
           "/clone/enchase/YELjewel5-2",
           "/clone/enchase/YELjewel5-3", }) : "/clone/enchase/YELjewel6",

        ({ "/clone/enchase/YELjewel6-1",
           "/clone/enchase/YELjewel6-2",
           "/clone/enchase/YELjewel6-3", }) : "/clone/enchase/YELjewel7",
           
        // ���ĵĺϳɹ�ʽ
        ({ "/clone/enchase/rune01-1",
           "/clone/enchase/rune01-2",
           "/clone/enchase/rune01-3", }) : "/clone/enchase/rune02",
           
        ({ "/clone/enchase/rune02-1",
           "/clone/enchase/rune02-2",
           "/clone/enchase/rune02-3", }) : "/clone/enchase/rune03",

        ({ "/clone/enchase/rune03-1",
           "/clone/enchase/rune03-2",
           "/clone/enchase/rune03-3", }) : "/clone/enchase/rune04",
           
        ({ "/clone/enchase/rune04-1",
           "/clone/enchase/rune04-2",
           "/clone/enchase/rune04-3", }) : "/clone/enchase/rune05",

        ({ "/clone/enchase/rune05-1",
           "/clone/enchase/rune05-2",
           "/clone/enchase/rune05-3", }) : "/clone/enchase/rune06",

        ({ "/clone/enchase/rune06-1",
           "/clone/enchase/rune06-2",
           "/clone/enchase/rune06-3", }) : "/clone/enchase/rune07",

        ({ "/clone/enchase/rune07-1",
           "/clone/enchase/rune07-2",
           "/clone/enchase/rune07-3", }) : "/clone/enchase/rune08",

        ({ "/clone/enchase/rune08-1",
           "/clone/enchase/rune08-2",
           "/clone/enchase/rune08-3", }) : "/clone/enchase/rune09",

        ({ "/clone/enchase/rune09-1",
           "/clone/enchase/rune09-2",
           "/clone/enchase/rune09-3", }) : "/clone/enchase/rune10",

        ({ "/clone/enchase/rune10-1",
           "/clone/enchase/rune10-2",
           "/clone/enchase/rune10-3",
           "/data/enchase/YELjewel3-1", }) : "/clone/enchase/rune11",

        ({ "/clone/enchase/rune11-1",
           "/clone/enchase/rune11-2",
           "/clone/enchase/rune11-3",
           "/data/enchase/MAGjewel3-1", }) : "/clone/enchase/rune12",

        ({ "/clone/enchase/rune12-1",
           "/clone/enchase/rune12-2",
           "/clone/enchase/rune12-3",
           "/data/enchase/BLUjewel3-1", }) : "/clone/enchase/rune13",

        ({ "/clone/enchase/rune13-1",
           "/clone/enchase/rune13-2",
           "/clone/enchase/rune13-3",
           "/data/enchase/REDjewel3-1", }) : "/clone/enchase/rune14",
                                                                                                                                 
        ({ "/clone/enchase/rune14-1",
           "/clone/enchase/rune14-2",
           "/clone/enchase/rune14-3",
           "/data/enchase/GRNjewel3-1", }) : "/clone/enchase/rune15",

        ({ "/clone/enchase/rune15-1",
           "/clone/enchase/rune15-2",
           "/clone/enchase/rune15-3",
           "/data/enchase/BLKjewel3-1", }) : "/clone/enchase/rune16",

        ({ "/clone/enchase/rune16-1",
           "/clone/enchase/rune16-2",
           "/clone/enchase/rune16-3",
           "/data/enchase/YELjewel4-1", }) : "/clone/enchase/rune17",

        ({ "/clone/enchase/rune17-1",
           "/clone/enchase/rune17-2",
           "/clone/enchase/rune17-3",
           "/data/enchase/MAGjewel4-1", }) : "/clone/enchase/rune18",

        ({ "/clone/enchase/rune18-1",
           "/clone/enchase/rune18-2",
           "/clone/enchase/rune18-3",
           "/data/enchase/BLUjewel4-1", }) : "/clone/enchase/rune19",

        ({ "/clone/enchase/rune19-1",
           "/clone/enchase/rune19-2",
           "/clone/enchase/rune19-3",
           "/data/enchase/REDjewel4-1", }) : "/clone/enchase/rune20",
                                                                                                                                 
        ({ "/clone/enchase/rune20-1",
           "/clone/enchase/rune20-2",
           "/clone/enchase/rune20-3",
           "/data/enchase/GRNjewel4-1", }) : "/clone/enchase/rune21",

        ({ "/clone/enchase/rune21-1",
           "/clone/enchase/rune21-2",
           "/data/enchase/BLKjewel4-1", }) : "/clone/enchase/rune22",

        ({ "/clone/enchase/rune22-1",
           "/clone/enchase/rune22-2",
           "/data/enchase/YELjewel5-1", }) : "/clone/enchase/rune23",

        ({ "/clone/enchase/rune23-1",
           "/clone/enchase/rune23-2",
           "/data/enchase/MAGjewel5-1", }) : "/clone/enchase/rune24",

        ({ "/clone/enchase/rune24-1",
           "/clone/enchase/rune24-2",
           "/data/enchase/BLUjewel5-1", }) : "/clone/enchase/rune25",

        ({ "/clone/enchase/rune25-1",
           "/clone/enchase/rune25-2",
           "/data/enchase/REDjewel5-1", }) : "/clone/enchase/rune26",
                                                                                                                                 
        ({ "/clone/enchase/rune26-1",
           "/clone/enchase/rune26-2",
           "/data/enchase/GRNjewel5-1", }) : "/clone/enchase/rune27",

        ({ "/clone/enchase/rune27-1",
           "/clone/enchase/rune27-2",
           "/data/enchase/BLKjewel5-1", }) : "/clone/enchase/rune28",
           
        ({ "/clone/enchase/rune28-1",
           "/clone/enchase/rune28-2",
           "/data/enchase/YELjewel6-1", }) : "/clone/enchase/rune29",

        ({ "/clone/enchase/rune29-1",
           "/clone/enchase/rune29-2",
           "/data/enchase/MAGjewel6-1", }) : "/clone/enchase/rune30",

        ({ "/clone/enchase/rune30-1",
           "/clone/enchase/rune30-2",
           "/data/enchase/BLUjewel6-1", }) : "/clone/enchase/rune31",

        ({ "/clone/enchase/rune31-1",
           "/clone/enchase/rune31-2",
           "/data/enchase/REDjewel6-1", }) : "/clone/enchase/rune32",
                                                                                                                                 
        ({ "/clone/enchase/rune32-1",
           "/clone/enchase/rune32-2",
           "/data/enchase/GRNjewel6-1", }) : "/clone/enchase/rune33",
                                                            
        // ����������
        ({ "/clone/fam/max/xuanhuang-1",
           "/clone/fam/max/longjia-1",
           "/clone/fam/item/kunlun-1",
           "/clone/fam/item/baxian-1", }) : "/clone/fam/max/zhenyu",

        // �������׵�
        ({ "/clone/fam/pill/dimai-1",
           "/clone/fam/pill/renshen4-1",
           "/clone/fam/etc/lv7d-1", }) : "/clone/fam/max/longjia",

        // �������䵤
        ({ "/clone/fam/pill/yulu-1",
           "/clone/fam/pill/lingzhi4-1",
           "/clone/fam/etc/lv7a-1", }) : "/clone/fam/max/xuanhuang",

        // ����ѪȪ
        ({ "/clone/fam/pill/puti2-1",
           "/clone/fam/pill/sheli3-1",
           "/clone/fam/etc/lv7b-1", }) : "/clone/fam/pill/dimai",

        // ������¶
        ({ "/clone/fam/pill/sheli2-1",
           "/clone/fam/pill/puti3-1",
           "/clone/fam/etc/lv7c-1", }) : "/clone/fam/pill/yulu",

        // ǧ����ĵ�
        ({ "/clone/fam/pill/renshen1-1",
           "/clone/fam/pill/renshen2-1",
           "/clone/fam/etc/lv5c-1", }) : "/clone/fam/pill/renshen4",

        // ǧ����֥��
        ({ "/clone/fam/pill/lingzhi1-1",
           "/clone/fam/pill/lingzhi2-1",
           "/clone/fam/etc/lv5c-1", }) : "/clone/fam/pill/lingzhi4",

        // ǧ��ѩ����
        ({ "/clone/fam/pill/xuelian1-1",
           "/clone/fam/pill/xuelian2-1",
           "/clone/fam/etc/lv5c-1", }) : "/clone/fam/pill/xuelian4",

        // ������ĵ�
        ({ "/clone/fam/pill/renshen1-1",
           "/clone/fam/etc/lv5e-1", }) : "/clone/fam/pill/renshen3",

        // ������֥��
        ({ "/clone/fam/pill/lingzhi1-1",
           "/clone/fam/etc/lv5e-1", }) : "/clone/fam/pill/lingzhi3",

        // ����ѩ����
        ({ "/clone/fam/pill/xuelian1-1",
           "/clone/fam/etc/lv5e-1", }) : "/clone/fam/pill/xuelian3",

        // ��쵤
        ({ "/clone/fam/pill/linghui1-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/linghui2",

        // ������
        ({ "/clone/fam/pill/neili1-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/neili2",

        // ������
        ({ "/clone/fam/pill/puti1-1",
           "/clone/fam/pill/puti2-1",
           "/clone/fam/pill/puti3-1", }) : "/clone/fam/pill/puti4",

        // ʥ����
        ({ "/clone/fam/pill/sheli1-1",
           "/clone/fam/pill/sheli2-1",
           "/clone/fam/pill/sheli3-1", }) : "/clone/fam/pill/sheli4",

        // ��������
        ({ "/clone/fam/pill/sheli2-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/sheli3",

        // ������
        ({ "/clone/fam/pill/puti2-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/puti3",

        // ������
        ({ "/clone/fam/pill/puti1-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/puti2",

        // ��������
        ({ "/clone/fam/pill/sheli1-1",
           "/clone/fam/pill/full1-1", }) : "/clone/fam/pill/sheli2",

        // ��������
        ({ "/clone/fam/etc/lv5a-1",
           "/clone/fam/etc/lv5b-1",
           "/clone/fam/etc/lv5d-1",
           "/clone/fam/etc/lv7d-1",
           "/clone/fam/gift/str3-1", }) : "/clone/fam/max/tianshu1",

        // ��������
        ({ "/clone/fam/etc/lv5a-1",
           "/clone/fam/etc/lv5b-1",
           "/clone/fam/etc/lv5d-1",
           "/clone/fam/etc/lv7d-1",
           "/clone/fam/gift/con3-1", }) : "/clone/fam/max/tianshu1",

        // ��������
        ({ "/clone/fam/etc/lv5a-1",
           "/clone/fam/etc/lv5b-1",
           "/clone/fam/etc/lv5d-1",
           "/clone/fam/etc/lv7d-1",
           "/clone/fam/gift/int3-1", }) : "/clone/fam/max/tianshu1",

        // ��������
        ({ "/clone/fam/etc/lv5a-1",
           "/clone/fam/etc/lv5b-1",
           "/clone/fam/etc/lv5d-1",
           "/clone/fam/etc/lv7d-1",
           "/clone/fam/gift/dex3-1", }) : "/clone/fam/max/tianshu1",

        // ������ʯ��Ƭ�ϲ���Ϊһ����ʯ
        ({ "/data/enchase/cdiamond-1",
           "/data/enchase/cdiamond-2",
           "/data/enchase/cdiamond-3" }) : "/clone/gift/diamond",

        // ������ʯ�ϲ���Ϊһ��������ʯ
        ({ "/data/enchase/diamond-1",
           "/data/enchase/diamond-2",
           "/data/enchase/diamond-3" }) : "/clone/gift/fdiamond",

        // ����������ʯ�ϲ���Ϊһ����֮��ʯ
        ({ "/data/enchase/fdiamond-1",
           "/data/enchase/fdiamond-2",
           "/data/enchase/fdiamond-3" }) : "/clone/gift/mdiamond",

        // ���������Ƭ�ϲ���Ϊһ�����
        ({ "/data/enchase/cagate-1",
           "/data/enchase/cagate-2",
           "/data/enchase/cagate-3" }) : "/clone/gift/agate",

        // ������觺ϲ���Ϊһ���������
        ({ "/data/enchase/agate-1",
           "/data/enchase/agate-2",
           "/data/enchase/agate-3" }) : "/clone/gift/fagate",

        // ����������觺ϲ���Ϊһ����֮���
        ({ "/data/enchase/fagate-1",
           "/data/enchase/fagate-2",
           "/data/enchase/fagate-3" }) : "/clone/gift/magate",

        // ����ˮ����Ƭ�ϲ���Ϊһ��ˮ��
        ({ "/data/enchase/ccrystal-1",
           "/data/enchase/ccrystal-2",
           "/data/enchase/ccrystal-3" }) : "/clone/gift/crystal",

        // ����ˮ���ϲ���Ϊһ������ˮ��
        ({ "/data/enchase/crystal-1",
           "/data/enchase/crystal-2",
           "/data/enchase/crystal-3" }) : "/clone/gift/fcrystal",

        // ��������ˮ���ϲ���Ϊһ����֮ˮ��
        ({ "/data/enchase/fcrystal-1",
           "/data/enchase/fcrystal-2",
           "/data/enchase/fcrystal-3" }) : "/clone/gift/mcrystal",

        // ���������Ƭ�ϲ���Ϊһ�����
        ({ "/data/enchase/cjade-1",
           "/data/enchase/cjade-2",
           "/data/enchase/cjade-3" }) : "/clone/gift/jade",

        // �������ϲ���Ϊһ���������
        ({ "/data/enchase/jade-1",
           "/data/enchase/jade-2",
           "/data/enchase/jade-3" }) : "/clone/gift/fjade",

        // �����������ϲ���Ϊһ����֮���
        ({ "/data/enchase/fjade-1",
           "/data/enchase/fjade-2",
           "/data/enchase/fjade-3" }) : "/clone/gift/mjade",

        // Ǭ��ʥˮ
        ({ "/clone/fam/gift/int3-1",
           "/clone/fam/etc/lv7a-1",
           "/clone/fam/item/stone5-1" }) : "/clone/fam/item/bless_water",

        // Ǭ��ʥˮ
        ({ "/clone/fam/gift/con3-1",
           "/clone/fam/etc/lv7a-1",
           "/clone/fam/item/stone5-1" }) : "/clone/fam/item/bless_water",

        // Ǭ��ʥˮ
        ({ "/clone/fam/gift/dex3-1",
           "/clone/fam/etc/lv7a-1",
           "/clone/fam/item/stone5-1" }) : "/clone/fam/item/bless_water",

        // Ǭ��ʥˮ
        ({ "/clone/fam/gift/str3-1",
           "/clone/fam/etc/lv7a-1",
           "/clone/fam/item/stone5-1" }) : "/clone/fam/item/bless_water",

        // ��ʯ
        ({ "/clone/fam/item/stone3-1",
           "/clone/fam/item/stone1-1",
           }) : "/clone/fam/item/stone4",

        // �ʯ
        ({ "/clone/fam/item/stone2-1",
           "/clone/fam/item/stone1-1",
           }) : "/clone/fam/item/stone3",


        // ���»�ʯ
        ({ "/clone/fam/item/stone1-1",
           "/clone/fam/item/stone4-1",
           "/clone/fam/item/stone3-1",
           "/clone/fam/item/stone2-1",
           }) : "/clone/fam/item/stone5",

        // ��֮��������
       ({ "/data/enchase/BLKjewel7-1",
          "/data/enchase/BLUjewel7-1",
          "/data/enchase/CYNjewel7-1",
          "/data/enchase/GRNjewel7-1",
          "/data/enchase/MAGjewel7-1",
          "/data/enchase/REDjewel7-1",
          "/data/enchase/WHTjewel7-1",
          "/data/enchase/YELjewel7-1",
          "/data/enchase/mjade-1",
          "/clone/enchase/rune07-1",
           }) : "/clone/fam/etc/hanjing",

        // ʥħ֮�ġ�ħ
       ({ "/data/enchase/BLKjewel7-1",
          "/data/enchase/BLUjewel7-1",
          "/data/enchase/CYNjewel7-1",
          "/data/enchase/GRNjewel7-1",
          "/data/enchase/MAGjewel7-1",
          "/data/enchase/REDjewel7-1",
          "/data/enchase/WHTjewel7-1",
          "/data/enchase/YELjewel7-1",
          "/data/enchase/mcrystal-1",
          "/clone/enchase/rune07-1",
           }) : "/clone/fam/etc/mozhixin",

        // ��֮���顤��
       ({ "/data/enchase/BLKjewel7-1",
          "/data/enchase/BLUjewel7-1",
          "/data/enchase/CYNjewel7-1",
          "/data/enchase/GRNjewel7-1",
          "/data/enchase/MAGjewel7-1",
          "/data/enchase/REDjewel7-1",
          "/data/enchase/WHTjewel7-1",
          "/data/enchase/YELjewel7-1",
          "/data/enchase/magate-1",
          "/clone/enchase/rune07-1",
           }) : "/clone/fam/etc/huojingling",

        // ����֮ͫ����
       ({ "/data/enchase/BLKjewel7-1",
          "/data/enchase/BLUjewel7-1",
          "/data/enchase/CYNjewel7-1",
          "/data/enchase/GRNjewel7-1",
          "/data/enchase/MAGjewel7-1",
          "/data/enchase/REDjewel7-1",
          "/data/enchase/WHTjewel7-1",
          "/data/enchase/YELjewel7-1",
          "/data/enchase/mdiamond-1",
          "/clone/enchase/rune07-1",
           }) : "/clone/fam/etc/leishentong",
           	
        //����֮��
        ({ "/clone/gift/mjade-1",
        	 "/clone/gift/mcrystal-1",
        	 "/clone/gift/magate-1",
        	 "/clone/gift/mdiamond-1",
        	 "/clone/fam/etc/hanjing-1",
        	 "/clone/fam/etc/mozhixin-1",
        	 "/clone/fam/etc/huojingling-1",
        	 "/clone/fam/etc/leishentong-1",
        	 "/clone/fam/item/bless_water-1",
        	}) : "/clone/item/noname",
       
]);

int main(object me, string arg)
{
        mapping same;                   // �ж��ظ�����Ʒ����Ҫ��mapping
	string *item_list, *name_list;  // �ϲ�����ƷID���ƥ��Ļ������ֱ�
        string bname;                   // ��Ʒ��Ӧ���ļ��Ļ�������
        object *ob_list;                // �ϲ���������Ʒ
        string *per;                    // mapping�м�¼�Ŀɺϲ��Ļ������ֱ�
	object obj;                     // ���ɵ���Ʒ
        int mp, i;

	if (! arg)
                return notify_fail("��Ҫ�ϲ�ʲô��Ʒ��\n");

        if (me->is_busy())
                return notify_fail("��æ����������������������ɣ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");

        if (me->query("max_jingli") < 300)
                return notify_fail("�����ڵľ�����Ϊ���ޣ��޷��ϳ���Ʒ��\n");

        if (me->query("jingli") < 300)
                return notify_fail("�����ھ������ã��޷��ϳ���Ʒ��\n");

        item_list = explode(arg, "&");
        ob_list   = allocate(sizeof(item_list));
        name_list = allocate(sizeof(item_list));
        same = allocate_mapping(sizeof(item_list));
        for (i = 0; i < sizeof(item_list); i++)
        {
                bname = item_list[i];
                while (bname[0] == ' ') bname = bname[1..<0];
                while (bname[strlen(bname) - 1] == ' ') bname = bname[0..<2];
                ob_list[i] = present(bname, me);

                if (! objectp(ob_list[i]))
                        return notify_fail("������û�� " + bname + " ������Ʒ����\n");

                /*
                if (ob_list[i]->query("no_identify"))
                        return notify_fail("�����ϵ� " + bname + " ��û��ȥ��������\n");
                */

                if (i > 0 && member_array(ob_list[i], ob_list[0..i - 1]) != -1)
                        return notify_fail("�ϲ���Ʒ��Ҫָ����ͬ����Ʒ����Ҫ�ظ�ָ"
                                           "��һ����Ʒ��\n");

                bname = base_name(ob_list[i]);
                if (strsrch(bname, "/data/enchase/") >= 0)
                	sscanf(bname, "%s-%*s", bname);

                if (undefinedp(same[bname]))
                        same[bname] = 1;
                else
                        same[bname]++;
                name_list[i] = bname + "-" + (string) same[bname];
        }

        tell_object(me, HIW "\n��˫Ŀ΢�գ���������Ʒ�������У���ת�ھ���"
                        "ʹ���ǽ��ڡ�\n" NOR);

        me->start_busy(1);
        me->add("jingli", -200);
        foreach (per in keys(combine_list))
        {
                if (per - name_list == ({ }) && sizeof(per) == sizeof(name_list))
                {
                        // �ҵ��˺��ʵ����
                        obj = new(combine_list[per]);
                        for (i = 0; i < sizeof(ob_list); i++)
                        {
                                if (ob_list[i]->query_amount())
                                        ob_list[i]->add_amount(-1);
                                else
                                {
                     			if (strsrch(base_name(ob_list[i]), "/data/enchase/") >= 0)
                     				rm(base_name(ob_list[i]) + ".c");

                                        destruct(ob_list[i]);
                                }
                        }
                        message("vision", HIW "\n��ʱ��ֻ��" + me->name() + HIW "����һ��"
                                          "�⻪��������ת˲���ţ��ƺ�������ʲô��ͬѰ����"
                                          "���顣\n\n" NOR, environment(me), ({me}));

                        tell_object(me, HIW "��ʱ��ֻ������⻪�����������㼱æ̯�����ƣ�"
                                        "��������\n��Ȼ������һ" + obj->query("unit") +
                                        obj->name() + HIW "����������ɫϼ�⡣\n\n" NOR);

			if (obj->query("value"))
			{
				mp = (int)(obj->query("value") / 700);
				mp = 1 + random(mp);
				if (mp < 1) mp = 1;
				if (mp > 100) mp = 100;

	                        me->add("magic_points", mp);
			        tell_object(me, HIC "��ͨ���ϳ�"+ obj->name() + HIC "����"
                                                "�����̣��Ӷ������" + chinese_number(mp) +
                                                "����ۡ�\n" NOR);
			}
                        me->add("max_jingli", -1);
                        obj->move(me, 1);
                        return 1;
                }
        }
        tell_object(me, HIR "���ǹ��˰��죬�ƺ�û���κα仯���㲻��һ��"
                        "��̾��\n" NOR);

        return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : combine <������Ʒ> & <������Ʒ> & ����

���ָ��������㽫ĳЩ������Ʒ�ϲ���һ���µ���Ʒ����Щ���ܺ�
�������Ҫ����ȥ�����ˡ�ÿ�κϲ�������ʧһ�㾫�������ޡ����
Ҫ�ϲ��ļ�����Ʒ������ͬ������Ҫָ�����ǵ���ţ�������������
ʯ�����Ҫ��һ������Ҫ���룺

  combine diamond & diamond 2 & diamond 3

HELP);
    	return 1;
}
