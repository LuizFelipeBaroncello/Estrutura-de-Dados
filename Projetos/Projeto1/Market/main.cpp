#include "performance.h"
#include "user_interaction.h"
#include "control.h"

int main()
{
    using namespace control;

    Control* control = new Control();
    control->print_data();
    delete control;
}
