#define _CRT_SECURE_NO_WARNINGS  1
#include"Function.h"
#include<string.h>
#include<malloc.h>
struct Student* Search_number(struct Student* head, int number) {//����ѧ�Ų���
	struct Student* curr = head->next;
	while (curr != NULL && curr->number != number) {
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("Not Found.");
	}
	else return curr;
}

struct Student* Search_name(struct Student* head, char name[]) {//������������
	struct Student* curr = head->next;
	while (curr != NULL && strcmp(curr->name,name) != 0 ) {
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("Not Found.");
	}
	else return curr;
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
void InsertStudent0(struct Student* head) {//�ռ����ݲ����� ����̨
	struct Student* temp = (struct Student*)malloc(sizeof(struct Student));
	printf("������ѧ������\n");
	scanf("%s", temp->name);
	printf("������ѧ��ѧ��\n");
	scanf("%d", &temp->number);
	printf("������ѧ���Ա�(0ΪŮ��1Ϊ����)\n");
	scanf("%d", &temp->gender);
	printf("������ѧ����ѧԺ\n");
	scanf("%s", temp->college);
	printf("������ѧ����רҵ\n");
	scanf("%s", temp->major);
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

void InsertMember0(struct Member* head) {//����member ����̨
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	printf("�������Ա����\n");
	scanf("%s", temp->name);
	printf("�������Աѧ��\n");
	scanf("%d", &temp->number);
	printf("�������Ա������-1Ϊû��˳��	0 ΪͨѶ���� 1��ʼΪ1�� 2Ϊ2��������\n");
	scanf("%d", &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertMember1(struct Member* head, FILE* fp) {//����member �ļ�
	struct Member* temp = (struct Member*)malloc(sizeof(struct Member));
	fscanf(fp,"%s %d %d", temp->name, &temp->number, &temp->rank);
	struct Member* curr = head->next;
	head->next = temp;
	temp->next = curr;
}

void InsertCurr0_number(struct Curriculum* head,int number,struct Student* head_s) {//����ѧ�� ����̨
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	printf("������γ�����\n");
	scanf("%s", temp->name);
	printf("������γ�ѧ��\n");
	scanf("%lf", &temp->credit);
	printf("������γ�����ѧ��\n");
	scanf("%d", &temp->term);
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
}

void InsertCurr1_number(struct Curriculum* head, int number, struct Student* head_s, FILE* fp) {//����ѧ�� �ļ�
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp,"%s %lf %d", temp->name, &temp->credit, &temp->term);
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
}

void InsertCurr0_name(struct Curriculum* head, char name[], struct Student* head_s) {//�������� ����̨
	struct Student* curr = Search_name(head_s, name);
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	printf("������γ�����\n");
	scanf("%s", temp->name);
	printf("������γ�ѧ��\n");
	scanf("%lf", &temp->credit);
	printf("������γ�����ѧ��\n");
	scanf("%d", &temp->term);
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
}

void InsertCurr1_name(struct Curriculum* head, char name[], struct Student* head_s, FILE* fp) {//����ѧ�� �ļ�
	struct Student* curr = Search_number(head_s, name);
	if (curr == NULL) return;
	struct Curriculum* temp = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	fscanf(fp, "%s %lf %d", temp->name, &temp->credit, &temp->term);
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
}

void InsertComp0_number(struct Competition* head,int number,struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	printf("�����뾺������\n");
	scanf("%s", temp->name);
	printf("�����뾺�����췽\n");
	scanf("%s", temp->HostName);
	printf("�����뾺�����ڣ��� �� ��\n");
	scanf("%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("�����뾺������(A or B or C)\n");
	scanf("%c", &temp->grade);
	printf("������񽱵ȼ�(gold/silver/bronze)\n");
	scanf("%s", temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
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
		InsertMember0(temp2->head);
	}
}

void InsertComp0_name(struct Competition* head, char name[], struct Student* head_s ) {
	struct Student* curr = Search_name(head_s, name);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	printf("�����뾺������\n");
	scanf("%s", temp->name);
	printf("�����뾺�����췽\n");
	scanf("%s", temp->HostName);
	printf("�����뾺�����ڣ��� �� ��\n");
	scanf("%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("�����뾺������(A or B or C)\n");
	scanf("%c", &temp->grade);
	printf("������񽱵ȼ�(gold/silver/bronze)\n");
	scanf("%s", temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
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
		InsertMember0(temp2->head);
	}
}

void InsertComp1_number(struct Competition* head, int number, struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	fscanf(fp,"%s %s %d %d %d %c %s", temp->name, temp->HostName, &temp->year, &temp->month, &temp->day,&temp->grade,temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
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
		InsertMember1(temp2->head,fp);
	}
}

void InsertComp1_name(struct Competition* head, char name[], struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_name(head_s, name);
	if (curr == NULL) return;
	struct Competition* temp = (struct Competition*)malloc(sizeof(struct Competition));
	fscanf(fp,"%s %s %d %d %d %c %s", temp->name, temp->HostName, &temp->year, &temp->month, &temp->day, &temp->grade, temp->rank);
	if (temp->grade == 'A' && strcmp(temp->rank, "gold") == 0) temp->increaseGpa = 0.4;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "gold") == 0) || (temp->grade == 'A' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.2;
	else if ((temp->grade == 'A' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'B' && strcmp(temp->rank, "silver") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "gold") == 0)) temp->increaseGpa = 0.1;
	else if ((temp->grade == 'B' && strcmp(temp->rank, "bronze") == 0) || (temp->grade == 'C' && strcmp(temp->rank, "silver") == 0)) temp->increaseGpa = 0.05;
	else if ((temp->grade == 'C' && strcmp(temp->rank, "bronze") == 0)) temp->increaseGpa = 0.02;
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
		InsertMember1(temp2->head, fp);
	}
}

void InsertProj0_number(struct Project* head, int number, struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	printf("��������Ŀ����\n");
	scanf("%s", temp->name);
	printf("������ָ����ʦ����\n");
	scanf("%s", temp->teacherName);
	printf("��������Ŀ���\n");
	scanf("%d", &temp->number);
	printf("�������������ڣ� �� �� ��\n");
	scanf("%d %d %d", &temp->year1, &temp->month1, &temp->day1);
	printf("������������ڣ��� �� ��\n");
	scanf("%d %d %d", &temp->year2, &temp->month2, &temp->day2);
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
		InsertMember0(temp2->head);
	}
}

void InsertProj0_name(struct Project* head, char name[], struct Student* head_s) {
	struct Student* curr = Search_name(head_s, name);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	printf("��������Ŀ����\n");
	scanf("%s", temp->name);
	printf("������ָ����ʦ����\n");
	scanf("%s", temp->teacherName);
	printf("��������Ŀ���\n");
	scanf("%d", &temp->number);
	printf("�������������ڣ� �� �� ��\n");
	scanf("%d %d %d", &temp->year1, &temp->month1, &temp->day1);
	printf("������������ڣ��� �� ��\n");
	scanf("%d %d %d", &temp->year2, &temp->month2, &temp->day2);
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
		InsertMember0(temp2->head);
	}
}

