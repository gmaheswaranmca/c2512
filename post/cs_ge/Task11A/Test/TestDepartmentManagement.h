#pragma once
#include <string>
#include <gtest/gtest.h>
#include "./../Client/Headers/department_main.h"

class TestDepartmentManagement : public testing::Test {
protected:
    DepartmentController* controller = nullptr;
    DepartmentFileRepo* repo = nullptr;
    std::ostringstream output;
    // Called before each test
    void SetUp() override {        
        std::cout.rdbuf(output.rdbuf());  // Mock output
        controller = new DepartmentController;
        repo = new DepartmentFileRepo;
    }
 
    // Called after each test
    void TearDown() override {
        if(controller != nullptr) { delete controller; }
        if(repo != nullptr) { delete repo; }
    }
};
 
TEST_F(TestDepartmentManagement, CreateDepartmentPage) {
    std::istringstream input("Neurology\nNeurology Dept");
    std::cin.rdbuf(input.rdbuf());  // Mock input
    
    controller->Create();
    
    std::vector<Department> departments = repo->ReadAll();
    Department savedDepartment = departments[departments.size()-1];
    
    EXPECT_NE(output.str().find("Department created successfully"), std::string::npos) ; 
    EXPECT_EQ(savedDepartment.GetName(), "Neurology");
}
 
TEST_F(TestDepartmentManagement, DepartmentDisplayPage) {       
    controller->Display();

    EXPECT_NE(output.str().find("Neurology"), std::string::npos) ; 
}