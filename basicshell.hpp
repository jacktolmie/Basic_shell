#ifndef Basicshell_H
#define Basicshell_H

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "cmd_map.hpp"

using namespace std::placeholders;

class Basicshell
{
public:
    using arguments = std::deque<std::string>;
    using _register = std::function<int(std::deque<std::string>&)>;

private:
    
	/* Used to store the command entered. Needed here as it will
	 * be used in multiple cpp files. */
	std::string command{std::string()};

	/* A string to hold value after each keypress. Testing for
	 * inserting chars between characters in the string.*/
	std::string prev_cmd_holder;

	// Checks if prev_cmd_holder or command should be used.
	std::string check_command;

	// Used to store location of cursor when moving left/right.
	int cursor_moves{0};

	// Bools for checking for open ' or " in commands.
	bool inner_quote{false};
	bool outer_quote{false};
	bool inner_single{false};
	bool outer_single{false};

	// A container to store previously called commands.
	std::deque<std::pair<int, std::string>> previous_commands;

	// This is for previous_commands vector call.
	size_t vec_size{0};

    // Function to add command to stored_commands container.
    void add_command(std::string&);

    // Function for when arrow keys are pressed.
    size_t arrow_press(std::string&);

    // Function when backspace is pressed.
    size_t backspace(std::string&);

    // Function for !# history option.
    int bang(std::string&);

    // Function to check for closing quotes
    void check_quote(std::string&);

    /* Function that just clears the screen.
     * It is run at the beginning of Basicshell. */
    int clear_screen(arguments&);

    // Function to remove char from front of cursor.
    size_t delete_char(std::string&);

    // Function that returns the key that was pressed.
    int getch(void);

    // Function that displays the available commands that can be run.
    int help(arguments&);

    // Function that prints history of commands on the screen.
    int history(arguments&);

    // Function to insert characters typed
    void insert_char(std::string&, int);

    // Function to list all registered commands.
    int list_commands(arguments&);

    // Function that prints command on the current line in terminal.
    void print_line(const std::string& = std::string());

    // Function that print out description in help command
    void print_string(const std::string&);

    // Function that processes the command when enter is pressed.
    void process_command(std::string&);

    // Function that processes the string for finding flags/options sent.
    arguments process_options(std::string&);

    // Function to load up default commands.
    void registerdefaults();

	// Function when tab key is pressed.
	size_t tab_press(std::string&);

	/* Function to break string into tokens
	 * that will be used in various functions.*/
	arguments tokens(std::string&);

public:
	/* A map that has the stored commands that are available during
     * the running of Basicshell. Use the 'register' function to
	 * add new commands to the map. */
	Cmd_map stored_commands;

    // Name of the shell. Defaults to Basicshell.
	std::string shell_name;

    // Empty container for passing to functions.
    arguments empty_container;

    Basicshell(std::string sent_name = "Basicshell");
    virtual ~Basicshell() = default;

	// Just starts the shell to make it interactive.
    void initial_shell();

	/*This is for registering commands. All commands MUST already meet the
	 *  function signature before being able to be used. The signature is:
	 *  int <function name>(arguments&)*/
	int register_command(const std::string&,
						 _register,
						 const std::string& short_desc = std::string(),
						 const std::string& long_desc = std::string(),
						 size_t number_of_args = 0,
						 size_t num_of_options = 0);
};

#endif  // BASICSHELL_HPP
