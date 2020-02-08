#include "component.h"

class block
{
public:
    block();

private:
    std::list<component *> block_component_list;
};