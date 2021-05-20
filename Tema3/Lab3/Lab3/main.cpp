#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n,i,j,k,h,contor=0,contor2=0;
	float a[100][101],aux,S,piv;
	cout << "n=";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
    	}

	}
	if (a[1][1] == 0)
	{
		i = 1;
		do {
			i += 1;
		} while (!(a[i][1] != 0 || i > n));
		if (i > n)
		{
			cout << "Sistemul nu are solutie unica"<<endl;
		}
		for (j = 1; j <= n + 1; j++)
		{
			contor++;
			aux = a[1][j];
			a[1][j] = a[i][j];
			a[i][j] = aux;

		}
	}

	for (i = 2; i <= n; i++)
	{
		a[i][1] = a[i][1] / a[1][1];
	}

	for (k = 2; k <= n; k++)
	{
		i = k;
		do {
			S = 0;
			piv = 0;
			for (h = 1; h <= k - 1; h++)
			{
				S += a[i][h] * a[h][k];
			}
			piv = a[i][k] - S;
			i += 1;

		} while (!(piv!=0 || i>n));
		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica" << endl;
		}
		if (i != k + 1)
		{
			for (j = 1; j <= n + 1; j++)
			{
				contor2++;
				aux = a[k][j];
				a[k][j] = a[i - 1][j];
				a[i - 1][j] = aux;

			}
		}
		for (j = k; j <= n; j++)
		{
			S = 0;
			for (h = 1; h <= k - 1; h++)
			{
				S += a[k][h] * a[h][j];
			}
			a[k][j] = a[k][j] - S;
		}
		for (i = k + 1; i <= n; i++)
		{
			S = 0;
			for (h = 1; h <= k - 1; h++)
			{
				S += a[i][h] * a[h][k];
			}
			a[i][k] = (a[i][k] - S) / a[k][k];
		}
	}
	for (i = 2; i <= n; i++)
	{
		S = 0;
		for (k = 1; k <= i - 1; k++)
		{
			S += a[i][k] * a[k][n + 1];
		}
		a[i][n + 1] = a[i][n + 1] - S;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	
	for (i = n; i >= 1; i--)
	{
		S = 0;
		for (j = i + 1; j <= n; j++)
		{
			S += a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	cout << contor << endl;
	cout << contor2 << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "X" << i << "=" << a[i][n + 1] << endl;
	}
	cout << "L= " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			
			if (i == j)
			{
				cout << "1 ";
			}
			else if (i < j)
			{
				cout << "0 ";
			}
			else cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "R= " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{

			 if (i > j)
			{
				cout << "0 ";
			}
			else cout << a[i][j] << " ";
		}
		cout << endl;
	}
}