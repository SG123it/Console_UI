#include <iostream>
#include <string>
#include <numeric>
#include <limits>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "console_ui.hpp"

//Структура необходимая для функции calculate_vars
struct return_data {
    std::string title_split_line = "";
    int center_textsplitline_index = 0;

    std::string text_split_line = "";
};

//Calculating size of window
return_data calculate_vars(const console_UI::window_settings &window) {
    return_data return_values;
    //-----------------
    { //вычисление text_split_line
        int max_length = 0;
        int temp_length = 0;
        for (char sym : window.text + "\n") { //поиск максимально большой строки
            
            if (sym == '\n') { //перенос строки найден

                if (temp_length > max_length)  {
                    max_length = temp_length;
                    temp_length = 0;
                }

            }
            else temp_length++;

        }
        if (max_length > window.text_split_line_maxlength) max_length = window.text_split_line_maxlength;

        return_values.text_split_line = std::string(max_length, '-');
    }
    //-----------------

    return_values.center_textsplitline_index = (return_values.text_split_line.size() / 2);

    //-----------------
    if (window.title.size() + (return_values.center_textsplitline_index) > return_values.text_split_line.size()) {
        int difference = 0;

        difference = (window.title.size() + (return_values.center_textsplitline_index) - return_values.text_split_line.size());

        if (difference >= 0) {
            return_values.text_split_line += std::string(difference, '-');
            return_values.center_textsplitline_index = (return_values.text_split_line.size() / 2);
        }
    }

    return_values.title_split_line = std::string(window.title.size(), '-');
    //-----------------
    return return_values;

}

//Print window
void console_UI::print_window(const window_settings &window) {

    return_data data = calculate_vars(window);


    //STEP1: title
    if (!window.title.empty()) {

        if (data.center_textsplitline_index - static_cast<int>(window.title.size()) >= 0) {
            std::cout << std::endl;

            std::cout << std::endl << std::string(data.center_textsplitline_index - static_cast<int>(window.title.size()), ' ');
            std::cout << " " << std::string(static_cast<int>(window.title.size()), '-') << " ";

            std::cout << std::endl;

            std::cout << std::string(data.center_textsplitline_index - static_cast<int>(window.title.size()), ' ');
            std::cout << "|" << window.title << "|\n";
        }
        else {
            std::cout << std::string(data.center_textsplitline_index / 2, ' ');
            std::cout << "|" << window.title << "|\n";
        }

    }
    
    //STEP2: body
    std::cout << data.text_split_line << "\n";
    std::cout << window.text;
    std::cout << "\n" << data.text_split_line << "\n";
}