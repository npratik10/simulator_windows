#include <iostream>
#include "pisym.h"
#include "adder.h"
#include "component_queue.h"

int main()
{
    std::string clk_name = "clk";
    clock *clk = new clock(clk_name);

    adder *add1 = new adder();
    add1->set_component_attributes("add1", 1, 1, 1, 1);
    add1->set_component_clock(clk);
    add1->set_as_first_component(true);

    adder *add2 = new adder();
    add2->set_component_clock(clk);
    add2->set_component_attributes("add2", 1, 1, 1, 1);

    adder *add3 = new adder();
    add3->set_component_clock(clk);
    add3->set_component_attributes("add3", 1, 1, 4, 1);

    adder *add4 = new adder();
    add4->set_component_clock(clk);
    add4->set_component_attributes("add4", 1, 1, 1, 1);

    adder *add5 = new adder();
    add5->set_component_clock(clk);
    add5->set_component_attributes("add5", 1, 1, 1, 1);

    add1->connect_component_downstream(add2);
    add2->connect_component_downstream(add3);
    add3->connect_component_downstream(add4);
    add4->connect_component_downstream(add5);

    component_queue *fifo1 = new component_queue("fifo1", clk, 4, 1);

   std::cout << "Hello world from The App!" << std::endl;

   piMonteCarloSimulation pisym{};
   std::cout << "Symulated value of PI:" << std::endl;
   for (int i = 0; i < 10; ++i)
      std::cout << "  " << pisym.aproxPi() << std::endl;
   uint32_t j = 5;
   for (int i = 0; i < 20; i++)
   {
       clk->trigger_clk();
       cout << "Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
       if (clk->get_rise_edge())
       {
           //add1->component_function();
           //add2->component_function();
           add1->process_clock();
           add2->process_clock();
           add3->process_clock();
           add4->process_clock();
           add5->process_clock();
       }
       cout << "Output add1: " << add1->processed_output << std::endl;
       cout << "Output add2: " << add2->processed_output << std::endl;
       cout << "Output add3: " << add3->processed_output << std::endl;
       cout << "Output add4: " << add4->processed_output << std::endl;
       cout << "Output add5: " << add5->processed_output << std::endl;

       if (!fifo1->is_full())
        fifo1->push_back(j++);
   }

   for (int i = 0; i < 10; i++)
   {
       clk->trigger_clk();
       cout << "Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
       if (clk->get_rise_edge())
       {
           if (fifo1->ready_front())
           {
               uint32_t data = fifo1->front();
               cout << "data: " << data << std::endl;
               fifo1->pop_front();
           }
       }
   }
   return 0;
}