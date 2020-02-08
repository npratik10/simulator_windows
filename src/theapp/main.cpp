#include <iostream>
#include "pisym.h"
#include "clock.h"

int main()
{
    std::string clk_name = "clk";
    clock *clk = new clock(clk_name);

   std::cout << "Hello world from The App!" << std::endl;

   piMonteCarloSimulation pisym{};
   std::cout << "Symulated value of PI:" << std::endl;
   for (int i = 0; i < 10; ++i)
      std::cout << "  " << pisym.aproxPi() << std::endl;

   for (int i = 0; i < 10; i++)
   {
       clk->trigger_clk();
       cout << "Clk: " << clk->get_clock_cycle() << ", riseEdge: " << clk->get_rise_edge() << std::endl;
   }

   return 0;
}