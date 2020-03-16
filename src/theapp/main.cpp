#include <iostream>
#include "subtract.h"

int main()
{
    std::string clk_name = "clk";
    clock *clk = new clock(clk_name);

   subtract *sub1 = new subtract("sub1", clk);
   component_queue<uint32_t> *fifo_ip1 = new component_queue<uint32_t>("fifo_ip1", clk, 4, 1);
   component_queue<uint32_t> *fifo_ip2 = new component_queue<uint32_t>("fifo_ip2", clk, 4, 1);
   component_queue<uint32_t> *fifo_op = new component_queue<uint32_t>("fifo_op", clk, 4, 1);

   sub1->connect_upstream(fifo_ip1);
   sub1->connect_upstream(fifo_ip2);
   sub1->connect_downstream(fifo_op);

   cout << "sub Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
   fifo_ip1->push_back(6);
   fifo_ip2->push_back(3);
   uint32_t outstanding_cnt = 1;

   while (outstanding_cnt != 0)
   {
       clk->trigger_clk();
       cout << "sub Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
       if (clk->get_rise_edge())
       {
           sub1->process_clock();

           if (fifo_op->ready_front())
           {
               uint32_t data = fifo_op->front();
               cout << "result: " << data << std::endl;
               fifo_op->pop_front();
               outstanding_cnt--;
           }
       }
   }
   cout << "sub Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;

   return 0;
}