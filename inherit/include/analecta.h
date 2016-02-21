// analecta.h

#ifndef ANALECTA_D
#define ANALECTA_D      "/adm/daemons/analectad"
#endif

#define ANALECTA_DIR            DATA_DIR + "analecta/"
#define HEAD_LINES              8
#define MAX_CONTENT_LINES       4000

// ��ѡ����
int sort_analectas(mapping a1, mapping a2) { return (a1["add_time"] - a2["add_time"]); }

// ɸѡ��ѡ
int filter_analectas(mapping analecta, int time) { return (analecta["add_time"] > time); }

