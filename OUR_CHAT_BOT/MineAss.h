// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <iomanip> // for setw() setprecision() ไรทำนองนั้น
// #include <cstdlib> // for rand and srand
// #include <ctime> // for time
//using namespace std;
namespace MineAss{

void UcanRandomMenuInThisStore(){
    system("cls");
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
        //exit(1); //search มา อยู่ใน <cstdlib>
    }
    
    vector <string> storeItems;
    string name;
    int i = 1;
    cout << "•—————————————————•°•✿•°——————————————————•" << endl;
    cout << setw(10) << left << " " << "เลือกร้านได้เลยไอ้หนุ่ม!! " << endl;
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
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cout << "เลือกระหว่าง (1-" << numofStore << ") หรือ อยากจะสุ่มก็ตามจายย (0) แต่ถ้าใส่อักษรเราสุ่มนะ เตือนแล้ว" << endl; 
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cin >> storeSelection; //For now cant recieve more than 1 input.
        if (cin.fail())
        {
            storeSelection = 0;
        }
        
       
        cin.clear();
        fflush(stdin);
        system("cls");//clear ก่่อนหน้านั้นออก
        
        if(storeSelection < 0 || storeSelection > numofStore){
            cout << "•—————————————————•°•✿•°——————————————————•" << endl;
            for(int i = 0; i<numofStore;i++){
                
                cout << "[" << i+1 << "]." << " " << storeItems[i] << endl;
            }
            cout << "•—————————————————•°•✿•°——————————————————•" << endl;
        }
        
    }while(storeSelection < 0 || storeSelection > numofStore); //ถ้าจะใช้ while(-1) สลับเอา check ว่า storeselec in 0<s<i-1
    if(storeSelection == 0){
        srand(time(0));
        storeSelection = rand() % numofStore + 1;
    }
    
    /*if(storeSelection == "0")
        srand(time(0));
        storeSelection = rand() % numofStore + 1;
    else if(storeSelection == "1") 
        fileName = "ข้าวผัดปูเยาวราช";
    else if(storeSelection == "2")
        fileName = "ข้าวต้มบุษบา";
    else if(storeSelection == "3")
        fileName = "ก๋วยจั๊บญวน_หลังมอ";
    else if(storeSelection == "4")
        fileName = "สเต๊กลุงเม่น";
    else if(storeSelection == "5")
        fileName = "ราชาหมูทอด_เล้งแซ่บ";
    else if(storeSelection == "6")
        fileName = "อาหารตามสั่ง_ByLachada";
    else if(storeSelection == "7")
        fileName = "ก๋วยเตี๋ยวเป็ดแม่บุญรอด";
    else if(storeSelection == "8")
        fileName = "ข้าวมันไก่_ต่อประตูเกษตร";
    else if(storeSelection == "9")
        fileName = "Rice_away";
    else if(storeSelection == "10")
        fileName = "Hachi";
    else if(storeSelection == "11")
        fileName = "Katsu_oni";
    else if(storeSelection == "12")
        fileName = "น้องอ้อย";
    else if(storeSelection == "13")
        fileName = "กะบับ";
    else if(storeSelection == "14")
        fileName = "บ้านนม";
    else if(storeSelection == "15")
        fileName = "ขนมจีนหัวมุม";
    else if(storeSelection == "16")
        fileName = "เจ๊ศรีกระทะร้อน";
    else if(storeSelection == "17")
        fileName = "เจ๊หมู";
    else if(storeSelection == "18")
        fileName = "PP_shabu";
    else if(storeSelection == "19")
        fileName = "หลงฮัว";
    else if(storeSelection == "20")
        fileName = "สุกี้ช้างเผือก";
    else if(storeSelection == "21")
        fileName = "ข้าวมันไก่สีฟ้า";
    else if(storeSelection == "22")
        fileName = "ธารินทร์";
    else if(storeSelection == "23")
        fileName = "ชุติภรผัดไทย";
    else if(storeSelection == "24")
        fileName = "เจ๊ศรีกระทะร้อน";
    else if(storeSelection == "25")
        fileName = "เจียวดาวหลังมอ2";
    else if(storeSelection == "26")
        fileName = "เจียวดาวหลังมอเจ้าแรก";
    else if(storeSelection == "27")
        fileName = "ปูซ่าส์";
    else if(storeSelection == "28")
        fileName = "ป้าอ้วน";
    else if(storeSelection == "29")
        fileName = "ก๋วยเตี๋ยวเส้นคลุกโกไข่เจ๊น้อยหลังมอ";
    else if(storeSelection == "30")
        fileName = "ร้านอาหารยอดฮิต";
    else if(storeSelection == "31")
        fileName = "บะหมี่พุงระเบิด";
    else if(storeSelection == "32")
        fileName = "ก๋วยเตี๋ยวต้มยำกุ้งน้ำข้นซุปเปอร์แซ่บ";
    else if(storeSelection == "33")
        fileName = "The_Steak(เดอะสเต็ก)";
    else if(storeSelection == "34")
        fileName = "กะเพราเนื้อเนื้อ";
    else if(storeSelection == "35")
        fileName = "Ramenya(ราเมนยะ)";
    else if(storeSelection == "36")
        fileName = "kinkai_fried_chicken";
    else if(storeSelection == "37")
        fileName = "ร้านsmell";
    else if(storeSelection == "38")
        fileName = "ร้านก๋วยเตี๋ยวต้มยำ";
    else if(storeSelection == "39")
        fileName = "ลุงพันธ์หอ6ชาย";*/
    fileName = storeItems[storeSelection-1];
    
    L2.open("Data/Menu_in_store/"+ fileName + ".txt");

    if (!L2.is_open()) { //check ว่า file ร้านนั้นเปิดได้ไหม
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
                cout << storeItems[storeSelection-1] << " " << "ร้านนี้อยู่แถวๆ " << location << endl; // [] 0 1 2 เลย -1
            }
            cout << "✦•·················•✦•··················•✦"  << endl;
        }else if (line != "/where") {
            menuItems.push_back(line); // the next line is the menu.
        }
       
        
    }
    

    L2.close(); //close
    
    int numofMenuItems = menuItems.size();
    if (numofMenuItems == 0) {
        cout << "ร้านนี้ไม่มีเมนู (แล้วเขาเปิดร้านทำไม?)" << endl;
        //exit(1); // check that store have menu otherwise end.
       
    }
    bool done = false;

    while (true) {
        cout << endl;
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;
        cout << "เอาหละต่อมาฉันมี 3 อย่างให้นายเลือก:" << endl;
        cout << "[1]. ขอดูเมนูทั้งหมดในร้านนี้(เผื่ออยากดูก่อน)" << endl;
        cout << "[2]. นึกอะไรไม่ออกก็กดอันนี้นะ (เดี๋ยวสุ่มให้เองง)" << endl;
        cout << "[3]. ออก!" << endl;
        cout << "❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀" << endl;

        string choice;
        cin >> choice;
        cin.clear();
        fflush(stdin);
        //clear ก่่อนหน้านั้นออก

        if(choice.size() > 1) cout << "รู้จักแค่ 1 ถึง 3" << endl;
        else
        {
            char _choice = choice[0];
            switch(_choice){
            case '1': {
                system("cls");
                cout << "•—————————————————•°•✿•°——————————————————•" << endl;
                cout << "เท่าที่เรารู้มาในร้านนี้มีเมนู" << endl;
                for (int i = 0; i < menuItems.size(); i++) {
                cout << "- " << menuItems[i] << endl;
                }
                cout << "•—————————————————•°•✿•°——————————————————•" << endl;
                break;
            }
            case '2': {
                system("cls");
                srand(time(0)); // seed the random number generator with the current time.
                int random = rand() % numofMenuItems;
                string randomMenuItem = menuItems[random]; //menu in vector that add before.
                cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━❂❂━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
                cout << setw(50) << left << " แนะนำนะเราว่าควรเลือกเมนู: ";
                cout << randomMenuItem << endl;
                cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━❂❂━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
                //exit(1);
                done = true;
                break;
            }
            case '3': {
                //exit(1); 
                done = true;
                break; //quit.
            }
            default: {
                system("cls");
                cout << "อย่าดื้อสิบอกว่ามีให้เลือกแค่ (1-3) ไง" << endl;
                break;
            }
            }
        }

        if(done) break;
    }


}
}


   
