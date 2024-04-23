#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string file_name="f.txt";

int main()
{
    string text_s;

    ofstream first_out;
    first_out.open(file_name);//открытие файла на вывод
    if (!first_out.is_open())
    {
      cout << "Error open someone file! 1 \n";
      return -1;
    }

    cout << "input strings: \n";
    do//заполнение файла
    {
        getline(cin, text_s);
        first_out << text_s << endl;

    } while (text_s != "\0");

    first_out.close();

    ifstream first_in;
    first_in.open(file_name);//открытие файла на ввод
    if (!first_in.is_open())
    {
      cout << "Error open someone file! 2 \n";
      return -1;
    }

    vector<string> *text = new vector<string>;
    typename vector<string>::iterator it=text->begin();

    do//чтение файла
    {
        getline(first_in, text_s);
        text->push_back(text_s);

    } while (text_s != "\0");
    first_in.clear();
    first_in.close();


    ofstream second_out;
    second_out.open(file_name);//открытие файла на вывод
    if (!second_out.is_open())
    {
      cout << "Error open someone file! 3 \n";
      return -1;
    }

    for(it = text->begin(); it!= text->end(); it++)//основоной цикл обработки
    {
        text_s.clear();//выходная строка
        unsigned short i=0;
        while((*it)[i] == ',') i++;
        while ((*it)[i] != '\0')
        {
            while((*it)[i]==',' and (*it)[i+1]==',') i++;
            if((*it)[i]==',' and (*it)[i+1]!=' ')
            {
                text_s+=", ";
                i++;
            }
            else if((*it)[i]==' ' and (*it)[i+1]==',')
            {
                //text_s+=',';
                i++;
            }
            else //if((*it)[i] != ',')
            {
                text_s+=(*it)[i];
                i++;
            }
        }
            //else text_s+=(*it)[i];
          second_out << text_s << endl;
        }

    second_out.close();

    ifstream second_in;
    second_in.open(file_name);//открытие файла на ввод
    if (!second_in.is_open())
    {
      cout << "Error open someone file! 4 \n";
      return -1;
    }
    while (!second_in.eof())//вывод полученного
    {
        getline(second_in, text_s);
        cout << text_s << "\n";
    }

    return 0;
}
