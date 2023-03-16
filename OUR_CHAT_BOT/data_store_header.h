/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;*/

ifstream RF1_1,RF2_2;

class Store_3
{
    vector <string> menu;
    string store_3_name,where;
    string text;
    bool set_where = false, noname = true;
    
    public:
    Store_3(string);

    void show_data(); //สำหรับ debug
    bool check_menu(string input);
    int acess_menu_size(); //คิดว่าน่าจะเอาไปใช้ประกอบการสุ่ม
    string assecc_menu(int index); //เอาไว้ดึงค่าตอนสุ่ม
    string show_name();
    string show_where();
    void show_menu();
    void name_and_location();

};

Store_3::Store_3(string store_3name)
{
    //cout << "created class" << endl; //debug
    store_3_name = store_3name;
    string filename = "Data//Menu_in_store//" + store_3name +".txt";
    RF2_2.open(filename);
    while(getline(RF2_2, text))
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
    RF2_2.close();
}

void Store_3::show_data() //สำหรับ debug
{
    cout << "store_3 " << store_3_name << " at " << where << endl << "menu\n";
    for(string i: menu) cout << i << endl;
    cout << endl;
}

bool Store_3::check_menu(string input)
{
    bool a;
    for(string i: menu)
    {
        a = (i == input)? true: false;

        if(a) break;
    }

    return a;
}

int Store_3::acess_menu_size() //คิดว่าน่าจะเอาไปใช้ประกอบการสุ่ม
{
    return menu.size();
}

string Store_3::assecc_menu(int index) //เอาไว้ดึงค่าตอนสุ่ม
{
    return menu[index];
}

string Store_3::show_name()
{
    return store_3_name;
}

string Store_3::show_where()
{
    return where;
}

void Store_3::show_menu()
{
    for(string i: menu) cout << i << endl;
    cout << endl;
}

void Store_3::name_and_location()
{
    cout << "ร้าน " << store_3_name << " อยู่ที่ " << where << endl;
}


