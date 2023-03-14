#include <iostream>
#include <string>
#include <vector>
#include <Windows.h> //Sleep()
#include <fstream>
#include <ctime>
//#include <cstdlib>
#include <conio.h> //getch()
//#include <stdio.h>

#include "AI_working.h" //my_header

using namespace std;

void give_name(string &);

void Nono(string &name)
{
    system("cls"); //ใช้เคลียร์ terminal
    cout << "y and n only" << endl;
    //give_name(name);
}

void give_name(string &name)
{
    string say = "คุณต้องการตั้งชื่อให้ chat bot ของเราหรือไม่ (y/n)";
    vector <string> _say = {"ชื่อ Chat bot นี้ถูกตั้งเป็นค่าเริ่มต้น ("+name+") เรียบร้อยแล้ว","กรุณาใส่ชื่อที่คุณต้องการ (ถ้าไม่ใส่อะไรเลยชื่อจะกลายเป็นชื่อเริ่มต้น (" +name+") และ Enter เฉยๆ ก็ถือว่าใส่ชื่อแล้วนะ)"};
    my_command::cout_string_dalay(say);

    bool flag = false;

    do
    {
        char ans[3]; //แค่จองเผื่อ

        cin >> ans;
        cin.clear(); //สำหรับเคลียร์ตัวที่เหลือ
        fflush(stdin); //ใช้กับ clear

        if (ans[1] == '\0')
        {
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
                    my_command::cout_string_dalay(_say[0]);
                    Sleep(1000);
                    flag = true;
                    break;
                default:
                    Nono(name);
                    break;
            }
        }
        else 
        {
            Nono(name);
        }

    }
    while(flag != true);


}

int main()
{
    system("cls");
    string name = "AI จีบีที่"; // เปลี่ยนชื่อได้นะ

    give_name(name);
    system("cls");

    active_ai_intro(name);
    cout << name+" กลับไปนอนแล้ว";

    Sleep(2000);
}


