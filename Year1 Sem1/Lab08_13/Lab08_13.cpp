#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MAX 20

int main()
{
	int a[MAX][MAX][MAX];
	int m = 0, n = 0, p = 0;
	printf("Read a 3D matrix from the xoy prespective, then the program will display it from the yoz and xoz perspectives.\n");
	scanf_s("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++) {//z
		for (int j = 0; j < m; j++) {//x
			for (int k = 0; k < p; k++) {//y
				scanf("%d", &a[i][j][k]);
			}
		}
	}

	printf("\nFrom the yOz perspective\n");
	for (int j = 0; j < m; j++) {//x
		for (int k = 0; k < p; k++) {//y
			for (int i = 0; i < n; i++) {//z
				printf("%d ", a[i][j][k]);
			}printf("\n");
		}printf("\n");
	}
	printf("\n");
	printf("\n");

	printf("\nFrom the xOz perspective\n");
	for (int k = 0; k < p; k++) {//y
		for (int j = 0; j < m; j++) {//x
			for (int i = 0; i < n; i++) {//z
				printf("%d ", a[i][j][k]);
			}printf("\n");
		}printf("\n");
	}

}

