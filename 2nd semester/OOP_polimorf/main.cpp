#include <iostream>
#include <string>

using namespace std;


class plant
{

public:

    virtual void show()
    {
        cout << "it is plant" << endl;
    }
};

class flower : public plant
{

public:
    void show()
    {
        cout << "it is flower" << endl;
    }
};

class fruit : public plant
{

public:
    void show()
    {
        cout << "it is fruit"<<endl;
    }
};

class Vegetable : public plant
{

public:
    void show()
    {
        cout << "it is Vegetable"<<endl;
    }
};


int main()
{

    plant *plant_list[5];
    plant_list[0] = new plant;
    plant_list[1] = new flower;
    plant_list[2] = new fruit;
    plant_list[3] = new flower;
    plant_list[4] = new Vegetable;

    for(int i = 0; i< 5;i++)
    {
        plant_list[i]->show();
    }
    return 0;
}
