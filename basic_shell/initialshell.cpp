#include "../basicshell.hpp"

// Create the initial shell when creating a Basicshell object.
void Basicshell::initial_shell()
{
	// Register the default commands.
    Basicshell::registerdefaults();

    Basicshell::clear_screen(empty_container);

    std::cout << "\033[38;2;225;255;255m" << "\033[38;2;0;255;0m"
            << "Now running in " << shell_name << " shell." << '\n';

	// Keep looping until 'exit' or 'quit' is typed in, then break out of loop.
	while (true) {
		// Variable to store returned key press.
		size_t returned_key{0};

		// Keep looping for key presses until 'enter' is pressed.
		while (true) {
            Basicshell::print_line(check_command);
			if (check_command == "!")
                returned_key = Basicshell::bang(check_command);

			// Variable to check if returned function sent 'keypress'.
            size_t keypress{(returned_key) ? returned_key : Basicshell::getch()};

			// Check for the key pressed.
			switch (keypress) {
				/* Check if backspace was pressed. This can
				 * be different on different os's I think.
				 */
				case 8: {
                    Basicshell::backspace(check_command);
                    Basicshell::print_line(check_command);
					returned_key = 0;
					continue;
				}

				// Check if 'tab' was pressed.
				case 9: {
                    returned_key = Basicshell::tab_press(check_command);
					continue;
				}

				// If enter was pressed, break loop.
				case 10: {
					// Check for closed quotes in string.
                    Basicshell::check_quote(check_command);
					break;
				}

				// Check if arrow key was pressed.
				case 27: {
                    returned_key = Basicshell::arrow_press(check_command);
					continue;
				}

				// Check if '!' was pressed.
				case 33: {
					/* Check if ! is not at the start of command,
					 * and if so, do not run bang command.
					 */
					if (check_command.size() > 0) {
                        Basicshell::insert_char(check_command, keypress);
						continue;
					}
					// Insert ! and send command to bang function.
                    Basicshell::insert_char(check_command, keypress);
                    returned_key = Basicshell::bang(check_command);
					continue;
				}

				// Check if backspace was pressed.
				case 127: {
                    Basicshell::backspace(check_command);
                    Basicshell::print_line(check_command);
					returned_key = 0;
					continue;
				}

				/* If none of the above, insert pressed key
				 *  into command string */
				default: {
                    Basicshell::insert_char(check_command, keypress);
					returned_key = 0;
					continue;
				}
			}

			break;
		}
		/* Check if a previous command was selected. Use
		 *  that if it was, otherwise use any previously
		 *  typed command. */
		command = (!prev_cmd_holder.empty() ? prev_cmd_holder : check_command);

		// If sent command is to exit or quit shell.
		if (command == "quit" || command == "exit") {
            std::cout << "\nLeaving " << shell_name << " shell." << std::endl;
			return;
		}

		// Process the command to break into strings if options are provided.
        Basicshell::process_command(command);

		// Reset commands to empty string.
		check_command = std::string();
		command = std::string();
		prev_cmd_holder = std::string();

		// Reset integers to default.
		cursor_moves = 0;
		vec_size = 0;
		returned_key = 0;
	}
}
