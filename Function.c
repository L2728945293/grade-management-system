#define _CRT_SECURE_NO_WARNINGS  1
#include<string.h>
#include<malloc.h>
#include"Function.h"
void Student_Init(struct Student* curr) {
	for (int i = 1; i < 9; i++) {
		curr->term[i] = 0;
		curr->termGPA[i] = 0;
	}
	curr->number = 0;
	curr->gender = -1;
	curr->curriculumNum = 0;
	curr->CurrGpa = 0;
	curr->totalGpa = 0;
	curr->totalRank = 0;
	curr->increaseGPA = 0;
	strcpy(curr->password,"123456");
	curr->unlock = 1;
}

struct Student* Search_number(struct Student* head, int number) {//根据学号查找
	struct Student* curr = head->next;
	while (curr != NULL && curr->number != number) {
		curr = curr->next;
	}
	return curr;
}

struct Teacher* TehSearch_number(struct Teacher* head, int number) {//根据学号查找
	struct Teacher* curr = head->next;
	while (curr != NULL && curr->number != number) {
		curr = curr->next;
	}
	return curr;
}

struct researchAchievement* Search_ach(struct researchAchievement* head, char name[]) {
	struct researchAchievement* curr = head->next;
	while (curr != NULL && strcmp(curr->paperName,name)!=0) {
		curr = curr->next;
	}
	return curr;
}

struct Project* Search_Pro(struct Project* head, char name[]) {
	struct Project* curr = head->next;
	while (curr != NULL && strcmp(curr->name, name) != 0) {
		curr = curr->next;
	}
	return curr;
}

struct Competition* Search_Cmp(struct Competition* head, char name[]) {
	struct Competition* curr = head->next;
	while (curr != NULL && strcmp(curr->name, name) != 0) {
		curr = curr->next;
	}
	return curr;
}

struct Curriculum* Search_cur(struct Curriculum* head, char name[]) {
	struct Curriculum* curr = head->next;
	while (curr != NULL && strcmp(curr->name, name) != 0) {
		curr = curr->next;
	}
	return curr;
}
void InsertStudent0(struct Student* head) {//收集数据并创建 控制台
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	Student_Init(temp);
	printf("请输入学生姓名\n");
	scanf("%s", temp->name);
	printf("请输入学生学号\n");
	scanf("%d", &temp->number);
	struct Student* exist = Search_number(head, temp->number);
	if (exist != NULL) {
		printf("该学生已存在");
		return;
	}
	printf("请输入学生性别(0为女生1为男生)\n");
	scanf("%d", &temp->gender);
	printf("请输入学生的学院\n");
	scanf("%s", temp->college);
	printf("请输入学生的专业\n");
	scanf("%s", temp->major);
	strcpy(temp->password, "123456");
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertStudent1(struct Student* head,FILE* fp) {
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	Student_Init(temp);
	fscanf(fp,"%s %d %d %s %s", temp->name, &temp->number, &temp->gender,temp->college,temp->major);
	strcpy(temp->password, "123456");
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember0(struct Member* head) {//创建member 控制台
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	printf("请输入成员姓名\n");
	scanf("%s", temp->name);
	printf("请输入成员学号\n");
	scanf("%d", &temp->number);
	struct Student* exist = Search_number(head, temp->number);
	if (exist != NULL) {
		printf("该学生已存在");
		return;
	}
	printf("请输入成员排名（-1为没有顺序	0 为通讯作者 1开始为1作 2为2作……）\n");
	scanf("%d", &temp->rank);
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
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	printf("请输入课程名称\n");
	scanf("%s", temp->name);
	printf("请输入课程学分\n");
	scanf("%lf", &temp->credit);
	printf("请输入课程所属学期\n");
	scanf("%d", &temp->term);
	printf("请输入课程得分\n");
	scanf("%lf", &temp->score);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	struct Curriculum* temp1 = Search_cur(head, temp->name);
	if (temp1 == NULL) {
		struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
		strcpy(temp2->name, temp->name);
		temp2->credit = temp->credit;
		temp2->term = temp->term;
		struct Curriculum* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
	}
	calcCurrGpa(curr);
	for (int i = 1; i < 9; i++) calcTermGPA(curr, i);
}

void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp) {//根据学号 文件
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp,"%s %lf %d %lf", temp->name, &temp->credit, &temp->term,&temp->score);
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	struct Curriculum* temp1 = Search_cur(head, temp->name);
	if (temp1 == NULL) {
		struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
		strcpy(temp2->name, temp->name);
		temp2->credit = temp->credit;
		temp2->term = temp->term;
		struct Curriculum* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
	}
	calcCurrGpa(curr);
	for (int i = 1; i < 9; i++) calcTermGPA(curr, i);
}


