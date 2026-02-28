#include <iostream>
#include <string>
#include <numeric>
#include <limits>

#include "console_ui.hpp"
struct return_data {
        std::string title_split_line = "";

        std::string text_split_line = "";
};

return_data calculate_vars(const console_UI::window_settings &window){
    return_data return_values;
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

        if (window.title.size() > return_values.text_split_line.size()) {
            int difference = (window.title.size() - return_values.text_split_line.size());
            return_values.text_split_line += std::string(difference, '-');
        }
    }
    return_values.title_split_line = std::string(window.title.size(), '-');

    return return_values;

}

std::string console_UI::window_print(const window_settings &window, bool user_feedback) {
    return_data data = calculate_vars(window);
    
    //STEP1: title
    if (data.title_split_line.size() - 1 > 0) {
        int center_title_index = (data.text_split_line.size() / 2) - window.title.size();

        std::cout << std::string(center_title_index + 1, ' ');
        std::cout << " " << std::string(window.title.size(), '-') << " " << std::endl;

        std::cout << std::string(center_title_index, ' ');
        std::cout << " |" << window.title << "| \n";
    }
    //STEP2: body
    std::cout << data.text_split_line << "\n";
    std::cout << window.text;
    std::cout << "\n" << data.text_split_line << "\n";

    std::string user_feedback_return = "";

<<<<<<< HEAD
    if (user_feedback) user_feedback_return = input();
=======
    
>>>>>>> bc0e00af3b7456775c98927fed64ce8ee086fabe

    return user_feedback_return;
}