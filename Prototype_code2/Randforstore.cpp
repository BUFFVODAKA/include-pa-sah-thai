#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

ifstream RF1,RF2;

    class Store
    {
        vector <string> menu;
        string store_name,where;
        string text;
        bool set_where = false, noname = true;
        public:
        Store(string);
        void show_data(); 
        bool check_menu(string input);
        int acess_menu_size(); 
        string assecc_menu(int index); 
        string show_name();
        string show_where();
        void show_menu();
        void name_and_location();

    };

Store::Store(string storename)
{
    store_name = storename;
    string filename = "data_store_menu//menu//" + storename +".txt";
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

void Random_Store(){
    vector<Store> allstore;
    string filename = "data_store_menu/store_list.txt";
    RF1.open(filename);

    if (!RF1.is_open()) { 
        cout << "Failed to open file!" << endl;
        exit(1);
    }

    string name;
    while(getline(RF1,name))
    {
        Store name(name);
        allstore.push_back(name);
    }
    
    
	

}

int main() 
{
    Random_Store();
}