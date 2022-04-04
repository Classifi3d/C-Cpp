#define  _CRT_SECURE_NO_WARNINGS
#include  <cstdio>
#include  <conio.h>

int  main() {
	char stud1[20], stud2[20];
	float markStud1, markStud2;
	printf("Type the name of the two students then their respectiv marks\n");
	scanf("%s%s", stud1, stud2);
	scanf_s("%f%f", &markStud1, &markStud2);
	printf("%s %.2f \n %s %-.2f",stud1, markStud1, stud2, markStud2);

		

	return  0;
}

