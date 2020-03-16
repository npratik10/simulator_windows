#include <iostream>
#include <queue>

#include "clock.h"

// component_queue q;
//
// Push to the queue:
// if (!q.is_full())
// {
//   q.push_back(5);
// }
//
// Pop the queue
// if (q.ready_front())
// {
//   data pkt = q.front();
//   q.pop_front();
// }

template <typename DATA_TYPE>
class component_queue
{
public:

    class queue_data_packet
    {
    public:
        DATA_TYPE m_data;
        uint64_t m_maturity_time;
    };

    component_queue(std::string name, clock *clk, uint32_t capacity, uint32_t delay)
    {
        m_fifo_name = name;
        m_fifo_clock = clk;
        m_clock_name = clk->get_clk_name();
        m_capacity = capacity;
        m_delay = delay;
    }

    virtual ~component_queue() {}

    bool push_back(DATA_TYPE data)
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

    void pop_front()
    {
        if (m_last_clk_popped == m_fifo_clock->get_clock_cycle())
            return;

        m_sim_queue.pop();
        m_last_clk_popped = m_fifo_clock->get_clock_cycle();
    }

    DATA_TYPE front()
    {
        return m_sim_queue.front().m_data;
    }

    bool ready_front()
    {
        if (m_sim_queue.empty())
            return false;

        if (m_sim_queue.front().m_maturity_time <= m_fifo_clock->get_clock_cycle())
            return true;

        return false;
    }

    bool is_full()
    {
        if (m_sim_queue.size() == m_capacity)
            return true;
        return false;
    }

private:
    std::queue<queue_data_packet> m_sim_queue;
    uint32_t m_delay;
    uint32_t m_capacity;
    uint64_t m_last_clk_pushed;
    uint64_t m_last_clk_popped;
    std::string m_clock_name;       // clock to trigger the module
    std::string m_fifo_name;          // component name
    clock *m_fifo_clock;
};
