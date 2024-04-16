#define _CRT_SECURE_NO_WARNINGS  1
#include<string.h>
#include<malloc.h>
#include"Function.h"
void Student_Init(struct Student* curr) {
	for (int i = 1; i < 9; i++) {
		curr->term[i] = 0;
		curr->termGPA[i] = 0;
	}
	curr->head_ach = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	curr->head_ach->next = NULL;
	curr->head_curr = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	curr->head_curr->next = NULL;
	curr->head_cmp = (struct Competition*)malloc(sizeof(struct Competition));
	curr->head_cmp->next = NULL;
	curr->head_pro = (struct Project*)malloc(sizeof(struct Project));
	curr->head_pro->next = NULL;
	curr->number = 0;
	curr->gender = -1;
	curr->curriculumNum = 0;
	curr->CurrGpa = 0;
	curr->totalGpa = 0;
	curr->totalRank = 0;
	curr->increaseGPA = 0;
	strcpy(curr->password, "123456");
	curr->unlock = 1;
}


struct Student* Search_number(struct Student* head, int number) {//����ѧ�Ų���
	struct Student* curr = head->next;
	while (curr != NULL && curr->number != number) {
		curr = curr->next;
	}
	return curr;
}

struct Teacher* TehSearch_number(struct Teacher* head, int number) {//����ѧ�Ų���
	struct Teacher* curr = head->next;
	while (curr != NULL && curr->number != number) {
		curr = curr->next;
	}
	return curr;
}

struct researchAchievement* Search_ach(struct researchAchievement* head, char name[]) {
	struct researchAchievement* curr = head->next;
	while (curr != NULL && strcmp(curr->paperName, name) != 0) {
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
void InsertStudent0(struct Student* head) {//�ռ����ݲ����� ����̨
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	Student_Init(temp);
	printf("------������ѧ������------\n");
	scanf("%s", temp->name);
	printf("------������ѧ��ѧ��------\n");
	scanf("%d", &temp->number);
	struct Student* exist = Search_number(head, temp->number);
	if (exist != NULL) {
		printf("------ѧ��Ϊ%d��ѧ���Ѵ���------\n", temp->number);
		return;
	}
	printf("------������ѧ���Ա�(0ΪŮ��1Ϊ����)------\n");
	scanf("%d", &temp->gender);
	printf("------������ѧ����ѧԺ------\n");
	scanf("%s", temp->college);
	printf("------������ѧ����רҵ------\n");
	scanf("%s", temp->major);
	strcpy(temp->password, "123456");
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertStudent1(struct Student* head, FILE* fp) {
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	Student_Init(temp);
	fscanf(fp, "%s %d %d %s %s", temp->name, &temp->number, &temp->gender, temp->college, temp->major);
	struct Student* exist = Search_number(head, temp->number);
	if (exist != NULL) {
		printf("------ѧ��Ϊ%d��ѧ���Ѵ���------\n",temp->number);
		return;
	}
	strcpy(temp->password, "123456");
	struct Student* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember0(struct Member* head) {//����member ����̨
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	printf("------�������Ա����------\n");
	scanf("%s", temp->name);
	printf("------�������Աѧ��------\n");
	scanf("%d", &temp->number);
	struct Student* exist = Search_number(head, temp->number);
	if (exist != NULL) {
		printf("------��ѧ���Ѵ���------\n");
		return;
	}
	printf("------�������Ա������-1Ϊû��˳��	0 ΪͨѶ���� 1��ʼΪ1�� 2Ϊ2��������------\n");
	scanf("%d", &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember1(struct Member* head, FILE* fp) {//����member �ļ�
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	fscanf(fp, "%s %d %d", temp->name, &temp->number, &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertCurr0_number(struct Curriculum* head, int number, struct Student* head_s) {//����ѧ�� ����̨
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	printf("------������γ�����------\n");
	scanf("%s", temp->name);
	struct Curriculum* find = Search_cur(curr->head_curr, temp->name);
	if (find != NULL)
	{
		printf("------�ÿγ��Ѿ�����------\n");
		return;
	}
	printf("------������γ�ѧ��------\n");
	scanf("%lf", &temp->credit);
	printf("------������γ�����ѧ��------\n");
	scanf("%d", &temp->term);
	printf("------������γ̵÷�------\n");
	scanf("%lf", &temp->score);
	if (temp->score >= 90) {
		temp->grade = 4;
	}
	else if (temp->score < 60) temp->grade = 0;
	else {
		temp->grade = (temp->score - 50) / 10.0;
	}
	struct Curriculum* temp_n = curr->head_curr->next;
	curr->head_curr->next = temp;
	temp->next = temp_n;
	struct Curriculum* temp1 = Search_cur(head, temp->name);
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	if (temp1 == NULL) {//�ܿγ��б��ﻹû�иÿγ̵ļ�¼
		struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
		for (int i = 0; i < 5; i++)
			temp2->num[i] = 0;//������������ʼ��
		if (temp->score >= 90)
			temp2->num[4]++;
		else if (temp->score < 90 && temp->score >= 80)
			temp2->num[3]++;
		else if (temp->score < 80 && temp->score >= 70)
			temp2->num[2]++;
		else if (temp->score < 70 && temp->score >= 60)
			temp2->num[1]++;
		else temp2->num[0]++;
		strcpy(temp2->name, temp->name);
		temp2->credit = temp->credit;
		temp2->term = temp->term;
		struct Curriculum* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		if (temp->score >= 90)
			temp1->num[4]++;
		else if (temp->score < 90 && temp->score >= 80)
			temp1->num[3]++;
		else if (temp->score < 80 && temp->score >= 70)
			temp1->num[2]++;
		else if (temp->score < 70 && temp->score >= 60)
			temp1->num[1]++;
		else temp1->num[0]++;
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcCurrGpa(curr);
	for (int i = 1; i < 9; i++) calcTermGPA(curr, i);
}

void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp) {//����ѧ�� �ļ�
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp, "%s", temp->name);
	struct Curriculum* find = Search_cur(curr->head_curr, temp->name);
	if (find != NULL)
	{
		printf("------�ÿγ��Ѿ�����------\n");
		fclose(fp);
		return;
	}
	fscanf(fp, "%lf %d %lf", &temp->credit, &temp->term, &temp->score);
	if (temp->score >= 90) {
		temp->grade = 4;
	}
	else if (temp->score < 60) temp->grade = 0;
	else {
		temp->grade = (temp->score - 50) / 10.0;
	}
	temp->next = curr->head_curr->next;
	curr->head_curr->next = temp;
	struct Curriculum* temp1 = Search_cur(head, temp->name);
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	if (temp1 == NULL) {//�ܿγ��б��ﻹû�иÿγ̵ļ�¼
		struct Curriculum* temp2 = (struct Curriculum*)malloc(sizeof(struct Curriculum));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
		for (int i = 0; i < 5; i++)
			temp2->num[i] = 0;//������������ʼ��
		if (temp->score >= 90)
			temp2->num[4]++;
		else if (temp->score < 90 && temp->score >= 80)
			temp2->num[3]++;
		else if (temp->score < 80 && temp->score >= 70)
			temp2->num[2]++;
		else if (temp->score < 70 && temp->score >= 60)
			temp2->num[1]++;
		else temp2->num[0]++;
		strcpy(temp2->name, temp->name);
		temp2->credit = temp->credit;
		temp2->term = temp->term;
		struct Curriculum* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		if (temp->score >= 90)
			temp1->num[4]++;
		else if (temp->score < 90 && temp->score >= 80)
			temp1->num[3]++;
		else if (temp->score < 80 && temp->score >= 70)
			temp1->num[2]++;
		else if (temp->score < 70 && temp->score >= 60)
			temp1->num[1]++;
		else temp1->num[0]++;
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcCurrGpa(curr);
	for (int i = 1; i < 9; i++) calcTermGPA(curr, i);
}


void InsertComp0_number(struct Competition* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	printf("------�����뾺������------\n");
	scanf("%s", temp->name);
	struct Competition* find = Search_Cmp(curr->head_cmp, temp->name);
	if (find != NULL) {
		printf("�þ����Ѵ���\n");
		return;
	}
	printf("------�����뾺�����췽------\n");
	scanf("%s", temp->HostName);
	printf("------�����뾺�����ڣ��� �� ��------\n");
	scanf("%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("------�����뾺������(A or B or C)------\n");
	scanf("%c", &temp->grade);
	while (temp->grade != 'A' && temp->grade != 'B' && temp->grade != 'C')
		scanf("%c", &temp->grade);
	printf("------������񽱵ȼ�(gold/silver/bronze)------\n");
	scanf("%s", temp->rank);
	printf("------�������˳��(-1Ϊû��˳��)------\n");
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	scanf("%d", &member->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0 && member->rank <= 6) {
		temp->increaseGpa = 0.4; curr->increaseGPA += 0.4;
	}
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) {
		temp->increaseGpa = 0.2;
		curr->increaseGPA += 0.2;
	}
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0) && member->rank <= 6) { temp->increaseGpa = 0.1; curr->increaseGPA += 0.1; }
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) { temp->increaseGpa = 0.05; curr->increaseGPA += 0.05; }
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0) && member->rank <= 6) {
		temp->increaseGpa = 0.02;
		curr->increaseGPA += 0.02;
	}
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	struct Competition* temp1 = Search_Cmp(head, temp->name);
	if (temp1 == NULL) {
		struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcTotalGpa(curr);
}


void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	fscanf(fp,"%s", temp->name);
	struct Competition* find = Search_Cmp(curr->head_cmp, temp->name);
	if (find != NULL) {
		printf("�þ����Ѵ���\n");
		fclose(fp);
		return;
	}
	fscanf(fp, "%s %d %d %d", temp->HostName, &temp->year, &temp->month, &temp->day);
	fscanf(fp, "%c", &temp->grade);
	while (temp->grade != 'A' && temp->grade != 'B' && temp->grade != 'C')
		fscanf(fp,"%c", &temp->grade);
	fscanf(fp, " %s %d", temp->rank, &member->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0 && member->rank <= 6) {
		temp->increaseGpa = 0.4; curr->increaseGPA += 0.4;
	}
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) {
		temp->increaseGpa = 0.2;
		curr->increaseGPA += 0.2;
	}
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0) && member->rank <= 6) { temp->increaseGpa = 0.1; curr->increaseGPA += 0.1; }
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0) && member->rank <= 6) { temp->increaseGpa = 0.05; curr->increaseGPA += 0.05; }
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0) && member->rank <= 6) {
		temp->increaseGpa = 0.02;
		curr->increaseGPA += 0.02;
	}
	struct Competition* temp_n = curr->head_cmp->next;
	curr->head_cmp->next = temp;
	temp->next = temp_n;
	struct Competition* temp1 = Search_Cmp(head, temp->name);
	if (temp1 == NULL) {
		struct Competition* temp2 = (struct Competition*)malloc(sizeof(struct Competition));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcTotalGpa(curr);
}

