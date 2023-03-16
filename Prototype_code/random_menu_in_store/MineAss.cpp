#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // for setw() setprecision() ไรทำนองนั้น
#include <cstdlib> // for rand and srand
#include <ctime> // for time

using namespace std;

void UcanRandomMenuInThisStore(){
    ifstream L1,L2;
    string fileName;
    string allstore = "Data/Store_list.txt";
    
    cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
    cout << endl;
    cout << setw(7) << left << " " << "ยินดีต้อนรับสู้ร้านอาหารอร่อยใกล้ มช." << endl;   
    cout << endl;
    cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
    cout << endl;
   
    L1.open(allstore);
    
    if (!L1.is_open()) { //First check that the file can be open.
        cout << "เอิ่ม อยากจะบอกว่าหาร้าน บ่ เจอ กดใหม่ๆ!" << endl;
        exit(1); //search มา อยู่ใน <cstdlib>
    }
    
    vector <string> storeItems;
    string name;
    int i = 1;
    cout << "•—————————————————•°•✿•°——————————————————•" << endl;
    cout << setw(10) << left << " " << "เลือกร้่านได้เลยไอ้หนุ่ม!! " << endl;
    while(getline(L1,name)){
        cout << "[" << i << "]." << " " << name << endl;
        storeItems.push_back(name); //collect name of store
        i++; // because this
    }
    cout << "•—————————————————•°•✿•°——————————————————•"  << endl;
    cout << endl;
    
    int numofStore = storeItems.size(); //จำนวน store ทั้งหมดที่มี

    // Get store selection from user
    int storeSelection;
    do{
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cout << "เลือกระหว่าง (1-" << numofStore << ") หรือ อยากจะสุ่มก็ตามจายย (0)" << endl; 
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cin >> storeSelection; //For now cant recieve more than 1 input.
        if(storeSelection < 0 || storeSelection > numofStore){
        cout << "ก็บอกแล้วไงให้เลือกแค่ (1-" << numofStore << ") หรือไม่ก็สุ่ม (0)" << endl;
        }
        
    }while(storeSelection < 0 || storeSelection > numofStore); //ถ้าจะใช้ while(-1) สลับเอา check ว่า storeselec in 0<s<i-1
    
    
    if(storeSelection == 0){
        srand(time(0));
        storeSelection = rand() % numofStore + 1;
        
    }
    
    switch (storeSelection) { //ดูท่าจะมีหลาย case
        case 1: 
            fileName = "ข้าวผัดปูเยาวราช";
            break;
        case 2:
            fileName = "ข้าวต้มบุษบา";
            break;
        case 3:
            fileName = "ก๋วยจั๊บญวน_หลังมอ";
            break;
        case 4:
            fileName = "สเต๊กลุงเม่น";
            break;
        case 5:
            fileName = "ราชาหมูทอด_เล้งแซ่บ";
        case 6:
            fileName = "อาหารตามสั่ง_ByLachada";
            break;
        case 7:
            fileName = "ก๋วยเตี๋ยวเป็ดแม่บุญรอด";
            break;
        case 8:
            fileName = "ข้าวมันไก่_ต่อประตูเกษตร";
            break;
       }

    
    L2.open("Data/Menu_in_store/"+ fileName + ".txt");

    if (!L2.is_open()) { //First check that the file can be open.
        cout << "เราหาร้านไม่เจอง่ะ! (ลองเลือกใหม่ๆ)" << endl;
        exit(0); //search มา อยู่ใน <cstdlib> or exit(1) not sure
    }
    vector<string> menuItems; //menu in any store
    string line;
    while (getline(L2, line)) {
        if (line == "where") {
            // read the next line as the Nameof location.
            string location;
            cout << endl;
            cout << "✦•·················•✦•··················•✦" << endl;
            while(getline(L2, location)){ //เผื่อว่า the location have more than one line.
                if(location == "/where"){
                    break;
                }
                cout << storeItems[storeSelection-1] << " " << "ร้่านนี้อยู่แถวๆ " << location << "มอ" << endl; // [] 0 1 2 เลย -1
            }
            cout << "✦•·················•✦•··················•✦"  << endl;
        }else if (line != "/where") {
            menuItems.push_back(line); // the next line is the menu.
        }
       
        
    }
    

    L2.close(); //close
    
    int numofMenuItems = menuItems.size();
    if (numofMenuItems == 0) {
        cout << "ร้่านนี้ไม่มีเมนู (แล้วเขาเปิดร้านทำไม?)" << endl;
        exit(1); // check that store have menu otherwise end.
       
    }

    while (true) {
        cout << endl;
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cout << "เอาหละต่อมาฉันมี 3 อย่างให้นายเลือก:" << endl;
        cout << "[1]. ขอดูเมนูทั้งหมดในร้านนี้(เผื่ออยากดูก่อน)" << endl;
        cout << "[2]. นึกอะไรไม่ออกก็กดอันนี้นะ (เดี๋ยวสุ่มให้เองง)" << endl;
        cout << "[3]. ออก!" << endl;
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;

        int choice;
        cin >> choice;

        switch(choice){
        case 1: {
            cout << "•—————————————————•°•✿•°——————————————————•" << endl;
            cout << "เท่าที่เรารู้มาในร้่่านนี้มีเมนู" << endl;
            for (int i = 0; i < menuItems.size(); i++) {
            cout << "- " << menuItems[i] << endl;
            }
            cout << "•—————————————————•°•✿•°——————————————————•" << endl;
            break;
        }
        case 2: {
            srand(time(0)); // seed the random number generator with the current time.
            int random = rand() % numofMenuItems;
            string randomMenuItem = menuItems[random]; //menu in vector that add before.
            cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━❂❂━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << setw(50) << left << " แนะนำนะเราว่าควรเลือกเมนู";
            cout << setw(1) << ":";
            cout << setw(29) << right << randomMenuItem << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━❂❂━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
            exit(1);
            break;
        }
        case 3: {
            exit(1); 
            break; //quit.
        }
        default: {
            cout << "อย่าดื้อสิบอกว่ามีให้เลือกแค่ (1-3) ไง" << endl;
            break;
        }
        }
    }

}

int main() {
    UcanRandomMenuInThisStore(); //call function
}

   
