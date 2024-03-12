#pragma once
struct Curriculum {
	char* name[30];
	int score;
	int term;
	struct Curriculum* next;
};

struct Member {
	char* name[30];
	int rank;//-1Ϊû��˳��	0 ΪͨѶ���� 1��ʼΪ1�� 2Ϊ2������
	struct Member* next;
};
struct researchAchievement {
	char* paperName[30];
	struct Member* head;
	char* journalName[30];
	char* meetingName[30];
	char* publishTime[30];
	int increaseGpa;
	char level;//'A'->0.4	'B'->0.2	'C'->0.1 'D'->0.05	'D'->0.02	'E'->0.01
	int year,month,day;
	int reel;//��
	int period;//��
	int paperNum;//���ĺ�
	int start, end;//ҳ�뷶Χ
	struct researchAchievement* next;
};
struct Competition {
	char* Name[30];
	char* HostName[30];
	struct Member* head;
	int year, month, day;
	char grade;//����
	int rank;//����
	int increaseGpa;
};

struct Project {
	struct Member* head;
	char* name[30];
	char* number[30];
	char* teacherName[30];
	int year1, month1, day1;//����
	int year2, month2, day2;//����
};
struct Student {
	struct Curriculum* curr;
	struct researchAchievement* ach;
	struct Competition* cmp;
	int curriculumNum;//�γ���Ŀ
	int gpa;
	int term1, term2, term3, term4, term5, term6, term7, term8;//��ѧ������
	int totalRank;//������

};