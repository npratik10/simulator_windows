#include <iostream>
#include <queue>

class clock;

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

//template <typename DATA_TYPE>
class component_queue
{
public:

    class queue_data_packet
    {
        public:
            //DATA_TYPE m_data;
            uint32_t m_data;
            uint64_t m_maturity_time;
    };

    component_queue(std::string name, clock *clk, uint32_t capacity, uint32_t delay);
    virtual ~component_queue();
    //void push_back(DATA_TYPE data);
    bool push_back(uint32_t data);
    void pop_front();
    //DATA_TYPE front();
    uint32_t front();
    bool ready_front();
    bool is_full();

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
