#pragma once

#include "libdef.h"
#include <optional>

class PIMPLRandom;

class EXPORT_SYMBOL Random
{
   PIMPLRandom* pimpl;
public:
   explicit Random(std::optional<int> const seed);
   ~Random();
   int Next();
   int Next(int const max);
   int Next(int const min, int const max);
   double NextDouble();
};