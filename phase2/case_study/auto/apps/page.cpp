//single source file app...
#define CLRSCR_METHOD 2 // 1 - ANSI Escape Codes 2- system "clear"
#include <termios.h>
#include <unistd.h>

#include<iostream>
#include<limits>

#include<string>


class UiCommon {
    public:
        void Clear() {  
#if CLRSCR_METHOD == 1
            std::cout << "\033[2J\033[1;1H"; 
#else 
            system("clear");
#endif
        }
        void Line(char ch) {
            for(int I =0; I < 80; I++) {
                std::cout << ch;
            }
            std::cout << std::endl;
        }
        void Title(std::string title) {
            std::cout << title << std::endl;
        }
        void TitleBar(std::string title, char lineCh='-') {
            Clear();
            Line(lineCh);
            Title(title);
            Line(lineCh);
        }
        void PressAnyKey(bool beforeNumber = false) {
            std::cout << "Press any key to continue..."; 
            std::cin.get();
            if(beforeNumber) {
                std::cin.get();
            }
        }

        class Input {
            public:
                Input() {
                    srand(static_cast<unsigned>(time(0)));
                }
                std::string Str(std::string caption = "") {
                    std::cout << caption;

                    std::string str;
                    std::cin >> str;
                    return str;
                }
                int Int(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stoi(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Int(caption);
                    }
                }
                float Float(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stof(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Float(caption);
                    }
                }
                double Double(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stod(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Double(caption);
                    }
                }
                int giveMeNumber(int start, int end)
                {	
                    const int MAX_SIZE = end - start + 1;
                    int num = rand() % MAX_SIZE;
                    num += start;
                    return num;
                }
                bool exist() {
                    int num = giveMeNumber(1,10);
                    return (num == 1);
                }
        };

        Input in;
};

extern UiCommon uiCommon;
void ManageFloor();
void ManageAdmin();
void AppMain();

void ManageApps() {
    AppMain();
}

int main() {
    ManageApps();
    return 0;
}

#include<iostream>
#include<sstream>
#include<string>


class FloorController { 
    public: 
        static void Read(std::string& floorNumber, int flags = 3) {
            if((flags & 1) != 0) {
                std::cout << "Floor Number:"; std::cin >> floorNumber;
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Floor Management > Create floor");
            int flags = 3;
            std::string floorNumber;
            
            do {
                Read(floorNumber, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `floor number`." << std::endl; 
                soutput << "91 - Proceed to create floor." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Floor is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Floor Management > Edit floor");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Floor Management > Delete floor");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Floor Management > List of floors");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadFloorMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Floor Management");

    std::stringstream soutput;
    soutput << "1 - Create Floor" << std::endl;
    soutput << "2 - Edit Floor" << std::endl;
    soutput << "3 - Delete Floor" << std::endl;
    soutput << "4 - Display All Floors" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageFloor() { 
    FloorController controller;
    
    int choice;

    do { 
        choice = ReadFloorMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}
#include<iostream>
#include<sstream>
#include<string>


class AdminController { 
    public: 
        static void Read(std::string& name,
            std::string& email,
            std::string& password,
            std::string& phone,
            int role, 
            int flags = 31) {

            
            if((flags & 1) != 0) {
                name = uiCommon.in.Str("Enter name:");
            }

            if((flags & 2) != 0) {
                do {
                    email = uiCommon.in.Str("Enter email:");
                    if(!uiCommon.in.exist()) {
                        break;
                    }
                    std::cout << "Email exist." << std::endl;
                } while(true);
            }
            if((flags & 4) != 0) {
                password = uiCommon.in.Str("Enter password:");
            }
            if((flags & 8) != 0) {
                phone = uiCommon.in.Str("Enter phone:");
            }
            if((flags & 16) != 0) {
                role = 1; // 1 - admin
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Admin Management > Create admin");
            int flags = 31;
            std::string name;
            std::string email;
            std::string password;
            std::string phone;
            int role = 0; 
            
            do {
                Read(name, email, password, phone, role, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `name`." << std::endl; 
                soutput << "2 - edit `email`." << std::endl; 
                soutput << "4 - edit `password`." << std::endl; 
                soutput << "8 - edit `phone`." << std::endl; 
                soutput << "3 - edit `phone` and `email`." << std::endl; 
                soutput << "91 - Proceed to create admin." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Admin is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Admin Management > List of Admins");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadAdminMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Admin Management");

    std::stringstream soutput;
    soutput << "1 - Create Admin" << std::endl;
    soutput << "2 - Edit Admin" << std::endl;
    soutput << "3 - Delete Admin" << std::endl;
    soutput << "4 - Display All Admins" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageAdmin() { 
    AdminController controller;
    
    int choice;

    do { 
        choice = ReadAdminMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}
#include <iostream>
#include <sstream>

UiCommon uiCommon;

static int ReadAppMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App");

    std::stringstream soutput;
    soutput << "1 - Floor Management" << std::endl;
    soutput << "2 - Admin Management" << std::endl;
    soutput << "99 - Logout" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageApp() { 
    
    int choice;

    do { 
        choice = ReadAppMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                ManageFloor();
            } break;
            case 2: {
                ManageAdmin();
            } break;
        }
    } while(99 != choice);
}

void AppMain() {
    ManageApp();
}
