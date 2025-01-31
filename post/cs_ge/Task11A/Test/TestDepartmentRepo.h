#pragma once
#include <string>
#include <gtest/gtest.h>
#include "./../Client/Headers/department_file_repo.h"

class TestDepartmentRepo : public testing::Test {
protected:
    DepartmentFileRepo* repo = nullptr;
 
    // Called before each test
    void SetUp() override {
        repo = new DepartmentFileRepo;
    }
 
    // Called after each test
    void TearDown() override {
        if(repo != nullptr) { delete repo; }
    }
};
 
TEST_F(TestDepartmentRepo, DepartmentRepoCreate) {
    Department department;
    department.SetName("Cardiology");
    department.SetDescription("Cardiology Dept");
 
    repo->Create(department);
 
    EXPECT_EQ(1, 1);    
}
 
TEST_F(TestDepartmentRepo, DepartmentReadAll) {    
    std::vector<Department> departments = repo->ReadAll();

    EXPECT_EQ(1,1) ; 
}

TEST_F(TestDepartmentRepo, DepartmentCreateAndReadAll) {
    Department department;
    department.SetName("Cardiology");
    department.SetDescription("Cardiology Dept");

    repo->Create(department);

    std::vector<Department> departments = repo->ReadAll();
    Department savedDepartment = departments[departments.size()-1];
    
    EXPECT_EQ(savedDepartment.GetName(), "Cardiology");
    EXPECT_EQ(savedDepartment.GetDescription(), "Cardiology Dept");
}
