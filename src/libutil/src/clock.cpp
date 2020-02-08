#include "clock.h"

clock::clock(std::string name)
{
    clkName = name;
    clkCnt = 0;
    riseEdge = true;
}

bool clock::trigger_clk()
{
    if (riseEdge)
    {
        riseEdge = false;
        clkCnt++;
        return true;
    }
    else
    {
        riseEdge = true;
        return false;
    }
}

std::string clock::get_clk_name()
{
    return clkName;
}

uint64_t clock::get_clock_cycle()
{
    return clkCnt;
}

bool clock::get_rise_edge()
{
    return riseEdge;
}
