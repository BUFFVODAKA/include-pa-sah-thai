#include "command_list.h"
//#include "shutdown_function.h" //ไม่ใช้แล้ว
#include "Random_Drinks.h"
#include "rand_store_and_food_main.h"
#include "TalkCodeV1.h" //talk_bot
#include "countdown.h"

string name;

void active_ai_intro(string name);
void Lazy_ai_intro(string name);

void talk_with_me_active()
{
    system("cls");
    string say = "โอเค ว่าแต่ มีอะไรอย่างนั้นหรอ\n";
    my_command::cout_string_dalay(say);

    talk_bot::main_talk_bot(name);
}

void cho_func2_active()
{
    vector <string> list_command = {"สุ่มร้านอาหาร(1)                        (แนะนำ ฟังก์ชั่นหลักเลย)","สุ่มเครื่องดื่ม(2)                         (จะลองก็ได้นะ อันนี้)","คุยเล่นกับฉัน(3)                         (ฉันใช้ if-else เด้อ ไม่ใช่ Ai อย่าหวังเยอะจะดีกว่า)","เปิดโหมบอทขี้เกียจ(4)                    (แน่ใจรึ ว่า จะเล่นอันนี้้)","(5)","นับเวลาถอยหลัง(6)                      (ลองก็ได้นะ ตั้งใจทำอยู่)","ออก(0)"};
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
            case '1': //cout << "รอเรียกใช้ฟังก์ชั่นหลักของกลุ่มเรา (AI_working.h line 142 and 36)" << endl; //รอเรียกใช้ function หลักของกลุ่มเรา
                    main_function::intro_rand_food_store();
                    cho_func2_active(); 
                    break; 
            case '2': //coutdown_to_shutdown:: main_countdown_1(); 
                        random_drink::main_random_drink();
                        cho_func2_active(); break;
            case '3': talk_with_me_active();cho_func2_active(); break;
            case '4': Lazy_ai_intro(::name); break;
            case '5':
                    
                    cho_func2_active(); 
                    break;
            case '6':countdown::main_countdown_1();
                    cho_func2_active();
                    break;

            case '0': 

                    for (int i = 0; i<bye.size(); i++)
                    {
                        cout << bye[i];
                        Sleep(3);
                    }
                    cout << endl;
                    break;

            default: cout<< "ขอโทษนะ เราเข้าใจแค่เลข 0-6 เท่านั้น" << endl ; cho_func2_active(); break;
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
    //cout << rand_num << " (ดูเลขที่สุมมา)" << endl; //debug

    if(rand_num > 40)
    {
        //cout << "ขี้เกียจละ ฉันไปก่อนนะ" << endl;
        return false;
    }
    else return true;
}

void talk_with_me_lazy(bool do_check)
{
    system("cls");
    //do_check = true; //debug
    if(do_check)
    {
        string say = "อะอะอะ มีอะไรล่ะ ว่ามาเลย";
        Sleep(1000);
        my_command::cout_string_dalay(say);
        talk_bot::main_talk_bot(name);

        cho_func2_lazy();
    }
    else cout << "ขี้เกียจแล้วอ่ะ ไว้คุยกันวันหลังนะ ไปละ บ้ายบาย\n";
}

void turn_off_lazy_text()
{
    system("cls");
    string say = "Turn off Lazy mode";

    my_command::cout_string_dalay(say);
    Sleep(1000);
system("cls"); //clear
}

void cho_func2_lazy()
{
    vector <string> list_command = {"สุ่มร้าน(1)","สุ่มเครื่องดื่ม(2)","คุยเล่น(3)","ปิดโหมบอทขี้เกียจ(4)","คำนวณการแชร์บิล(5)","นับเวลาถอยหลัง(6)","ออก(0)"};
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
                            //cout << "โค้ดนี้เอาออกไปแล้ว (43 และ 167)" << endl;
                            //coutdown_to_shutdown:: main_countdown_1();
                            random_drink::main_random_drink();
                            cho_func2_lazy(); 
                            break;
                        }
                        else
                        {
                            cout << "ขี้เขียจแล้วอ่ะ ไปเดินหาร้านเครื่องดื่มเอาเองแล้วกันนะ ฉันไปล่ะ" << endl; 
                            break;
                        }
            case '3': talk_with_me_lazy(do_it_or_not());
                    break;
            case '4': turn_off_lazy_text(); 
                        active_ai_intro(::name);//(::name); 
                        break;
            case '6':countdown::main_countdown_1();
                    cho_func2_active();
                    break;
            case '0': 

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
    system("cls");

    my_command::cout_vector_string_delay(say);
    cout << "กดอะไรก็ได้เพื่อไปต่อ เพื่อไปต่อ\r";
    getch();
    cout << "                                        \r";

    cho_func2_lazy();
}
