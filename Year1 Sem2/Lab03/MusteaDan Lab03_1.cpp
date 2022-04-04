#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

# define DIM 20

int posibil(int, int & );
void afis_sol(int);
int x[DIM], n;

int main(void) {
  int k, sum; //sum se transmite la o referinta avind acces la suma returnata
  //printf("\nIntrodu numarul care urmeaza sa fie descompus( <DIM=20)\n");
  scanf("%d", & n);
  k = 0;
  x[k] = 0;
  do {
    while (x[k] < n) {
      x[k]++;
      if (posibil(k, sum))
        if (sum == n) afis_sol(k);
        else {
          k++;
          x[k] = 0;
        }
    } //while
    k--;
  } while (!(k < 0));
} //main
int posibil(int k, int & s) {
  s = 0;
  if (k == 0) return 1; //initial e posibil ori ce
  //sa am valori crescatoare doar
  if (x[k] >= x[k - 1]) {
    for (int i = 0; i <= k; i++) s += x[i]; //calculez suma
    if (s <= n) return 1;
  }
  return 0;
} //posibil
void afis_sol(int k) {
  for (int i = 0; i <= k; i++)
    printf("%d ", x[i]);
  printf(" \n");
} //afis_sol 