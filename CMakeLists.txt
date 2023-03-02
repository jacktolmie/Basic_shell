cmake_minimum_required(VERSION 3.5)

project(basic_shell LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(basic_shell main.cpp
basicshell.hpp
cmd_map.hpp
testregister.hpp

basic_shell/cmd_map/add_command.cpp
basic_shell/cmd_map/cmd_map.cpp
basic_shell/cmd_map/find_match.cpp
basic_shell/cmd_map/help_descriptions.cpp
basic_shell/cmd_map/match_args.cpp
basic_shell/cmd_map/send_element.cpp

basic_shell/arrowpress.cpp
basic_shell/backspace.cpp
basic_shell/bang.cpp
basic_shell/basicshell.cpp
basic_shell/checkquote.cpp
basic_shell/deletechar.cpp
basic_shell/getch.cpp
basic_shell/help.cpp
basic_shell/history.cpp
basic_shell/initialshell.cpp
basic_shell/insertchar.cpp
basic_shell/processcommand.cpp
basic_shell/processoptions.cpp
basic_shell/registercommand.cpp
basic_shell/registerdefaults.cpp
basic_shell/tabpress.cpp
basic_shell/testregister.cpp
basic_shell/token.cpp

)
