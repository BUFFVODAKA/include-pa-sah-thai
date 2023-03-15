namespace main_function  
{
    #define pass (void)0 //debug

    int want_me_to_work;

    void continue_check()
    {
        cout <<  "อยากจะสุ่มต่อไหม\n ต้องการ ตอบ 1\n ไม่แล้ว ตอบ 2" << endl;

        vector <string> want_1_2_only = {"อ่านนะ 1 กับ 2 เข้าใจครับ หนึ่ง กับ สอง\n\n", "ใส่เลขผิด\n\n"};
        
        int index;
        string ans;
        cin >> ans;
        cin.clear();
        fflush(stdin);

        if(ans.size() > 1)
        {
            system("cls");
            index = rand()%2;
            cout << want_1_2_only.at(index);
            continue_check();
        }
        else
        {
            char _ans = ans[0];

            switch (_ans)
            {
            case '1':
                break;
            case '2':
                want_me_to_work = 0;
                break;
            default:
                index = rand()%2;
                system("cls");
                cout << want_1_2_only[index];
                continue_check();
                break;
            }
        }
    }

    void choice()
    {
        vector <string> command_list = {"------------------------------------","สุ่มอาหารที่มีในร้าน(1)\nสุ่มร้านจากอาหาร(2)\nสุ่มทั้งคู๋(3)\nพอละ ไม่ต้องสุ่มละ(4)"};

        my_command::showcommand_and_line(command_list);

        string ans;
        cin >> ans;
        cin.clear();
        fflush(stdin);

        if(ans.size() > 1)
        {
            system("cls");
            cout << "ฉันเข้าใจแต่ 0-2 อ่ะ อย่าแกล้งกันได้ไหม\n";
            choice();
        }
        else 
        {
            char _ans = ans[0];
            
            switch (_ans)
            {
            case '1':
                continue_check();
                pass;
                break;
            case '2':
                continue_check();
                pass;
                break;
            case '3':
                continue_check();
                pass;
                break;
            case '0':
                break;
            
            default:
                system("cls");
                cout << "0-3 เถอะนะ ได้โปรด\n\n";
                choice();
                break;
            }
        }
    }

    void intro_rand_food_store()
    {
        want_me_to_work = 1;

        vector <string> say = {"โอเค เดี๋ยวเราสุ่มให้นะ","ว่าแต่ สุ่มแบบไหนดีล่ะ\n"};
        my_command::cout_delay_vector_and_wait(say);

        while(want_me_to_work)
        {
            choice();
        }
        
        system("cls");
        string _exit = "ออกจากฟังก์ชั่นสุ่มร้านแล้ว\n";
        my_command::cout_string_dalay(_exit);

    }
}