#include<iostream>
#include<sstream>
#include<string>

#include "./../headers/floor_main.h"
#include "./../headers/ui_common.h"

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