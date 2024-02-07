#include "testregister.hpp"

TestRegister::TestRegister()
{
    // Send Basic_Shell the name of your shell.
    Basic_Shell::shell_name = name;

    Basic_Shell::register_command(command_name,
								command,
								short_desc,
								long_desc,
								number_of_options,
								number_of_args);

	TestRegister::initial_shell();
}

int TestRegister::test_attempt(const std::deque<std::string>& options)
{
	std::cout << "\nRunning testregister test_attempt.\n";
	for (const auto& cmd : options) {
		std::cout << cmd << '\n';
	}
	std::cout << std::endl;
	return 0;
}
