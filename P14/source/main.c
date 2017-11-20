#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

int minmum(const int grade[][EXAMS], int pulpis, int tests);
int maxmum(const int grade[][EXAMS], int pulpis, int tests);
double average(const int setOfGrades[], int tests);
void printArray(const int grade[][EXAMS], int pulpis, int tests);

int main(void)
{
	int student;
	const int studentGrade[STUDENTS][EXAMS]=
	{
		{77,68,86,73},
		{96,87,89,78},
		{70,90,86,81}	};
	printf("The array is:\n");
	printArray(studentGrade, STUDENTS, EXAMS);

	printf("\n\nThe Lowest grade: %d\nThe Highest grade: %d\n"
		, minmum(studentGrade, STUDENTS, EXAMS)
		, maxmum(studentGrade, STUDENTS, EXAMS));
	
	for (student = 0; student < STUDENTS; student++)
	{
		printf("The average grade for student %d is %.2f\n"
			, student
			, average(studentGrade[student], EXAMS)	);
	}

	system("pause");
	return 0;
}
/////////////////////////////////////
void printArray(const int grade[][EXAMS], int pulpis, int tests)
{
	int i;
	int j;
	printf("		[0]  [1]  [2]  [3]");
	for (i = 0; i < pulpis; i++)
	{
		printf("\nstudentGrade[%d] ", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-5d", grade[i][j]);
		}
	}
}
///////////////////////////////////////////////////////
int minmum(const int grade[][EXAMS], int pulpis, int tests)
{
	int i;
	int j;
	int lowGrade = 100;
	for (i = 0; i < pulpis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] < lowGrade)
			{
				lowGrade = grade[i][j];
			}
		}
	}
	return lowGrade;
}
///////////////////////////////////////////////////
int maxmum(const int grade[][EXAMS], int pulpis, int tests)
{
	int i;
	int j;
	int highGrade = 0;
	for (i = 0; i < pulpis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grade[i][j] > highGrade)
			{
				highGrade = grade[i][j];
			}
		}
	}
	return highGrade;
}
//////////////////////////////////////////////////////////
double average(const int setOfGrades[], int tests)
{
	int i;
	int total = 0;
	for (i = 0; i < tests; i++)
	{
		total += setOfGrades[i];
	}
	return (double)total / tests;
}