#ifndef UTILITY_1_H
#define UTILITY_1_H

#include <iostream>
#include <string>

using namespace std;

class student
{
private:
    string name;
    int id = 0;
    string degree;
public:
    student(){};
    student(string name,int id,string degree);
    int get_id();
    void set_id(const int id);
    string get_name();
    void set_name(const string& name);
    string get_degree();
    void set_degree(const string& degree);
};


student::student(string name, int id, string degree)
{
    this->name=name;
    this->id=id;
    this->degree=degree;
}

int student::get_id()
{
    return id;
}

void student::set_id(const int id)
{
    this->id = id;
}

string student::get_name()
{
    return name;
}

void student::set_name(const string &name)
{
    this->name = name;
}

string student::get_degree()
{
    return degree;
}

void student::set_degree(const string &degree)
{
    this->degree = degree;
}






class employee
{
protected:
    string surname;
    int num;
    string post;
public:
    employee(){};
    employee(string name,int num,string degree);
    int get_num();
    void set_num(const int num);
    string get_surname();
    void set_surname(const string& name);
    string get_post();
    void set_post(const string& post);
};

employee::employee(string surname, int num, string post)
{
    this->surname=surname;
    this->num=num;
    this->post=post;
}

int employee::get_num()
{
    return num;
}

void employee::set_num(const int num)
{
        this->num = num;
}

string employee::get_surname()
{
    return surname;
}

void employee::set_surname(const string &surname)
{
    this->surname = surname;
}

string employee::get_post()
{
    return post;
}

void employee::set_post(const string &post)
{
    this->post = post;
}


#endif // UTILITY_1_H
