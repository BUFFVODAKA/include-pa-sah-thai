namespace countdown
{
    using namespace std;

    #define def void
    #define elif else if

    bool already_stop;
    int ti;

    def countdown(int Ti);
    def print_before_shudown();
    

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
            cout << "นับเท่าไรดีล่ะ : ";
            cin >> sec;
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
        cout << "จะให้ฉันนับถอยหลังเอีกไหม (y/n) :";
        cin >> ANS; 
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

    def open_song()
    {
        vector <string> song_name = {"song1.wav","song2.mp3","song3.mp3"};
        vector <int> time = {230,15,124};

        int index = rand()%song_name.size();
        
        string song = "song\\"+song_name[index];
        ti = time[index];

        system(song.c_str());
    }

    def countdown_again(int Ti)
    {
        bool sure = true,running = true, start = true,started = true; 
    
        while (Ti)
        {
            if (GetAsyncKeyState(VK_ESCAPE) && started) 
            {
                //running = false;
                sure = false;
                Ti = 0;
                start = false;
                running = false;
                //system("TASKKILL /F /IM Media Player.exe"); // bug โปรแกมมีช่องว่าง
                system("cls");
                cout << "โอเค ฉันหยุดนับแล้ว" << endl;
            }

            if (start) 
            {
                Current_time(Ti);
                Ti--;
                cout << "\nถ้าหมดเวลา ฉันจะเปิดเพลงอีกครั้ง (ถ้าอยากให้หยุดก็กด esc สิ)" << endl;
                Sleep(1000);
            }

            if(!(Ti))   break;
        }

        if(sure)
        {
            ti =0;
            print_before_shudown();
        }
    }

    def print_before_shudown()
    {
        string say = "\nฉันจะเปิดเพลงแล้วนะ";

        my_command::cout_string_dalay(say);
        Sleep(2000);
        open_song();

        if(!already_stop)countdown_again(ti);

    }

    def countdown(int Ti)
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

            if(!(Ti))   break;
        }

        if(sure)
        {
            print_before_shudown();  
            //cout << "shutdown" << endl << command;//system("shutdown /S /t 1");
        }

        else main_countdown_2(Ti);
    }

    def main_countdown_1()
    {
        srand(time(0));
        already_stop = false;
        int second;
        system("cls");
        string say = "ฉันไม่แน่่ใจนะว่าฉันจะนับตรงไหมแต่\nนับกี่วินาทีดีล่ะ (ถ้ายกเลิกให้ใส่ 0 นะ) : ";
        my_command::cout_string_delay_not_endl(say);

        do
        {
            cin >> second;
            cin.ignore();

            if(second < 0) cout << "ฉันนับถอยหลังแบบเลขติดลบไม่เป็นอ่ะ ขอเลขใหม่ได้ไหม" << endl;
        }
        while (second < 0);

        if(second) 
        {
            say = "OK ถ้าจะหยุดก่อนก็กด esc นะ\nแล้วก็ถ้าไม่มากดฉันก็จะเปิดเพลงอยู่อย่างนี้แหละ\n";
            my_command::cout_string_delay_not_endl(say);
            countdown(second);
        }
        else 
        {
            cout << "ได้เลย เรายกเลิกคำสั่งแล้ว"<< endl;
        }

        system("cls");
        cout << "เพลงที่เปิดไว้ก็ปิดเองเลยละกันนะ\n";
        cout << "ออกจากฟังก์ชั่นนับถอยหลังแล้ว\n\n" << endl;
    }
}