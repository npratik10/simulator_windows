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
    m_delay             = input_delay;
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

uint32_t component::get_input()
{
    return uint32_t();
}

bool component::is_component_output_ready()
{
    if (m_component_clock->get_clock_cycle() == output_ready_cycle)
    {
        return true;
    }
    return false;
}

bool component::output_ready()
{
    if (m_component_clock->get_clock_cycle() == (process_clk_cycle + m_delay))
    {
        return true;
    }
    return false;
}

bool component::input_ready(bool &is_src_upstream_component)
{
    if (is_first_in_block)
    {
        is_src_upstream_component = false;
        if (one_time)
        {
            one_time = false;
            return true; //temporary use 5 for the first block
        }
        else
            return false;
    }
    else if (upstream_component->output_ready())
    {
        is_src_upstream_component = true;
        return true;
    }
    else
        return false;
}

uint32_t component::get_output()
{
    return processed_output;
}

uint32_t component::get_input(bool is_src_upstream_component)
{
    if (is_src_upstream_component)
        return upstream_component->get_output();
    return 5;
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
    bool is_upstream_component_ip;
    if (input_ready(is_upstream_component_ip))
    {
        this->process_clk_cycle = m_component_clock->get_clock_cycle();
        this->processed_input = get_input(is_upstream_component_ip);
        this->component_function();
    }
}
