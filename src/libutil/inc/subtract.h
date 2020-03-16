#include "component_block.h"

class subtract : public component_block
{
public:
    subtract(std::string name, clock *clk);
    virtual ~subtract();
    virtual void process_clock() override;
    uint32_t result = 0;
}
;