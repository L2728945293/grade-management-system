#define _CRT_SECURE_NO_WARNINGS  1
#include"Function.h"
#include<string.h>
#include<malloc.h>
struct Student* Search_number(struct Student* head, int number) {//根据学号查找
	struct Student* curr = head;
	while (curr->next != NULL && curr->number != number) {
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("Not Found."); return NULL;
	}
	else return curr;
}

struct Student* Search_name(struct Student* head, char name[]) {//根据姓名查找
	struct Student* curr = head;
	while (curr->next != NULL && strcmp(curr->name,name) != 0 ) {
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("Not Found."); return NULL;
	}
	else return curr;
}

void InsertStudent0(struct Student* head) {//收集数据并创建 控制台
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	scanf("请输入学生姓名%s", temp->name);
	scanf("请输入学生学号%d", &temp->number);
	scanf("请输入学生性别%d(0为女生1为男生)", &temp->gender);
	scanf("请输入学生的学院%s", temp->college);
	scanf("请输入学生的专业%s", temp->major);
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertStudent1(struct Student* head,FILE* fp) {
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	fscanf(fp,"%s %d %d %s %s", temp->name, &temp->number, &temp->gender,temp->college,temp->major);
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember0(struct Member* head) {//创建member 控制台
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	scanf("请输入学生姓名%s", temp->name);
	scanf("请输入学生学号%d", &temp->number);
	scanf("请输入学生排名%d（-1为没有顺序	0 为通讯作者 1开始为1作 2为2作……）", &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember1(struct Member* head, FILE* fp) {//创建member 文件
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	fscanf(fp,"%s %d %d", temp->name, &temp->number, &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertCurr0_number(struct Curriculum* head,int number,struct Student* head_s) {//根据学号 控制台
	struct Student* curr = Search_number(head_s, number);
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	scanf("请输入课程名称%s", temp->name);
	scanf("请输入课程学分%lf", &temp->credit);
	scanf("请输入课程所属学期%d", &temp->term);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	temp2->credit = temp->credit;
	temp2->term = temp->term;
	struct Curriculum* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
}

void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp) {//根据学号 文件
	struct Student* curr = Search_number(head_s, number);
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp,"%s %lf %d", temp->name, &temp->credit, &temp->term);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	temp2->credit = temp->credit;
	temp2->term = temp->term;
	struct Curriculum* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
}

void InsertCurr0_name(struct Curriculum* head, char name[], struct Student* head_s) {//根据姓名 控制台
	struct Student* curr = Search_name(head_s, name);
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	scanf("请输入课程名称%s", temp->name);
	scanf("请输入课程学分%lf", &temp->credit);
	scanf("请输入课程所属学期%d", &temp->term);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	temp2->credit = temp->credit;
	temp2->term = temp->term;
	struct Curriculum* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
}

void InsertCurr1_name(struct Curriculum* head, char name[], struct Student* head_s, FILE* fp) {//根据学号 文件
	struct Student* curr = Search_name(head_s, name);
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp,"%s %lf %d", temp->name, &temp->credit, &temp->term);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	temp2->credit = temp->credit;
	temp2->term = temp->term;
	struct Curriculum* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
}

void InsertComp0_number(struct Competition* head,int number,struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
	scanf("请输入竞赛名称%s", temp->name);
	scanf("请输入竞赛主办方%s", temp->HostName);
	scanf("请输入竞赛日期：%d年%d月%d日", &temp->year,&temp->month,&temp->day);
	scanf("请输入竞赛级别%c(A or B or C)", &temp->grade);
	scanf("请输入获奖等级%s(gold/silver/bronze)", temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->HostName, temp->HostName);
	strcpy(temp2->rank, temp->rank);
	temp2->grade = temp->grade;
	temp2->year = temp->year;
	temp2->month = temp->month;
	temp2->day = temp->day;
	struct Competition* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember0(temp2->head);
}

void InsertComp0_name(struct Competition* head, char name[], struct Student* head_s ) {
	struct Student* curr = Search_name(head_s, name);
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
	scanf("请输入竞赛名称%s", temp->name);
	scanf("请输入竞赛主办方%s", temp->HostName);
	scanf("请输入竞赛日期：%d年%d月%d日", &temp->year, &temp->month, &temp->day);
	scanf("请输入竞赛级别%c(A or B or C)", &temp->grade);
	scanf("请输入获奖等级%s(gold/silver/bronze)", temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->HostName, temp->HostName);
	strcpy(temp2->rank, temp->rank);
	temp2->grade = temp->grade;
	temp2->year = temp->year;
	temp2->month = temp->month;
	temp2->day = temp->day;
	struct Competition* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember0(temp2->head);
}

void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
	fscanf(fp,"%s %s %d %d %d %c %s", temp->name, temp->HostName, &temp->year, &temp->month, &temp->day,&temp->grade,temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->HostName, temp->HostName);
	strcpy(temp2->rank, temp->rank);
	temp2->grade = temp->grade;
	temp2->year = temp->year;
	temp2->month = temp->month;
	temp2->day = temp->day;
	struct Competition* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember1(temp2->head, fp);
}

void InsertComp1_name(struct Competition* head, char name[], struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_name(head_s, name);
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
	fscanf(fp,"%s %s %d %d %d %c %s", temp->name, temp->HostName, &temp->year, &temp->month, &temp->day, &temp->grade, temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->HostName, temp->HostName);
	strcpy(temp2->rank, temp->rank);
	temp2->grade = temp->grade;
	temp2->year = temp->year;
	temp2->month = temp->month;
	temp2->day = temp->day;
	struct Competition* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember1(temp2->head, fp);
}

void InsertProj0_number(struct Project* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
	scanf("请输入项目名称%s", temp->name);
	scanf("请输入指导老师姓名%s", temp->teacherName);
	scanf("请输入项目编号%d", &temp->number);
	scanf("请输入立项日期：%d年%d月%d日", &temp->year1, &temp->month1, &temp->day1);
	scanf("请输入结项日期：%d年%d月%d日", &temp->year2, &temp->month2, &temp->day2);
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->teacherName, temp->teacherName);
	temp2->number = temp->number;
	temp2->year1 = temp->year1;
	temp2->month1 = temp->month1;
	temp2->day1 = temp->day1;
	temp2->year2 = temp->year2;
	temp2->month2 = temp->month2;
	temp2->day2 = temp->day2;
	struct Project* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember0(temp2->head);
}

void InsertProj0_name(struct Project* head, char name[], struct Student* head_s) {
	struct Student* curr = Search_name(head_s, name);
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
	scanf("请输入项目名称%s", temp->name);
	scanf("请输入指导老师姓名%s", temp->teacherName);
	scanf("请输入项目编号%d", &temp->number);
	scanf("请输入立项日期：%d年%d月%d日", &temp->year1, &temp->month1, &temp->day1);
	scanf("请输入结项日期：%d年%d月%d日", &temp->year2, &temp->month2, &temp->day2);
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->teacherName, temp->teacherName);
	temp2->number = temp->number;
	temp2->year1 = temp->year1;
	temp2->month1 = temp->month1;
	temp2->day1 = temp->day1;
	temp2->year2 = temp->year2;
	temp2->month2 = temp->month2;
	temp2->day2 = temp->day2;
	struct Project* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember0(temp2->head);
}

