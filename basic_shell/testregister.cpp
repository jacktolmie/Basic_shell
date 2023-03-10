#include "../testregister.hpp"

TestRegister::TestRegister()
{
    // Send Basicshell the name of your shell.
    Basicshell::shell_name = name;

    Basicshell::register_command(command_name,
								command,
								short_desc,
								long_desc,
								number_of_options,
								number_of_args);

	TestRegister::initial_shell();
}

TestRegister::~TestRegister()
{
	// dtor
}
