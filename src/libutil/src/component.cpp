#include "component.h"

component::component()
{
    downstream_component = nullptr;
    upstream_component = nullptr;
    is_first_in_block = false;
    processed_output = 0;
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

component * component::get_downstream_component()
{
    return downstream_component;
}

component * component::get_upstream_component()
{
    return upstream_component;
}

uint32_t component::get_output_delay()
{
    return m_output_delay;
}

uint32_t component::get_input_delay()
{
    return m_input_delay;
}

bool component::is_component_output_ready()
{
    uint32_t total_delay = this->m_output_delay + downstream_component->get_input_delay();
    //if ((m_component_clock->get_clock_cycle() + total_delay) )
    return false;
}

uint32_t component::set_component_output()
{
    return processed_output;
}

void component::set_as_first_component(bool state)
{
    is_first_in_block = state;
}

void component::connect_component_downstream(component * node)
{
    downstream_component = node;
    if (node->get_upstream_component() == nullptr)
    {
        node->connect_component_upstream(this);
    }
}

void component::connect_component_upstream(component * node)
{
    upstream_component = node;
    if (node->get_downstream_component() == nullptr)
    {
        node->connect_component_downstream(this);
    }
}

void component::set_component_clock(clock *component_clk)
{
    m_component_clock = component_clk;
}

void component::component_function()
{
}

void component::process_clock()
{
    this->component_function();
}