void InsertProj1_number(struct Project* head, int number, struct Student* head_s,FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	fscanf(fp, "%s %s %d %d %d %d %d %d", temp->name, temp->teacherName, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2);
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
		InsertMember1(temp2->head,fp);
	}
}

void InsertProj1_name(struct Project* head, char name[], struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_name(head_s, name);
	if (curr == NULL) return;
	struct Project* temp = (struct Project*)malloc(sizeof(struct Project));
	fscanf(fp, "%s %s %d %d %d %d %d %d", temp->name, temp->teacherName, &temp->year1, &temp->month1, &temp->day1, &temp->year2, &temp->month2, &temp->day2);
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
		InsertMember1(temp2->head,fp);
	}
}

void InsertResearch0_number(struct researchAchievement* head,int number,struct Student* head_s) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	printf("������������Ŀ\n");
	scanf("%s", temp->paperName);
	printf("��Ϊ�ڿ�������1 ��Ϊ����������2\n");
	int JorM = 0;
	scanf("%d", &JorM);
	if (JorM == 1) {
		printf("�������ڿ���Ŀ\n");
		scanf("%s", temp->journalName);
	}
	else {
		printf("�����������Ŀ\n");
		scanf("%s", temp->meetingName);
	}
	printf("�����뷢��ʱ�䣺 �� �� �� \n");
	scanf("%d %d %d", &temp->year,&temp->month,&temp->day);
	printf("���������ļ�����Ϣ(A/B/C/D/E/F)\n");
	scanf("%c", &temp->level);
	if (temp->level == 'A') temp->increaseGpa = 0.4;
	else if (temp->level == 'B') temp->increaseGpa = 0.2;
	else if (temp->level == 'C') temp->increaseGpa = 0.1;
	else if (temp->level == 'D') temp->increaseGpa = 0.05;
	else if (temp->level == 'E') temp->increaseGpa = 0.02;
	else if (temp->level == 'F') temp->increaseGpa = 0.01;
	printf("���������ľ��ڡ����ĺš�ҳ�뷶Χ\n");
	scanf("%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		InsertMember0(temp2->head);
	}
}

