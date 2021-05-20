#include<iostream>
using namespace std;
int main()
{
	int n, i, j,k;
	float a[100][100],y[100][100];
	cout << "Citeste n= ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)

		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
			cout << endl;
		}
	}

	pasul2:for (i = 1; i <= n; i++)
	{
		cout << "y[" << i << "][" << j << "]=";
		cin >> y[i][n];
	}
	for (j = n - 1; j >= 1; j--)
	{
		for (i = 1; i <= n; i++)
		{
			y[i][j] = 0;
			for (k = 1; k <= n; k++)
			{
				y[i][j] = y[i][j]+a[i][k] * y[k][j + 1];
				
		    }
		}
	}
	for (i = 1; i <= n; i++)
	{
		y[i][n + 1] = 0;
		for (k = 1; k <= n; k++)
		{
			y[i][n+1] = y[i][n + 1]+ a[i][k] * y[k][1];
		}
		y[i][n + 1] = -y[i][n + 1];
	}
	for (j = n - 1; j >= 1; j--)
	{
		for (i = 1; i <= n; i++)
		{
			cout <<  y[i][j]<<" ";
		}
		cout << endl;
	}
	int  lin, permutare = 0;
	float  aux, S, piv;
	
	for (k = 1; k < n; k++)
	{
		piv = fabs(y[k][k]);
		lin = k;
		for (i = k + 1; i <= n; i++)
		{
			if (piv < fabs(y[i][k]))
			{
				piv = fabs(y[i][k]);
				lin = i;
			}
			//cout << "pivotul =" << piv << "  pozitia este de linia=" << i << " si coloana=" << k << endl;

		}

		if (piv == 0)
		{
			cout << "Sistemul nu are solutie unica si alege alt y0"<<endl;
			goto pasul2;
		}
		
		for (i = k + 1; i <= n; i++)
		{
			y[i][k] = y[i][k] / y[k][k];
			for (j = k + 1; j <= n + 1; j++)
			{
				y[i][j] = y[i][j] - y[i][k] * y[k][j];
			}
		}
	}
	if (y[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica alege alt y0"<<endl;
		goto pasul2;
	}
	y[n][n + 1] = y[n][n + 1] / y[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		S = 0;
		for (j = i + 1; j <= n; j++)
		{
			S = S + y[i][j] * y[j][n + 1];
		}
		y[i][n + 1] = (y[i][n + 1] - S) / y[i][i];
	}
	for (i = 1; i <= n; i++)
	{
		cout << "C" << i << "=" << y[i][n + 1] << endl;

	}
	//cout << "numarul de permutari este =" << permutare;

}