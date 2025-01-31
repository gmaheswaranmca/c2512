
#pragma once
#include <gtest/gtest.h>
#include "./../Client/Headers/department.h"
 
class TestDepartmentModel : public testing::Test {

};
 

TEST_F(TestDepartmentModel, TestDepartmentModelCardiology) {
    Department department;
    department.SetId(101);
    department.SetName("Cardiology");
    department.SetDescription("Cardiology Dept");

    EXPECT_EQ(department.GetId(), 101);
    //EXPECT_EQ(department.GetId(), 1) << "Department id not matched";    
    EXPECT_EQ(department.GetName(), "Cardiology");   
    EXPECT_EQ(department.GetDescription(), "Cardiology Dept");   
}

TEST_F(TestDepartmentModel, TestDepartmentModelNeurology) {
    Department department;;
    department.SetId(102);
    department.SetName("Neurology");
    department.SetDescription("Neurology Dept");

    EXPECT_EQ(department.GetId(),102);    
    EXPECT_EQ(department.GetName(), "Neurology");
    EXPECT_EQ(department.GetDescription(), "Neurology Dept");
}



