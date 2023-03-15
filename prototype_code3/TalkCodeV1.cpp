#include<iostream>
#include<string>
#include<vector>
using namespace std;

void main_talk_bot(string name)
{
    string Choice;
    int ListSize ;
    vector<string> Ans1 = {"",""," "};
    srand(time(0));
    do{
        cout << "โปรดเลือกทางเลือกของท่าน\n (0)เลิกถามและพากลับไปหน้าแรก\n (1)อากาศวันนี้\n (2)ถามเกี่ยวกับbot\n (3)อื่นๆ\n";
        cin >> Choice;
        cin.clear();
        fflush(stdin);
        if(Choice == "0"){
            cout << "ออกจากฟังก์ชั่น" << endl;
            break;
        }else if(Choice == "1"){
            system("cls");
            cout << ;
        }else if(Choice == "2"){
            
            
        }else{
            cout << "ใส่เลขผิดนะจ๊ะ" << "\n";
        }
    }while(Choice != "0");

}

int main(){
    main_talk_bot("Abdul");
}