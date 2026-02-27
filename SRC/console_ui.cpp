#include <iostream>
#include <string>

#include "console_ui.hpp"

console_UI::return_data console_UI::calculate_vars(const window_settings &window){
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

        return_values.text_split_line = std::string(max_length, '-');

    }
    return_values.title_split_line = std::string(window.title.size(), '-');

    return return_values;

}

std::string console_UI::window_print(const window_settings &window, bool user_feedback) {
    return_data data = calculate_vars(window);
    
    //STEP1: title
    int center_title_index = (data.text_split_line.size() / 2) - window.title.size();

    std::cout << std::string(center_title_index + 1, ' ');
    std::cout << " " << std::string(window.title.size(), '-') << " " << std::endl;

    std::cout << std::string(center_title_index, ' ');
    std::cout << " |" << window.title << "| \n";

    //STEP2: body
    std::cout << data.text_split_line << "\n";
    std::cout << window.text;
    std::cout << "\n" << data.text_split_line << "\n";

    std::string user_feedback_return = "";
    if (user_feedback) {
        user_feedback_return = "";
        std::cout << "\n>>> ";

        std::getline(std::cin, user_feedback_return);
    }

    return user_feedback_return;
}