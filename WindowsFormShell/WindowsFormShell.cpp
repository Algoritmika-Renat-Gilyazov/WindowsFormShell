#include "Shell.h"
int main(int argc, char** argv)
{
    Form::WindowsShell::Shell sh{};
    return sh.run();
}