void InsertComp0_number(struct Competition* head,int number,struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	printf("请输入竞赛名称\n");
	scanf("%s", temp->name);
	printf("请输入竞赛主办方\n");
	scanf("%s", temp->HostName);
	printf("请输入竞赛日期：年 月 日\n");
	scanf("%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("请输入竞赛级别(A or B or C)\n");
	scanf("%c", &temp->grade);
	printf("请输入获奖等级(gold/silver/bronze)\n");
	scanf("%s", temp->rank);
	printf("请输入获奖顺序(-1为没有顺序)\n");
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	scanf("%d", &member->rank);
	member->next = head->head->next;
	head->head->next = member;
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0&&member->rank<=6) temp->increaseGpa += 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)&& member->rank <= 6) temp->increaseGpa += 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0) && member->rank <= 6) temp->increaseGpa += 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) temp->increaseGpa += 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0) && member->rank <= 6) temp->increaseGpa += 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	struct Competition* temp1 = Search_Cmp(head, temp->name);
	if (temp1 == NULL) {
		struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
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
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}


void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	fscanf(fp,"%s %s %d %d %d %c %s %d", temp->name, temp->HostName, &temp->year, &temp->month, &temp->day,&temp->grade,temp->rank,&member->rank);
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = head->head->next;
	head->head->next = member;
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0 && member->rank <= 6) temp->increaseGpa += 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) temp->increaseGpa += 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0) && member->rank <= 6) temp->increaseGpa += 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) temp->increaseGpa += 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0) && member->rank <= 6) temp->increaseGpa += 0.02;
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	struct Competition* temp1 = Search_Cmp(head, temp->name);
	if (temp1 == NULL) {
		struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
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
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}

