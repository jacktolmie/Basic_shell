#ifndef TESTREGISTER_HPP
#define TESTREGISTER_HPP

#include "../include/basicshell.hpp"

class TestRegister : public Basic_Shell
{
public:
	explicit TestRegister();
	virtual ~TestRegister() = default;

	/* Test function to show basic signature for a
	 * command to be able to register correctly.
	 */
	int test_attempt(const std::deque<std::string>&);

private:
	/* If this is to initialize the shell, give name
	 * variable the name you would like, otherwise this is not needed
	 */
	std::string 		name = "Cool Game";

	// Short description of your command. Used in 'help'.
	std::string 		short_desc =
		"This is the short description of TestRegister. Just a test.";

	// Long description of your command. Used in 'help <command name>'.
	std::string 		long_desc =
		"This is the longer description of TestRegister. This will be used "
		"when calling up 'help TestRegister'. Hopefully this works better.";

	/* Name of the command that will be used in the
	 * list of stored commands, and the 'help' function.
	 */
	std::string 		command_name = "test_attempt";

	// The number of options possible. Default is 0.
	size_t 				number_of_options = 0;

	// The number of arguments the command will require.
	size_t 				number_of_args = 1;

	/* Used to register the test. Look up 'std::bind' for details
	 * of how it is used.
	 */
	Alias::_register 	command = std::bind(&TestRegister::test_attempt, this, _1);
};

#endif  // TESTREGISTER_HPP
