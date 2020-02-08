#include <iostream>
#include <list>
#include <queue>

class component
{
public:
    component();
    virtual ~component();
    std::string get_module_clock_name();
    std::string get_component_name();
    void get_incoming_component();
    void get_outgoing_component();
    void set_component_attributes(uint32_t input_buffer_capacity, uint32_t output_buffer_capacity,
        uint32_t input_delay, uint32_t output_delay);
    uint32_t get_component_input();
    uint32_t set_component_output();

    virtual void process_component_function();

private:
    component *dowmstream_component;     // downstream component
    component *upstream_component;       // upstream component
    std::string module_clock_name;       // clock to trigger the module
    std::string component_name;          // component name
    uint32_t output_delay;               // Input Delay of the component
    uint32_t input_delay;                // Output delay of the component
    std::queue<uint32_t> input_buffer;   // Input Buffer
    std::queue<uint32_t> output_buffer;  // Output Buffer
    uint32_t processed_output;
};