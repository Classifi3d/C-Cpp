#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
using  namespace  std;

#define  MAX  20

int  main() {
	int  a[MAX];
	int* v = a;
	int  n, negativeMean, postiveMean, negativeMeanCounter, postiveMeanCounter;
	printf("Read  from  the  keyboard  a  dimension  then  an  array  with  integer  as  elements,  then  the  program  determines  the  mean  value  of  the  negative/positive  elements  from  a  one  dimensional  array.\n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &v[i]);
	}

	negativeMean = 0, negativeMeanCounter = 0;
	postiveMean = 0, postiveMeanCounter = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] < 0) {
			negativeMean += v[i];
			negativeMeanCounter++;
		}
		if (v[i] >= 0) {
			postiveMean += v[i];
			postiveMeanCounter++;
		}
	}


	for (int i = 0; i < n; i++) {
		printf("%d  ", v[i]);
	}printf("\n");


	if (!(negativeMean == 0 && negativeMeanCounter == 0)) {
		printf("negative  mean  value:%d\n", negativeMean / negativeMeanCounter);
	}

	if (!(postiveMean == 0 && postiveMeanCounter == 0)) {
		printf("positive  mean  value:%d", postiveMean / postiveMeanCounter);
	}


	return 0;
}