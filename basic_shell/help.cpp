#include <iomanip>
#include <sstream>

#include "../basicshell.hpp"

// A function to show what commands are available.
int Basicshell::help(arguments& search_word)
{
	if (search_word.empty()) {
        std::cout << "\033[38;2;0;255;0m" << '\n'
         << "****************************************" << '\n'
         << "*                 Help                 *" << '\n'
         << "* The following commands are available *" << '\n'
         << "****************************************" << '\n';

        std::cout << "\033[38;2;255;255;255m" << "\nquit " << "\033[38;2;0;255;0m"
                << "or " << "\033[38;2;255;255;255m" << "exit "
                << "\033[38;2;0;255;0m" << "to leave " << shell_name
                << " shell" << '\n';// << IOCtrl::endl;
		for (auto& cmd : stored_commands.short_help()) {
			// Set the command to white, and the description to green.
            std::cout << "\033[38;2;255;255;255m" << std::setw(20) << std::left << cmd.first
					  << "\033[38;2;0;255;0m";
            Basicshell::print_string(cmd.second);
			std::cout << "\n\n";
		}
		std::cout << "\nUse help <command name> for a more indepth description "
					 "of the command (eg 'help history')\n"
                  << "\033[38;2;255;255;255m";

	} else {
        std::cout << "\033[38;2;0;255;0m" << '\n'
            << "****************************************" << '\n'
            << "*       Help for the command(s):       *" << '\n'
            << "****************************************" << '\n';
		for (auto& word : search_word) {
			for (auto& cmd : stored_commands.long_help()) {
				if (word == cmd.first) {
                    std::cout << "\033[38;2;255;255;255m" << std::setw(20) << std::left
							  << cmd.first << "\033[38;2;0;255;0m";
                    Basicshell::print_string(cmd.second);
					std::cout << "\n\n";
				}
			}
        }
	}

	return 0;
}

void Basicshell::print_string(const std::string& str)
{
	std::stringstream stream(str);
	size_t column{40}, count{column};

	/* Go through description and print out each
	 * word. If the line is too long, wrap the line
	 */
	while (!stream.eof()) {
		std::string word;
		std::getline(stream, word, ' ');
		if (word.size() < count) {
			count -= word.size();
			std::cout << word << ' ';
		} else {
			count = column;
			std::cout << std::setfill(' ') << std::setw(21) << std::left << '\n'
					  << word << ' ';
			count -= word.size();
		}
	}
}
