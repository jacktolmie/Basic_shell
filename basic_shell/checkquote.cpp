#include "../basicshell.hpp"

void Basicshell::check_quote(std::string& check_command)
{
    if (Basicshell::inner_quote) {
		check_command.push_back('\\');
		check_command.push_back('"');
        Basicshell::inner_quote = false;
	}
    if (Basicshell::inner_single) {
		check_command.push_back('\\');
		check_command.push_back('\'');
        Basicshell::inner_single = false;
	}
    if (Basicshell::outer_quote) {
		check_command.push_back('"');
        Basicshell::outer_quote = false;
	}
    if (Basicshell::outer_single) {
		check_command.push_back('\'');
        Basicshell::outer_single = false;
	}
}
