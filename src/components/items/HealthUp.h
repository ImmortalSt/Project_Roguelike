#include "items.h"

class HealthUp : public Item {
protected:
    int m_healAmount;

public:
    HealthUp(std::string name, int id, int money, int healAmount) : Item(name, id, money), m_healAmount(healAmount) {}

    virtual ~HealthUp() {}

    int getHealAmount() const {
        return m_healAmount;
    }

};