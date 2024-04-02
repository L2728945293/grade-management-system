#define _CRT_SECURE_NO_WARNINGS  1
#include"main.h"
#include"Function.h"
#include<stdio.h>
#include<malloc.h>

int main() {
	struct Teacher* head = (struct Teacher*)malloc(sizeof(struct Teacher));
	head->next = NULL;
	struct Student* Sthead = (struct Student*)malloc(sizeof(struct Student));
	Sthead->next = NULL;
	struct Curriculum* Currhead = (struct Curriculum*)malloc(sizeof(struct Curriculum));
	Currhead->next = NULL;
	struct researchAchievement* Achhead = (struct researchAchievement*)malloc(sizeof(struct researchAchievement));
	Achhead->next = NULL;
	struct Competition* Cmphead = (struct Competition*)malloc(sizeof(struct Competition));
	Cmphead->next = NULL;
	struct Project* Prohead = (struct Project*)malloc(sizeof(struct Project));
	Prohead->next = NULL;
	int login;
	printf("欢迎来到成绩管理系统\n");
	while (1) {
		printf("\n学生端：请输入0\n教师端：请输入1\n退出请输入2\n");
		scanf("%d", &login);

		if (login == 1) {
			printf("注册：请输入0\n登录：请输入1\n");
			int choose;
			scanf("%d", &choose);
			if (choose == 0) Tehsignup(head);
			if (choose == 1)teacherlogin(head,Sthead,Currhead,Achhead,Prohead,Cmphead);
		}
		else if (login == 0) studentlogin(Sthead);
		else {
			break;
		}
	}
	return 0;
}