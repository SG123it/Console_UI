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


    
    static std::string window_get(const window_settings &window, bool user_feedback = false);
    static std::string input(unsigned int maxAttempts = 10);

private:
    struct return_data {
        std::string title_split_line = "";
        int center_textsplitline_index = 0;

        std::string text_split_line = "";
    };

    static return_data calculate_vars(const console_UI::window_settings &window);
};