#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H

#include <algorithm>
#include <deque>
#include <functional>


#include "../include/cmd_map.hpp"
#include "../include/alias.hpp"

using namespace std::placeholders;

class Basic_Shell
{

private:
    
    /* A container used to store words that need to bypass
     * the process_command function check. */
    std::set<std::string> 	skipped_words{"help", "history", "list"};
    
	/* Used to store the command entered. Needed here as it will
	 * be used in multiple cpp files. */
	std::string 			command{std::string()};

	/* A string to hold value after each keypress. Testing for
	 * inserting chars between characters in the string.*/
	std::string 			prev_cmd_holder;

	// Checks if prev_cmd_holder or command should be used.
	std::string 			check_command;

	// Used to store location of cursor when moving left/right.
	int cursor_moves{0};

	// Bools for checking for open ' or " in commands.
	bool 					inner_quote{false};
	bool 					outer_quote{false};
	bool 					inner_single{false};
	bool 					outer_single{false};

	// A container to store previously called commands.
	Alias::deqstr 			previous_commands;

	// This is for previous_commands vector call.
	size_t 					vec_size{0};

	// Function to add command to stored_commands container.
	void add_command(const std::string&);

	// Functions for when arrow keys are pressed.
	size_t arrow_press(std::string&);
    
    // Function when backspace is pressed.
	size_t backspace(std::string&);
    
    // Function for !# history option.
	int bang(std::string&);
    
    // Function to check for closing quotes
	void check_quote(std::string&);
    
    /* Function to check for words that need to
     * bypass the process_command check of proper
     * arguments/options passed. */
    bool check_skip_list(const std::string&);
    
    // Just clears the screen. Is run at the beginning of Basic_Shell.
	int clear_screen(Alias::arguments&);
    
    // Function to remove char from front of cursor.
	size_t delete_char(std::string&);
    
    // Returns the key that was pressed.
	int getch(void);
    
    // Displays the available commands that can be run.
	int help(Alias::arguments&);
    
    // Prints history of commands on the screen.
	int history(Alias::arguments&);
    
    // Function to insert characters typed
	void insert_char(std::string&, int);
    
    // Function to list all registered commands.
	int list_commands(Alias::arguments&);
    
    // Prints command on the current line in terminal.
	void print_line(const std::string& = std::string());
    
    // Print out description in help command
	void print_string(const std::string&);
    
    // Process the command when enter is pressed.
	void process_command(std::string&);
    
    // Process string for finding flags/options sent.
	Alias::arguments process_options(std::string&);
    
    // Function to load up default commands.
	void registerdefaults();

	// Function when tab key is pressed.
	size_t tab_press(std::string&);

	/* Function to break string into tokens
	 * that will be used in various functions.*/
	Alias::arguments tokens(const std::string&);

public:
	/* A map that has the stored commands that are available during
	 * the running of Basic_Shell. Use the 'register' function to
	 * add new commands to the map. */
	Cmd_map stored_commands;

	// Name of the shell. Defaults to Basic_Shell.
	std::string shell_name;

	Basic_Shell(std::string sent_name = "Basic_Shell");
	virtual ~Basic_Shell() = default;
    
    // Function to add word to skipped_words container.
    void add_skipped_command(const std::string&);

	// Just starts the shell to make it interactive.
	void initial_shell();

	/*This is for registering commands. All commands MUST already meet the
	 *  function signature before being able to be used. The signature is:
	 *  int <function name>(arguments&)*/
	int register_command(const std::string&,
						 Alias::_register,
						 const std::string& short_desc = std::string(),
						 const std::string& long_desc = std::string(),
						 size_t number_of_args = 0,
						 size_t num_of_options = 0);

	// Empty container for passing to functions.
	Alias::arguments empty_container;
};

#endif  // BASIC_SHELL_H
