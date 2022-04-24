#include <iostream>
#include <Windows.h>
#include <ios>
#include <limits>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <urlmon.h>
#include <tchar.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <string>
#include <direct.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")

using namespace std;


void Clear()
{
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
    return;
}


int main()
{

    SetConsoleTitle(_T("Login and Register Form"));
    _mkdir("C:/Login"); 

    std::fstream myfile;
    std::string line;
    ofstream outFile;
    string username;
    string password;


    string option;
    std::cout << "[1] Login\n";
    std::cout << "[2] Register\n";
    cin >> option;

    if (option == "1")
    {
        ifstream file1("C:/Login/username.txt");
        ifstream file2("C:/Login/password.txt");
        string content1;
        string content2;
        while (file1 >> content1) {
            while (file2 >> content2) {
                Clear();
                std::cout << "Username: ";
                cin >> username;
                std::cout << "Password: ";
                cin >> password;


                if (content1 == username && content2 == password)
                {
                    std::cout << "Login Success !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 != username && content2 != password)
                {
                    std::cout << "Incorect Username or Password !!\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 != username && content2 == password)
                {
                    std::cout << "Incorect Username !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                if (content1 == username && content2 != password)
                {
                    std::cout << "Incorect Password !\n";
                    Sleep(3000);
                    exit(EXIT_FAILURE);
                }
                else {
                    std::cout << "Incorect !\n";
                    Sleep(2000);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    if (option == "2")
    {
        std::cout << "Username: ";
        cin >> username;
        std::cout << "Password: ";
        cin >> password;

        outFile.open("c:/Login/Username.txt");
        outFile << username << endl;
        outFile.close();

        outFile.open("C:/Login/Password.txt");
        outFile << password << endl;
        outFile.close();
        Clear();
        main();
    }


}
