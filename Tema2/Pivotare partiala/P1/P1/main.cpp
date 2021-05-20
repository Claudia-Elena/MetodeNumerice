#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, i, j,k,lin,permutare=0;
	float a[100][101],aux,S,piv;
	cout << "n=";
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	for (k = 1; k < n; k++)
	{
		piv = fabs(a[k][k]);
		lin = k;
		for (i = k + 1; i <= n; i++)
		{
			if (piv < fabs(a[i][k]))
			{
				piv = fabs(a[i][k]);
				lin = i;
			}
			cout << "pivotul =" << piv << "  pozitia este de linia=" << i << " si coloana=" << k << endl;
         
		}
		
		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica";
		}
		if (lin != k)
		{
			for (j = k; j <= n + 1; j++)
			{
				
				permutare++;
				aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}
			cout << "S-a facut o permutare intre linia " << k << " si " << lin << endl;
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
	if (a[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica";
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		S = 0;
		for (j = 1 + 1; j <= n; j++)
		{
			S = S + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1] << endl;

	}
	cout << "numarul de permutari este =" << permutare;
	
}