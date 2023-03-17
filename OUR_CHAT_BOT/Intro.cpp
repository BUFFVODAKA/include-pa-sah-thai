#include <iostream>
#include <string>
#include <vector>
#include <Windows.h> //Sleep()
#include <fstream>
#include <ctime>
#include <iomanip>
#include <conio.h> //getch()
#include <algorithm>

#include "AI_working.h" //my_header

using namespace std;

void give_name(string &);

void Nono(string &name)
{
    system("cls"); //ใช้เคลียร์ terminal
    cout << "y and n only" << endl;
}

void give_name(string &name)
{
    string say = "คุณต้องการตั้งชื่อให้ chat bot ของเราหรือไม่ (y/n)";
    vector <string> _say = {"ชื่อ Chat bot นี้ถูกตั้งเป็นค่าเริ่มต้น ("+name+") เรียบร้อยแล้ว","กรุณาใส่ชื่อที่คุณต้องการ (ถ้าไม่ใส่อะไรเลยชื่อจะกลายเป็นชื่อเริ่มต้น (" +name+") และ Enter เฉยๆ ก็ถือว่าใส่ชื่อแล้วนะ) ถ้าเป็นภาษาไทยหรือภาษาอื่นมัน cin ไม่ได้นะ"};
    my_command::cout_string_dalay(say);

    bool flag = false;

    do
    {
        string ans, say;

        cin >> ans;
        cin.clear(); //สำหรับเคลียร์ตัวที่เหลือ
        fflush(stdin); //ใช้กับ clear

        if (ans.size() > 1)
        {
            system("cls"); //ใช้เคลียร์ terminal
            cout << "y and n only" << endl;
        }
        else
        {
            char _ans = ans[0];

            switch (ans[0])
            {
                case 'y':case 'Y':
                    my_command::cout_string_dalay(_say[1]); 
                    getline(cin, name);
                    say = "ชื่อ Chat bot นี้ถูกตั้งเป็น "+name+" เรียบร้อยแล้ว";
                    my_command::cout_string_dalay(say);
                    flag = true;
                    Sleep(1000);
                    break;
                case 'n':case 'N':
                    my_command::cout_string_dalay(say); 
                    Sleep(1000);
                    flag = true;
                    break;
                default:
                    system("cls"); //ใช้เคลียร์ terminal
                    Nono(name);
                    break;
            }
        }
    }
    while(flag != true);

}

int main()
{
    srand(time(0));
    system("cls");
    string name = "อับดุล"; // เปลี่ยนชื่อได้นะ

    give_name(name);
    system("cls");

    active_ai_intro(name);
    cout << name+" กลับไปนอนแล้ว";

    Sleep(2000);
}


