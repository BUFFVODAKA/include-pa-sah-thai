#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void GetDrinkList(vector<string> &DrinksLists,string FileNames){
    ifstream source;
    source.open(FileNames.c_str());
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
    do{
        cout << "Please Select (0)Stop Asking (1)See The List of Drinks (2)Suggest Drinks for you\n";
        cin >> Choice;
        if(Choice == 0){
            break;
        }else if(Choice == 1){
            for(int i = 0; i < DrinksLists.size(); i++){
                cout << "(" << i+1 << ")" << DrinksLists[i] << "\n";
            }
        }else if(Choice == 2){
            int RNG = rand()%(DrinksLists.size()+1);
            cout << "We Suggest you to drink " << DrinksLists[RNG] << "\n";
        }else{
            cout << "Invalid Input" << "\n";
        }
    }while(Choice != 0);
}