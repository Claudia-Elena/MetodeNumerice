#include<iostream>
using namespace std;
int main()
{
	int n, i, j, k,h;
	float a[100][100], b[100][100], d[100][100],c[100];
	
	///Pasul1////////////////////
	cout << "Citeste n= ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)

		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
			
		}
	}
	///Pasul2////////////////////
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)

		{
			if (i == j) {
				b[i][j] = 1;
			}
			else
			{
				b[i][j] = 0;
			}
			cout << endl;
		}
	}
	///Pasul3////////////////////
for (k = 1; k <=n-1; k++)
{
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = 0;
			for (h = 1; h <= n; h++)
			{
				d[i][j] = d[i][j] + a[i][h] * b[h][j];
			}
		}
	}
	c[k] = 0;
	for (i = 1; i <= n; i++)
	{
		c[k] = c[k] + d[i][i];
	}
	c[k] = -c[k] / k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j) {
				b[i][j] = d[i][j]+c[k];
			}
			else
			{
				b[i][j] = d[i][j];
			}
		}
	}
}
///Pasul4////////////////////
for (i = 1; i <= n; i++)
{
	for (j = 1; j <= n; j++)
	{
		d[i][j] = 0;
		for (h = 1; h <= n; h++)
		{
			d[i][j] = d[i][j] + a[i][h] * b[h][j];
		}
	}
}
///Pasul5////////////////////
c[n] = 0;
///Pasul6////////////////////
for (i = 1; i <= n; i++)
{
	c[n] = c[n] + d[i][i];
}
c[n] = -c[n] / n;
///Pasul7////////////////////
if (c[n] == 0)
{
	cout << "Matricea nu este inversabila";
}
else
{
	cout << "Matricea inversabila este "<<endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			float f = -b[i][j] / c[n];
			cout << f << " ";
		}
		cout << endl;
	}
}cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "Coeficientii polinomului caracteristic sunt" << c[i]<<" ";
		cout << endl;
	}


}