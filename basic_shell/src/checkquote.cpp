#include "../include/basicshell.hpp"

void Basic_Shell::check_quote(std::string& check_command)
{
    if (Basic_Shell::inner_quote) {
		check_command.push_back('\\');
		check_command.push_back('"');
        Basic_Shell::inner_quote = false;
	}
    if (Basic_Shell::inner_single) {
		check_command.push_back('\\');
		check_command.push_back('\'');
        Basic_Shell::inner_single = false;
	}
    if (Basic_Shell::outer_quote) {
		check_command.push_back('"');
        Basic_Shell::outer_quote = false;
	}
    if (Basic_Shell::outer_single) {
		check_command.push_back('\'');
        Basic_Shell::outer_single = false;
	}
}
