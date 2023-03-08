#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // for rand and srand
#include <ctime> // for time

using namespace std;

void UcanRandomMenuInThisStore(){
    ifstream L1,L2;
    string fileName;
    string allstore = "Menu_in_store/Store_list.txt";
    
    cout << "**---------------------------**" << endl;
    cout << "Welcome to HIDDEN Store" << endl;           //Display.
    cout << "**---------------------------**" << endl;
   
    cout << "Please select a store:" << endl;
    
    L1.open(allstore);
    
    if (!L1.is_open()) { //First check that the file can be open.
        cout << "Failed to open file!" << endl;
        exit(1); //search มา อยู่ใน <cstdlib>
    }
    
    vector <string> storeItems;
    string name;
    int i = 1;
    while(getline(L1,name)){
        cout << i << " - " << name << endl;
        storeItems.push_back(name); //collect name of store
        i++; // because this
    }
    
    int numofStore = storeItems.size(); //จำนวน store ทั้งหมดที่มี

    // Get store selection from user
    int storeSelection;
    do{
        cout << "Enter selection (1-" << numofStore << ") or Random (0): "; 
        cin >> storeSelection; //For now cant recieve more than 1 input.
        if(storeSelection < 0 || storeSelection > numofStore){
        cout << "Invalid selection! Please enter a number between 0 and " << numofStore << "." << endl;
        }
    }while(storeSelection < 0 || storeSelection > numofStore); //ถ้าจะใช้ while(-1) สลับเอา check ว่า storeselec in 0<s<i-1
    
    
    if(storeSelection == 0){
        srand(time(0));
        storeSelection = rand() % numofStore + 1;
        
    }
    
    switch (storeSelection) { //ดูท่าจะมีหลาย case
        case 1: 
            fileName = "StoreA";
            break;
        case 2:
            fileName = "StoreB";
            break;
        case 3:
            fileName = "StoreC";
            break;
       }

    
    L2.open("Menu_in_store/"+ fileName + ".txt");

    if (!L2.is_open()) { //First check that the file can be open.
        cout << "Failed to open file!" << endl;
        exit(0); //search มา อยู่ใน <cstdlib> or exit(1) not sure
    }
    
    vector<string> menuItems; //menu in any store
    string line;
    while (getline(L2, line)) {
        if (line == "where") {
            // read the next line as the Nameof location.
            string location;
            cout << endl;
            cout << "**---------------------------**" << endl;
            while(getline(L2, location)){ //เผื่อว่า the location have more than one line.
                if(location == "/where"){
                    break;
                }
                cout << storeItems[storeSelection-1] << "'s Location: " << location << endl; // [] 0 1 2 เลย -1
            }
            cout << "**---------------------------**" << endl;
        }else if (line != "/where") {
            menuItems.push_back(line); // the next line is the menu.
        }
       
        
    }
    

    L2.close(); //close
    
    int numofMenuItems = menuItems.size();
    if (numofMenuItems == 0) {
        cout << "No menu items found!" << endl;
        exit(1); // check that store have menu otherwise end.
       
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

        switch(choice){
        case 1: {
            cout << "**---------------------------**" << endl;
            cout << "All menu in this Store:" << endl;
            for (int i = 0; i < menuItems.size(); i++) {
            cout << "- " << menuItems[i] << endl;
            }
            cout << "**---------------------------**" << endl;
            break;
        }
        case 2: {
            srand(time(0)); // seed the random number generator with the current time.
            int random = rand() % numofMenuItems;
            string randomMenuItem = menuItems[random]; //menu in vector that add before.
            cout << "-------------------------------" << endl;
            cout << "I adivce you to choose: " << randomMenuItem << endl;
            cout << "-------------------------------" << endl;
            break;
        }
        case 3: {
            cout << "Thanks for using our system.";
            exit(1); 
            break; //quit.
        }
        default: {
            cout << "Invalid choice!" << endl;
            break;
        }
        }
    }

}

int main() {
    UcanRandomMenuInThisStore(); //call function
}

   

