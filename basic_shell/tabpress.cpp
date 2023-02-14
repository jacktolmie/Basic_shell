#include "../basicshell.hpp"

size_t Basicshell::tab_press(std::string& sent_command)
{
    int keypress{Basicshell::getch()};

	if (keypress != 9) {
		return keypress;
	}
	/* If tab is pressed again, and command is
	 *  empty, display all available commands */
	if (sent_command.empty()) {
		size_t count{0};
        std::cout<<'\n';
		for (auto& cmd : stored_commands.get_set()) {
            std::cout << cmd.func_name;
			if (count < 2) {
				++count;
                std::cout << '\t';
			} else {
                std::cout <<'\n';
				count = 0;
			}
		}
        std::cout<< std::endl;
	}

	/* If tab is pressed again, and command is not
	 *  empty, find any commands that start with
	 *  command argument. */
	if (!sent_command.empty()) {
        std::string token{Basicshell::tokens(sent_command).back()};

		std::deque<std::string> temp_cmds;

		for (auto& cmd : stored_commands.get_set()) {
			/* Looks for any commands that match the
			 *  'command' sent. */
			if (cmd.func_name.rfind(token, 0) == 0) {
				temp_cmds.push_back(cmd.func_name);
			}
		}
		// If no matching commands, return.
		if (temp_cmds.empty()) {
			return 0;
		}
		/* If there is only one item in the deque
		 *  then print the command to the screen.
		 *  Otherwise print all items in deque.*/
		if (temp_cmds.size() == 1) {
			while (sent_command.back() != ' ' && !sent_command.empty()) {
				sent_command.pop_back();
			}
			sent_command.append(temp_cmds.front());
            Basicshell::print_line(sent_command);
			return 0;
		} else {
            std::cout << '\n';
			for (auto& cmd : temp_cmds) {
                std::cout << cmd << '\t';
			}
		}
        std::cout << std::endl;

		/* Fill in any chars that match each string in deque.
		 *  For example 'te' in words 'test' and 'tests' would
		 *  fill in the partial typed command 'te' to 'test'.
		 *  Get the size of the largest word, and use that for
		 *  the end of the loop. */
		for (size_t i{token.size()};
			 i < std::size(*max_element(
					 temp_cmds.begin(),
					 temp_cmds.end(),
					 [](auto& word1, auto& word2) {
						 return word1.size() < word2.size();
					 }));
			 ++i) {
			if (std::all_of(temp_cmds.begin(),
							temp_cmds.end(),
							[&](auto& word) {
								return word[i] == temp_cmds[0][i];
							})) {
				sent_command.push_back(temp_cmds[0][i]);
				continue;
			}
			break;
		}

		temp_cmds.clear();
	}
	return 0;
}
