#ifndef UTILITY_2_H
#define UTILITY_2_H

#include </home/egor/Документы/c++/OOP_3/utility_1.h>


class manager
{
    student stud;
    employee empl;
    string struct_name;
public:
    manager();
    manager(int id,string name,string degree);
    void set_struct_name(const string& struct_name);
    string get_struct_name();
};

manager::manager()
{
    stud.set_id(0);
   stud.set_degree("manager");
}

manager::manager(int id, string name,string degree)
{
    stud.set_id(id);
    stud.set_name(name);
    empl.set_post("manager");
    stud.set_degree(degree);
}

void manager::set_struct_name(const string &struct_name)
{
    this->struct_name = struct_name;
}

string manager::get_struct_name()
{
    return struct_name;
}


class scientist
{
    student stud;
    employee empl;
    string curr_project;
public:
    scientist();
    scientist(int id,string name,string degree);
    void set_project(const string& project);
    string get_project();
};

scientist::scientist()
{
    stud.set_id(0);
    stud.set_degree("scientist");
}

scientist::scientist(int id, string name,string degree)
{
    stud.set_id(id);
    stud.set_name(name);
    empl.set_post("scientist");
    stud.set_degree(degree);
}

void scientist::set_project(const string &project)
{
    curr_project = project;
}

string scientist::get_project()
{
    return curr_project;
}

class laborer
{
    employee empl;
    string curr_work;
public:
    laborer();
    laborer(int num, string name);
    void set_curr_work(const string& curr_work);
    string get_curr_work();
};

laborer::laborer()
{
    empl.set_num(0);
    empl.set_post("laborer");
}

inline laborer::laborer(int num, string name)
{
     empl.set_num(num);
    empl.set_post("laborer");
     empl.set_surname(name);
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
