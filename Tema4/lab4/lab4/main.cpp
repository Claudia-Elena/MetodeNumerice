#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, i;
	float a[100], b[100], c[100], t[100];
	cout << "n=";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	for (i = 1; i < n; i++)
	{
		cout << "b[" << i << "]=";
		cin >> b[i];
	}
	for (i = 1; i < n; i++)
	{
		cout << "c[" << i << "]=";
		cin >> c[i];
	}
	for (i = 1; i <= n; i++)
	{
		cout << "t[" << i << "]=";
		cin >> t[i];
	}

	for (i = 1; i < n; i++)
	{
		if (a[i] == 0)
		{
			cout << "�Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia" << i;
		}
		c[i] = c[i] / a[i];
		cout << "c= " << c[i] << endl;
		a[i + 1] = a[i + 1] - b[i] * c[i];
		cout << "a= " << a[i] << endl;
	}

	for (i = 2; i <= n; i++)
	{
		t[i] = t[i] - c[i-1] * t[i-1];
		cout <<"t= "<< t[i] << endl;
	}
	if (a[n] == 0)
	{
		cout << "�Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia" << n;
	}
	t[n] = t[n] / a[n];

	cout << "t= " << t[n] << endl;
	for (i = n - 1; i >= 1; i--)
	{
		t[i] = (t[i] - b[i] * t[i + 1]) / a[i];

		cout << "t= " << t[i] << endl;
	}
	for (i = 1; i <= n; i++)
	{
		cout << "X" << i << "=" << t[i] << endl;
	}
}