void InsertProj0_number(struct Project* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	printf("请输入项目名称\n");
	scanf("%s", temp->name);
	printf("请输入指导老师姓名\n");
	scanf("%s", temp->teacherName);
	printf("请输入项目编号\n");
	scanf("%d", &temp->number);
	printf("请输入立项日期： 年 月 日\n");
	scanf("%d %d %d", &temp->year1, &temp->month1, &temp->day1);
	printf("请输入结项日期：年 月 日\n");
	scanf("%d %d %d", &temp->year2, &temp->month2, &temp->day2);
	printf("请输入加分人顺序\n");
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	scanf("%d", &member->rank);
	member->next = head->head->next;
	head->head->next = member;
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	struct Project* temp1 = Search_Pro(head, temp->name);
	if (temp1 == NULL) {
		struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
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
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}

void InsertProj1_number(struct Project* head, int number, struct Student* head_s,FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	fscanf(fp, "%s %s %d %d %d %d %d %d %d", temp->name, temp->teacherName, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2,&member->rank);
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	struct Project* temp1 = Search_Pro(head, temp->name);
	if (temp1 == NULL) {
		struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
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
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}

void InsertResearch0_number(struct researchAchievement* head,int number,struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	printf("请输入论文题目\n");
	scanf("%s", temp->paperName);
	printf("若为期刊请输入1 若为会议请输入2\n");
	scanf("%d", &temp->JorM);
	if (temp->JorM == 1) {
		printf("请输入期刊题目\n");
		scanf("%s", temp->journalName);
	}
	else {
		printf("请输入会议题目\n");
		scanf("%s", temp->meetingName);
	}
	printf("请输入发表时间： 年 月 日 \n");
	scanf("%d %d %d", &temp->year,&temp->month,&temp->day);
	printf("请输入论文级别信息(A/B/C/D/E/F)\n");
	scanf("%c", &temp->level);
	printf("请输入作者顺序（0 为通讯作者 1开始为1作 2为2作……）");
	scanf("%d", &member->rank);
	if (temp->level == 'A'&& member->rank == 1) temp->increaseGpa += 0.4;
	else if (temp->level == 'B' && member->rank == 1) temp->increaseGpa += 0.2;
	else if (temp->level == 'C' && member->rank == 1) temp->increaseGpa += 0.1;
	else if (temp->level == 'D' && member->rank == 1) temp->increaseGpa += 0.05;
	else if (temp->level == 'E' && member->rank == 1) temp->increaseGpa += 0.02;
	else if (temp->level == 'F' && member->rank == 1) temp->increaseGpa += 0.01;
	printf("请输入论文卷、期、论文号、页码范围\n");
	scanf("%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (temp->JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
			temp2->JorM = 1;
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
			temp2->JorM = 0;
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}


void InsertResearch1_number(struct researchAchievement* head, int number, struct Student* head_s,FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	fscanf(fp,"%s", temp->paperName);
	fscanf(fp,"%d", &temp->JorM);
	if (temp->JorM == 1) {
		fscanf(fp,"%s", temp->journalName);
	}
	else {
		fscanf(fp,"%s", temp->meetingName);
	}
	fscanf(fp,"%d %d %d", &temp->year, &temp->month, &temp->day);
	fscanf(fp,"%c", &temp->level);
	fscanf(fp, "%d", &member->rank);
	if (temp->level == 'A' && member->rank == 1) temp->increaseGpa += 0.4;
	else if (temp->level == 'B' && member->rank == 1) temp->increaseGpa += 0.2;
	else if (temp->level == 'C' && member->rank == 1) temp->increaseGpa += 0.1;
	else if (temp->level == 'D' && member->rank == 1) temp->increaseGpa += 0.05;
	else if (temp->level == 'E' && member->rank == 1) temp->increaseGpa += 0.02;
	else if (temp->level == 'F' && member->rank == 1) temp->increaseGpa += 0.01;
	fscanf(fp,"%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (temp->JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
			temp2->JorM = 1;
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
			temp2->JorM = 0;
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp2->head->next;
		temp2->head->next = member2;
	}
	else {
		struct Member* member2 = (struct Member*)malloc(sizeof(struct Member));
		strcpy(member2->name, member->name);
		member2->number = member->number;
		member2->rank = member->rank;
		member2->next = temp1->head->next;
		temp1->head->next = member2;
	}
	calcTotalGpa(curr);
}


void sortByGPA(struct Student* head) {
	if (head->next == NULL) return;
	struct Student* lastSorted = head->next;
	struct Student* curr = head->next->next;
	while (curr != NULL) {
		if (lastSorted->totalGpa >= curr->totalGpa) {
			lastSorted = lastSorted->next;
		}
		else {
			struct Student* pre = head;
			while (pre->next->totalGpa >= curr->totalGpa) {
				pre = pre->next;
			}
			lastSorted->next = curr->next;
			curr->next = pre->next;
			pre->next = curr;
		}
		curr = lastSorted->next;
	}
}

void calcCurrGpa(struct Student* curr) {
	double totalCredit = 0;
	double totalScore = 0;
	struct Curriculum* temp = curr->head_curr->next;
	while (temp != NULL) {
		totalScore += temp->credit * temp->score;
		totalCredit += temp->credit;
		temp = temp->next;
	}
	double CurrGPA = totalScore / totalCredit;
	curr->CurrGpa = CurrGPA;
}

void calcTermGPA(struct Student* curr,int term) {
	struct Curriculum* temp = curr->head_curr->next;
	double totalCredit = 0;
	double totalScore = 0;
	while (temp != NULL) {
		if (temp->term != term) temp = temp->next;
		else {
			totalScore += temp->credit * temp->score;
			totalCredit += temp->credit;
			temp = temp->next;
		}
	}
	double CurrGPA = totalScore / totalCredit;
	curr->termGPA[term] = CurrGPA;
}

void sortByTermGPA(struct Student* head,int term) {
	if (head->next == NULL) return;
	struct Student* lastSorted = head->next;
	struct Student* curr = head->next->next;
	while (curr != NULL) {
		if (lastSorted->termGPA[term] >= curr->termGPA[term]) {
			lastSorted = lastSorted->next;
		}
		else {
			struct Student* pre = head;
			while (pre->next->termGPA[term] >= curr->termGPA[term]) {
				pre = pre->next;
			}
			lastSorted->next = curr->next;
			curr->next = pre->next;
			pre->next = curr;
		}
		curr = lastSorted->next;
	}
}

void sortByRank(struct Member* head) {
	if (head->next == NULL) return;
	struct Member* lastSorted = head->next;
	struct Member* curr = head->next->next;
	while (curr != NULL) {
		if (lastSorted->rank <= curr->rank) {
			lastSorted = lastSorted->next;
		}
		else {
			struct Member* pre = head;
			while (pre->next->rank <= curr->rank) {
				pre = pre->next;
			}
			lastSorted->next = curr->next;
			curr->next = pre->next;
			pre->next = curr;
		}
		curr = lastSorted->next;
	}
}

void rank_Students(struct Student* head) {
	for (int i = 1; i < 9; i++) {
		sortByTermGPA(head, i);
		int rank = 1;
		struct Student* temp = head->next;
		while (temp != NULL) {
			temp->term[i] = rank++;
			temp = temp->next;
		}
	}
	sortByGPA(head);
	int rank = 1;
	struct Student* temp = head->next;
	while (temp != NULL) {
		temp->totalRank = rank++;
		temp = temp->next;
	}
}



void calcTotalGpa(struct Student* curr) {
	if (curr->increaseGPA <= 0.4) curr->totalGpa = curr->CurrGpa + curr->increaseGPA;
	else curr->totalGpa = curr->CurrGpa + 0.4;
}

void deleteStudent(struct Student* head, int number) {
	struct Student* curr = head->next;
	struct Student* pre = head;
	while (curr != NULL && curr->number != number) {
		pre = pre->next;
		curr = curr->next;
	}
	if (curr != NULL) {
		pre->next = curr->next;
		free(curr);
	}
}

void deleteCurriculum(struct Student* head, char name[], struct Curriculum* Currhead) {
	struct Student* temp = head->next;
	while (temp != NULL) {
		struct Curriculum* temp1 = temp->head_curr;
		while (temp1->next != NULL && strcmp(temp1->next->name, name) != 0) {
			temp1 = temp1->next;
		}
		if (temp1->next != NULL) {
			temp1->next = temp1->next->next;
		}
		temp = temp->next;
	}
	struct Curriculum* temp2 = Currhead;
	while (temp2->next != NULL && strcmp(temp2->next->name, name) != 0) {
		temp2 = temp2->next;
	}
	if (temp2->next != NULL) temp2->next = temp2->next->next;
}

void deleteProject(struct Student* head, char name[], struct Project* Prohead) {
	struct Student* temp = head->next;
	while (temp != NULL) {
		struct Project* temp1 = temp->head_pro;
		while (temp1->next != NULL && strcmp(temp1->next->name, name) != 0) {
			temp1 = temp1->next;
		}
		if (temp1->next != NULL) {
			temp1->next = temp1->next->next;
		}
		temp = temp->next;
	}
	struct Project* temp2 = Prohead;
	while (temp2->next != NULL && strcmp(temp2->next->name, name) != 0) {
		temp2 = temp2->next;
	}
	if (temp2->next != NULL) temp2->next = temp2->next->next;
}

void deleteResearch(struct Student* head, char name[], struct researchAchievement* Reshead) {
	struct Student* temp = head->next;
	while (temp != NULL) {
		struct researchAchievement* temp1 = temp->head_ach;
		while (temp1->next != NULL && strcmp(temp1->next->paperName, name) != 0) {
			temp1 = temp1->next;
		}
		if (temp1->next != NULL) {
			temp1->next = temp1->next->next;
		}
		temp = temp->next;
	}
	struct researchAchievement* temp2 = Reshead;
	while (temp2->next != NULL && strcmp(temp2->next->paperName, name) != 0) {
		temp2 = temp2->next;
	}
	if (temp2->next != NULL) temp2->next = temp2->next->next;
}

void deleteCompetition(struct Student* head, char name[], struct Competiton* Cmphead) {
	struct Student* temp = head->next;
	while (temp != NULL) {
		struct Competition* temp1 = temp->head_cmp;
		while (temp1->next != NULL && strcmp(temp1->next->name, name) != 0) {
			temp1 = temp1->next;
		}
		if (temp1->next != NULL) {
			temp1->next = temp1->next->next;
		}
		temp = temp->next;
	}
	struct Competition* temp2 = Cmphead;
	while (temp2->next != NULL && strcmp(temp2->next->name, name) != 0) {
		temp2 = temp2->next;
	}
	if (temp2->next != NULL) temp2->next = temp2->next->next;
}

void printInfo_student(struct Student* head ,struct Student* temp) {
	rank_Students(head);
	printf("姓名：%s\n学院：%s\n专业：%s\n学号：%d\n总排名：%d\n总GPA：%d\n", temp->name, temp->college, temp->major, temp->number, temp->totalRank, temp->totalGpa);
	for (int i = 1; i < 9; i++) {
		printf("第%d学期排名：%d GPA:%d", i, temp->term[i], temp->termGPA[i]);
	}
}

void printInfo_Curr(struct Curriculum* temp) {
	printf("课程名称：%s\n课程学期：%d\n课程学分：%lf\n", temp->name, temp->term, temp->credit);
}

void printInfo_ach(struct researchAchievement* temp) {
	printf("论文名称：%s\n", temp->paperName);
	if (temp->JorM == 1) {
		printf("期刊名：%s\n", temp->journalName);
	}
	else printf("会议名：%s\n", temp->meetingName);
	printf("出版日期：%d年%d月%d日\n", temp->year, temp->month, temp->day);
	printf("卷号：%d\n期号：%d\n论文号：%d\n页码范围：%d - %d\n", temp->reel,temp->period,temp->paperNum,temp->start,temp->end);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		if (curr->rank == 0) {
			printf("通讯作者：%s\n", curr->name);
		}
		else {
			printf("%s ",curr->name);
		}
		curr = curr->next;
	}
	printf("\n");
}

void printInfo_cmp(struct Competition* temp) {
	printf("竞赛名称：%s\n竞赛主办方：%s\n竞赛日期：%d年%d月%d日\n竞赛级别：%c\n竞赛名次%s\n", temp->name, temp->HostName, temp->year, temp->month, temp->day, temp->grade, temp->rank);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		printf("%s ", curr->name);
		curr = curr->next;
	}
	printf("\n");
}

void printInfo_Pro(struct Project* temp) {
	printf("项目名称：%s\n指导老师：%s\n项目编号：%d\n立项日期：%d年%d月%d日\n结项日期：%d年%d月%d日\n", temp->name, temp->teacherName, temp->number, temp->year1, temp->month1, temp->day1, temp->year2, temp->month2, temp->day2);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		printf("%s ", curr->name);
		curr = curr->next;
	}
	printf("\n");
}
void amendCurrInfo(struct Student* curr) {
	printf("选择要修改的课程名称：\n");
	char cuname[30];
	scanf("%s", cuname);
	struct Curriculum* p = Search_cur(curr->head_curr, cuname);
	if (p == NULL) {
		printf("未找到此课程请重试\n");
	}
	else {
		printf("请输入修改的成绩：\n");
		double newscore = 0;
		scanf("%lf", &newscore);
		p->score = newscore;
		printf("修改完毕\n");
	}
	calcCurrGpa(curr);
	calcTotalGpa(curr);
	for (int i = 0; i < 9; i++) calcTermGPA(curr, i);
	return;
}

