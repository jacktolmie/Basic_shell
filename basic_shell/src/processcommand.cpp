#include "../include/basicshell.hpp"

void Basic_Shell::process_command(std::string& sent_command)
{
	std::stringstream ss(sent_command);
	std::string first_command;

	// Take first word from sent command to check if valid command.
	ss >> first_command;

	// Check if the command is available, if not send "Unknown command".
	auto it{stored_commands.send_element(first_command)};
	if (it.func_name != "noname") {
		// Break rest of sent_command into strings to process options/flags
        Alias::arguments options{Basic_Shell::process_options(sent_command)};

		// If function is help or history, skip argument check.
		if (it.func_name == "help" || it.func_name == "history") {
			it.func_command(options);
			// Adds command to previous_commands container.
            Basic_Shell::add_command(sent_command);
			return;
		}

		// Check that the number of arguments match required amount.
		if (!stored_commands.match_args(it.func_name, options.size())) {
            std::cout << '\n'
					<< "Wrong number of arguments/options. Required argument: "
					<< it.number_of_args;
			if (it.number_of_options) {
                std::cout << ". Optional arguments: " << it.number_of_options;
			}
            std::cout << ". A total of "
					<< (it.number_of_args + it.number_of_options)
					<< ". You provided " << options.size() << '.'
                    << std::endl;
			return;
		} else {
			/* Run the command, and add the command to the deque
			 * of previously run commands. */
			it.func_command(options);
			// Adds command to previous_commands container.
            Basic_Shell::add_command(sent_command);
		}
	} else {
		// If no matching commands, display error.
        std::cout << '\n' << sent_command << " Unknown command"
                << std::endl;
	}
}

void Basic_Shell::add_command(const std::string& sent_command)
{
	/* Adds command to previous_commands container. If it is not
	 *  the last command added to the deque. */
	if (previous_commands.front().second != sent_command) {
		previous_commands.push_front(
			std::pair((previous_commands.size() == 0)
						  ? 1
						  : previous_commands.front().first + 1,
					  sent_command));
	}
}
