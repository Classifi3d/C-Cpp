//
//  main.cpp
//  Inmultire_chinezeasca
//
//  Created by Paul Cureu on 17/10/2019.
//  Copyright © 2019 Paul Cureu. All rights reserved.
//
#include <stdio.h>

int ver(long long a, long long b)
{
	if (a < 10 && b < 10)
		return 5;
	else
		if (a < 10)
			return 1;
		else
			if (b < 10)
				return 0;
	return 10;
}

void separare_cif_b(long long b, int mp[100], int& q)
{
	for (int i = 1; b; i++)
	{
		mp[i] = b % 10;
		b /= 10;
		q = i;
	}
}

void separare_cif_a(long long a, int imp[100], int& q)
{
	for (int i = 1; a; i++)
	{
		imp[i] = a % 10;
		a /= 10;
		q = i;
	}
}

void rezultat(int x[100][100], int n, int m, int pres)
{
	int rez[100];
	int sum = 0, p = m;
	for (int j = m; j >= 1; j--) {
		for (int i = 1; i <= n; i++)
			sum = sum + x[i][j];
		if (sum >= 10) {
			rez[--p] = sum % 10;
			sum /= 10;
		}
		else {
			rez[--p] = sum % 10;
			sum = 0;
		}


	}
	if (pres) {
		rez[0] = rez[0] * -1;
	}
	printf("Produsul chinezesc = ");
	for (int i = 0; i < m; i++) {
		printf("%d", rez[i]);

	}
	printf("\n");
}

int main() {
	long long a, b; int k = 0, q = 0, x[100][100] = { 0 }, m = 1, n = 1, l = 2, ul_el = 0, pres = 0;
	int imp[100], mp[100];
	scanf_s("%lld%lld", &a, &b);

	if (a < 0) {
		a *= -1;
		pres = 1;
	}
	else
		if (b < 0) {
			b *= -1;
			pres = 1;
		}

	if (ver(a, b) == 5) {
		printf("%lld", a * b);

	}
	else
		if (ver(a, b) == 1) {
			separare_cif_b(b, mp, q);
			for (int j = q; j >= 1; --j)
			{
				x[n][m++] = ((mp[j] * a) / 10) % 10;
				x[n++][m] = (mp[j] * a) % 10;
			}
			n = q;
			rezultat(x, n, m, pres);
		}
		else
			if (ver(a, b) == 0) {
				separare_cif_a(a, imp, q);
				for (int j = q; j >= 1; --j)
				{
					x[n][m++] = ((imp[j] * b) / 10) % 10;
					x[n++][m] = (imp[j] * b) % 10;
				}
				n = q;
				rezultat(x, n, m, pres);
			}
			else
			{
				separare_cif_a(a, imp, k);
				separare_cif_b(b, mp, q);


				for (int j = q; j >= 1; --j) {
					for (int i = k; i >= 1; --i) {
						x[n][m++] = ((imp[i] * mp[j]) / 10) % 10;
					}
					n++; m = l;
					if (n % 2 == 0 && n != 1) {
						for (int i = k; i >= 1; --i) {
							x[n][m++] = (imp[i] * mp[j]) % 10;
						}
						ul_el = m;
						m = l; n++; l++;
					}
				}

				m = ul_el - 1; n--;

				rezultat(x, n, m, pres);
			}
	return 0;
}
