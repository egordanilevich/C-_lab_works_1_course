#ifndef UTILITY_2_H
#define UTILITY_2_H

#include <utility_1.h>

class manager:private student, private employee
{
    string struct_name;
public:
    manager();
    manager(int id,string name,string degree);
    void set_struct_name(const string& struct_name);
    string get_struct_name();
};

manager::manager()
{
    set_id(0);
    set_degree("manager");
}

manager::manager(int id, string name,string degree)
{
    set_id(id);
    set_name(name);
    set_post("manager");
    set_degree(degree);
}

void manager::set_struct_name(const string &struct_name)
{
    this->struct_name = struct_name;
}

string manager::get_struct_name()
{
    return struct_name;
}


class scientist:private student, private employee
{
    string curr_project;
public:
    scientist();
    scientist(int id,string name,string degree);
    void set_project(const string& project);
    string get_project();
};

scientist::scientist()
{
    set_id(0);
    set_post("scientist");
}

scientist::scientist(int id, string name,string degree)
{
    set_id(id);
    set_name(name);
    set_post("scientist");
    set_degree(degree);
}

void scientist::set_project(const string &project)
{
    curr_project = project;
}

string scientist::get_project()
{
    return curr_project;
}

class laborer: public employee
{
    string curr_work;
public:
    laborer();
    laborer(int num, string name);
    void set_curr_work(const string& curr_work);
    string get_curr_work();
};

laborer::laborer()
{
    num = 0;
    post = "laborer";
}

inline laborer::laborer(int num, string name)
{
    this->num = num;
    post = "laborer";
    surname = name;
}

void laborer::set_curr_work(const string &curr_work)
{
    this->curr_work = curr_work;
}

string laborer::get_curr_work()
{
    return curr_work;
}


#endif // UTILITY_2_H
