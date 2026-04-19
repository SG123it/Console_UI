#pragma once

#include <iostream>

class console_UI {
public:
    struct window_settings {
        window_settings(std::string title = "", std::string text = "") {
            this->title = " " + title + " ";
            this->text = text;
        }
        std::string title = "";
        std::string text = "";
        
        unsigned short int text_split_line_maxlength = 100;
    };


    
    static void print_window(const window_settings &window);
    static std::string input(unsigned int maxAttempts = 10);
};