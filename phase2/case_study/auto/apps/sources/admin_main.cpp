#include<iostream>
#include<sstream>
#include<string>

#include "./../headers/admin_main.h"
#include "./../headers/ui_common.h"

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