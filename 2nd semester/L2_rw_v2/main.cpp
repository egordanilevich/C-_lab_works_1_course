#include<iostream>
#include<cmath>
#include<string>
#include<fstream>


const int n = 2;
using namespace std;
const string f_name = "f.txt";
struct worker
{
    string fio;
    unsigned int oklad;
    char pol;
    string doljnost;
};
int main()
{

    ofstream fout;

    fout.open(f_name);
    if (!fout.is_open())
    {
        cout << "error open!" << endl;
        return -1;
    }
    worker m[n];
    bool error = false;
    for (int i = 0; i < n; i++)
    {

            cout << "sotrudnik " << i + 1 << ": " << endl << endl;
            cout << "f.i.o.: ";
            //cin.get();
            getline(cin, m[i].fio);
            cout << "doljnost: ";
            getline(cin, m[i].doljnost);
            cout << "oklad: ";
            cin >> m[i].oklad;
            cout << "pol: ";
            cin >> m[i].pol;
            cin.get();
            system("clear");
    }



    for (int i = 0; i < n; i++)
    {
        fout.write((char*)&m[i], sizeof(worker));
    }
    fout.close();

    ifstream out(f_name);
    for (int i = 0; i < n; i++)
    {
        out.read((char*)&m[i], sizeof(worker));
        for (int j = 0; j < n; j++)
        {
            cout<<m[j].fio<<endl;
            cout<<m[j].oklad<<endl;
            cout<<m[j].doljnost<<endl;
            cout<<m[j].pol<<endl<<endl;
        }
    }
    fout.close();


    unsigned int fond = 0;
    unsigned short mans = 0, womens = 0;
    unsigned int fmans = 0, fwomens = 0;

    for (int i = 0; i < n; i++)
    {
        if (m[i].pol == 'm')
        {
            mans++;
            fmans += m[i].oklad;
        }
        else if (m[i].pol == 'w')
        {
            womens++;
            fwomens += m[i].oklad;
        }
        else
        {
            error = true;
            cout << "error" << endl;
            return 0;
        }
    }


    fond = fmans + fwomens;

    cout << "full fond: " << fond << endl;
    cout << "mans: " << mans << " womans: " << womens << endl;
    cout << "fond mans: " << fmans <<"fond womans: " << fwomens << endl;
    fout.close();
    return 0;
}
