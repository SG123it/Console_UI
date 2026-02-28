#include <iostream>

class console_UI {
public:
    struct window_settings {
        window_settings(std::string title = "", std::string text = "") {
            this->title = title;
            this->text = text;
        }
        std::string title = "";
        std::string text = "";

        unsigned short int text_split_line_maxlength = 100;
    };
    static std::string window_print(const window_settings &window, bool user_feedback = false);

private:
    struct return_data {
        std::string title_split_line = "";

        std::string text_split_line = "";
    };
    static return_data calculate_vars(const window_settings &window);
};