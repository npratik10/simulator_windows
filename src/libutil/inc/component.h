#include <iostream>
#include <list>
#include <queue>
#include "clock.h"

class component
{
public:
    // ctor
    component();
    // dtor
    virtual ~component();

    // setrr function
    void set_component_attributes(std::string component_name, uint32_t input_buffer_capacity, uint32_t output_buffer_capacity,
        uint32_t input_delay, uint32_t output_delay);
    uint32_t set_component_output();
    void set_as_first_component(bool state);
    void connect_component_downstream(component* node);
    void connect_component_upstream(component* node);
    void set_component_clock(clock *component_clk);

    // getrr function
    std::string get_module_clock_name();
    std::string get_component_name();
    void get_incoming_component();
    void get_outgoing_component();
    uint32_t get_component_input();
    component* get_downstream_component();
    component* get_upstream_component();
    uint32_t get_output_delay();
    uint32_t get_input_delay();

    // logic function
    bool is_component_output_ready();

    // process function
    virtual void component_function();
    void process_clock();

private:
    component *downstream_component;     // downstream component
    component *upstream_component;       // upstream component
    std::string m_module_clock_name;       // clock to trigger the module
    std::string m_component_name;          // component name
    uint32_t m_output_delay;               // Input Delay of the component
    uint32_t m_input_delay;                // Output delay of the component
    std::queue<uint32_t> input_buffer;   // Input Buffer
    std::queue<uint32_t> output_buffer;  // Output Buffer
    bool is_first_in_block;
    clock *m_component_clock;

protected:
    uint32_t processed_output;
};
