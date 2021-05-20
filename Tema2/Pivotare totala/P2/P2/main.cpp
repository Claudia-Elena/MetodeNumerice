#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, i, j, k, piv, linie, coloana;
	float a[100][100], eps;
	int c[10][10], aux, nr_perm_col;
	cout << " eps= ";
	cin >> eps;
	cout << endl;
	cout << "n= ";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a" << "[" << i << "]""[" << j << "]= ";
			cin >> a[i][j];
		}
	nr_perm_col = 0;
	for (k = 1; k <= n - 1; k++)
	{
		piv = fabs(a[k][k]);
		linie = k;
		coloana = k;
		for (j = k; j <= n; j++)
		{
			for (i = k; i <= n; i++)
			{
				if (piv < fabs(a[i][j]))
				{
					piv = fabs(a[i][j]);
					linie = i;
					coloana = j;
				}
			}
		}
		if (piv <= eps)
		{
			cout << "sistemul nu are solutie unica" << endl;
		}
		if (linie != k)
		{
			for (j = k; j <= n + 1; j++)
			{
				aux = a[k][j];
				a[k][j] = a[linie][j];
				a[linie][j] = aux;
			}
		}
		if (coloana != k)
		{
			nr_perm_col++;
			c[nr_perm_col][1] = k;
			c[nr_perm_col][2] = coloana;
			for (i = 1; i <= n; i++)
			{
				aux = a[i][k];
				a[i][k] = a[i][coloana];
				a[i][coloana] = aux;
			}
		}
		for (i = k + 1; i <= n; i++)
		{
			a[i][k] = a[i][k] / a[k][k];
			for (j = k + 1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		}
	}
	if (a[n][n] <= eps)
	{
		cout << "sistemul nu are solutie unica" << endl;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	float suma;
	for (i = n - 1; i >= 1; i--)
	{
		suma = 0;
		for (j = i + 1; j <= n; j++)
		{
			suma = suma + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - suma) / a[i][i];
	}
	if (nr_perm_col != 0)
	{
		for (i = nr_perm_col; i <= 1; i++)
		{
			aux = a[c[i][1]][n + 1];
			a[c[i][1]][n + 1] = a[c[i][2]][n + 1];
			a[c[i][2]][n + 1] = aux;
		}
	}
	cout << "Solutiile sunt: " << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1] << endl;
	}
}