void amendStudentInfo(struct Student* curr) {
	printf("修改姓名输入1\n修改学号输入2\n修改性别输入3\n修改学院输入4\n修改专业输入5\n解锁密码输入6\n退出输入0\n");
	int x;
	scanf("%d", &x);
	if (x == 0) return;
	else if (x == 1) {
		printf("请输入修改的姓名：\n");
		char newname[30];
		scanf("%s", newname);
		strcpy(curr->name, newname);
		printf("修改完毕\n");
	}
	else if (x == 2) {
		printf("请输入新学号：\n");
		int newnumber = 0;
		scanf("%d", newnumber);
		curr->number = newnumber;
		printf("修改完毕\n");
	}
	else if (x == 3) {
		if (curr->gender == 0) curr->gender = 1;
		else curr->gender = 0;
		printf("性别已修改\n");
	}
	else if (x == 4) {
		printf("请输入新学院：\n");
		char newclg[30];
		scanf("%s", newclg);
		strcpy(curr->college, newclg);
		printf("修改完毕\n");
	}
	else if (x == 5) {
		printf("请输入新专业名称：\n");
		char newmajor[30];
		scanf("%s", newmajor);
		strcpy(curr->major, newmajor);
		printf("修改完毕\n");
	}
	else {
		curr->unlock = 0;
		strcpy(curr->password, "123456");
		printf("修改完毕\n");
	}
}