void InsertProj1_number(struct Project* head, int number, struct Student* head_s,FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
	fscanf(fp, "%s %s %d %d %d %d %d %d", temp->name, temp->teacherName, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2);
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->teacherName, temp->teacherName);
	temp2->number = temp->number;
	temp2->year1 = temp->year1;
	temp2->month1 = temp->month1;
	temp2->day1 = temp->day1;
	temp2->year2 = temp->year2;
	temp2->month2 = temp->month2;
	temp2->day2 = temp->day2;
	struct Project* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember1(temp2->head,fp);
}

void InsertProj1_name(struct Project* head, char name[], struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_name(head_s, name);
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
	fscanf(fp, "%s %s %d %d %d %d %d %d", temp->name, temp->teacherName, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2);
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	strcpy(temp2->name, temp->name);
	strcpy(temp2->teacherName, temp->teacherName);
	temp2->number = temp->number;
	temp2->year1 = temp->year1;
	temp2->month1 = temp->month1;
	temp2->day1 = temp->day1;
	temp2->year2 = temp->year2;
	temp2->month2 = temp->month2;
	temp2->day2 = temp->day2;
	struct Project* temp2_n = head->next;
	head->next = temp2;
	temp2->next = temp2_n;
	InsertMember1(temp2->head, fp);
}

void InsertResearch0(struct researchAchievement* head) {

}