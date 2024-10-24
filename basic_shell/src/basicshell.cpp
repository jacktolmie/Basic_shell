#include "../include/basicshell.hpp"

Basic_Shell::Basic_Shell(std::string sent_name) : shell_name(sent_name)
{
	// ctor
}

// A function that just clears the screen.
int Basic_Shell::clear_screen(Alias::arguments&)
{
    std::cout << "\033[2J\033[1;1H";
	return 0;
}

// Prints command to screen, by erasing the line first.
void Basic_Shell::print_line(const std::string& sent_command)
{
	// Create a string to place cursor position.
	std::string place_cursor{
		"\x1b[" + std::to_string((sent_command.size() + 4) - cursor_moves) +
		"C"};

	/* Carriage return followed by clearing the line.
	 * Then print >>> and the command. Set cursor position.*/
    std::cout << '\r' << "\x1b[2K"
            << ">>> " << sent_command << '\r' << place_cursor;
}

// Lists all of the registered commands.
int Basic_Shell::list_commands(Alias::arguments&)
{
    std::cout << "\033[38;2;0;255;0m" << '\n'
              << "These are the commands currently available:\n";

    for (auto& cmd : stored_commands.get_set()) {
        std::cout << cmd.func_name << '\t';
    }

    std::cout << "\033[38;2;255;255;255m" << '\n' << "exit"
            << "\033[38;2;0;255;0m" << " or " << "\033[38;2;255;255;255m"
            << "quit" << "\033[38;2;0;255;0m" << " to end session."
            << "\033[38;2;255;255;255m" << "\033[38;2;0;255;0m" <<'\n';

	return 0;
}
