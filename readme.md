<b><h2>This lib helps you to create simple console UI</h2></b>

<h1>cmakelists tempate</h1>


set(PROJECT_VERSION 1.0)<br>
<br>
cmake_minimum_required(VERSION 3.10...3.30)<br>
project(name VERSION ${PROJECT_VERSION})<br>
<br>
add_subdirectory(include/Console_UI)<br>
<br>
set(SRC<br>
    #all files
)<br>
<br>
add_executable(program ${SRC})<br>
<br>
target_link_libraries(program PRIVATE console_ui)<br>
<br>



<br>

<h1>main.cpp tempate</h1>

```
#include <iostream>

#include <console_ui.hpp>

int main() {
    console_UI::window_settings UI_settings;
    UI_settings.text = R"(
    
    You can write here any length text!
    Hello everyone!

    )";
    UI_settings.title = "Some title";

    std::cout << console_UI::window_print(UI_settings, true);


}
```

<br>

<h1>Cmake build</h1>

<b>
1. cd path/to/project<br>
2. cmake -B build -G "MinGW Makefiles"<br>
3. cmake --build build<br>
</b>

<br><br>

