#include "component_queue.h"

template <typename DATA_TYPE>
class component_block
{
public:

    component_block(std::string name, clock *clk)
    {
        m_block_name = name;
        m_block_clock = clk;
    }

    virtual ~component_block() {}

    void connect_downstream(component_queue<DATA_TYPE>* fifo)
    {
        downstream_connections.push_back(fifo);
    }

    void connect_upstream(component_queue<DATA_TYPE>* fifo)
    {
        upstream_connections.push_back(fifo);
    }

    virtual void process_clock() {};

    std::vector<component_queue<DATA_TYPE>*> downstream_connections;
    std::vector<component_queue<DATA_TYPE>*> upstream_connections;

private:
    std::string m_clock_name;       // clock to trigger the module
    std::string m_block_name;          // component name
    clock *m_block_clock;
};
