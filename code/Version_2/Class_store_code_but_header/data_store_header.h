// น่าจะต้องเอาออกตอนเอาไปใช้จริง หรือไม่ก็อาจจะปล่อยทิ้งไว้เลย
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
//

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
