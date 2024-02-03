#include "../include/basicshell.hpp"

// A function that registers tests that are stored in 'available_tests' map.
int Basic_Shell::register_command(const std::string& func_name,
								Alias::_register func,
								const std::string& short_desc,
								const std::string& long_desc,
								size_t arguments,
								size_t options)
{
	// If the function is already stored, commant and return.
	if (stored_commands.find_match(func_name)) {
        std::cout << "Command " << func_name << " already stored."
                << std::endl;
		return 0;
	}

	// Creates a variable from the arguments to add
	stored_commands.add_command(func_name,
								func,
								short_desc,
								long_desc,
								arguments,
								options);

	return 0;
}