void InsertProj0_number(struct Project* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	printf("------��������Ŀ����------\n");
	scanf("%s", temp->name);
	struct Project* find = Search_Pro(curr->head_pro, temp->name);
	if (find != NULL)
	{
		printf("����Ŀ�Ѵ���\n");
		return;
	}
	printf("------������ָ����ʦ����------\n");
	scanf("%s", temp->teacherName);
	printf("------��������Ŀ���------\n");
	scanf("%d", &temp->number);
	printf("------�������������ڣ� �� �� ��------\n");
	scanf("%d %d %d", &temp->year1, &temp->month1, &temp->day1);
	printf("------������������ڣ��� �� ��------\n");
	scanf("%d %d %d", &temp->year2, &temp->month2, &temp->day2);
	printf("------������ӷ���˳��------\n");
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	scanf("%d", &member->rank);
	if (member->rank == 1) curr->increaseGPA += 0.1;
	else if (member->rank == 2) curr->increaseGPA += 0.2;
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	struct Project* temp1 = Search_Pro(head, temp->name);
	if (temp1 == NULL) {
		struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcTotalGpa(curr);
}

void InsertProj1_number(struct Project* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	fscanf(fp, "%s", temp->name);
	struct Project* find = Search_Pro(curr->head_pro, temp->name);
	if (find != NULL)
	{
		printf("����Ŀ�Ѵ���\n");
		fclose(fp);
		return;
	}
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	fscanf(fp, "%s %d %d %d %d %d %d %d %d", temp->teacherName,&temp->number, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2, &member->rank);
	if (member->rank == 1) curr->increaseGPA += 0.1;
	else if (member->rank == 2) curr->increaseGPA += 0.2;
	struct Project* temp_n = curr->head_pro->next;
	curr->head_pro->next = temp;
	temp->next = temp_n;
	struct Project* temp1 = Search_Pro(head, temp->name);
	if (temp1 == NULL) {
		struct Project* temp2 = (struct Project*)malloc(sizeof(struct Project));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcTotalGpa(curr);
}

void InsertResearch0_number(struct researchAchievement* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	printf("------������������Ŀ------\n");
	scanf("%s", temp->paperName);
	struct researchAchievement* find = Search_ach(curr->head_ach, temp->paperName);
	if (find != NULL)
	{
		printf("�������Ѵ���\n");
		return;
	}
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	printf("------��Ϊ�ڿ�������1 ��Ϊ����������2------\n");
	scanf("%d", &temp->JorM);
	if (temp->JorM == 1) {
		printf("------�������ڿ���Ŀ------\n");
		scanf("%s", temp->journalName);
		//printf("%s", temp->journalName);
	}
	else {
		printf("------�����������Ŀ------\n");
		scanf("%s", temp->meetingName);
		//printf("%s", temp->meetingName);
	}
	printf("------�����뷢��ʱ�䣺 �� �� �� ------\n");
	scanf("%d", &temp->year);
	scanf("%d", &temp->month);
	scanf("%d", &temp->day);
	printf("------���������ļ�����Ϣ(A/B/C/D/E/F)------\n");
	scanf("%c", &temp->level);
	while (temp->level != 'A' && temp->level != 'B' && temp->level != 'C' && temp->level != 'D' && temp->level != 'E' && temp->level != 'F')
		scanf("%c", &temp->level);
	printf("------����������˳��0 ΪͨѶ���� 1��ʼΪ1�� 2Ϊ2��������------\n");
	scanf("%d", &member->rank);
	if (temp->level == 'A' && member->rank == 1) {
		temp->increaseGpa = 0.4; curr->increaseGPA += 0.4;
	}
	else if (temp->level == 'B' && member->rank == 1) {
		temp->increaseGpa = 0.2; curr->increaseGPA += 0.2;
	}
	else if (temp->level == 'C' && member->rank == 1) {
		temp->increaseGpa = 0.1; curr->increaseGPA += 0.1;
	}
	else if (temp->level == 'D' && member->rank == 1) {
		temp->increaseGpa = 0.05; curr->increaseGPA += 0.05;
	}
	else if (temp->level == 'E' && member->rank == 1) {
		temp->increaseGpa = 0.02; curr->increaseGPA += 0.02;
	}
	else if (temp->level == 'F' && member->rank == 1) {
		temp->increaseGpa = 0.01; curr->increaseGPA += 0.01;
	}
	printf("------���������ľ��ڡ����ĺš�ҳ�뷶Χ------\n");
	scanf("%d %d %d %d %d", &temp->reel,&temp->period,&temp->paperNum,&temp->start,&temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->paperNum = temp->paperNum; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
	}
	calcTotalGpa(curr);
}


void InsertResearch1_number(struct researchAchievement* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) {
		printf("------δ�ҵ���ѧ��------\n");
		return;
	}
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	
	fscanf(fp, "%s", temp->paperName);
	struct researchAchievement* find = Search_ach(curr->head_ach, temp->paperName);
	if (find != NULL)
	{
		printf("�������Ѵ���\n");
		fclose(fp);
		return;
	}
	struct Member* member = (struct Member*)malloc(sizeof(struct Member));
	strcpy(member->name, curr->name);
	member->number = curr->number;
	member->next = NULL;
	fscanf(fp, "%d", &temp->JorM);
	printf("%d", temp->JorM);
	if (temp->JorM == 1) {
		fscanf(fp, "%s", temp->journalName);
		printf("%s", temp->journalName);
	}
	else {
		fscanf(fp, "%s", temp->meetingName);
	}
	fscanf(fp, "%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("%d %d %d", temp->year, temp->month, temp->day);
	while (temp->level != 'A' && temp->level != 'B' && temp->level != 'C' && temp->level != 'D' && temp->level != 'E' && temp->level != 'F')
		fscanf(fp,"%c", &temp->level);
	printf("%c", temp->level);
	fscanf(fp, "%d", &member->rank);
	printf("%d", member->rank);
	if (temp->level == 'A' && member->rank == 1) {
		temp->increaseGpa = 0.4; curr->increaseGPA += 0.4;
	}
	else if (temp->level == 'B' && member->rank == 1) {
		temp->increaseGpa = 0.2; curr->increaseGPA += 0.2;
	}
	else if (temp->level == 'C' && member->rank == 1) {
		temp->increaseGpa = 0.1; curr->increaseGPA += 0.1;
	}
	else if (temp->level == 'D' && member->rank == 1) {
		temp->increaseGpa = 0.05; curr->increaseGPA += 0.05;
	}
	else if (temp->level == 'E' && member->rank == 1) {
		temp->increaseGpa = 0.02; curr->increaseGPA += 0.02;
	}
	else if (temp->level == 'F' && member->rank == 1) {
		temp->increaseGpa = 0.01; curr->increaseGPA += 0.01;
	}
	fscanf(fp, "%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	printf("%d %d %d %d %d", temp->reel, temp->period, temp->paperNum, temp->start, temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		temp2->head = (struct Member*)malloc(sizeof(struct Member));
		temp2->head->next = NULL;
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
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->paperNum = temp->paperNum; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		member->next = temp2->head->next;
		temp2->head->next = member;
	}
	else {
		member->next = temp1->head->next;
		temp1->head->next = member;
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
		totalScore += temp->credit * temp->grade;
		totalCredit += temp->credit;
		temp = temp->next;
	}
	if (totalCredit != 0) {
		double CurrGPA = totalScore / totalCredit;
		curr->CurrGpa = CurrGPA;
	}
	if (totalCredit == 0 && totalScore == 0) curr->CurrGpa = 0;
}

void calcTermGPA(struct Student* curr, int term) {
	struct Curriculum* temp = curr->head_curr->next;
	double totalCredit = 0;
	double totalScore = 0;
	while (temp != NULL) {
		if (temp->term != term) temp = temp->next;
		else {
			totalScore += temp->credit * temp->grade;
			totalCredit += temp->credit;
			temp = temp->next;
		}
	}
	if (totalCredit != 0) {
		double CurrGPA = totalScore / totalCredit;
		curr->termGPA[term] = CurrGPA;
	}
	if (totalCredit == 0 && totalScore == 0) curr->termGPA[term] = 0;
}

void sortByTermGPA(struct Student* head, int term) {
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
	while (temp != NULL) {//ɾ��ѧ���Ŀγ�
		struct Curriculum* temp1 = temp->head_curr;
		while (temp1->next != NULL && strcmp(temp1->next->name, name) != 0) {
			temp1 = temp1->next;
		}
		if (temp1->next != NULL) {
			temp1->next = temp1->next->next;
		}
		temp = temp->next;
	}
	struct Curriculum* temp2 = Currhead;//ɾ�����б��е�
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

void printInfo_student(struct Student* head, struct Student* temp) {
	struct Student* curr = head->next;
	while (curr != NULL) {
		calcCurrGpa(curr);
		for (int i = 1; i < 9; i++) calcTermGPA(curr, i);
		calcTotalGpa(curr);
		curr = curr->next;
	}
	rank_Students(head);
	printf("------������%s\nѧԺ��%s\nרҵ��%s\nѧ�ţ�%d\n��������%d\n��GPA��%.2lf\n�γ�GPA��%.2lf\n�ӷ֣�%.2lf------\n", temp->name, temp->college, temp->major, temp->number, temp->totalRank, temp->totalGpa, temp->CurrGpa, temp->increaseGPA);
	for (int i = 1; i < 9; i++) {
		printf("------��%dѧ��������%d GPA:%.2lf------\n", i, temp->term[i], temp->termGPA[i]);
	}
	printf("\n");
}

void printInfo_Curr(struct Curriculum* temp) {
	printf("------�γ����ƣ�%s\n�γ�ѧ�ڣ�%d\n�γ�ѧ�֣�%.2lf------\n", temp->name, temp->term, temp->credit);
	printf("------����������%d------\n", temp->num[0]);
	printf("------��������%d------\n", temp->num[1]);
	printf("------�е�����%d------\n", temp->num[2]);
	printf("------��������%d------\n", temp->num[3]);
	printf("------��������%d------\n", temp->num[4]);
}

void printInfo_ach(struct researchAchievement* temp) {
	printf("------�������ƣ�%s------\n", temp->paperName);
	if (temp->JorM == 1) {
		printf("------�ڿ�����%s------\n", temp->journalName);
	}
	else printf("------��������%s------\n", temp->meetingName);
	printf("------�������ڣ�%d��%d��%d��------\n", temp->year, temp->month, temp->day);
	printf("------���ļ���%c------\n", temp->level);
	printf("------��ţ�%d\n�ںţ�%d\n���ĺţ�%d\nҳ�뷶Χ��%d - %d------\n", temp->reel, temp->period, temp->paperNum, temp->start, temp->end);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		if (curr->rank == 0) {
			printf("------ͨѶ���ߣ�%s------\n", curr->name);
		}
		else {
			printf("%s ", curr->name);
		}
		curr = curr->next;
	}
	printf("\n");
}

void printInfo_cmp(struct Competition* temp) {
	printf("------�������ƣ�%s\n�������췽��%s\n�������ڣ�%d��%d��%d��\n��������%c\n��������%s------\n", temp->name, temp->HostName, temp->year, temp->month, temp->day, temp->grade, temp->rank);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		printf("%s ", curr->name);
		curr = curr->next;
	}
	printf("\n");
}

void printInfo_Pro(struct Project* temp) {
	printf("------��Ŀ���ƣ�%s\nָ����ʦ��%s\n��Ŀ��ţ�%d\n�������ڣ�%d��%d��%d��\n�������ڣ�%d��%d��%d��------\n", temp->name, temp->teacherName, temp->number, temp->year1, temp->month1, temp->day1, temp->year2, temp->month2, temp->day2);
	sortByRank(temp->head);
	struct Member* curr = temp->head->next;
	while (curr != NULL) {
		printf("%s ", curr->name);
		curr = curr->next;
	}
	printf("\n");
}
void amendCurrInfo(struct Student* curr, struct Curriculum* head, struct Student* Sthead) {
	printf("------ѡ��Ҫ�޸ĵĿγ����ƣ�------\n");
	char cuname[100];
	scanf("%s", cuname);
	struct Curriculum* p = Search_cur(curr->head_curr, cuname);
	struct Curriculum* p1 = Search_cur(head, cuname);
	if (p == NULL) {
		printf("------δ�ҵ��˿γ�������------\n");
	}
	else {
		while (1) {
			printf("------�޸�ѧ���ɼ�����1-------\n-------�޸Ŀγ���������2------\n------�޸Ŀγ�����ѧ������3-------\n-------�޸Ŀγ�ѧ������4-------\n------�˳�����0-------\n");
			int x;
			scanf("%d", &x);
			if (x == 1) {
				printf("------�������޸ĵĳɼ���------\n");
				if (p->score >= 90)
					p1->num[4]--;
				else if (p->score < 90 && p->score >= 80)
					p1->num[3]--;
				else if (p->score < 80 && p->score >= 70)
					p1->num[2]--;
				else if (p->score < 70 && p->score >= 60)
					p1->num[1]--;
				else p1->num[0]--;
				double newscore = 0;
				scanf("%lf", &newscore);
				p->score = newscore;
				if (p->score >= 90) {
					p->grade = 4;
				}
				else if (p->score < 60) p->grade = 0;
				else {
					p->grade = (p->score - 50) / 10.0;
				}
				if (p->score >= 90)
					p1->num[4]++;
				else if (p->score < 90 && p->score >= 80)
					p1->num[3]++;
				else if (p->score < 80 && p->score >= 70)
					p1->num[2]++;
				else if (p->score < 70 && p->score >= 60)
					p1->num[1]++;
				else p1->num[0]++;
				printf("------�޸����------\n");
				calcCurrGpa(curr);
				calcTotalGpa(curr);
				for (int i = 0; i < 9; i++) calcTermGPA(curr, i);

			}
			else if (x == 2) {
				printf("------������γ������ƣ�------\n");
				char newcurr[100];
				scanf("%s", newcurr);
				strcpy(p->name, newcurr);
				strcpy(p1->name, newcurr);
				//�޸�����ѧ����Ϣ�еĿγ�����
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct Curriculum* curr = Search_cur(st->head_curr, cuname);
					strcpy(curr->name, newcurr);
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 3) {
				printf("------������γ���ѧ�ڣ�------\n");
				int m;
				scanf("%d", &m);
				p->term = m;
				p1->term = m;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct Curriculum* curr = Search_cur(st->head_curr, cuname);
					curr->term = m;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 4) {
				printf("------������γ���ѧ�֣�------\n");
				double m;
				scanf("%lf", &m);
				p->credit = m;
				p1->credit = m;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct Curriculum* curr = Search_cur(st->head_curr, cuname);
					curr->credit = m;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else {
				break;
			}
		}
		return;
	}
}
void amendresearch(struct Student* ach, struct researchAchievement* head, struct Student* Sthead) {
	printf("------ѡ��Ҫ�޸ĵ��������ƣ�------\n");
	char cuname[100];
	scanf("%s", cuname);
	struct researchAchievement* p = Search_ach(ach->head_ach, cuname);
	struct researchAchievement* p1 = Search_ach(head, cuname);
	if (p == NULL) {
		printf("------δ�ҵ�������������------\n");
	}
	else {
		while (1) {
			printf("------����1�޸���������------\n------����2�޸����ĺ�------\n------����3�޸���������------\n------����4�޸����ľ��ڣ�ҳ��------\n------����5�޸���������------\n------����0�˳�------\n");
			int x;
			scanf("%d", &x);
			if (x == 0) break;
			else if (x == 1) {
				if (p->JorM) {
					p->JorM = 0;
					printf("------�������������------\n");
					char newmeet[100];
					scanf("%s", newmeet);
					strcpy(p->meetingName, newmeet);
					strcpy(p1->meetingName, newmeet);
					struct Member* member = p1->head->next;
					while (member != NULL) {
						struct Student* st = Search_number(Sthead, member->number);
						struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
						strcpy(ach->meetingName, newmeet);
						member = member->next;
					}
					printf("------�޸����------\n");
				}
				else {
					p->JorM = 1;
					printf("------�����ڿ�������------\n");
					char newjoul[100];
					scanf("%s", newjoul);
					strcpy(p->journalName, newjoul);
					strcpy(p1->journalName, newjoul);
					struct Member* member = p1->head->next;
					while (member != NULL) {
						struct Student* st = Search_number(Sthead, member->number);
						struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
						strcpy(ach->journalName, newjoul);
						member = member->next;
					}
					printf("------�޸����------\n");
				}
			}
			else if (x == 2) {
				printf("------�����������ĺ�------\n");
				int newnm;
				scanf("%d", &newnm);
				p->paperNum = newnm;
				p1->paperNum = newnm;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
					ach->paperNum = newnm;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 3) {
				printf("------����������������------\n");
				int x, y, z;
				scanf("%d %d %d", &x, &y, &z);
				p->year = x; p->month = y; p->day = z;
				p1->year = x; p1->month = y; p1->day = z;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
					ach->year = x; ach->month = y; ach->day = z;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 4) {
				printf("------�������µľ� ���ڣ� ҳ�뷶Χ------\n");
				int x, y, newstart, newend;
				scanf("%d %d %d %d", &x, &y, &newstart, &newend);
				p->reel = x; p->period = y; p->start = newstart; p->end = newend;
				p1->reel = x; p1->period = y; p1->start = newstart; p1->end = newend;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
					ach->reel = x; ach->period = y; ach->start = newstart; ach->end = newend;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else {
				printf("------����������������------\n");
				char newpap[100];
				scanf("%s", newpap);
				strcpy(p->paperName, newpap);
				strcpy(p1->paperName, newpap);
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  researchAchievement* ach = Search_ach(st->head_ach, cuname);
					strcpy(ach->paperName, newpap);
					member = member->next;
				}
				printf("------�޸����------\n");
			}
		}
	}
	return;
}
void amendProject(struct Student* pro, struct Project* head, struct Student* Sthead) {
	printf("------ѡ��Ҫ�޸ĵ���Ŀ���ƣ�------\n");
	char cuname[100];
	scanf("%s", cuname);
	struct Project* p = Search_Pro(pro->head_pro, cuname);
	struct Project* p1 = Search_Pro(head, cuname);
	if (p == NULL) {
		printf("------δ�ҵ�����Ŀ������------\n");
	}
	else {
		while (1) {
			printf("------����1�޸���Ŀ����------\n------����2�޸���Ŀ���------\n------����3�޸�����ʱ��------\n------����4�޸Ľ�������------\n------����0�˳�------\n");
			int x;
			scanf("%d", &x);
			if (x == 0) break;
			else if (x == 1) {
				printf("------��������Ŀ������------\n");
				char newpro[100];
				scanf("%s", newpro);
				strcpy(p->name, newpro);
				strcpy(p1->name, newpro);
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Project* pro = Search_Pro(st->head_pro, cuname);
					strcpy(pro->name, newpro);
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 2) {
				printf("------�������µı��------\n");
				int newnm;
				scanf("%d", &newnm);
				p->number = newnm;
				p1->number = newnm;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Project* pro = Search_Pro(st->head_pro, cuname);
					pro->number = newnm;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 3) {
				printf("------����������������------\n");
				int x, y, z;
				scanf("%d %d %d", &x, &y, &z);
				p->year1 = x; p->month1 = y; p->day1 = z;
				p1->year1 = x; p1->month1 = y; p1->day1 = z;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Project* pro = Search_Pro(st->head_pro, cuname);
					pro->year1 = x; pro->month1 = y; pro->day1 = z;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else {
				printf("------�������½�������------\n");
				int x, y, z;
				scanf("%d %d %d", &x, &y, &z);
				p->year2 = x; p->month2 = y; p->day2 = z;
				p1->year2 = x; p1->month2 = y; p1->day2 = z;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Project* pro = Search_Pro(st->head_pro, cuname);
					pro->year2 = x; pro->month2 = y; pro->day2 = z;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
		}
	}
	return;
}
void amendcomp(struct Student* cmp, struct Competition* head, struct Student* Sthead) {
	printf("------ѡ��Ҫ�޸ĵľ������ƣ�------\n");
	char cuname[100];
	scanf("%s", cuname);
	struct Competition* p = Search_Cmp(cmp->head_cmp, cuname);
	struct Competition* p1 = Search_Cmp(head, cuname);
	if (p == NULL) {
		printf("------δ�ҵ��˾���������------\n");
	}
	else {
		while (1) {
			printf("------����1�޸ľ�������------\n------����2�޸����췽����------\n-----����3�޸ľ���ʱ�䣨�����գ�------\n------����0�˳�------\n");
			int x;
			scanf("%d", &x);
			if (x == 0)break;
			else if (x == 1) {
				printf("------�����뾺��������------\n");
				char newcmp[100];
				scanf("%s", newcmp);
				strcpy(p->name, newcmp);
				strcpy(p1->name, newcmp);
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Competition* cmp = Search_Cmp(st->head_cmp, cuname);
					strcpy(cmp->name, newcmp);
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else if (x == 2) {
				printf("------���������췽������------\n");
				char newcmpht[100];
				scanf("%s", newcmpht);
				strcpy(p->HostName, newcmpht);
				strcpy(p1->HostName, newcmpht);
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Competition* cmp = Search_Cmp(st->head_cmp, cuname);
					strcpy(cmp->HostName, newcmpht);
					member = member->next;
				}
				printf("------�޸����------\n");
			}
			else {
				printf("------�������޸ĵ�����------\n");
				int x, y, z;
				scanf("%d %d %d", &x, &y, &z);
				p->year = x; p->month = y; p->day = z;
				p1->year = x; p1->month = y; p1->day = z;
				struct Member* member = p1->head->next;
				while (member != NULL) {
					struct Student* st = Search_number(Sthead, member->number);
					struct  Competition* cmp = Search_Cmp(st->head_cmp, cuname);
					cmp->year = x; cmp->month = y; cmp->day = z;
					member = member->next;
				}
				printf("------�޸����------\n");
			}
		}
	}

}
void amendStudentInfo(struct Student* curr) {
	while (1) {
		printf("------�޸���������1------\n------�޸�ѧ������2------\n------�޸��Ա�����3------\n------�޸�ѧԺ����4------\n------�޸�רҵ����5------\n------������������6------\n------�˳�����0------\n");
		int x;
		scanf("%d", &x);
		if (x == 0) break;
		else if (x == 1) {
			printf("------�������޸ĵ�������------\n");
			char newname[100];
			scanf("%s", newname);
			strcpy(curr->name, newname);
			printf("------�޸����------\n");
		}
		else if (x == 2) {
			printf("------��������ѧ�ţ�------\n");
			int newnumber = 0;
			scanf("%d", &newnumber);
			curr->number = newnumber;
			printf("------�޸����------\n");
		}
		else if (x == 3) {
			if (curr->gender == 0) curr->gender = 1;
			else curr->gender = 0;
			printf("------�Ա����޸�------\n");
		}
		else if (x == 4) {
			printf("------��������ѧԺ��------\n");
			char newclg[100];
			scanf("%s", newclg);
			strcpy(curr->college, newclg);
			printf("------�޸����-------\n");
		}
		else if (x == 5) {
			printf("------��������רҵ���ƣ�------\n");
			char newmajor[100];
			scanf("%s", newmajor);
			strcpy(curr->major, newmajor);
			printf("------�޸����------\n");
		}
		else {
			curr->unlock = 1;
			strcpy(curr->password, "123456");
			printf("------�޸����------\n");
		}
	}
}

void operation_teacher(int op, struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead) {
	if (op == 0) {
		printf("------�½�ѧ����Ϣ������0------\n------�½�ѧ���γ���Ϣ������1------\n------�½�������Ϣ������2------\n------�½���Ŀ��Ϣ������3------\n------�½�������Ϣ������4------\n");
		int op1;
		scanf("%d", &op1);
		printf("------������Ҫ�½���Ϣ��Ŀ------\n");
		int num;
		scanf("%d", &num);
		while (num <= 0) {
			printf("���벻�Ϸ�������������\n");
			scanf("%d", &num);
		}
		printf("------��ѡ�����뷽ʽ------\n------0Ϊ��������------\n------1Ϊ���ļ�����------\n");
		int way;
		scanf("%d", &way);
		if (op1 == 0 && way == 0) {
			for (int i = 0; i < num; i++)
			{
				InsertStudent0(Sthead);
			}
			printf("------�½��ɹ�------\n");
		}
		else if (op1 == 0 && way == 1) {
			printf("------�������ļ���ַ------\n");
			char address[100];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			for (int i = 0; i < num; i++)
			{
				InsertStudent1(Sthead, fp);
			}
			printf("------�½��ɹ�------\n");
			fclose(fp);
		}
		else if (op1 == 1 && way == 0) {
			for (int i = 0; i < num; i++)
			{
				printf("------������ѧ��ѧ��------\n");
				int number;
				scanf("%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n------�ò����½�����ʧ��------\n");
					return;
				}
				InsertCurr0_number(Currhead, number, Sthead);
			}
			printf("------�½��ɹ�------\n");
		}
		else if (op1 == 1 && way == 1) {
			printf("------�������ļ���ַ------\n");
			char address[100];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			for (int i = 0; i < num; i++)
			{
				//printf("������ѧ��ѧ��\n");
				int number;
				fscanf(fp, "%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n------�ò����½�����ʧ��------\n");
					fclose(fp);
					return;
				}
				InsertCurr1_number(Currhead, number, Sthead, fp);
			}
			printf("------�½��ɹ�------\n");
			fclose(fp);
		}
		else if (op1 == 2 && way == 0) {
			for (int i = 0; i < num; i++)
			{
				printf("------������ѧ��ѧ��------\n");
				int number;
				scanf("%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n");
					return;
				}
				InsertResearch0_number(Achhead, number, Sthead);
			}
			printf("------�½��ɹ�------\n");
		}
		else if (op1 == 2 && way == 1) {
			printf("------�������ļ���ַ------\n");
			char address[100];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			for (int i = 0; i < num; i++)
			{
				//printf("������ѧ��ѧ��\n");
				int number;
				fscanf(fp, "%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n------�ò����½�����ʧ��------\n");
					fclose(fp);
					return;
				}
				InsertResearch1_number(Achhead, number, Sthead, fp);
			}
			printf("------�½��ɹ�------\n");
			fclose(fp);
		}
		else if (op1 == 3 && way == 0) {
			for (int i = 0; i < num; i++) {
				printf("------������ѧ��ѧ��------\n");
				int number;
				scanf("%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n");
					return;
				}
				InsertProj0_number(Prohead, number, Sthead);
			}
			printf("------�½��ɹ�------\n");
		}
		else if (op1 == 3 && way == 1) {
			printf("------�������ļ���ַ------\n");
			char address[100];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			for (int i = 0; i < num; i++)
			{
				//printf("������ѧ��ѧ��\n");
				int number;
				fscanf(fp, "%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n------�ò����½�����ʧ��------\n");
					fclose(fp);
					return;
				}
				InsertProj1_number(Prohead, number, Sthead, fp);
			}
			printf("------�½��ɹ�------\n");
			fclose(fp);
		}
		else if (op1 == 4 && way == 0) {
			for (int i = 0; i < num; i++)
			{
				printf("------������ѧ��ѧ��-------\n");
				int number;
				scanf("%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("-------��ѧ��������------\n");
					return;
				}
				InsertComp0_number(Cmphead, number, Sthead);
			}
			printf("------�½��ɹ�------\n");
		}
		else if (op1 == 4 && way == 1) {
			printf("------�������ļ���ַ------\n");
			char address[100];
			scanf("%s", address);
			FILE* fp = fopen(address, "r");
			for (int i = 0; i < num; i++)
			{
				//printf("������ѧ��ѧ��\n");
				int number;
				fscanf(fp, "%d", &number);
				struct Student* temp = Search_number(Sthead, number);
				if (temp == NULL) {
					printf("------��ѧ��������------\n------�ò����½�����ʧ��------\n");
					fclose(fp);
					return;
				}
				InsertComp1_number(Cmphead, number, Sthead, fp);
			}
			printf("------�½��ɹ�------\n");
			fclose(fp);
		}
	}
	else if (op == 1) {
		printf("------ɾ��ѧ����Ϣ������0------\n------ɾ���γ���Ϣ������1------\n------ɾ��������Ϣ������2------\n------ɾ����Ŀ��Ϣ������3------\n------ɾ��������Ϣ������4------\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) {
			printf("------������Ҫɾ��ѧ����ѧ��------\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("------��ѧ��������------\n");
				return;
			}
			deleteStudent(Sthead, number);
			printf("------ɾ���ɹ�------\n");
		}
		else if (op1 == 1) {
			printf("------������Ҫɾ���γ�����------\n");
			char name[100];
			scanf("%s", name);
			struct Curriculum* temp = Search_cur(Currhead, name);
			if (temp == NULL) {
				printf("------�����ڸÿγ�------\n");
				return;
			}
			deleteCurriculum(Sthead, name, Currhead);
			printf("------ɾ���ɹ�------\n");
		}
		else if (op1 == 2) {
			printf("------������Ҫɾ����������------\n");
			char name[100];
			scanf("%s", name);
			struct researchAchievement* temp = Search_ach(Achhead, name);
			if (temp == NULL) {
				printf("------�����ڸ�����------\n");
				return;
			}
			deleteResearch(Sthead, name, Achhead);
			printf("------ɾ���ɹ�------\n");
		}
		else if (op1 == 3) {
			printf("------������Ҫɾ����Ŀ����------\n");
			char name[100];
			scanf("%s", name);
			struct Project* temp = Search_Pro(Prohead, name);
			if (temp == NULL) {
				printf("-------�����ڸ���Ŀ------\n");
				return;
			}
			deleteCurriculum(Sthead, name, Prohead);
			printf("------ɾ���ɹ�------\n");
		}
		else if (op1 == 4) {
			printf("------������Ҫɾ����������------\n");
			char name[100];
			scanf("%s", name);
			struct Competition* temp = Search_Cmp(Cmphead, name);
			if (temp == NULL) {
				printf("------�����ڸþ���------\n");
				return;
			}
			deleteCompetition(Sthead, name, Cmphead);
			printf("------ɾ���ɹ�------\n");
		}
	}
	else if (op == 2) {
		printf("------������Ҫ�޸���Ϣ��ѧ����ѧ��------\n");
		int number;
		scanf("%d", &number);
		struct Student* temp = Search_number(Sthead, number);
		if (temp == NULL) {
			printf("------��ѧ��������------\n");
			return;
		}
		printf("------�޸�ѧ����Ϣ������0------\n------�γ̷���������1------\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) amendStudentInfo(temp);
		else if (op1 == 1) amendCurrInfo(temp ,Currhead,Sthead);
	}
	else if (op == 3) {
		printf("------��ѯѧ����Ϣ������0------\n------��ѯ�γ���Ϣ������1------\n------��ѯ������Ϣ������2------\n------��ѯ��Ŀ��Ϣ������3------\n------��ѯ������Ϣ������4------\n------�г�����ѧ����Ϣ������5------\n------�г����пγ���Ϣ������6------\n------�г�����������Ϣ������7------\n------�г�������Ŀ��Ϣ������8------\n------�г����о�����Ϣ������9------\n");
		int op1;
		scanf("%d", &op1);
		if (op1 == 0) {
			printf("------������ѧ��ѧ��------\n");
			int number;
			scanf("%d", &number);
			struct Student* temp = Search_number(Sthead, number);
			if (temp == NULL) {
				printf("------��ѧ��������------\n");
				return;
			}
			printInfo_student(Sthead, temp);
		}
		else if (op1 == 1) {
			printf("------������γ�����------\n");
			char name[100];
			scanf("%s", name);
			struct Curriculum* temp = Search_cur(Currhead, name);
			if (temp == NULL) {
				printf("------�ÿγ̲�����------\n");
				return;
			}
			printInfo_Curr(temp);
		}
		else if (op1 == 2) {
			printf("------��������������------\n");
			char name[100];
			scanf("%s", name);
			struct researchAchievement* temp = Search_ach(Achhead, name);
			if (temp == NULL) {
				printf("------�����Ĳ�����------\n");
				return;
			}
			printInfo_ach(temp);
		}
		else if (op1 == 3) {
			printf("------��������Ŀ����------\n");
			char name[100];
			scanf("%s", name);
			struct Project* temp = Search_Pro(Prohead, name);
			if (temp == NULL) {
				printf("------����Ŀ������------\n");
				return;
			}
			printInfo_Pro(temp);
		}
		else if (op1 == 4) {
			printf("------�����뾺������------\n");
			char name[100];
			scanf("%s", name);
			struct Competition* temp = Search_Cmp(Cmphead, name);
			if (temp == NULL) {
				printf("------�þ���������------\n");
				return;
			}
			printInfo_cmp(temp);
		}
		else if (op1 == 5) {
			struct Student* temp = Sthead->next;
			while (temp != NULL)
			{
				printInfo_student(Sthead, temp);
				temp = temp->next;
			}
		}
		else if (op1 == 6) {
			struct Curriculum* temp = Currhead->next;
			while (temp != NULL)
			{
				printInfo_Curr(temp);
				temp = temp->next;
			}
		}
		else if (op1 == 7) {
			struct researchAchievement* temp = Achhead->next;
			while (temp != NULL)
			{
				printInfo_ach(temp);
				temp = temp->next;
			}
		}
		else if (op1 == 8) {
			struct Project* temp = Prohead->next;
			while (temp != NULL)
			{
				printInfo_Pro(temp);
				temp = temp->next;
			}
		}
		else if (op1 == 9) {
			struct Competition* temp = Cmphead->next;
			while (temp != NULL)
			{
				printInfo_cmp(temp);
				temp = temp->next;
			}
		}
	}
	else return;
}
void StuchangePassword(struct Student* s) {
	char newPassword[20];
	char confirmPassword[20];
	printf("------�����������룺------\n");
	scanf("%s", newPassword);
	printf("------���ٴ����������룺------\n");
	scanf("%s", confirmPassword);
	while (1) {
		if (strcmp(newPassword, confirmPassword) != 0) {
			printf("------�����������벻һ��------\n");
			break;
		}
		else {
			strcpy(s->password, newPassword);
			printf("------�����޸ĳɹ�------\n");
			break;
		}
	}
	return;
}

