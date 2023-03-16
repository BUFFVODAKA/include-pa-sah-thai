#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

ifstream RF1,RF2;

class Store
{
    vector <string> menu;
    string store_name,where;
    string text;
    bool set_where = false, noname = true;
    
    public:
    Store(string);

    void show_data(); //สำหรับ debug
    bool check_menu(string input);
    int acess_menu_size(); //คิดว่าน่าจะเอาไปใช้ประกอบการสุ่ม
    string assecc_menu(int index); //เอาไว้ดึงค่าตอนสุ่ม
    string show_name();
    string show_where();
    void show_menu();
    void name_and_location();

};

Store::Store(string storename)
{
    //cout << "created class" << endl; //debug
    store_name = storename;
    string filename = "Data//Menu_in_store//" + storename +".txt";
    RF2.open(filename);
    while(getline(RF2, text))
    {
        //cout << text << endl; //debug
        if(text == "where")
        {
            set_where = true;
            continue;
        }

        if(set_where)
        {
            where = text;
            set_where = false;
            continue;
        }

        if(text == "/where") continue;

        menu.push_back(text);

    }
    RF2.close();
}

void Store::show_data() //สำหรับ debug
{
    cout << "store " << store_name << " at " << where << endl << "menu\n";
    for(string i: menu) cout << i << endl;
    cout << endl;
}

bool Store::check_menu(string input)
{
    bool a;
    for(string i: menu)
    {
        a = (i == input)? true: false;

        if(a) break;
    }

    return a;
}

int Store::acess_menu_size() //คิดว่าน่าจะเอาไปใช้ประกอบการสุ่ม
{
    return menu.size();
}

string Store::assecc_menu(int index) //เอาไว้ดึงค่าตอนสุ่ม
{
    return menu[index];
}

string Store::show_name()
{
    return store_name;
}

string Store::show_where()
{
    return where;
}

void Store::show_menu()
{
    for(string i: menu) cout << i << endl;
    cout << endl;
}

void Store::name_and_location()
{
    cout << "ร้าน " << store_name << " อยู่ที่ " << where << endl;
}


