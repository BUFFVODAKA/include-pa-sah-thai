#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

ifstream RF2;
    
    class Store
    {
        public:
        vector <string> menu;
        string store_name,where;
        string text;
        bool set_where = false, noname = true;
        Store(string);
        void show_data(); 
        bool check_menu(string input);
        int acess_menu_size(); 
        string assecc_menu(int index); 
        string show_name();
        string show_where();
        void show_menu();
        void name_and_location();
        void recrive_key(string k);
    };


Store::Store(string storename)
{
    store_name = storename;
    string filename = "data_store_menu/menu/Menu_in_store/" + storename +".txt";
    RF2.open(filename);
    while(getline(RF2, text))
    {
        
        if(text == "where")
        {
            set_where = true;
            continue;
        }

        if(set_where)
        {
            where = text;
            set_where = false;
            continue;
        }

        if(text == "/where") continue;

        menu.push_back(text);

    }
    RF2.close();
}

int main()
{
    system("cls");
    ifstream RF1;
    vector<Store> allstore;
    vector<string> menu_list;

    string filename1 = "data_store_menu/store_list.txt";
    
    cout << "**---------------------------**" << endl;
    cout << "\nสวัสดีเจ้าคะ ยินดีที่ได้รับใช้นายท่านนะเจ้าคะ" << endl;           
    cout << "\n**---------------------------**" << endl;
   
    
    RF1.open(filename1);
    
    if (!RF1.is_open()) { 
        cout << "เปิดไฟล์ไม่สำเร็จนะคะ" << endl;
        exit(1); 
    }else{
        string name;
        while(getline(RF1,name))
        {
            Store A(name);
            allstore.push_back(A);
        }
    }
    
    
    cout << "\nวันนี้นายท่านอยากรับประทานอะไรหรือเจ้าคะ\n";
    int c=0,count = 1,numberofmenu = 0;
    

    for(unsigned int i=0; i<allstore.size(); i++)
    {
        for(unsigned int j=0; j<allstore[i].menu.size(); j++)
        {
            cout << count << " - " << allstore[i].menu[j] << endl;
            count++;
            numberofmenu += 1;
            menu_list.push_back(allstore[i].menu[j]);
        }
        
    }
    
    int menu_select;
    do{
        cout << "โปรดเลือกตัวเลขที่อยู่ด้านหน้าของเมนู (1-" << numberofmenu << ") หรือกดเลือกเลข (0) เพื่อสุ่มเมนู: "; 
        cin >> menu_select; //For now cant recieve more than 1 input.
        if(menu_select < 0 || menu_select > numberofmenu){
        cout << "ตัวเลือกไม่ถูกต้องนะเจ้าคะ!! โปรดเลือกตัวเลขระหว่าง 0 และ " << numberofmenu << " นะเจ้าคะ" << endl;
        }
    }while(menu_select < 0 || menu_select > numberofmenu); //ถ้าจะใช้ while(-1) สลับเอา check ว่า storeselec in 0<s<i-1
    
    if(menu_select == 0){
        srand(time(0));
        menu_select = rand() % numberofmenu + 1;
        
    }
    
    string menu_need;
    menu_need = menu_list[menu_select-1];

    /*switch (menu_select) { //ดูท่าจะมีหลาย case
        case 1: 
            menu_need = "MenuA";
            break;
        case 2:
            menu_need = "MenuB";
            break;
        case 3:
            menu_need = "MenuC";
            break;
        case 4:
            menu_need = "MenuD";
            break;
        case 5:
            menu_need = "MenuE";
            break;
        case 6:
            menu_need = "MenuF";
            break;
        case 7:
            menu_need = "MenuG";
            break;
       }*/



    
    cout << endl << "**---------------------------**" << endl;
    cout << "\nฉันแนะนำให้รับประทานเมนูที่นายท่านต้องการที่ร้าน " << endl;
    
    for(unsigned int i=0; i<allstore.size(); i++)
    {
        for(unsigned int j=0; j<allstore[i].menu.size(); j++)
        {
            if(allstore[i].menu[j] == menu_need){
                
                cout << allstore[i].store_name << " บริเวณ " << allstore[i].where;
                
            }
        }
        
    }
    cout << " ในวันนี้นะเจ้าคะ!!\n";
    cout << endl << "**---------------------------**" << endl;

    return 0;
}


/*for(unsigned int i=0; i<allstore.size(); i++)
    {
        for(unsigned int j=0; j<allstore[i].menu.size(); j++)
        {
            if(allstore[i].menu[j] == menu_i)
            {
                cout << "\nA";
                c++;
            }
        }
        if(c==0 && i+1==allstore.size()) cout << "\nSorry, we can't find your store";
    }*/