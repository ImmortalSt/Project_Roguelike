#pragma once
#include "items.h"

class Medkit : public Item {
protected:

public:
    Medkit(std::string name) : Item(name, ItemsName::medKit) {}

    virtual ~Medkit() {}

};