namespace coutdown_to_shutdown
{
    using namespace std;

    #define def void
    #define elif else if

    def countdown(int Ti, string command = "shutdown /S /t 1"); //prototype

    struct result_divmod 
    {
        int first, second;
    };
    
    def divmod(int &var1, int &var2,int dividend, int divisor) //เลียนแบบ python
    {
        result_divmod sum;
        sum.first = dividend/divisor;
        sum.second = dividend%divisor;


        var1 = sum.first;
        var2 = sum.second;
    }

    def Current_time(int Ti)
    {
        system("cls");
        int year = 0,day = 0,hour = 0,min = 0,sec = Ti;
        char space [] = " ";

        //min, sec = divmod(Ti,60) //return 2 ค่าไม่ได้หรอ

        divmod(min,sec,Ti,60);
        divmod(hour,min,min,60);
        divmod(day,hour,hour,24);
        divmod(year,day,day,365);


        if(year)
        {
            cout << " ปี : วัน : ชั่วโมง : นาที : วินาที" << endl;
            printf("%.2d : %.2d :   %.2d  :  %.2d :  %.2d",year,day,hour,min,sec);
        }
        elif(day)
        {
            cout << "วัน : ชั่วโมง : นาที : วินาที" << endl;
            printf("%.2d :   %.2d  :  %.2d :  %.2d",day,hour,min,sec);
        }
        elif (hour)
        {
            cout << "ชั่วโมง : นาที : วินาที" << endl;
            printf("  %.2d  :  %.2d :  %.2d",hour,min,sec);
        }
        elif (sec) 
        {
            cout << "นาที : วินาที" << endl;
            printf(" %.2d :  %.2d",min,sec);
        }


    }

    char toupper_char (char ANS)
    {
        return toupper(ANS);
    }

    def sub_main_countdown_2(int Ti)
    {
        char ANS[3];
        cout << "อยากให้นับต่อ (1) หรือนับใหม่ (2) ดีล่ะ" << endl;
        cin >> ANS;
        cin.clear();
        fflush(stdin);

        char ans = ANS[0];

        if(ANS[1] != '\0')
        {
            cout << "เรารู้จักแค่ 1 กับ 2 แค่นั้นฮะ" << endl;
            sub_main_countdown_2(Ti);
        }
        elif(ans == '1') 
        {
            cout << "ได้เลย" << endl;
            countdown(Ti);
        }
        elif(ans == '2')
        {
            int sec;
            cout << "OK" << endl;
            cout << "นับเท่าไรดีล่ะ (ครั้งนี้ใส่ 0 ได้นะ) : ";
            do
            {
                cin >> sec;
                cin.clear();
                fflush(stdin);  

                if(sec < 0) cout << "ฉันนับถอยหลังแบบเลขติดลบไม่เป็นอ่ะ ขอเลขใหม่ได้ไหม" << endl;
            }
            while (sec < 0);
            countdown(sec);
        }
        else 
        {
            cout << "ไหว้ละ ตอบ 1 หรือ 2 เถอะนะ เราไม่เข้าใจตัวอักษรอื่นจริงๆ" << endl;
            sub_main_countdown_2(Ti);
        } 

    }

    def main_countdown_2(int Ti)
    {
        char ANS[3];
        cout << "จะให้ฉันนับถอยหลังเพื่อปิดเครื่องอีกไหม (y/n) :";
        cin >> ANS; 
        cin.clear();
        fflush(stdin);
        char ans = ANS[0];

        if(ANS[1] != '\0')
        {
            cout << "เราเข้าใจแค่ y กับ n นะ" << endl;
            main_countdown_2(Ti);
        }
        elif(toupper_char(ans) == 'Y') 
        {
            cout << "ได้เลย" << endl;
            sub_main_countdown_2(Ti);
        }
        elif(toupper_char(ans) == 'N') 
        {
            cout << "OK" << endl;
        }
        else 
        {
            cout << "คือเราถูกเขียนมาให้รู้จักแค่ y กับ n อ่ะดิ" << endl;
            main_countdown_2(Ti);
        } 

    }

    def print_before_shudown()
    {
        string say = "\nแล้วเจอกันใหม่นะ";

        my_command::cout_string_dalay(say);
        Sleep(2000);
    }

    def countdown(int Ti,string command)
    {
        bool sure = true, running = true, start = false,started = false; 
        cout << "กด 1 เพื่อเริ่มนับ";
    
        while (running)
        {
            if (GetAsyncKeyState(VK_ESCAPE) && started) 
            {
                running = false;
                sure = false;
                start = false;
                started = false;
                system("cls");
                cout << "โอเค ฉันหยุดนับแล้ว" << endl;
            }
            else if(GetAsyncKeyState('1'))
            {
                start = true;
                started = true;
            }

            if (start) 
            {
                Current_time(Ti);
                Ti--;
                Sleep(1000);
            }

            if(Ti <= 0 && started)   break;
        }

        if(sure)
        {
            print_before_shudown();  
            //cout << "shutdown" << endl << command;
            system("shutdown /S /t 1");
            exit(0); // เผื่อโค้ดไม่ทำงานเลยบังคับให้มันออกไปก่อน
        }

        else main_countdown_2(Ti);
    }

    def main_countdown_1()
    {
        int second;
        system("cls");
        string say = "ฉันไม่แน่ใจนะว่าฉันจะนับตรงไหมแต่\nนับกี่วินาทีดีล่ะ (ถ้ายกเลิกให้ใส่ 0 นะ) : ";
        my_command::cout_string_delay_not_endl(say);

        do
        {
            cin >> second;
            cin.clear();
            fflush(stdin);

            if(second < 0) cout << "ฉันนับถอยหลังแบบเลขติดลบไม่เป็นอ่ะ ขอเลขใหม่ได้ไหม" << endl;
        }
        while (second < 0);

        if(second) 
        {
            say = "OK ถ้าจะหยุดก่อนก็กด esc นะ\nแล้วก็อย่าลืมเซฟงานทุกอย่างก่อนด้วยล่ะ เดี๋ยวงานจะหายเอา\n";
            my_command::cout_string_delay_not_endl(say);
            countdown(second);
        }
        else 
        {
            cout << "ได้เลย เรายกเลิกคำสั่งแล้ว"<< endl;
        }

        cout << "อออกจากฟังก์ชั่นนับเวลาแล้ว" << endl;
    }
}