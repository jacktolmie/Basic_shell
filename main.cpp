#include <iostream>
#include "basic_shell/include/basicshell.hpp"
using namespace std;

int main()
{
    Basic_Shell shell{"root"};
    shell.initial_shell();
    return 0;
}
