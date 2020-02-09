#include "adder.h"

adder::adder()
{
}

adder::~adder()
{
}

void adder::component_function()
{
    uint32_t input = get_component_input();
    processed_output = input + 20;
}
