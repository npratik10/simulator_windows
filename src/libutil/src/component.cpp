#include "component.h"

component::component()
{
}

component::~component()
{
}

std::string component::get_module_clock_name()
{
    return m_module_clock_name;
}

std::string component::get_component_name()
{
    return m_component_name;
}

void component::get_incoming_component()
{
}

void component::get_outgoing_component()
{
}

void component::set_component_attributes(std::string component_name, uint32_t input_buffer_capacity, uint32_t output_buffer_capacity,
                                          uint32_t input_delay, uint32_t output_delay)
{
    m_component_name    = component_name;
    m_output_delay      = output_delay;
    m_input_delay       = input_delay;
}

uint32_t component::get_component_input()
{
    if (is_first_in_block)
    {
        return 5; //temporary use 5 for the first block
    }

    return upstream_component->set_component_output();
}

uint32_t component::set_component_output()
{
    return processed_output;
}

void component::set_as_first_component(bool state)
{
    is_first_in_block = state;
}

void component::process_component_function()
{
}
