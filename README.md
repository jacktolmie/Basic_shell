# Basicshell

This is the basic shell for use with projects where you want a shell that you can create custom commands.

This will give the following features:

* Give the shell a custom name if desired. Defaults to "Basicshell".

* Stores previously typed commands that can be recalled via the
  up and down arrow keys.
  
* Recall a list of used commands using 'history' command to retrieve a
  list of commands with a number beside it to use with ! option.
  Running `history <command>` will recall only the history of the commands
  requested (`history help history` will recall any commands using
  help and history).
  
* Use !<#> to recall the desired command (eg. !2 recalls the second
  command in the list).
  
* Double press of tab to recall all available commands, or start typing 
  a command and use double tab key press to auto-fill command.
  
* Register custom commands that can be used in any shell that 
  inherits Basicshell, as long as it follows the right signature.
  
* Running `help` will display the list of available commands with
  a description of what it does. Any commands registered and stored
  in the 'stored_commands' container by the user will be listed here
  along with the description provided.

* Running `help <command>` will display a more indepth description
  of the command the user is looking for. It can also accept
  multiple commands (`help command1 command2` etc).
  
* Some commands will need to bypass the checking of number of arguments
  and options. If needed, use the Basicshell::add_skipped_command to
  add the command (eg. Basicshell::add_skipped_command("test_name")).

## To Install
On Debian based systems run:
```bash
sudo apt update && sudo upgrade -y
sudo apt install cmake build-essential
```

On Fedora based systems run:
To install on Fedora systems, run:
```bash
sudo dnf update
sudo dnf install cmake g++
```
Download the code:
```bash
git clone https://github.com/jacktolmie/Basic_shell.git
```

This template is packaged using CMake.
To build it, you can run:
```bash
cd Basic_shell/basic_shell
mkdir -p build
cmake -B build
cmake --build build
```
To run the shell:
```bash
build/basic_shell
```

## Including Basicshell

To include Basicshell in the code, include the following:

    #include "../include/blueshell.hpp"
    
    
## To instantiate Basicshell

After including blueshell.hpp, create an object via:

    Basicshell <variable name>;
    
    eg Basicshell game_shell;
    
## Registering and store a command to use:
     
To register a command:

    /* Used to register the test. Look up 'std::bind' for details
     * of how it is used. Creates a variable called command that
     * that can be passed as arguments.
     */
    _register command = std::bind(&TestRegister::test_attempt, this, _1);
   	
To store it in the list of available commands:

    Basicshell::register_command(std::string func_name, _register func, std::string short_desc, std::string long_desc, int arguments)
	eg (Create the variables as needed, or you can type each argument in the register_command call):
	
	// Short description of your command. Used in 'help'.
    std::string short_desc = "This is the short description of my command";
    
    // Long description of your command. Used in 'help <command name>'.
	std::string long_desc = "This is the longer description of my command. This will be used when calling up 'help command_name'.";
    
    /* Name of the command that will be used in the
     * list of stored commands, and the 'help' function.
     */
	std::string command_name = "command_name";
    
    // The number of arguments the command will require.
	size_t number_of_args = 1;
	
	// The number of options the command can accept.
	size_t number_of_options = 1;
    
    /* Used to register the test. Look up 'std::bind' for details
     * of how it is used.
     */
    _register command = std::bind(&TestRegister::test_attempt, this, _1);
    
    // Register the command using:
    Basicshell::register_command(<command name>, <the command>, <short help description>
                <long help description>, <number of required arguments to be passed>);
    // If the command name, descriptions and arguments are in variables:
    Basicshell::register_command(command_name, command, short_desc, long_desc, number_of_options, number_of_args);

    // If you want to pass them directly, with no variables:
	eg Basicshell::register_command("test_attempt", std::bind(&TestRegister::test_attempt, this, _1), "This is short help description", "This is a longer description for the help menu", 0, 1);
	
When you type `help` in the shell, it will display like this:
command_name        This is the short description of my command

Typing `help <command_name>` will display:
command_name        This is the longer description of my command. This will be used when calling up 'help command_name'.


## Example code for classes

Here is a test class:

    #include "../include/basicshell.hpp"

    class TestRegister : public Basicshell
    {
    public:
        explicit TestRegister();
        virtual ~TestRegister();
        
        /* Test function to show basic signature for a
        * command to be able to register correctly.
        */
        int test_attempt(std::deque<std::string>& options)
        {
            std::cout << "\nRunning testregister test_attempt.\n";
            for(auto& cmd : options){
                std::cout << cmd <<'\n';
            }
            std::cout<<std::endl;
            return 0;
        }

    private:
        /* If this is to initialize the shell, give name
        * variable the name you would like, otherwise this is not needed
        */
        std::string name = "Cool Game";
        
        // Short description of your command. Used in 'help'.
        std::string short_desc = "This is the short description of TestRegister";
        
        // Long description of your command. Used in 'help <command name>'.
        std::string long_desc = "This is the longer description of TestRegister. This will be used when calling up `help TestRegister`.";
        
        /* Name of the command that will be used in the
        * list of stored commands, and the 'help' function.
        */
        std::string command_name = "test_attempt";
        
        // The number of arguments the command will require.
        size_t number_of_args = 1;
        
        // The number of options the command can accept.
        size_t number_of_options = 1;
        
        /* Used to register the test. Look up 'std::bind' for details
        * of how it is used.
        */
        _register command = std::bind(&TestRegister::test_attempt, this, _1);
    };

    TestRegister::TestRegister()
    {
        // Send Basicshell the name of your shell.
        Basicshell::shell_name = name;
        
        Basicshell::register_command(command_name, command, short_desc, long_desc, number_of_options, number_of_args);
        TestRegister::initial_shell();
    }
