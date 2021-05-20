#include<iostream>
#include<math.h>

using namespace std;

double f(float x,float y) {
    return (y/pow((x*y+1),x));
    //return ((x * y - 1) / (pow(x, 2) + pow(y, 2) + 1));
}
int main()
{
    double x1, x2, y1, y2, x3, y3, l1, l2, l3, p = 0, S = 0,I1 = 0, I2 = 0,I=0;
    cout << "Introduceti x1 ";
    cin >> x1;
    cout << "Introduceti y1 ";
    cin >> y1;
    cout << "Introduceti x2 ";
    cin >> x2;
    cout << "Introduceti y2 ";
    cin >> y2;
    cout << "Introduceti x3 ";
    cin >> x3;
    cout << "Introduceti y3 ";
    cin >> y3;
    l1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    l2 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    l3 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    p = (l1 + l2 + l3) / 2;
    S = sqrt(p * (p - l1) * (p - l2) * (p - l3));
    I1 = (S / 12) * (f(x1, y1) + f(x2, y2) + f(x3, y3) + 9 * f(((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3)));
    cout << "Valoarea integralei este I1=" << I1<<endl;
    cout << "Introduceti x1 ";
    cin >> x1;
    cout << "Introduceti y1 ";
    cin >> y1;
    cout << "Introduceti x2 ";
    cin >> x2;
    cout << "Introduceti y2 ";
    cin >> y2;
    cout << "Introduceti x3 ";
    cin >> x3;
    cout << "Introduceti y3 ";
    cin >> y3;
    l1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    l2 = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
    l3 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    p = (l1 + l2 + l3) / 2;
    S = sqrt(p * (p - l1) * (p - l2) * (p - l3));
    I2 = (S / 12) * (f(x1, y1) + f(x2, y2) + f(x3, y3) + 9 * f(((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3)));
    cout << "Valoarea integralei este I2=" << I2<<endl;
    I = I1 + I2;

    cout << "Valoarea integralei este I=" << I;


}