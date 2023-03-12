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
    char format[] = "%s";
    while(getline(source,DrinksList)){
        sscanf(DrinksList.c_str(),format,DrinksList);
        DrinksLists.push_back(DrinksList);
    }
}

int main(){
    string FileNames = "Drinks_List.txt";
    vector<string> DrinksLists;
    GetDrinkList(DrinksLists,FileNames);
    int RNG = rand()%(DrinksLists.size()+1);
    cout << "เราขอแนะนำให้ท่านดื่ม" << DrinksLists[RNG];
}