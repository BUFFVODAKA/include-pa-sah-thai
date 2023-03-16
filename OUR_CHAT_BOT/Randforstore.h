// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cstdlib> 
// #include <ctime>

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
    string filename = "Data//Menu_in_store//" + storename +".txt";
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





void Rand_Store()
{
    system("cls");
    ifstream RF1;
    vector<Store> allstore;
    vector<string> menu_list;

    string filename1 = "Data//Store_list.txt";
    
    cout << "**---------------------------**" << endl;
    cout << "\nสวัสดีเจ้าคะ ดิฉันยินดีที่ได้รับใช้นายท่านนะเจ้าคะ" << endl;           
    cout << "\n**---------------------------**" << endl;
   
    
    RF1.open(filename1);
    
    if (!RF1.is_open()) { 
        cout << "\nเปิดไฟล์ไม่สำเร็จนะคะ\n" << endl;
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
    do
    {
        cout << "โปรดเลือกตัวเลขที่อยู่ด้านหน้าของเมนู (1-" << numberofmenu << ") หรือกดเลือกเลข (0) เพื่อสุ่มเมนู: "; 
        cin >> menu_select;
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "\n**---------------------------**" << endl;
            cout << "\nตัวเลือกไม่ถูกต้องนะเจ้าคะ!! ดังนั้นดิฉันขออนุญาตถือว่าเจ้านายจ้องการสุ่มอาหารนะเจ้าคะ\n";
            menu_select = 0;
        }

        if(menu_select < 0 || menu_select > numberofmenu)
        {
            cout << "\nตัวเลือกไม่ถูกต้องนะเจ้าคะ!! โปรดเลือกตัวเลขระหว่าง 0 และ " << numberofmenu << " นะเจ้าคะ\n" << endl;
        }
    }
    while(menu_select < 0 || menu_select > numberofmenu || cin.fail()); 
    
    
    
    
    if(menu_select == 0){
        srand(time(0));
        menu_select = rand() % numberofmenu + 1;
        
    }
    
    string menu_need;
    menu_need = menu_list[menu_select-1];

    
    cout << endl << "**---------------------------**" << endl;
    cout << "\nฉันแนะนำให้รับประทานเมนู " << menu_need << " ที่ร้าน\n" << endl;
    
    for(unsigned int i=0; i<allstore.size(); i++)
    {
        for(unsigned int j=0; j<allstore[i].menu.size(); j++)
        {
            if(allstore[i].menu[j] == menu_need){
                
                cout << allstore[i].store_name << " ที่ " << allstore[i].where << endl;
                
            }
        }
        
    }
    cout << " ในวันนี้นะเจ้าคะ!!\n";
    cout << endl << "**---------------------------**" << endl;

    
}


