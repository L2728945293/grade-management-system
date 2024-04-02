#pragma once
#include<stdio.h>
#include"main.h"
struct Student* Search_number(struct Student* head, int number);//根据学号查找
struct Student* Search_name(struct Student* head, char name[]);//根据姓名
struct Teacher* TehSearch_number(struct Teacher* head, int number);

struct researchAchievement* Search_ach(struct researchAchievement* head, char name[]);
struct Project* Search_Pro(struct Project* head, char name[]);
struct Competition* Search_Cmp(struct Competition* head, char name[]);
struct Curriculum* Search_cur(struct Curriculum* head, char name[]);

void InsertStudent0(struct Student* head);//收集数据并创建  控制台
void InsertStudent1(struct Student* head,FILE* fp);//收集数据并创建  文件
void InsertMember0(struct Member* head);
void InsertMember1(struct Member* head,FILE* fp);
//以下在函数实现中同时处理student
void InsertCurr0_number(struct Curriculum* head, int number, struct Student* head_s);
void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp);

void InsertComp0_number(struct Competition* head, int number, struct Student* head_s);
void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp);

void InsertProj0_number(struct Project* head, int number, struct Student* head_s);
void InsertProj1_number(struct Project* head, int number, struct Student* head_s, FILE* fp);

void InsertResearch0_number(struct researchAchievement* head, int number, struct Student* head_s);
void InsertResearch1_number(struct researchAchievement* head, int number, struct Student* head_s, FILE* fp);

void getCompetition_student(struct Student* curr);
void getResearch_student(struct Student* curr);
void getProject_student(struct Student* curr);

void calcCurrGpa(struct Student* curr);
void calcTotalGpa(struct Student* curr);
void calcTermGPA(struct Student* curr, int term);

void sortByGPA(struct Student* head);
void sortByTermGPA(struct Student* head, int term);
void rank_Students(struct Student* head);
void sortByRank(struct Member* head);

void amendStudentInfo(struct Student* head, int number);//amend包括修改信息和删除
void amendCurrInfo(struct Curriculum* head);//同时改变student中的Info
void amendProjInfo(struct Project* head);
void amendResearch(struct researchAchievement* head);

void deleteStudent(struct Student* head,int number);
void deleteResearch(struct Student* head, char name[], struct researchAchievement* Reshead);
void deleteCompetition(struct Student* head, char name[], struct Competiton* Cmphead);
void deleteProject(struct Student* head, char name[], struct Project* Prohead);
void deleteCurriculum(struct Student* head, char name[], struct Curriculum* Currhead);

void StuchangePassword(struct Student* s);
void TechchangePassword(struct Teacher* s);
void Tehsignup(struct Teacher* head);
void studentlogin(struct Student* head);
void teacherlogin(struct Teacher* head, struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead);

void opeartion_teacher(int op, struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead);


void printInfo_student(struct Student* temp);
void printInfo_Curr(struct Curriculum* temp);
void printInfo_ach(struct researchAchievement* temp);
void printInfo_cmp(struct Competition* temp);
void printInfo_Pro(struct Project* temp);