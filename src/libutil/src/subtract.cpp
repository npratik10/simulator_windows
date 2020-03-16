#include "subtract.h"
#include "component_queue.h"

subtract::subtract(std::string name, clock *clk): component_block(name, clk)
{
}

subtract::~subtract()
{
}

void subtract::process_clock()
{
    uint32_t data1, data2;
    bool ip_ready = false;
    if (upstream_connections.at(0)->ready_front())
    {
        data1 = upstream_connections.at(0)->front();
        ip_ready = true;
    }

    if (upstream_connections.at(1)->ready_front())
    {
        data2 = upstream_connections.at(1)->front();
    }

    if (!downstream_connections.at(0)->is_full() && ip_ready)
    {
        result = data1 - data2;
        if (downstream_connections.at(0)->push_back(result))
        {
            upstream_connections.at(0)->pop_front();
            upstream_connections.at(1)->pop_front();
        }
    }
}
