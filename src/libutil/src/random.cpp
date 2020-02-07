#include "random.h"

#include <random>
#include <array>

class PIMPLRandom
{
   std::mt19937 eng;
   std::uniform_int_distribution<> ndis{};
   std::uniform_real_distribution<> rdis{ 0,1 };

   friend class Random;
};

Random::Random(std::optional<int> const seed) :pimpl(new PIMPLRandom{})
{
   if (seed.has_value())
   {
      pimpl->eng.seed(seed.value());
   }
   else
   {
      std::random_device rd;

      auto seed_data = std::array<int, std::mt19937::state_size> {};
      std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));

      std::seed_seq seq(std::begin(seed_data), std::end(seed_data));

      pimpl->eng = std::mt19937{ seq };
   }
}

Random::~Random()
{
   delete pimpl;
}

int Random::Next()
{
   return pimpl->ndis(pimpl->eng);
}

int Random::Next(int const max)
{
   std::uniform_int_distribution<> dis{0, max};
   return dis(pimpl->eng);
}

int Random::Next(int const min, int const max)
{
   std::uniform_int_distribution<> dis{ min, max };
   return dis(pimpl->eng);
}

double Random::NextDouble()
{
   return pimpl->rdis(pimpl->eng);
}