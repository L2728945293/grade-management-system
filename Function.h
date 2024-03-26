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

void InsertResearch(struct researchAchievement* head);

float getGPA(int number);
float getGPA(char* name);
int getRank(int number,int term);
int getRank(char* name,int term);
int getTotalRank(int number);
int getTotalRank(char* name);
void getCompetition(struct Student* head, int number);
void getCompetition(struct Student* head, char* name);
void getResearch(struct Student* head, int number);
void getResearch(struct Student* head, char* name);
void getProject(struct Student* head, int number);
void getProject(struct Student* head, char* name);
void calcCurrGpa(struct Student* curr);

void amendStudentInfo(struct Student* head,int number);//amend�����޸���Ϣ��ɾ��
void amendStudentInfo(struct Student* head, char *name);
void amendCurrInfo(struct Curriculum* head);//ͬʱ�ı�student�е�Info
void amendProjInfo(struct Project* head);
void amendResearch(struct researchAchievement* head);

void sortByGpa(struct Student* head);

