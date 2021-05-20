#include<iostream>
#include<math.h>
using namespace std;
float g(float x)
{
	return 4. / sqrt(x + 3);
}
int main()
{
	float X0, eps, itmax,dif,X1,it=0;
	cout << " Citim X0=";
	cin >> X0;
	cout << "Citim epsilon=";
	cin >> eps;
	cout << "Citim numarul maxim de iteratii =";
	cin >> itmax;
	do {
		X1 = g(X0);
		dif = fabs(X1 - X0);
		X0 = X1;
		it++;
	} while ((dif > eps)  && (it <= itmax));

	if (it > itmax)
	{
		cout << "Nu se poate obtine solutia in" << itmax << "iteratii cu precizia" << eps<<endl;

	}
	cout << "Solutia obtinuta in " << it << " iteratii cu precizia" << eps << "este" << X1;
}