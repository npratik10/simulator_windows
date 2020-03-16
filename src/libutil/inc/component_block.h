#include <iostream>
#include <queue>

class clock;
class component_queue;

//template <typename DATA_TYPE>
class component_block
{
public:

    component_block(std::string name, clock *clk);
    virtual ~component_block();

    void connect_downstream(component_queue* fifo);
    void connect_upstream(component_queue* fifo);

    virtual void process_clock() {};

    std::vector<component_queue*> downstream_connections;
    std::vector<component_queue*> upstream_connections;

private:
    std::string m_clock_name;       // clock to trigger the module
    std::string m_block_name;          // component name
    clock *m_block_clock;
};
