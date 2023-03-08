// น่าจะต้องเอาออกตอนเอาไปใช้จริง
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
//

using namespace std;

ifstream RF1,RF2;

namespace store_data
{
    class Store
    {
        vector <string> menu;
        string store_name,where;
        string text;
        bool set_where = false, noname = true;
        
        public:
        Store(string storename)
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

        void show_data() //สำหรับ debug
        {
            cout << "store " << store_name << " at " << where << endl << "menu\n";
            for(string i: menu) cout << i << endl;
            cout << endl;
        }

        // int check_menu(string input) //ดูว่ามีเมนูที่ผู้ใช้ใส่มาไหม 
        // {
        //     int index;
        //     bool a;
        //     for(int i =0; i<menu.size(); i++) 
        //     {
        //         a = (menu[i] == input)? true: false;

        //         if(a) 
        //         {
        //             index = i;
        //             return index; //ส่ง index ที่เมนูนั้นๆอยู่ออกไป อาจจะไม่ได้เอาไปแล้วแล้วเปลี่ยนเป็น bool func
        //         }
        //     }
        //     return 0; //หมายความว่าหาไม่เจอ
        // }

        bool check_menu(string input)
        {
            bool a;
            for(string i: menu)
            {
                a = (i == input)? true: false;

                if(a) break;
            }

            return a;
        }

        int acess_menu_size() //คิดว่าน่าจะเอาไปใช้ประกอบการสุ่ม
        {
            return menu.size();
        }

        string assecc_menu(int index) //เอาไว้ดึงค่าตอนสุ่ม
        {
            return menu[index];
        }

        string show_name()
        {
            return store_name;
        }

        string show_where()
        {
            return where;
        }

        void show_menu()
        {
            for(string i: menu) cout << i << endl;
            cout << endl;
        }

        void name_and_location()
        {
            cout << "ร้าน " << store_name << " อยู่ที่ " << where << endl;
        }

    };
}

/*void find_menu(vector <store_data::Store> data) //debug menu_check
{
    vector <store_data::Store> have_this_menu;

    for(int i =0; i <data.size(); i++)
    {
        if(data[i].check_menu("MenuD")) have_this_menu.push_back(data[i]);
    }

    for(store_data::Store i: have_this_menu)
    {
        i.name_and_location();
    }
}*/

int main()
{
    //system("cls");
    
    string text;
    string filename = "Data//Store_list.txt";
    RF1.open(filename);

    vector <store_data::Store> data;

    while(getline(RF1, text))
    {
        //cout << text << endl; //debug
        store_data::Store obj(text);
        data.push_back(obj);
    }
    RF1.close();

    //for(store_data::Store i: data) i.show_data(); //debug ดูรายการของข้อมูล

    //for(store_data::Store i: data) cout << i.show_name() << endl; //debug function

    //find_menu(data); // debug

}
