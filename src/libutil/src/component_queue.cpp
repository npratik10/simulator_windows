#include "component_queue.h"
#include "clock.h"

//template<typename DATA_TYPE>
//component_queue<DATA_TYPE>::component_queue(std::string name, clock *clk, uint32_t capacity, uint32_t delay)
component_queue::component_queue(std::string name, clock *clk, uint32_t capacity, uint32_t delay)
{
    m_fifo_name = name;
    m_fifo_clock = clk;
    m_clock_name = clk->get_clk_name();
    m_capacity = capacity;
    m_delay = delay;
}

///template<typename DATA_TYPE>
//component_queue<DATA_TYPE>::~component_queue()
component_queue::~component_queue()
{
}

//template<typename DATA_TYPE>
//void component_queue<DATA_TYPE>::push_back(DATA_TYPE data)
bool component_queue::push_back(uint32_t data)
{
    if (m_last_clk_pushed == m_fifo_clock->get_clock_cycle())
        return false;

    queue_data_packet pkt;
    pkt.m_data = data;
    pkt.m_maturity_time = m_fifo_clock->get_clock_cycle() + m_delay;
    m_sim_queue.push(pkt);
    m_last_clk_pushed = m_fifo_clock->get_clock_cycle();
    return true;
}

//template<typename DATA_TYPE>
//void component_queue<DATA_TYPE>::pop_front()
void component_queue::pop_front()
{
    if (m_last_clk_popped == m_fifo_clock->get_clock_cycle())
        return;

    m_sim_queue.pop();
    m_last_clk_popped = m_fifo_clock->get_clock_cycle();
}

//template<typename DATA_TYPE>
//DATA_TYPE component_queue<DATA_TYPE>::front()
uint32_t component_queue::front()
{
    return m_sim_queue.front().m_data;
}

//template<typename DATA_TYPE>
//bool component_queue<DATA_TYPE>::ready_front()
bool component_queue::ready_front()
{
    if (m_sim_queue.empty())
        return false;

    if (m_sim_queue.front().m_maturity_time <= m_fifo_clock->get_clock_cycle())
        return true;

    return false;
}

//template<typename DATA_TYPE>
//bool component_queue<DATA_TYPE>::is_full()
bool component_queue::is_full()
{
    if (m_sim_queue.size() == m_capacity)
        return true;
    return false;
}
