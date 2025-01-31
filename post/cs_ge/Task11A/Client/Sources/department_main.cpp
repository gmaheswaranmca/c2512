#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "./../Headers/department_main.h"
#include "ui_common.h" 

//class DepartmentUi
void DepartmentUi::Read_(std::string& name, 
        std::string& description) {
    name = uiCommon.in.Str("Enter Department Name:");
    description = uiCommon.in.Str("Enter Department Description:");
}

void DepartmentUi::Create(Department& department) {
    //Read department fields from keyboard
    std::string name;
    std::string description;

    Read_(name, description);
    //Build department instance
    department.SetName(name);
    department.SetDescription(description);
}

void DepartmentUi::Display(std::vector<Department>& departments) {
    //Display departments table
    uiCommon.Line('~');
    std::cout << std::left << std::setw(6) << "Sno"
        << std::left << std::setw(20) << "Department" 
        << std::left << std::setw(20) << "Description" << std::endl;
    uiCommon.Line('~');    
    if (!departments.empty()) {          
        for (size_t i = 0; i < departments.size(); ++i) {
            std::cout << std::left <<  std::setw(6) << (i + 1) 
                << std::left << std::setw(20) << departments[i].GetName() 
                << std::left << std::setw(20) << departments[i].GetDescription() << std::endl;
        }
    } else { 
        std::cout << "No departments available." << std::endl;
    }
    uiCommon.Line('~');
}

//class DepartmentController
void DepartmentController::Create() {
    uiCommon.TitleBar("Department Management > Create Department", '#');

    Department newDepartment;
    view.Create(newDepartment);
    repo.Create(newDepartment);

    std::cout << "Department created successfully." << std::endl;
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
}

void DepartmentController::Display() {
    uiCommon.TitleBar("Department Management > Display Departments", '#');

    std::vector<Department> departments = repo.ReadAll();
    view.Display(departments);
    
    uiCommon.PressAnyKey(true);
}

//class DepartmentPage
int DepartmentPage::ReadMenu_() {
    std::string caption = "Department Management";
    std::vector<std::string> menuOptions {
        "1 - Create Department",
        "2 - Display Departments",
        "99 - Exit"
    };

    int choice = uiCommon.in.Menu(caption, menuOptions, '#');
    return choice;
}

void DepartmentPage::Main() {
    uiCommon.TitleBar("Department Management");

    int choice = 99;

    do {
        choice = ReadMenu_();
        switch (choice) {
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Display();
            } break;            
            case 99: {
                //Exit
            } break;
        }
    } while (99 != choice);
}
