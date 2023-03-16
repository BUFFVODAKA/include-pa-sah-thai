// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
namespace talk_bot{
void main_talk_bot(string name)
{
    string Choice;
    string Choice2;
    string Choice3;
    int ListSize ;
    vector<string> Ans1 = {"ร้อนๆหนาวๆอะ","ลองมองไปที่ท้องฟ้าสิ","น่านอนมาก","ออกไปดูเองได้เลยจ้า ไปแตะหญ้าบ้างนะ"};
    vector<string> Ans2 = {"botชื่อว่า........ลืมไปละ","เราถูกสร้างมาเพื่อช่วยเหลือพวกที่ไม่รู้ว่าจะกินอะไร","botอยากนอน","ดูหนัง","ดูการ์ตูน","กินข้าว"};
    srand(time(0));
    do{
        cout << "โปรดเลือกทางเลือกของท่าน\n (0)เลิกถามและพากลับไปหน้าแรก\n (1)อากาศวันนี้\n (2)ถามเกี่ยวกับbot\n (3)Modeตอบได้ทุกคำถาม\n";
        cin >> Choice;
        cin.clear();
        fflush(stdin);
        system("cls");
        if(Choice == "0"){
            cout << "ออกจากฟังก์ชั่น" << endl;
            break;
        }else if(Choice == "1"){
            cout << Ans1[rand()%Ans1.size()] << endl << endl;
        }else if(Choice == "2"){
            do{
            cout << "โปรดเลือกสิ่งที่จะถาม\n\n";
            cout << "(0)ไม่ถามละ\n(1)botชืออะไร\n(2)เกี่ยวกับbot\n(3)botอยากทำไร\n";
            cin >> Choice2;
            cin.clear();
            fflush(stdin);
            system("cls");
            if(Choice2 == "1"){
                cout << Ans2[0] << endl;
            }else if(Choice2 == "2"){
                cout << Ans2[1] << endl;
            }else if(Choice2 == "3"){
                cout << Ans2[rand()%4+2] << endl;
            }else{
            cout << "ใส่เลขผิดนะจ๊ะ" << "\n\n";
        }
            }while(Choice2 != "0");
        }else if(Choice == "3"){
            
            cout << "ตอนนี้บอทจะมีชื่อว่า Abdul\nไม่ว่าผู้ใช้จะถามอะไร Abdul ก็จะตอบทภคำถามได้เสมอ\n";
            do{
            cout << "โปรดเลือกทางเลือกของท่าน\n";
            cout << "(0)ไม่ถามละ\n(1)ถาม\n";
            cin >> Choice2;
            cin.clear();
            fflush(stdin);
            //system("cls");
            if(Choice2 == "1"){
                system("cls");
                cout << "------------------------------------\n";
                cout << "มีอะไรจะถามเหรอจ๊ะนายจ๊า\n";
                cin >> Choice3;
                cin.clear();
                fflush(stdin);
            if(Choice3 == "Abdul" || Choice3 == "abdul"){
                cout << "ได้" << endl;
                cout << "------------------------------------\n";
            }else{
                cout << "ได้" << endl;
                cout << "------------------------------------\n";
            }
            }else{
            cout << "ใส่เลขผิดนะจ๊ะ" << "\n------------------------------------\n";
        }

            }while(Choice2 !="0");

        }else{
            cout << "ใส่เลขผิดนะจ๊ะ" << "\n\n";
        }
    }while(Choice != "0");

}
}


