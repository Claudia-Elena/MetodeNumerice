#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, i, j, ITmax, IT;
	double a[100][100], b[100], x[100], y[100], max, S, eps;
	cout << "Citeste n=";
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

	for (i = 1; i <= n; i++)

	{
		cout << "b[" << i << "]=";
		cin >> b[i];
		cout << endl;
	}

	cout << "Citeste epsilon=";
	cin >> eps;
	cout << endl;
	cout << "Citeste numarul maxim de iteratii=";
	cin >> ITmax;
	for (i = 1; i <= n; i++)

	{
		cout << "x[" << i << "]=";
		cin >> x[i];
		cout << endl;
	}

	IT = 0;
	do {
		max = 0;
		for (i = 1; i <= n; i++)
          
		{
			S = 0;
			for (j = 1; j <= n; j++)

			{
				if (j != i)
				{
					S = S + a[i][j] * x[j];
				}
			}
			y[i] = (b[i] - S) / a[i][i];
			if (max < abs(y[i] - x[i]))
			{
				max = abs(y[i] - x[i]);
			}
			x[i] = y[i];
		}
		//for (i = 1; i <= n; i++)
		//{
		//	x[i] = y[i];
		//}
		IT++;
	} while ((max > eps) && (IT <= ITmax));
	if (IT > ITmax)
	{
		cout << "Nu se poate obtine solutia in " << ITmax << "iteratii cu precizia" << eps << endl;
	}
	for (i = 1; i <= n; i++)
	{
		cout << "Solutia obtinuta in " << IT << "iteratii cu precizia" << eps << " este " << x[i] << endl;

	}


}