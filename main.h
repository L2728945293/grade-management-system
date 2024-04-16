#pragma once
struct Curriculum {
	char name[100];
	double score;//分数
	double grade;//绩点
	int term;
	double credit;//学分
	struct Curriculum* next;
	int num[5];//<60 60-70 70-80 80-90 90-100
	struct Member* head;
};
struct Member {
	char name[30];
	int number;//学号
	int rank;//-1为没有顺序	0 为通讯作者 1开始为1作 2为2作……
	struct Member* next;
};
struct researchAchievement {
	char paperName[100];
	struct Member* head;
	char journalName[100];
	char meetingName[100];
	int JorM;//1期刊还是0会议
	double increaseGpa;
	char level;//'A'->0.4	'B'->0.2	'C'->0.1 'D'->0.05	'E'->0.02	'F'->0.01
	int year,month,day;
	int reel;//卷
	int period;//期
	int paperNum;//论文号
	int start, end;//页码范围
	struct researchAchievement* next;
};
struct Competition {
	char name[100];
	char HostName[100];
	struct Member* head;
	int year, month, day;
	char grade;//A.B.C
	double increaseGpa;
	char rank[30];//gold.../123
	struct Competition* next;
};

struct Project {
	struct Member* head;//rank1为负责人 2为第二名
	char name[100];
	int number;
	char teacherName[100];
	int year1, month1, day1;//立项
	int year2, month2, day2;//结项
	double increaseGpa;
	struct Project* next;
};
struct Student {
	struct Curriculum* head_curr;
	struct researchAchievement* head_ach;
	struct Competition* head_cmp;
	struct Project* head_pro;
	char name[100];
	char college[100];
	char major[100];
	int curriculumNum;//课程数目
	double CurrGpa;
	double increaseGPA;//<=0.4
	double totalGpa;
	double termGPA[9];
	int term[9];//各学期排名
	int totalRank;//总排名
	int number;//学号
	int gender;//0女1男
	int unlock;
	char password[20];
	struct Student* next;
};

struct Teacher {
	int number;
	char password[100];
	struct Teacher* next;
};