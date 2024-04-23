#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include <vector>

using namespace std;

string file_name="f.txt";

struct worker
{
    string fio;
    unsigned int oklad;
    char pol;
    string doljnost;

};

 ostream& operator<<(ostream& out, worker a)
 {
     out  << a.fio<<endl;
     out  << a.doljnost<<endl;
     out  << a.oklad<<endl;
     out  << a.pol << endl;
     return out;
 }
istream& operator>> (istream& in, worker& a)
{
    /*char c;
    in >> c;
    while (c !='\n') {
        a.fio+=c;
    }
    while (c !='\n') {
        a.doljnost+=c;
    }*/
    getline(in,a.fio);
    getline(in,a.doljnost);
    in>>a.oklad;
    in>>a.pol;
    return in;
}

int main()
{



    ofstream f_out;
    f_out.open(file_name);
    if (!f_out.is_open())
    {
      cout << "Error open file!  \n";
      return -1;
    }

    vector<worker> w_list;
    bool error = false;
    char next='y';
    int i=0;
    while (next == 'y')//заполнение
    {
            worker curr;
            cout << "sotrudnik # " << i + 1 << ": " << endl << endl;
            cout << "f.i.o.: ";
            cin.ignore();
            getline(cin, curr.fio);
            cout << "doljnost: ";
            getline(cin, curr.doljnost);
            cout << "oklad: ";
            cin >> curr.oklad;
            cout << "pol:";
            cin >> curr.pol;
            cin.get();
            w_list.push_back(curr);
            cout << "resume? y/n: ";
            cin >> next;
            system("clear");
            i++;

    }


    i=1;
    for (typename vector<worker>::iterator it = w_list.begin(); it != w_list.end(); it++)
    {
        /*//stream1.write((char*) &worker1, sizeof(employee));
        f_out.write( (char*) &(*it),sizeof (worker));
        //f_out << "sotrudnik # " << i << "\n";
        cout << "sotrudnik # " << i << "\n";
        //f_out << "f.i.o.: " << (*it).fio << "\n";
        cout << "f.i.o.: " << (*it).fio << "\n";
        //f_out << "doljnost: " << (*it).doljnost << "\n";
        cout << "doljnost: " << (*it).doljnost << "\n";
        //f_out << "oklad: " << (*it).oklad << "\n";
        cout << "oklad: " << (*it).oklad << "\n";
        //f_out << "pol: " << (*it).pol << "\n";
        cout << "pol: " << (*it).pol << "\n";
        f_out << "\n";
        i++;*/
        f_out << (*it);
        //cout << (*it);

    }
        f_out.close();
        ifstream f_in(file_name);
        f_in.open(file_name);
        if (!f_in.is_open())
        {
          cout << "Error open in file!  \n";
          return -1;
        }
        worker a;
        f_in >> a;
        cout << a <<" **** "<<endl;
        /*while(!f_in.eof())
        {

        }*/

    /*f_out << endl;
    unsigned int fond = 0;
    unsigned short mans = 0, womens = 0;
    unsigned int fmans = 0, fwomens = 0;
    for (typename vector<worker>::iterator it = w_list.begin(); it != w_list.end(); it++)
    {
        if ((*it).pol == 'm')
        {
            mans++;
            fmans += (*it).oklad;
        }
        else if ((*it).pol == 'w')
        {
            womens++;
            fwomens += (*it).oklad;
        }
        else
        {
            error = true;
            cout << "gender_error" << endl;
            return 0;
        }
    }

    f_out << "\n";
    f_out << "\n";
    f_out << "\n";

    fond = fmans + fwomens;
    f_out << "full fond: " << fond <<endl;
    cout << "full fond: " << fond << endl;
    f_out << "mans: " << mans << " womans: " << womens << endl;
    cout << "mans: " << mans << " womans: " << womens << endl;
    f_out << "fond mans: " << fmans << " fond womans: " << fwomens << endl;
    cout << "fond mans: " << fmans << " fond womans: " << fwomens << endl;
    f_out.close();*/
    return 0;
}
