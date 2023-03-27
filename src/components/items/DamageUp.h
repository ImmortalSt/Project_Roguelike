#include "items.h"

class DamageUp : public Item {
protected:
    int m_damage;

public:
    DamageUp(std::string name, int id, int damage) : Item(name, id), m_damage(damage) {}

    virtual ~DamageUp() {}

    int getDamageAmount() const {
        return m_damage;
    }

};