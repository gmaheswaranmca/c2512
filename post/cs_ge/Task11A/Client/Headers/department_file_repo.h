#pragma once
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstring> 

#include "department.h"

class DepartmentFileRepo 
{
private:
    std::string repo_file_name = "Department.dat";
    void CreateFile_();
    int GetLastId_();
public:
    void Create(Department& entity);
    std::vector<Department> ReadAll();
    //
    std::vector<Department> SearchByName(const std::string& name);
    Department ReadByName(std::string name);
    Department ReadById(int id);    
    void Update(Department& entity);
    void DeleteByName(const std::string& name);
};
