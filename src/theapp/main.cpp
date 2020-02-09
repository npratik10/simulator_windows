#include <iostream>
#include "pisym.h"
#include "adder.h"

int main()
{
    std::string clk_name = "clk";
    clock *clk = new clock(clk_name);

    adder *add1 = new adder();
    add1->set_component_attributes("add1", 1, 1, 1, 1);
    add1->set_as_first_component(true);

    adder *add2 = new adder();
    add2->set_component_attributes("add2", 1, 1, 1, 1);

    add1->connect_component_downstream(add2);

   std::cout << "Hello world from The App!" << std::endl;

   piMonteCarloSimulation pisym{};
   std::cout << "Symulated value of PI:" << std::endl;
   for (int i = 0; i < 10; ++i)
      std::cout << "  " << pisym.aproxPi() << std::endl;

   for (int i = 0; i < 10; i++)
   {
       clk->trigger_clk();
       cout << "Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
       if (clk->get_rise_edge())
       {
           //add1->component_function();
           //add2->component_function();
           add1->process_clock();
           add2->process_clock();
       }
       cout << "Output add1: " << add1->set_component_output() << std::endl;
       cout << "Output add1: " << add2->set_component_output() << std::endl;
   }
   return 0;
}