void InsertResearch0_name(struct researchAchievement* head, char name[], struct Student* head_s) {
	struct Student* curr = Search_number(head_s, name);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	printf("������������Ŀ\n");
	scanf("%s", temp->paperName);
	printf("��Ϊ�ڿ�������1 ��Ϊ����������2\n");
	int JorM = 0;
	scanf("%d", &JorM);
	if (JorM == 1) {
		printf("�������ڿ���Ŀ\n");
		scanf("%s", temp->journalName);
	}
	else {
		printf("�����������Ŀ\n");
		scanf("%s", temp->meetingName);
	}
	printf("�����뷢��ʱ�䣺 �� �� �� \n");
	scanf("%d %d %d", &temp->year, &temp->month, &temp->day);
	printf("���������ļ�����Ϣ(A/B/C/D/E/F)\n");
	scanf("%c", &temp->level);
	if (temp->level == 'A') temp->increaseGpa = 0.4;
	else if (temp->level == 'B') temp->increaseGpa = 0.2;
	else if (temp->level == 'C') temp->increaseGpa = 0.1;
	else if (temp->level == 'D') temp->increaseGpa = 0.05;
	else if (temp->level == 'E') temp->increaseGpa = 0.02;
	else if (temp->level == 'F') temp->increaseGpa = 0.01;
	printf("���������ľ��ڡ����ĺš�ҳ�뷶Χ\n");
	scanf("%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		InsertMember0(temp2->head);
	}
}

void InsertResearch1_number(struct researchAchievement* head, int number, struct Student* head_s,FILE* fp) {
	struct Student* curr = Search_number(head_s, number);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	fscanf(fp,"%s", temp->paperName);
	int JorM = 0;
	fscanf(fp,"%d", &JorM);
	if (JorM == 1) {
		fscanf(fp,"%s", temp->journalName);
	}
	else {
		fscanf(fp,"%s", temp->meetingName);
	}
	fscanf(fp,"%d %d %d", &temp->year, &temp->month, &temp->day);
	fscanf(fp,"%c", &temp->level);
	if (temp->level == 'A') temp->increaseGpa = 0.4;
	else if (temp->level == 'B') temp->increaseGpa = 0.2;
	else if (temp->level == 'C') temp->increaseGpa = 0.1;
	else if (temp->level == 'D') temp->increaseGpa = 0.05;
	else if (temp->level == 'E') temp->increaseGpa = 0.02;
	else if (temp->level == 'F') temp->increaseGpa = 0.01;
	fscanf(fp,"%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		InsertMember1(temp2->head,fp);
	}
}

void InsertResearch1_name(struct researchAchievement* head, char name[], struct Student* head_s, FILE* fp) {
	struct Student* curr = Search_number(head_s, name);
	if (curr == NULL) return;
	struct researchAchievement* temp = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	fscanf(fp, "%s", temp->paperName);
	int JorM = 0;
	fscanf(fp, "%d", &JorM);
	if (JorM == 1) {
		fscanf(fp, "%s", temp->journalName);
	}
	else {
		fscanf(fp, "%s", temp->meetingName);
	}
	fscanf(fp, "%d %d %d", &temp->year, &temp->month, &temp->day);
	fscanf(fp, "%c", &temp->level);
	if (temp->level == 'A') temp->increaseGpa = 0.4;
	else if (temp->level == 'B') temp->increaseGpa = 0.2;
	else if (temp->level == 'C') temp->increaseGpa = 0.1;
	else if (temp->level == 'D') temp->increaseGpa = 0.05;
	else if (temp->level == 'E') temp->increaseGpa = 0.02;
	else if (temp->level == 'F') temp->increaseGpa = 0.01;
	fscanf(fp, "%d %d %d %d %d", &temp->reel, &temp->period, &temp->paperNum, &temp->start, &temp->end);
	struct researchAchievement* temp_n = curr->head_ach->next;
	curr->head_ach->next = temp;
	temp->next = temp_n;
	struct researchAchievement* temp1 = Search_ach(head, temp->paperName);
	if (temp1 == NULL) {
		struct researchAchievement* temp2 = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
		strcpy(temp2->paperName, temp->paperName);
		if (JorM == 1) {
			strcpy(temp2->journalName, temp->journalName);
		}
		else {
			strcpy(temp2->meetingName, temp->meetingName);
		}
		temp2->year = temp->year; temp2->month = temp->month; temp2->day = temp->day; temp2->level = temp->level;
		temp2->increaseGpa = temp->increaseGpa; temp2->reel = temp->reel; temp2->period = temp->period; temp2->start = temp->start; temp2->end = temp->end;
		struct researchAchievement* temp2_n = head->next;
		head->next = temp2;
		temp2->next = temp2_n;
		InsertMember1(temp2->head,fp);
	}
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

double getCurrGPA(struct Student* curr) {
	return curr->CurrGpa;
}

double getTotalGPA(struct Student* curr) {
	return curr->totalGpa;
}

int getRank(struct Student* curr, int term) {
	return curr->term[term];
}

int getTotalRank(struct Student* curr) {
	return curr->totalRank;
}

void calcTotalGpa(struct Student* curr) {
	curr->totalGpa = curr->CurrGpa + curr->increaseGPA;
}