#pragma once
#include"main.h"
#include<stdio.h>
struct Student* Search_number(struct Student* head, int number);//����ѧ�Ų���
struct Student* Search_name(struct Student* head, char name[]);//��������

void InsertStudent0(struct Student* head);//�ռ����ݲ�����  ����̨
void InsertStudent1(struct Student* head,FILE* fp);//�ռ����ݲ�����  �ļ�
void InsertMember0(struct Member* head);
void InsertMember1(struct Member* head,FILE* fp);
//�����ں���ʵ����ͬʱ����student
void InsertCurr0_number(struct Curriculum* head, int number, struct Student* head_s);
void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp);
void InsertCurr0_name(struct Curriculum* head, char name[], struct Student* head_s);
void InsertCurr1_name(struct Curriculum* head, char name[], struct Student* head_s, FILE* fp);

void InsertComp0_number(struct Competition* head, int number, struct Student* head_s);
void InsertComp0_name(struct Competition* head, char name[], struct Student* head_s);
void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp);
void InsertComp1_name(struct Competition* head, char name[], struct Student* head_s, FILE* fp);

void InsertProj0_number(struct Project* head, int number, struct Student* head_s);
void InsertProj0_name(struct Project* head, char name[], struct Student* head_s);
void InsertProj1_number(struct Project* head, int number, struct Student* head_s, FILE* fp);
void InsertProj1_name(struct Project* head, char name[], struct Student* head_s, FILE* fp);

void InsertResearch0_number(struct researchAchievement* head, int number, struct Student* head_s);
void InsertResearch0_name(struct researchAchievement* head, char name[], struct Student* head_s);
void InsertResearch1_number(struct researchAchievement* head, int number, struct Student* head_s, FILE* fp);
void InsertResearch1_name(struct researchAchievement* head, char name[], struct Student* head_s, FILE* fp);


double getCurrGPA(struct Student* curr);
double getTotalGPA(struct Student* curr);
int getRank(struct Student* curr, int term);
int getTotalRank(struct Student* curr);

void getCompetition_student(struct Student* curr);
void getResearch_student(struct Student* curr);
void getProject_student(struct Student* curr);

void calcCurrGpa(struct Student* curr);
void calcTotalGpa(struct Student* curr);
void calcTermGPA(struct Student* curr, int term);

void sortByGpa(struct Student* head);
void sortByTermGPA(struct Student* head, int term);

void amendStudentInfo(struct Student* head, int number);//amend�����޸���Ϣ��ɾ��
void amendStudentInfo(struct Student* head, char name[]);
void amendCurrInfo(struct Curriculum* head);//ͬʱ�ı�student�е�Info
void amendProjInfo(struct Project* head);
void amendResearch(struct researchAchievement* head);