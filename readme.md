<b><h2>This lib helps you to create simple console UI</h2></b>

<h1>cmakelists tempate</h1>

<code>
cmake_minimum_required(VERSION 3.10)<br>
project(test)<br>
add_subdirectory(console_ui)<br><br>
add_executable(testapp main.cpp)<br><br>
target_include_directories(testapp PRIVATE console_ui/src)<br>
target_link_libraries(testapp PRIVATE console_ui)<br>
</code>

<br>

<h1>main.cpp tempate</h1>

<code>
int main() {<br>
    console_UI::window_settings UI_settings;<br>
    UI_settings.text = R"(<br>
    <br>
        Hello everyone!<br>
    <br>
    )";<br>
    UI_settings.title = "HIHIHI";<br>
    <br>
    console_UI::window_print(UI_settings, true);<br>
    <br>
    return 0;<br>
}
</code>

<br>

<h1>Cmake build</h1>

<b>
1. cd path/to/project<br>
2. cmake -B build -G "MinGW Makefiles"<br>
3. cmake --build build<br>
</b>
