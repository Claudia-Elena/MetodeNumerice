/*#include<iostream>
using namespace std;
int main()
{
	int n,  i, j;
	double a[10][11];
	cout << "Citit n=";
		cin >> n;
	// citim elementele matricei A
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n+1; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin>>a[i][j];
		}

	int k;
	//PASUL1
	for (k = 1; k <= n - 1; k++)
	{
		if (a[k][k] != 0)
		{
			for (i = k + 1; i <= n; i++)
			{
				a[i][k] = a[i][k] / a[k][k];
				for (j = k + 1; j <= n + 1; j++)
				{
					a[i][j] = a[i][j] - (a[i][k] * a[k][j]);
				}
			}
		}
		else {//PASUL 2.2
			int lin;
			for (lin = k + 1; lin <= n; lin++)
			{
				lin = k;
				do {
					lin++;
				} while (a[lin][k] != 0 || lin>n);
				if (lin > n)
				{
					cout << "Sistemul nu are solutie unica";
				}
				for (j = k; j <= n + 1; j++)
				{
					float aux;
					aux = a[k][j];
					a[k][j] = a[lin][j];
					a[lin][j] = aux;
				}
			}
		}
		
	}
	//PASUL 3
	if (a[n][n] == 0)
	{
		cout << "Sistemul nu are solutie unica";
		
	}
	//Determinam xn aplicand formula (4)
	//PASUL 4
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	//Determinam xi, n − 1 ≥ i ≥ 1, aplicand formulele(5)
	double s;
	//PASUL 5
	for (i = n - 1; i >= 1; i--)
	{
		s = 0;
		for (j = i + 1; j <= n; j++)
		{
			s = s + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];
	}
	//PASUL 6
	for (i = 1; i <= n; i++)
	{
		cout << "x" << i << "=" << a[i][n + 1]<<endl;
		
	}
	

	

}*/
#include<iostream>
/* math.h header file is included for abs() function */
#include<math.h>
using namespace std;

int main()
{
	int i, j, k, n;

	cout << "\nEnter the no. of equations: ";
	cin >> n;

	/* if no of equations are n then size of augmented matrix will be n*n+1. So here we are declaring 2d array 'mat' of size n+n+1 */
	float mat[100][101];

	/* for n equations there will be n unknowns which will be stored in array 'res' */
	float res[100];

	cout << "\nEnter the elements of the augmented matrix: ";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (abs(mat[i][i]) < abs(mat[j][i]))
			{
				for (k = 0; k < n + 1; k++)
				{
					/* swapping mat[i][k] and mat[j][k] */
					mat[i][k] = mat[i][k] + mat[j][k];
					mat[j][k] = mat[i][k] - mat[j][k];
					mat[i][k] = mat[i][k] - mat[j][k];
				}
			}
		}
	}

	/* performing Gaussian elimination */
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			float f = mat[j][i] / mat[i][i];
			for (k = 0; k < n + 1; k++)
			{
				mat[j][k] = mat[j][k] - f * mat[i][k];
			}
		}
	}

	/* Backward substitution for discovering values of unknowns */
	for (i = n - 1; i >= 0; i--)
	{
		res[i] = mat[i][n];

		for (j = i + 1; j < n; j++)
		{
			if (i != j)
			{
				res[i] = res[i] - mat[i][j] * res[j];
			}
		}
		res[i] = res[i] / mat[i][i];
	}

	cout << "\nThe values of unknowns for the above equations=>\n";
	for (i = 0; i < n; i++)
	{
		cout << res[i] << "\n";
	}

	return 0;
}
