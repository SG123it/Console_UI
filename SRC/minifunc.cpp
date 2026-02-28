#include <iostream>
#include <string>
#include <numeric>
#include <limits>

#include "console_ui.hpp"

std::string console_UI::input(unsigned int maxAttempts) {
    if (maxAttempts <= 0) maxAttempts = 1;

    std::string input_string = "";

    for (int i = 0; i < maxAttempts; i++) {
        std::cout << "\n>>> ";
        std::getline(std::cin, input_string);
        if (std::cin.fail() || std::cin.bad() || std::cin.eof() || std::cin.failbit) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            continue;
        }
        if (!input_string.empty()) break;
    }

    if (input_string.empty()) {
        std::cerr << "Input not success. The attempts are over";
<<<<<<< HEAD
    }
=======
    };
>>>>>>> bc0e00af3b7456775c98927fed64ce8ee086fabe

    return input_string;
}