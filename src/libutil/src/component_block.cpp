#include "component_block.h"
#include "component_queue.h"
#include "clock.h"

component_block::component_block(std::string name, clock * clk)
{
    m_block_name = name;
    m_block_clock = clk;
}

component_block::~component_block()
{
}

void component_block::connect_downstream(component_queue * fifo)
{
    downstream_connections.push_back(fifo);
}

void component_block::connect_upstream(component_queue * fifo)
{
    upstream_connections.push_back(fifo);
}
