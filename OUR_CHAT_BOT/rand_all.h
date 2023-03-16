#include "data_store_header.h"

    bool want_me_to_rand_all = false;

    string changtoupper(string ans)
    {
        for(int i =0; i < ans.size(); i++)
        {
            ans[i] = toupper(ans[i]);
        }
        //cout << ans << endl; //debug
        return ans;
    }

    void worng(vector<string> a, int count)
    {
        switch(count)
        {
            case 0:
                system("cls");
                cout << a[0] << endl << endl;
            default:
                system("cls");
                cout << a[1] << endl << endl;
        }
    } 

    bool ask_user_veg()
    {
        bool eat_veg;
        string ans;
        vector<string> question = {"กินผักไหม(y/n)","กิน ผัก ไหม ( Y / N )"};

        int count =0;

        cout << question[0] << endl;

        do
        {
            //cout << "enter do" << endl; debug
            cin >> ans;
            cin.clear();
            fflush(stdin);

            if(changtoupper(ans) == "Y")
            {
                eat_veg = true;
                break;
            }
            else if (changtoupper(ans) == "N")
            {
                eat_veg = false;
                break;
            }
            else
            {
                worng(question, count);
                count++;
            }
        }
        while (true);

        return eat_veg;
        
    }

    string ask_user_where()
    {
        string ans, where;
        vector<string> question = {"กินที่ไหนดีล่ะ \nที่ไหนก็ได้ สุ่มมาเถอะ (0)\nหลังมอ ตรงข้ามประตูหลังมอ (1)\nหลังมอ เลยทางม้าลายประตูศึกษา (2) \nหลังมอ ติดอาคารS1 (3)\nตรงข้ามอาคารS1 (4)\nหลังมอ ฝั่งประตูวิศวะ (5)\nหลังมอ เลยซอยวัดอุโมงค์ (6)\nหลังมอ บริเวณประตูหลังมอ (7)\nในมอ(8)\nออก (9)" ,"เรารู้จักแค่ 0 ถึง 9 อ่ะ"};

        system("cls");
        cout << question[0] << endl;

        int count =0;
        do
        {
            cin >> ans;
            cin.clear();
            fflush(stdin);

            if(ans == "1")
            {
                where = "หลังมอ ตรงข้ามประตูหลังมอ";
                break;
            }
            else if (ans == "2")
            {
                where = "หลังมอ เลยทางม้าลายประตูศึกษา";
                break;
            }
            else if (ans == "3")
            {
                where = "หลังมอ ติดอาคารS1";
                break;
            }
            else if (ans == "4")
            {
                where = "ตรงข้ามอาคารS1";
                break;
            }
            else if (ans == "5")
            {
                where = "หลังมอ ฝั่งประตูวิศวะ";
                break;
            }
            else if (ans == "6")
            {
                where = "หลังมอ เลยซอยวัดอุโมงค์";
                break;
            }
            else if (ans == "7")
            {
                where = "หลังมอ บริเวณประตูหลังมอ";
                break;
            }
            else if (ans == "8")
            {
                where = "ในมอ";
                break;
            }
            else if (ans == "9") //ออก
            {
                break;
            }

            else if(ans == "0")
            {
                want_me_to_rand_all = true;
                break;
            }
            else
            {
                worng(question, count);
                count++;
            }
        }
        while (true);

        return where;
    }

    void rand_all_main() //ใช้เป็น main ใน ฟังชั่นย่อย
    {
        srand(time(0));
        system("cls"); //clear terminal

        vector <string> say = {"โอเคๆ เดี๋ยวเราช่วยสุ่มให้","แต่ว่าช่วยตอบคำถามเรามาก่อนนะ\n"};

        my_command::cout_delay_vector_and_wait(say);

        
        RF1_1.open("Data//Store_list.txt");
        string  text;
        vector <Store_3> all_store;

        while(getline(RF1_1,text))
        {
            Store_3 create_store(text);
            all_store.push_back(create_store);
        }

        bool veg = ask_user_veg();
        string where = ask_user_where();

        if(want_me_to_rand_all)
        {
            int index = all_store.size();
            index = rand()%index;

            Store_3 A = all_store[index];

            index = A.acess_menu_size();
            index = rand()%index;

            system("cls");
            cout << "ลองไปร้าน " << A.show_name() << "ดูแล้วกัน ส่วนอาหารก็สั่ง " << A.assecc_menu(index) << endl;

            if(!veg) cout << "อย่าลืมสั่งไม่ใส่ผักด้วยนะ\n";
            cout << endl;
        }
        else
        {
            vector <Store_3> sub_store;
            int index;

            for(Store_3 i: all_store)
            {
                if(i.show_where() == where)
                {
                    sub_store.push_back(i);
                }
            }

            /*for(Store i: sub_store) //debug print data   in sub  store
            {
                i.name_and_location();
            }*/

            index = rand()%sub_store.size();

            Store_3 A = sub_store[index];

            index = A.acess_menu_size();
            index = rand()%index;

            system("cls");
            cout << "ลองไปร้าน " << A.show_name() << "ดูแล้วกัน ส่วนอาหารก็สั่ง " << A.assecc_menu(index) << endl;

            if(!veg) cout << "อย่าลืมสั่งไม่ใส่ผักด้วยนะ\n";
            cout << endl;
        }
    }

    // void debug_main() //debug print all data
    // {
    //     srand(time(0));
    //     system("cls"); //clear terminal
        
    //     RF1_1.open("Data//Store_list.txt");
    //     string  text;
    //     vector <Store> all_store;

    //     while(getline(RF1_1,text))
    //     {
    //         Store create_store(text);
    //         all_store.push_back(create_store);
    //     }

    //     for(Store i: all_store)
    //     {
    //         i.name_and_location();
    //     }
    // }
