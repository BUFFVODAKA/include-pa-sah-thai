#include "command_list.h"
#include "shutdown_function.h"

string name;

void active_ai_intro(string name);
void Lazy_ai_intro(string name);

void talk_with_me_active()
{
    cout << "Enter talk_with_me (AI working line 9 and 100)ตอนนี้ยังไม่ได้ทำ" << endl; //เดี๋ยวค่อยทำ
}

void cho_func2_active()
{
    vector <string> list_command = {"สุ่มร้านอาหาร(1)                        (แนะนำ)","ตั้งเวลาปิดเครื่อง(2)                     (จะลองก็ได้ ตั้งใจทำอยู่นะอันนี้)","คุยเล่นกับฉัน(3)                         (ฉันใช้ if-else เด้อ ไม่ใช่ Ai อย่าหวังเยอะจะดีกว่า)","เปิดโหมบอทขี้เกียจ(4)                    (แน่ใจรึ ว่า จะเล่นอันนี้้)","ออก(5)"};
    string bye = "โอเค แล้วเจอกันใหม่นะ";

    string ANS;

    my_command::show_command(list_command);

    cin >> ANS;
    cin.clear();
    fflush(stdin);


    if (ANS.size()>1)
    {
        cout << "ขอโทษนะ เราเข้าใจแค่เลข 1-4 เท่านั้น" << endl;
        cho_func2_active();
    }
    else
    {
        char ans = ANS[0];
        
        switch(ans)
        {
            case '1': cout << "รอเรียกใช้ฟังก์ชั่นหลักของกลุ่มเรา (AI_working.h line 142 and 36)" << endl; //รอเรียกใช้ function หลักของกลุ่มเรา
                    cho_func2_active(); 
                    break; 
            case '2': //coutdown_to_shutdown:: main_countdown_1(); 
                        cout << "โค้ดนี้เอาออกไปแล้ว" << endl;
                        cho_func2_active(); break;
            case '3': talk_with_me_active();cho_func2_active(); break;
            case '4': Lazy_ai_intro(::name); break;
            case '5': 

                    for (int i = 0; i<bye.size(); i++)
                    {
                        cout << bye[i];
                        Sleep(3);
                    }
                    cout << endl;
                    break;

            default: cout<< "ขอโทษนะ เราเข้าใจแค่เลข 1-4 เท่านั้น" << endl ; cho_func2_active(); break;
        }
    }
}

void cho_func_active()
{
    string say = "นี่คือฟังก์ชั่นที่ฉันสามารถทำงานได้ในตอนนี้";

    my_command::cout_string_dalay(say);

    cout <<  "กดอะไรก็ได้เพื่อไปต่อ เพื่อไปต่อ\r";
    getch();
    cout << "                                        \r";
    cho_func2_active();
}

void active_ai_intro(string name)
    {
        ::name = name;

        string say = "สวัสดี ฉันชื่อว่า "+name+" คุณมีอะไรให้ฉันช่วยอย่างนั้นหรอ";

        my_command::cout_string_dalay(say);

        cho_func_active();
    }

//
//
//
//Lazy
//
//
//
void cho_func2_lazy();

bool do_it_or_not()
{
    srand(time(0));
    int rand_num = (rand()%100)+1;
    cout << rand_num << " (ดูเลขที่สุมมา)" << endl; //debug

    if(rand_num > 40)
    {
        //cout << "ขี้เกียจละ ฉันไปก่อนนะ" << endl;
        return false;
    }
    else return true;
}

void talk_with_me_lazy(bool do_check)
{
    if(do_check)
    {
        string say = "อะอะอะ มีอะไรล่ะ ว่ามาเลย";
        my_command::cout_string_dalay(say);
        cout << "Enter talk_with_me (AI working line 9 and 100)ตอนนี้ยังไม่ได้ทำ" << endl; //เดี๋ยวค่อยทำ
        cho_func2_lazy();
    }
    else cout << "ขี้เกียจแล้วอ่ะ ไว้คุยกันวันหลังนะ ไปละ บ้ายบาย\n";
}

void turn_off_lazy_text()
{
    string say = "Turn off Lazy mode";

    my_command::cout_string_dalay(say);
    Sleep(1000);
system("cls"); //clear
}

void cho_func2_lazy()
{
    vector <string> list_command = {"สุ่มร้าน(1)","ตั้งเวลาปิดเครื่อง(2)","คุยเล่น(3)","ปิดโหมบอทขี้เกียจ(4)","ออก(5)"};
    string bye = "โอเค แล้วเจอกัน";

    string ANS;

    my_command::show_command(list_command);


    cin >> ANS;
    cin.clear();
    fflush(stdin);

    if (ANS.size()>1)
    {
        cout << "ขอโทษนะ เราเข้าใจแค่เลข 1-4 เท่านั้น" << endl;
        cho_func2_lazy();
    }
    else
    {
        char ans = ANS[0];
        
        switch(ans)
        {
            case '1': if(do_it_or_not())
                        {
                            cout << "รอเรียกใช้ฟังก์ชั่นหลักของกลุ่มเรา (AI_working.h line 142 and 36)" << endl; //รอเรียกใช้ function หลักของกลุ่มเรา
                            cho_func2_lazy(); 
                            break; 
                        }
                        else
                        {
                            cout << "ขี้เกียจอ่ะไปเดินดูเอาเองนะ ฉันไปก่อนล่ะ" << endl;
                            break;
                        }
            case '2': if(do_it_or_not())
                        {
                            coutdown_to_shutdown:: main_countdown_1();
                            cho_func2_lazy(); 
                            break;
                        }
                        else
                        {
                            cout << "ขี้เขียจแล้วอ่ะ กดปิดเองได้เลยนะ ฉันไปล่ะ" << endl; 
                            break;
                        }
            case '3': talk_with_me_lazy(do_it_or_not());
                    break;
            case '4': //turn_off_lazy_text(); 
                        cout << "โค้ดนี้เอาออกไปแล้ว" << endl;
                        active_ai_intro(::name);//(::name); 
                        break;
            case '5': 

                    for (int i = 0; i<bye.size(); i++)
                    {
                        cout << bye[i];
                        Sleep(3);
                    }
                    cout << endl;
                    break;

            default: cout<< "ขอโทษนะ เราเข้าใจแค่เลข 1-4 เท่านั้น" << endl ; cho_func2_lazy(); break;
        }
    }
}

void Lazy_ai_intro(string name)
{
    ::name = name;

    string activate = "Lazy Activated";
    vector <string> say = {"สวัสดี ฉันคือ "+name+" ที่โครตขี้เกียจเลย","ในโหมดนี้ฉันมีโอกาส 40% ที่จะทำงานให้คุณ แต่อีก 60% คือฉันจะไม่ทำ แล้วกลับไปนอน","และนี่คือคำสั่งที่ฉันทำได้"};
    system("cls"); //clear
    
    my_command::cout_string_dalay(activate);
    Sleep(1000);

    my_command::cout_vector_string_delay(say);
    cout << "กดอะไรก็ได้เพื่อไปต่อ เพื่อไปต่อ\r";
    getch();
    cout << "                                        \r";

    cho_func2_lazy();
}
