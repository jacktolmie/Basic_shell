#include "../basicshell.hpp"

std::deque<std::string> Basicshell::tokens(std::string& sent_command)
{
	std::stringstream stream(sent_command);
	std::deque<std::string> tokens;

	while (!stream.eof()) {
		std::string ss;
		stream >> ss;
		tokens.push_back(ss);
	}
	return tokens;
}
