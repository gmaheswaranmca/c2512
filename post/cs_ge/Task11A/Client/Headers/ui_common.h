#pragma once
#include <string>
#include <vector>

#include "ui_settings.h"

class UiCommon {
    public:
        void Clear();
        void Line(char ch);
        void Title(std::string title);
        void TitleBar(std::string title, char lineCh='-');
        void PressAnyKey(bool beforeNumber = false);

        class Input {
            public:
                Input();
                std::string Str(std::string caption = "");
                int Int(std::string caption = "");
                float Float(std::string caption = "");
                double Double(std::string caption = "");
                int Menu(std::string caption, 
                    std::vector<std::string> menuOptions,
                    char lineCh = '-');
                //Only for UI Design 
                int GenerateNumber(int start, int end);
                bool exist();
        };

        Input in;
};

extern UiCommon uiCommon;