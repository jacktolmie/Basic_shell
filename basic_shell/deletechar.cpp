#include "../basicshell.hpp"

size_t Basicshell::delete_char(std::string& sent_command)
{
	if (sent_command.empty() || cursor_moves == 0) {
		return 0;
	}
	sent_command.erase(sent_command.size() - cursor_moves, 1);
	--cursor_moves;
	return 0;
}
