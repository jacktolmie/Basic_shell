cmake_minimum_required(VERSION 3.5)

project(basic_shell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(basic_shell main.cpp
    basic_shell/include/basicshell.hpp
    basic_shell/include/cmd_map.hpp

    basic_shell/cmd_map/add_command.cpp
    basic_shell/cmd_map/cmd_map.cpp
    basic_shell/cmd_map/find_match.cpp
    basic_shell/cmd_map/help_descriptions.cpp
    basic_shell/cmd_map/match_args.cpp
    basic_shell/cmd_map/send_element.cpp

    basic_shell/src/arrowpress.cpp
    basic_shell/src/backspace.cpp
    basic_shell/src/bang.cpp
    basic_shell/src/basicshell.cpp
    basic_shell/src/checkquote.cpp
    basic_shell/src/deletechar.cpp
    basic_shell/src/getch.cpp
    basic_shell/src/help.cpp
    basic_shell/src/history.cpp
    basic_shell/src/initialshell.cpp
    basic_shell/src/insertchar.cpp
    basic_shell/src/processcommand.cpp
    basic_shell/src/processoptions.cpp
    basic_shell/src/registercommand.cpp
    basic_shell/src/registerdefaults.cpp
    basic_shell/src/tabpress.cpp
    basic_shell/src/token.cpp
    
    basic_shell/test_register/testregister.hpp
    basic_shell/test_register/testregister.cpp

)
