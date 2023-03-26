#include "items.h"

class DamageUp : public Item {
protected:
    int m_damage;

public:
    DamageUp(std::string name, int id, int money, int damage) : Item(name, id, money), m_damage(damage) {}

    virtual ~DamageUp() {}

    int getDamage() const {
        return m_damage;
    }

};