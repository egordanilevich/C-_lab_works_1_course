#include <iostream>
using namespace std;

int mod(int m, int n) {
    if (m < n)
        return m;
    else return mod(m - n, n);
}

int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else return gcd(n, mod(m, n));
}

int main() {
    //setlocale(LC_ALL, "Rus");
    int a, b;
    cout << "������� 2 �����" << endl;
    cin >> a;
    cin >> b;
    cout << "���:" << gcd(a, b) << endl;
    //system("pause");
    return 0;
}
