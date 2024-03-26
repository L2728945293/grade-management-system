#pragma once
struct Curriculum {
	char name[30];
	int score;
	char grade;
	int term;
	double credit;
	struct Curriculum* next;
};
struct Member {
	char name[30];
	int number;//学号
	int rank;//-1为没有顺序	0 为通讯作者 1开始为1作 2为2作……
	struct Member* next;
};
struct researchAchievement {
	char paperName[30];
	struct Member* head;
	char journalName[30];
	char meetingName[30];
	char publishTime[30];
	double increaseGpa;
	char level;//'A'->0.4	'B'->0.2	'C'->0.1 'D'->0.05	'D'->0.02	'E'->0.01
	int year,month,day;
	int reel;//卷
	int period;//期
	int paperNum;//论文号
	int start, end;//页码范围
	struct researchAchievement* next;
};
struct Competition {
	char name[30];
	char HostName[30];
	struct Member* head;
	int year, month, day;
	char grade;//A.B.C
	double increaseGpa;
	char rank[30];//gold.../123
	struct Competiton* next;
};

struct Project {
	struct Member* head;//rank1为负责人 2为第二名
	char name[30];
	int number;
	char teacherName[30];
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
	char name[30];
	char college[30];
	char major[30];
	int curriculumNum;//课程数目
	double CurrGpa;
	double increaseGPA;//<=0.4
	double totalGpa;
	int term1, term2, term3, term4, term5, term6, term7, term8;//各学期排名
	int totalRank;//总排名
	int number;//学号
	int gender;//0女1男
	struct Student* next;
};