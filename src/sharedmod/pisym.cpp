#include "pisym.h"

piMonteCarloSimulation::piMonteCarloSimulation()
   :rnd(std::optional<int>{})
{

}

double piMonteCarloSimulation::aproxPi()
{
   auto const Samples = 50000;

   auto hit = 0;
   auto x = 0.0;
   auto y = 0.0;

   for (auto i = 0; i<Samples; i++)
   {
      x = rnd.NextDouble();
      y = rnd.NextDouble();

      if (y <= std::sqrt(1 - std::pow(x, 2))) hit += 1;
   }

   return 4.0 * hit / Samples;
}
