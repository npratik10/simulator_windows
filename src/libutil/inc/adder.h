#include "component.h"

class adder : public component
{
public:
    adder();
    virtual ~adder();
    virtual void component_function() override;
}
;