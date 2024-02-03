#include "../include/basicshell.hpp"

int Basic_Shell::bang(std::string& sent_command)
{
	while (true) {
        Basic_Shell::print_line(sent_command);

		// If ! is removed via backspace, return.
		if (sent_command.empty()) {
			return 0;
		}

        int keypress{Basic_Shell::getch()};

		/* If key press is a number, add it to the string */
		if (keypress >= 48 && keypress <= 57) {
            Basic_Shell::insert_char(sent_command, keypress);
            Basic_Shell::print_line(sent_command);
			continue;
		}
		switch (keypress) {
			// Check for backspace.
			case 8: {
                Basic_Shell::backspace(sent_command);
				continue;
			}
			// Check if enter was pressed.
			case 10: {
				// If command is empty, return.
				if (sent_command.empty()) {
					return 0;
				}

				// Remove the '!' from the front of command.
				sent_command.erase(0, 1);

				// Search for command matching the number entered.
				auto cmd = std::find_if(previous_commands.begin(),
										previous_commands.end(),
										[&sent_command](const auto& cmd) {
											return std::to_string(cmd.first) ==
												   sent_command;
										});

				// If found, send command, otherwise allow to enter another.
				if (cmd != previous_commands.end()) {
					sent_command = cmd->second;
					return 0;
				} else {
                    std::cout << "\nNo command matching " << sent_command
                            << '\n';
					sent_command = "!";
					continue;
				}
				break;
			}

			case 127: {
                Basic_Shell::backspace(sent_command);
				continue;
			}

			// If none of the above were pressed, ignore key press.
			default: {
				continue;
			}
		}
	}
}
