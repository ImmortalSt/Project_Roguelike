#include "items.h"

class HealthUp : public Item {
protected:
    int m_healAmount;

public:
    HealthUp(std::string name, int healAmount) : Item(name, ItemsName::hpUp), m_healAmount(healAmount) {}

    virtual ~HealthUp() {}

    int getHealAmount() const {
        return m_healAmount;
    }

};