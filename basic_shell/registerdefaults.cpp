#include "../basicshell.hpp"

void Basicshell::registerdefaults()
{
	// Stores the commands in the stored_commands map.
    Basicshell::
		register_command("help",
                         std::bind(&Basicshell::help, this, _1),
						 "This menu",
						 "This menu displays what commands are available.",
						 0,
						 0);
    Basicshell::register_command("clear",
                                std::bind(&Basicshell::clear_screen, this, _1),
								"Clears the screen.",
								"Use this command to clear the screen.",
								0,
								0);
    Basicshell::
		register_command("history",
                         std::bind(&Basicshell::history, this, _1),
						 "Shows previously entered commands",
						 "This command will show previously used commands that "
						 "can be called up again using !# (eg. !2)",
						 0,
						 0);
    Basicshell::register_command(
		"list_commands",
        std::bind(&Basicshell::list_commands, this, _1),
		"Shows all available commands (not suites).",
		"This command will show all the commands available (not suites). "
		"If not registered, they will not be listed here.",
		0,
		0);
}
