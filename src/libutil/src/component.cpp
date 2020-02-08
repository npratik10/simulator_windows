#include "component.h"

component::component()
{
}

component::~component()
{
}

std::string component::get_module_clock_name()
{
    return std::string();
}

std::string component::get_component_name()
{
    return std::string();
}

void component::get_incoming_component()
{
}

void component::get_outgoing_component()
{
}

void component::set_component_attributes(uint32_t input_buffer_capacity, uint32_t output_buffer_capacity, uint32_t input_delay, uint32_t output_delay)
{
}

uint32_t component::get_component_input()
{
    return upstream_component->set_component_output();
}

uint32_t component::set_component_output()
{
    return processed_output;
}

void component::process_component_function()
{
}
