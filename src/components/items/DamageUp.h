#include "items.h"

class DamageUp : public Item {
protected:
    int m_damage;

public:
    DamageUp(std::string name, int damage) : Item(name, ItemsName::damageUp), m_damage(damage) {}

    virtual ~DamageUp() {}

    virtual int getParam() override {
        return m_damage;
    }

};