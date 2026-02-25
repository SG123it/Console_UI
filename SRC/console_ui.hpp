#include <iostream>

namespace console_UI {
    struct window_settings {
        std::string title = "title";
        std::string text = R"(
        
        TEXT

        )";
    };


    std::string window_print(window_settings window, bool user_feedback = false);

}