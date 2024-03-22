#pragma once
#include"main.h"
#include<stdio.h>
struct Student* Search(struct Student* head, int number);//����ѧ�Ų���
struct Student* Search(struct Student* head, char name[]);//��������
void InsertStudent(struct Student* head);//�ռ����ݲ�����
void InsertMember(struct Member* head);
void InsertComp(struct Competition* head);//�����ں���ʵ����ͬʱ����student
void InsertResearch(struct researchAchievement* head);
void InsertCurr(struct Curriculum* head);
void InsertProject(struct Project* head);
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

