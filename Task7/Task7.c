#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
const int max = 30;

struct date
{
    int day;
    int month;
    int year;
};

struct info
{
    char *discipline;
    char typeRating[5];
    union grade {
        bool testGrade;
        enum
        {
            Failing = 2,
            Fair = 3,
            Good = 4,
            Excellent = 5
        }gradeNum;
    };
    struct date exTestDate;
    char *teacherLastName;
};

struct semester
{
    int numSem, yearS;
    struct info *infDisc;
};

struct certificate
{
    char* lastName, firstName, patronymic;
    int certifNum;
    struct semester *sem;
};

void gradeExamFunc(int* t)
{
    int gradeExam;
    printf("Grade? (from 2 to 5) ");
    scanf("%d", &gradeExam);
    switch (gradeExam)
    {
    case(Excellent):
        *t = Excellent;
        break;
    case(Good):
        *t = Good;
        break;
    case(Fair):
        *t = Fair;
        break;
    case(Failing):
        *t = Failing;
        break;
    default: {
        printf("i will be think it was a ''fair'' (read the tips next time, please!) \n");
        *t = Fair;
        break;
    }
    }
}

void gradeTestFunc(bool* t)
{
    int gradeTest;
    printf("Grade? (1 is got test, 0 isnt) ");
    scanf("%d", &gradeTest);
    if (gradeTest == 0)
        *t = false;
    else *t = true;
}

void outpuut(struct certificate c, int n, int t)
{
    printf("Name: %s %s %s \n", &c.lastName, &c.firstName, &c.patronymic);
    printf("Number of certificate: %d \n", c.certifNum);
    for (int i = 0; i < n; i++) {
        printf("\n \nIn %d semester %d year result is:\n", c.sem[i].numSem, c.sem[i].yearS);
        for (int j = 0; j < t; j++) {
            printf("%s ", c.sem[i].infDisc[j].discipline);
            char q1[5] = "Exam", q2[5] = "exam", q3[5] = "Test", q4[5] = "test";
            if (!strcmp(c.sem[i].infDisc[j].typeRating, q1) || !strcmp(c.sem[i].infDisc[j].typeRating, q2))
                printf("\t%s \t%d \t", c.sem[i].infDisc[j].typeRating, c.sem[i].infDisc[j].gradeNum);
            else if (!strcmp(c.sem[i].infDisc[j].typeRating, q3) || !strcmp(c.sem[i].infDisc[j].typeRating, q4))
                printf("\t%s \t%d \t", c.sem[i].infDisc[j].typeRating, c.sem[i].infDisc[j].testGrade);
            else
                printf("%s \t%s \t%d \t", c.sem[i].infDisc[j].discipline, c.sem[i].infDisc[j].typeRating, c.sem[i].infDisc[j].gradeNum);
            printf("%d.%d.%d \t%s\n", c.sem[i].infDisc[j].exTestDate.day, c.sem[i].infDisc[j].exTestDate.month, c.sem[i].infDisc[j].exTestDate.year, &c.sem[i].infDisc[j].teacherLastName);
        }
    }
}

void main() {
    int gradeTest, n, t; bool r = 0, f = 0;
    struct certificate cer;
    printf("Number of semester? ");
    scanf_s("%d", &n);
    printf("Number of strings? ");
    scanf_s("%d", &t);
    printf("Name? ");
    cer.firstName = (char*)malloc(max*sizeof(char));
    scanf("%s", &cer.firstName);
    printf("Last name? ");
    cer.lastName = (char*)malloc(max * sizeof(char));
    scanf("%s", &cer.lastName);
    printf("Patronymic? ");
    cer.patronymic = (char*)malloc(max * sizeof(char));
    scanf("%s", &cer.patronymic);
    printf("Number of certificate? ");
    scanf("%d", &cer.certifNum);
    cer.sem = (struct semester*)malloc(n * sizeof(struct semester));
    for (int i = 0; i < n; i++) {
        cer.sem[i].numSem = i + 1;
        cer.sem[i].yearS = (i + 2) / 2;
        printf("\n \nNumber of semester is %d, number of year is %d \n", cer.sem[i].numSem, cer.sem[i].yearS);
        cer.sem[i].infDisc = (struct info*)malloc(sizeof(struct info) * t);
        for (int j = 0; j < t; j++) {
            printf("Discipline name? ");
            cer.sem[i].infDisc[j].discipline = (char*)malloc(max * sizeof(char));
            scanf("%s", cer.sem[i].infDisc[j].discipline);
            printf("Exam or test? ");
            scanf("%s", cer.sem[i].infDisc[j].typeRating);
            char q1[5] = "Exam", q2[5] = "exam", q3[5] = "Test", q4[5] = "test";
            if (!strcmp(cer.sem[i].infDisc[j].typeRating, q1) || !strcmp(cer.sem[i].infDisc[j].typeRating, q2)) {
                gradeExamFunc(&cer.sem[i].infDisc[j].gradeNum); r = 1;
            }
            else if (!strcmp(cer.sem[i].infDisc[j].typeRating, q3) || !strcmp(cer.sem[i].infDisc[j].typeRating, q4)) {
                gradeTestFunc(&cer.sem[i].infDisc[j].testGrade); f = 1;
            }
            else {
                printf(" i will be think it was an exam (read the tips next time, please!) \n");
                gradeExamFunc(&cer.sem[i].infDisc[j].gradeNum); r = 1;
            }
            printf("Day of exam? ");
            scanf("%d", &cer.sem[i].infDisc[j].exTestDate.day);
            printf("Month of exam? ");
            scanf("%d", &cer.sem[i].infDisc[j].exTestDate.month);
            printf("Year of exam? ");
            scanf("%d", &cer.sem[i].infDisc[j].exTestDate.year);
            printf("Teacher`s last name? ");
            cer.sem[i].infDisc[j].teacherLastName = (char*)malloc(max * sizeof(char));
            scanf("%s", &cer.sem[i].infDisc[j].teacherLastName);
        }
    }
    system("cls");
    outpuut(cer, n ,t);
    free(cer.sem);
}