#include <iostream>
#include <string>
#include <clocale>
using namespace std;

string rest(string str);
bool isestrpty(string str);
bool isodd(string str);
bool iseven(string str);

bool chet(string str)
{
    if (str[0] == '\0')//empty
    return true;
    else
    {
        int i;
        for (i = 0; str[i + 1] != '\0'; i++) 
        {
            str[i] = str[i + 1];
        }
        str[i] = '\0';
        
        if (str[0] == '\0')
        {
            //empty
            return false;
        }
        else
        {
            int j;
            for (j = 0; str[j + 1] != '\0'; j++) 
            {
                str[j] = str[j + 1];
            }    
            str[i] = '\0';
            chet(str);
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    cout << "Прямая рекурсия" << endl;
    string str;
    cout << "Введите строку:" << endl;
    cin >> str;
    if (chet(str))
    cout << "Чётное количество знаков" << endl;
    else cout << "Нечётное количество знаков" << endl;
    system("pause");
    return 0;
}

string rest(string str) 
{
    int i;
    for (i = 0; str[i + 1] != '\0'; i++) 
    {
        str[i] = str[i + 1];
    }
    str[i] = '\0';
    return str;
}
bool isestrpty(string str) 
{
    if (str[0] == '\0')
    return true;
    else
    return false;
}
bool iseven(string str) 
{
    if (isestrpty(str))
    return true;
    else
    return isodd(rest(str));
}
bool isodd(string str) 
{
    if (isestrpty(str))
    return false;
    else
    return iseven(rest(str));
}   