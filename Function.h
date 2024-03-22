#pragma once
#include"main.h"
#include<stdio.h>
struct Student* Search(struct Student* head, int number);//根据学号查找
struct Student* Search(struct Student* head, char name[]);//根据姓名
void InsertStudent(struct Student* head);//收集数据并创建
void InsertMember(struct Member* head);
void InsertComp(struct Competition* head);//以下在函数实现中同时处理student
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
void amendStudentInfo(struct Student* head,int number);//amend包括修改信息和删除
void amendStudentInfo(struct Student* head, char *name);
void amendCurrInfo(struct Curriculum* head);//同时改变student中的Info
void amendProjInfo(struct Project* head);
void amendResearch(struct researchAchievement* head);
void sortByGpa(struct Student* head);

