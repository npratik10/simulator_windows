#include "component_block.h"

class subtract : public component_block<uint32_t>
{
public:
    subtract(std::string name, clock *clk);
    virtual ~subtract();
    virtual void process_clock() override;
    uint32_t result = 0;
}
;