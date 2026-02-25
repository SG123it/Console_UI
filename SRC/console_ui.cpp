#include <iostream>
#include <string>

#include "console_ui.hpp"

std::string console_UI::window_print(window_settings window, bool user_feedback) {
    std::string print_text = "";

    std::string title_split_line = "";
    std::string text_split_line = "";

    { //вычисление text_split_line
        int max_length = 0;
        int temp_length = 0;
        for (char sym : window.text + "\n") { //поиск максимально большой строки
            
            if (sym == '\n') { //перенос строки найден

                if (temp_length > max_length) max_length = temp_length;

            }
            else temp_length++;

        }

        for (int i = 0; i < max_length; i++) text_split_line += "-";

    }
    for (int i = 0; i < window.title.size(); i++) title_split_line += "-"; //вычисление title_split_line

    //STEP1: title
    for (int i = 0; i < ((text_split_line.size() - 1) / 2) - (window.title.size()); i++) print_text += " "; //Запись титула в центр
    print_text += " -" + title_split_line + "- \n";

    for (int i = 0; i < ((text_split_line.size() - 1) / 2) - (window.title.size()); i++) print_text += " "; //Запись титула в центр
    print_text += "| " + window.title + " |\n";

    //STEP2: body
    print_text += text_split_line + "\n";
    print_text += window.text;
    print_text += "\n" + text_split_line + "\n";


    std::cout << print_text;

    std::string user_feedback_return = "";
    if (user_feedback) {
        while(true) {
            user_feedback_return = "";
            try {
                std::cout << "\n>>> ";
                std::cin.ignore();
                std::getline(std::cin, user_feedback_return);
            }
            catch(...) {
                continue;
            }
            break;
        }
    }

    return user_feedback_return;
}