void operation_teacher(int op,struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead) {
	if (op == 0) {
		printf("新建学生信息请输入0\n新建学生课程信息请输入1\n新建论文信息请输入2\n新建项目信息请输入3\n新建竞赛信息请输入4\n");
		int op1;
		scanf("%d", &op1);
		printf("请选择输入方式\n0为键盘输入\n1为从文件读入\n");
		int way;
		scanf("%d", &way);
		if (op1 == 0 && way == 0) {
			InsertStudent0(Sthead);
			printf("新建成功\n");
		}
		else if (op1 == 0 && way == 1) {
			printf("请输入文件地址\n");
			char address[30];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			InsertStudent1(Sthead, fp);
			printf("新建成功\n");
		}
		else if (op1 == 1 && way == 0) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			InsertCurr0_number(Currhead, number, Sthead);
			printf("新建成功\n");
		}
		else if (op1 == 1 && way == 1) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			printf("请输入文件地址\n");
			char address[30];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			InsertCurr1_number(Currhead, number, Sthead, fp);
			printf("新建成功\n");
		}
		else if (op1 == 2 && way == 0) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			InsertResearch0_number(Achhead, number, Sthead);
			printf("新建成功\n");
		}
		else if (op1 == 2 && way == 1) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			printf("请输入文件地址\n");
			char address[30];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			InsertResearch1_number(Currhead, number, Sthead, fp);
			printf("新建成功\n");
		}
		else if (op1 == 3 && way == 0) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			InsertProj0_number(Achhead, number, Sthead);
			printf("新建成功\n");
		}
		else if (op1 == 3 && way == 1) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			printf("请输入文件地址\n");
			char address[30];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			InsertProj1_number(Currhead, number, Sthead, fp);
			printf("新建成功\n");
		}
		else if (op1 == 4 && way == 0) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			InsertComp0_number(Achhead, number, Sthead);
			printf("新建成功\n");
		}
		else if (op1 == 4 && way == 1) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			printf("请输入文件地址\n");
			char address[30];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			InsertComp1_number(Currhead, number, Sthead, fp);
			printf("新建成功\n");
		}
	}
	else if (op == 1) {
		printf("删除学生信息请输入0\n删除课程信息请输入1\n删除论文信息请输入2\n删除项目信息请输入3\n删除竞赛信息请输入4\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) {
			printf("请输入要删除学生的学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			deleteStudent(Sthead, number);
			printf("删除成功\n");
		}
		else if (op1 == 1) {
			printf("请输入要删除课程名称\n");
			char name[30];
			scanf("%s", name);
			struct Curriculum* temp = Search_cur(Currhead, name);
			if (temp == NULL) {
				printf("不存在该课程\n");
				return;
			}
			deleteCurriculum(Sthead, name, Currhead);
			printf("删除成功\n");
		}
		else if (op1 == 2) {
			printf("请输入要删除论文名称\n");
			char name[30];
			scanf("%s", name);
			struct researchAchievement* temp = Search_ach(Achhead, name);
			if (temp == NULL) {
				printf("不存在该论文\n");
				return;
			}
			deleteResearch(Sthead, name, Achhead);
			printf("删除成功\n");
		}
		else if (op1 == 3) {
			printf("请输入要删除项目名称\n");
			char name[30];
			scanf("%s", name);
			struct Project* temp = Search_Pro(Prohead, name);
			if (temp == NULL) {
				printf("不存在该项目\n");
				return;
			}
			deleteCurriculum(Sthead, name, Prohead);
			printf("删除成功\n");
		}
		else if (op1 == 4) {
			printf("请输入要删除竞赛名称\n");
			char name[30];
			scanf("%s", name);
			struct Competition* temp = Search_Cmp(Cmphead, name);
			if (temp == NULL) {
				printf("不存在该竞赛\n");
				return;
			}
			deleteCompetition(Sthead, name, Cmphead);
			printf("删除成功\n");
		}
	}
	else if (op == 2) {
		printf("请输入要修改信息的学生的学号\n");
		int number;
		scanf("%d", &number);
		struct Student* temp = Search_number(Sthead, number);
		if (temp == NULL) {
			printf("该学生不存在\n");
			return;
		}
		printf("修改学生信息请输入0\n课程分数请输入1\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) amendStudentInfo(temp);
		else if (op1 == 1) amendCurrInfo(temp);
	}
	else if (op == 3) {
		printf("查询学生信息请输入0\n查询课程信息请输入1\n查询论文信息请输入2\n查询项目信息请输入3\n查询竞赛信息请输入4\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) {
			printf("请输入学生学号\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("该学生不存在\n");
				return;
			}
			printInfo_student(Sthead,temp);
		}
		else if (op1 == 1) {
			printf("请输入课程名称\n");
			char name[30];
			scanf("%s", name);
			struct Curriculum* temp = Search_cur(Currhead, name);
			if (temp == NULL) {
				printf("该课程不存在\n");
				return;
			}
			printInfo_Curr(temp);
		}
		else if (op1 == 2) {
			printf("请输入论文名称\n");
			char name[30];
			scanf("%s", name);
			struct researchAchievement* temp = Search_ach(Achhead, name);
			if (temp == NULL) {
				printf("该论文不存在\n");
				return;
			}
			printInfo_ach(temp);
		}
		else if (op1 == 3) {
			printf("请输入项目名称\n");
			char name[30];
			scanf("%s", name);
			struct Project* temp = Search_Pro(Prohead, name);
			if (temp == NULL) {
				printf("该项目不存在\n");
				return;
			}
			printInfo_Pro(temp);
		}
		else if (op1 == 4) {
			printf("请输入竞赛名称\n");
			char name[30];
			scanf("%s", name);
			struct Competition* temp = Search_Cmp(Cmphead, name);
			if (temp == NULL) {
				printf("该竞赛不存在\n");
				return;
			}
			printInfo_cmp(temp);
		}
	}
	else return;;
}
void StuchangePassword(struct Student* s) {
	char newPassword[20];
	char confirmPassword[20];
	printf("请输入新密码：");
	scanf("%s", newPassword);
	printf("请再次输入新密码：");
	scanf("%s", confirmPassword);
	while (1) {
		if (strcmp(newPassword, confirmPassword) != 0) {
			printf("两次输入密码不一致\n");
		}
		else {
			strcpy(s->password, newPassword);
			printf("密码修改成功\n");
			break;
		}
	}
	return;
}

void TechchangePassword(struct Teacher* s) {
	char newPassword[20];
	char confirmPassword[20];
	while (1) {
		printf("请输入新密码：");
		scanf("%s", newPassword);
		printf("请再次输入新密码：");
		scanf("%s", confirmPassword);
		if (strcmp(newPassword, confirmPassword) != 0) {
			printf("两次输入密码不一致\n");
		}
		else {
			strcpy(s->password, newPassword);
			printf("密码修改成功\n");
			break;
		}
	}
	return;
}

void Tehsignup(struct Teacher* head) {
	int numbeript = 0;
	char passwordipt[20];
	struct Teacher* s = (struct Teacher*)malloc(sizeof(struct Teacher));
	struct Teacher* p = NULL;
	printf("请输入注册的教师号：\n");
	while (1) {
		scanf("%d", &numbeript);
		p = TehSearch_number(head, numbeript);
		if (p == NULL) {
			s->number = numbeript;
			printf("请设置登录密码：\n");
			scanf("%s", passwordipt);
			strcpy(s->password, passwordipt);
			s->next = head->next;
			head->next = s;
			printf("注册成功\n");
			break;
		}
		else {
			printf("此教师号已被注册请重试\n");
		}
	}
}

void studentlogin(struct Student* head) {
	int numberinput = 0;
	char passwordinput[20];
	int logintimes = 0;
	int idexit = 0;
	struct Student* p = NULL;
	printf("请输入学号: ");
	while (1) {
		scanf("%d", &numberinput);
		p = Search_number(head, numberinput);
		if (p == NULL) printf("\n无此学号学生，请重新输入学号: \n");
		else { break; }
	}
	if (p->unlock == 0) {
		printf("您的账号已被封锁，请联系老师解锁\n");
	}
	else {
		printf("请输入密码: \n");
		while (1) {
			scanf("%s", passwordinput);
			if (strcmp(p->password, passwordinput) == 0) {
				int x;
				while (1) {
					printf("查询信息请输入0\n修改密码请输入1\n退出请输入2\n");
					scanf("%d", &x);
					if (x == 0) {
						printf("姓名：%s ,性别：%d, 学号：%d ,专业：%s ,总排名：%d", p->name, p->gender, p->number, p->major, p->totalRank);
						printf(" 总GPA：%f\n", p->totalGpa);
						for (int i = 1; i < 9; i++) {
							printf("第%d学期排名为 %d：",i, p->term[i]);
						}
					}
					else if (x == 1) StuchangePassword(p);
					else {
						break;
					}
				}
				break;
			}
			else {
				logintimes++;
				if (logintimes >= 5) {
					printf("失败次数过多已自动锁定请联系老师进行解锁\n");
					p->unlock = 0;
					break;
				}
				printf("密码输入错误请重新输入(还剩%d此机会)\n",(5-logintimes));
			}
		}
	}
}

void teacherlogin(struct Teacher* head, struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead) {
	int numberinput = 0;
	char passwordinput[20];
	struct Teacher* p = NULL;
	printf("请输入教师号: \n");
	while (1) {
		scanf("%d", &numberinput);
		p = TehSearch_number(head, numberinput);
		if (p == NULL) {
			printf("没有此教师\n");
			printf("注册：请输入0\n重新登录：请输入1\n");
			int choose;
			scanf("%d", &choose);
			if (choose == 0) Tehsignup(head);
			if (choose == 1)teacherlogin(head,Sthead,Currhead,Achhead,Prohead,Cmphead);
			return;
		}
		else { break; }
	}
	printf("请输入密码: \n");
	while (1) {
		scanf("%s", passwordinput);
		if (strcmp(p->password, passwordinput) == 0) {
			int x = 0;
			printf("登录成功\n");
			while (1) {
				printf("管理学生信息请输入0\n修改密码请输入1\n退出请输入2\n");
				scanf("%d", &x);
				if (x == 0) {
					while (1) {
						printf("新建信息请输入0\n删除信息请输入1\n修改信息请输入2\n查询信息请输入3\n退出请输入4\n");
						int op;
						scanf("%d", &op);
						if (op == 4) break;
						operation_teacher(op, Sthead, Currhead,Achhead,Prohead,Cmphead);
					}
				}
				else if (x == 1) TechchangePassword(p);
				else { break; }
			}
			break;
		}
		else {
			printf("密码输入错误请重试\n");
		}
	}
}
