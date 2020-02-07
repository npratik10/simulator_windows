#include <iostream>

using namespace std;

class clock
{
private:
    uint64_t 	clkCnt;
    bool      riseEdge;
    std::string    clkName;

public:
    clock(std::string name);
    bool trigger_clk();
    std::string get_clk_name();
    uint64_t get_clock_cycle();
};
