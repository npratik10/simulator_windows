#include "..\inc\adder.h"

adder::adder()
{
}

adder::~adder()
{
}

void adder::process_component_function()
{
    uint32_t input = get_component_input();
    processed_output = input + 20;
}
