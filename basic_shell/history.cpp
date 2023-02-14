#include "../basicshell.hpp"

int Basicshell::history(arguments& searched_word)
{
    std::cout << '\n';
	/* If there is no word specified, print out
	 * entire history. */
	if (searched_word.empty()) {
		std::for_each(previous_commands.rbegin(),
					  previous_commands.rend(),
					  [](const auto& cmd) {
                          std::cout << cmd.first << "  " << cmd.second
                                  << '\n';
					  });
	} else {
		// Loop through searched_word for searched items.
		for (auto& word : searched_word) {
			// Search for any matching command in previous_commands container.
			std::for_each(previous_commands.rbegin(),
						  previous_commands.rend(),
						  [this, &word](auto& searched) {
							  if (word ==
                                  Basicshell::tokens(searched.second).front()) {
                                  std::cout << searched.first << ' '
                                          << searched.second << '\n';
							  }
                              std::cout << '\n';//this might be wrong
						  });
		}
	}
    std::cout << "Use ! to recall a command (eg. !2)" << '\n';

	return 0;
}
