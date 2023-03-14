//#include <iostream>
//#include <string>
//#include <vector>
// #include <Windows.h>
// #include <cstdlib>
// #include <ctime>
//#include <conio.h>

using namespace std;

namespace my_command
{
    void show_command(vector <string> command)
    {
        for(int i  = 0; i<command.size(); i++)
        {
            cout << command[i] << endl;
        }    
        cout << "ให้ฉํนทำอะไรดี : ";
    }

    void cout_string_dalay(string say)
    {
        for(int i = 0; i<say.size();i++)
        {
            cout <<say[i];
            Sleep(3);
        }
        cout << endl;
    }

    void cout_vector_string_delay(vector<string> say)
    {
        for (int j =0; j < say.size(); j++)
        {
            for(int i = 0; i<say[j].size();i++)
            {
                cout <<say[j][i];
                Sleep(3);
            }
            cout << endl;
        }
    }


    void cout_string_delay_not_endl(string say)
    {
        for(int i = 0; i<say.size();i++)
        {
            cout <<say[i];
            Sleep(3);
        }

        // for(char for_cout: say)
        // {
        //     cout << for_cout;
        //     Sleep(3);
        // }
    }
}