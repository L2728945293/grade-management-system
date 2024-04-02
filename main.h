#pragma once
struct Curriculum {
	char name[30];
	double score;
	char grade;
	int term;
	double credit;
	struct Curriculum* next;
};
struct Member {
	char name[30];
	int number;//ѧ��
	int rank;//-1Ϊû��˳��	0 ΪͨѶ���� 1��ʼΪ1�� 2Ϊ2������
	struct Member* next;
};
struct researchAchievement {
	char paperName[30];
	struct Member* head;
	char journalName[30];
	char meetingName[30];
	int JorM;//1�ڿ�����0����
	double increaseGpa;
	char level;//'A'->0.4	'B'->0.2	'C'->0.1 'D'->0.05	'E'->0.02	'F'->0.01
	int year,month,day;
	int reel;//��
	int period;//��
	int paperNum;//���ĺ�
	int start, end;//ҳ�뷶Χ
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
	struct Competition* next;
};

struct Project {
	struct Member* head;//rank1Ϊ������ 2Ϊ�ڶ���
	char name[30];
	int number;
	char teacherName[30];
	int year1, month1, day1;//����
	int year2, month2, day2;//����
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
	int curriculumNum;//�γ���Ŀ
	double CurrGpa;
	double increaseGPA;//<=0.4
	double totalGpa;
	double termGPA[9];
	int term[9];//��ѧ������
	int totalRank;//������
	int number;//ѧ��
	int gender;//0Ů1��
	int unlock;
	char password[20];
	struct Student* next;
};

struct Teacher {
	int number;
	char password[20];
	struct Teacher* next;
};