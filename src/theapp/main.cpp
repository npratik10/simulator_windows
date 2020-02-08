#include <iostream>
#include "pisym.h"
#include "clock.h"
#include "adder.h"

int main()
{
    std::string clk_name = "clk";
    clock *clk = new clock(clk_name);

    adder *add1 = new adder();
    add1->set_component_attributes("add1", 1, 1, 1, 1);
    add1->set_as_first_component(true);

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
           add1->process_component_function();
   }
   cout << "Output: " << add1->set_component_output() << std::endl;
   return 0;
}