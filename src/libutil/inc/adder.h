#include "component.h"

class adder : public component
{
public:
    adder();
    virtual ~adder();
    virtual void process_component_function() override;
}
;