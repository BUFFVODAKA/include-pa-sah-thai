#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // for rand and srand
#include <ctime> // for time

using namespace std;

void UcanRandomMenuInThisStore(){
    string storename;
    cout << "Enter the name of the file: ";
    cin >> storename;
    string fileName = "C:/Users/Win 10/Desktop/include-pa-sah-thai-main/code/test/Menu_in_store/" + storename +".txt"; //หรือ location ที่ๆร้านนั้นๆอยู่
    //string fileName = "/Users/adisornsancharoen/Desktop/project tset for me/testPro/code/test/Menu_in_store/" + storename + ".txt"; //my ios

    ifstream file(fileName);

    if (!file.is_open()) { //First check that the file can be open.
        cout << "Failed to open file!" << endl;
        exit(1); //search มา อยู่ใน <cstdlib>
       
           
    
    }
    
    vector<string> menuItems;
    string line;
    while (getline(file, line)) {
        if (line == "where") {
            // read the next line as the Nameof location.
            string location;
            cout << "**---------------------------**" << endl;
            while(getline(file, location)){ //เผื่อว่า the location have more than one line.
                if(location == "/where"){
                    break;
                }
                cout << "Location: " << location << endl;
            }
            cout << "**---------------------------**" << endl;
        }else if (line != "/where") {
            menuItems.push_back(line); // the next line is the menu.
        }
       
        
    }
    

    file.close();
    
    int numofMenuItems = menuItems.size();
    if (numofMenuItems == 0) {
        cout << "No menu items found!" << endl;
        exit(1);
       
    }

     while (true) {
        cout << endl;
        cout << "================================" << endl;
        cout << "Choose an option:" << endl;
        cout << "[1]. List all menu in This Store" << endl;
        cout << "[2]. Randomly select a menu" << endl;
        cout << "[3]. Quit" << endl;
        cout << "================================" << endl;

        int choice;
        cin >> choice;

        /*
        
        Note: But if the input not the int the result a@!#@@#.
        
        */


        if (choice == 1) {
            cout << "Menu items:" << endl;
            for (int i = 0; i < menuItems.size(); i++) {
                cout << "- " << menuItems[i] << endl;
            }

        } else if (choice == 2) {
            srand(time(0)); // seed the random number generator with the current time.
            int random = rand() % numofMenuItems;
            string randomMenuItem = menuItems[random]; //menu in vector that add before.
            cout << "-------------------------------" << endl;
            cout << "Random menu item: " << randomMenuItem << endl;
            cout << "-------------------------------" << endl;
        } else if (choice == 3) {
            break; //quit.
        } else {
            cout << "Invalid choice!" << endl;
        }
    }



}


int main() {
    UcanRandomMenuInThisStore();
}

   

