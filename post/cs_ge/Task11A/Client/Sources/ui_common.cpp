#include <termios.h>
#include <unistd.h>

#include <limits>

#include <iostream>
#include <sstream>

#include <string>
#include <vector>

#include "ui_settings.h"
#include "./../Headers/ui_common.h"

//class UiCommon
void UiCommon::Clear() {  
#if CLRSCR_METHOD == 1
    std::cout << "\033[2J\033[1;1H"; 
#else 
    system("clear");
#endif
}

void UiCommon::Line(char ch) {
    for(int I =0; I < 80; I++) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

void UiCommon::Title(std::string title) {
    std::cout << title << std::endl;
}

void UiCommon::TitleBar(std::string title, char lineCh) {
    Clear();
    Line(lineCh);
    Title(title);
    Line(lineCh);
}

void UiCommon::PressAnyKey(bool beforeNumber) {
    std::cout << "Press <RETURN> key to continue..."; 
    std::cin.get();
    if(beforeNumber) {
        std::cin.get();
    }
}

//class UiCommon::Input
UiCommon::Input::Input() {
    srand(static_cast<unsigned>(time(0)));
}

std::string UiCommon::Input::Str(std::string caption) {
    std::cout << caption;

    std::string str;
    std::getline(std::cin, str);
    return str;
}

int UiCommon::Input::Int(std::string caption) {
    std::string str = this->Str(caption);
    try {
        // Convert to int
        int value = std::stoi(str);
        return value;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Number" << std::endl;
        return this->Int(caption);
    }
}

float UiCommon::Input::Float(std::string caption) {
    std::string str = this->Str(caption);
    try {
        // Convert to int
        float value = std::stof(str);
        return value;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Number" << std::endl;
        return this->Float(caption);
    }
}

double UiCommon::Input::Double(std::string caption) {
    std::string str = this->Str(caption);
    try {
        // Convert to int
        double value = std::stod(str);
        return value;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Number" << std::endl;
        return this->Double(caption);
    }
}

int UiCommon::Input::Menu(std::string caption, 
    std::vector<std::string> menuOptions,
    char lineCh) {
    int choice;

    uiCommon.TitleBar(caption, lineCh);

    std::stringstream soutput;
    for(auto menuOption : menuOptions) {
        soutput << menuOption << std::endl;
    }
    soutput << "Your choice:";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

int UiCommon::Input::GenerateNumber(int start, int end)
{	
    const int MAX_SIZE = end - start + 1;
    int num = rand() % MAX_SIZE;
    num += start;
    return num;
}

bool UiCommon::Input::exist() {
    int num = GenerateNumber(1,10);
    return (num == 1);
}
        
//UiCommon instance
UiCommon uiCommon;
