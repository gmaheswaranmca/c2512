#ifndef DEPARTMENT_MAIN_H
#define DEPARTMENT_MAIN_H

#include <string>
#include <iostream>

#include "./../Headers/department_file_repo.h"

class DepartmentUi {
    private:
        void Read_(std::string& name, 
            std::string& description);
    public:        
        void Create(Department& department);
        void Display(std::vector<Department>& departments);
};

class DepartmentController {
    private:
        DepartmentFileRepo repo;        
        DepartmentUi view;
    public:        
        void Create();
        void Display();
};

class DepartmentPage {
    private:
        DepartmentController controller;

        int ReadMenu_();
    public:
        void Main();
};
#endif 