void TechchangePassword(struct Teacher* s) {
	char newPassword[20];
	char confirmPassword[20];
	while (1) {
		printf("------�����������룺------");
		scanf("%s", newPassword);
		printf("------���ٴ����������룺------");
		scanf("%s", confirmPassword);
		if (strcmp(newPassword, confirmPassword) != 0) {
			printf("------�����������벻һ��------\n");
			break;
		}
		else {
			strcpy(s->password, newPassword);
			printf("------�����޸ĳɹ�------\n");
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
	printf("------������ע��Ľ�ʦ�ţ�------\n");
	while (1) {
		scanf("%d", &numbeript);
		p = TehSearch_number(head, numbeript);
		if (p == NULL) {
			s->number = numbeript;
			printf("------�����õ�¼���룺------\n");
			scanf("%s", passwordipt);
			strcpy(s->password, passwordipt);
			s->next = head->next;
			head->next = s;
			printf("------ע��ɹ�!!------\n");
			break;
		}
		else {
			printf("------�˽�ʦ���ѱ�ע�� ��������1 �˳�����0------\n");
			int x;
			scanf("%d", &x);
			if (x == 0) return;
		}
	}
}

void studentlogin(struct Student* head) {
	int numberinput = 0;
	char passwordinput[20];
	int logintimes = 0;
	int idexit = 0;
	struct Student* p = NULL;
	while (1) {
		printf("------������ѧ��: ------");
		scanf("%d", &numberinput);
		p = Search_number(head, numberinput);
		if (p == NULL) {
			printf("\n------�޴�ѧ��ѧ��������1��������ѧ��: ------\n------����0�˳�------\n");
			int x;
			scanf("%d", &x);
			if (x == 0) return;
		}
		else { break; }
	}
	if (p->unlock == 0) {
		printf("------�����˺��ѱ�����������ϵ��ʦ����------\n");
	}
	else {
		printf("------����������: ------\n");
		while (1) {
			scanf("%s", passwordinput);
			if (strcmp(p->password, passwordinput) == 0) {
				int x;
				while (1) {
					printf("\n------��ѯ��Ϣ������0------\n------�޸�����������1------\n------�˳�������2------\n");
					scanf("%d", &x);
					if (x == 0) {
						while (1) {
							printf("------��ѯ������Ϣ����1------\n------��ѯ�γ���Ϣ����2------\n------��ѯ���ģ���Ŀ����������Ϣ����3------\n------�˳�����0------\n");
							int n;
							scanf("%d", &n);
							if (n == 0) break;
							else if (n == 1) {
								printInfo_student(head, p);
							}
							else if (n == 2) {
								struct Curriculum* curr = p->head_curr;
								if (curr->next == NULL) {
									printf("------��ѧ���޿γ�------\n");
								}
								else {
									curr = curr->next;
									while (curr != NULL) {
										printf("------�γ�����Ϊ------%s\n", curr->name);
										printf("------�γ�ѧ��Ϊ------%.2lf\n", curr->credit);
										printf("------�γ̷���Ϊ------%.2lf\n", curr->score);
										printf("------�γ̼���Ϊ------%.2lf\n", curr->grade);
										printf("------�γ�ѧ��Ϊ------%d\n", curr->term);
										curr = curr->next;
									}
								}

							}
							else {
								struct researchAchievement* ach = p->head_ach;
								struct Project* pro = p->head_pro;
								struct Competition* cmp = p->head_cmp;
								if (ach->next == NULL) {
									printf("------�����ļ�¼------\n"); 
								}
								else {
									ach = ach->next;
									while (ach != NULL) {
										printInfo_ach(ach);
										ach = ach->next;
									}
								}
								if (pro->next == NULL) {
									printf("-----����Ŀ��¼------\n");
								}
								else {
									pro = pro->next;
									while (pro != NULL) {
										printInfo_Pro(pro);
										pro = pro->next;
									}
								}
								if (cmp->next == NULL) {
									printf("------�޾�����¼------\n");
								}
								else {
									cmp = cmp->next;
									while (cmp != NULL) {
										printInfo_cmp(cmp);
										cmp = cmp->next;
									}
								}
							}
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
					printf("------ʧ�ܴ����������Զ���������ϵ��ʦ���н���------\n");
					p->unlock = 0;
					break;
				}
				printf("------���������������������(��ʣ%d�˻���)------\n", (5 - logintimes));
			}
		}
	}
}

void teacherlogin(struct Teacher* head, struct Student* Sthead, struct Curriculum* Currhead, struct researchAchievement* Achhead, struct Project* Prohead, struct Competition* Cmphead) {
	int numberinput = 0;
	char passwordinput[20];
	struct Teacher* p = NULL;
	printf("------�������ʦ��: ------\n");
	while (1) {
		scanf("%d", &numberinput);
		p = TehSearch_number(head, numberinput);
		if (p == NULL) {
			printf("------û�д˽�ʦ------\n");
			printf("------ע�᣺������0------\n------���µ�¼��������1------\n");
			int choose;
			scanf("%d", &choose);
			if (choose == 0) Tehsignup(head);
			if (choose == 1)teacherlogin(head, Sthead, Currhead, Achhead, Prohead, Cmphead);
			return;
		}
		else { break; }
	}
	printf("------����������: ------\n");
	while (1) {
		scanf("%s", passwordinput);
		if (strcmp(p->password, passwordinput) == 0) {
			int x = 0;
			printf("------��¼�ɹ�!!------\n");
			while (1) {
				printf("\n------����ѧ����Ϣ������0------\n------�޸�����������1------\n------�˳�������2------\n");
				scanf("%d", &x);
				if (x == 0) {
					while (1) {
						printf("------�½���Ϣ������0------\n------ɾ����Ϣ������1------\n------�޸���Ϣ������2------\n------��ѯ��Ϣ������3------\n------�˳�������4------\n");
						int op;
						scanf("%d", &op);
						if (op == 4) break;
						operation_teacher(op, Sthead, Currhead, Achhead, Prohead, Cmphead);
					}
				}
				else if (x == 1) TechchangePassword(p);
				else { break; }
			}
			break;
		}
		else {
			printf("------����������� ����1���� ����0�˳�------\n");
			int x;
			scanf("%d", &x);
			if (x == 1) printf("------����������------\n");
			else return;
		}
	}
}