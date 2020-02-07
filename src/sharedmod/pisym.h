#pragma once

#include "random.h"

class EXPORT_SYMBOL piMonteCarloSimulation
{
   Random rnd;
public:
   piMonteCarloSimulation();
   double aproxPi();
};