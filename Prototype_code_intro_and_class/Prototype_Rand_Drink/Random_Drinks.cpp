#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void GetDrinkList(vector<string> &DrinksLists,string FileNames){
    ifstream source;
    source.open(FileNames);//(FileNames.c_str());
    string DrinksList;
    while(getline(source,DrinksList)){
        DrinksLists.push_back(DrinksList);
    }
}

int main(){
    ifstream source;
    string FileNames = "Drinks_List.txt";
    vector<string> DrinksLists;
    GetDrinkList(DrinksLists,FileNames);
    int Choice;
    int ListSize = DrinksLists.size();
    int RNG;
    srand(time(0));
    do{
        cout << "โปรดเลือกทางเลือกของท่าน (0)เลิกถามและพากลับไปหน้าแรก (1)เอารายชื่อเครื่องดื่มมา (2)แนะนำเครื่องดื่มมาซิ\n";
        cin >> Choice;
        cin.clear();
        fflush(stdin);
        if(Choice == 0){
            cout << "ออกจากฟังก์ชั่น" << endl;
            break;
        }else if(Choice == 1){
            for(int i = 0; i < DrinksLists.size(); i++){
                cout << "(" << i+1 << ")" << DrinksLists[i] << "\n";
            }
        }else if(Choice == 2){
            RNG = rand()%ListSize;
            //cout << RNG; **debug มาคับ
            cout << "เราแนะนำให้ท่านดื่ม " << DrinksLists[RNG] << "\n";
            //cout << "exit" << endl; **debug อีกหนึ่งกรุบกริบ
        }else{
            cout << "ใส่เลขผิดนะจ๊ะ" << "\n";
        }
    }while(Choice != 0);
}