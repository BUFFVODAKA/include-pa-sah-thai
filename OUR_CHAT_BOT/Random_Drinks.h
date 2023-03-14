// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cstdlib>
// #include <ctime>

//using namespace std;

namespace random_drink
{
    void GetDrinkList(vector<string> &DrinksLists,string FileNames){
        ifstream source;
        source.open(FileNames);//(FileNames.c_str());
        string DrinksList;
        while(getline(source,DrinksList)){
            DrinksLists.push_back(DrinksList);
        }
    }

    void main_random_drink(){

        system("cls");
        vector <string> say = {"โอเค เลือกโหมดเครื่องดื่มสินะ\n","โปรดเลือกทางเลือกของท่าน","โอเค ออกจากฟังก์ชั่นเครื่องดื่มแล้ว\n"};
        my_command::cout_string_dalay(say[0]);

        ifstream source;
        string FileNames = "Drinks_List.txt";
        vector<string> DrinksLists;
        GetDrinkList(DrinksLists,FileNames);
        int Choice;
        int ListSize = DrinksLists.size();
        int RNG;
        srand(time(0));
        do{
            my_command::cout_string_dalay(say[1]);

            cout << "(0)เลิกถามและพากลับไปหน้าแรก \n(1)เอารายชื่อเครื่องดื่มมา \n(2)แนะนำเครื่องดื่มมาซิ\n";
            cin >> Choice;
            cin.clear();
            fflush(stdin);
            if(Choice == 0){
                system("cls");
                my_command::cout_string_dalay(say[2]);
                break;
            }else if(Choice == 1){
                system("cls");
                for(int i = 0; i < DrinksLists.size(); i++){
                    cout << "(" << i+1 << ")" << DrinksLists[i] << "\n";
                }
                cout << endl;
            }else if(Choice == 2){
                system("cls");
                RNG = rand()%ListSize;
                //cout << RNG; **debug มาคับ
                cout << "\nเราแนะนำให้ท่านดื่ม " << DrinksLists[RNG] << "\n\n";
                //cout << "exit" << endl; **debug อีกหนึ่งกรุบกริบ
            }else{
                system("cls");
                cout << "ใส่เลขผิดนะจ๊ะ" << "\n";
            }
        }while(Choice != 0);
    }
}