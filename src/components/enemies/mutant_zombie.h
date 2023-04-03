#include "enemies.h"

class MutantZombie : public Enemy {   // Мутировавший зомби, урон атака защита умножены на int
private:
    int m_hpMultiplier;
    int m_damageMultiplier;
    int m_armorMultiplier;

public:
    MutantZombie(int hp, int damage, int armor, int hpMultiplier, int damageMultiplier, int armorMultiplier, int )
        : Enemy(hp, damage, armor), m_hpMultiplier(hpMultiplier), m_damageMultiplier(damageMultiplier), m_armorMultiplier(armorMultiplier) {}

    virtual ~MutantZombie() {}

    virtual void update() {
        // Для будущего использования
    }

    virtual void render() {
        // Для будущего использования
    }

    virtual int getHp() const {
        return m_hp * m_hpMultiplier;
    }

    virtual int getDamage() const {
        return m_damage * m_damageMultiplier;
    }

    virtual int getArmor() const {
        return m_armor * m_armorMultiplier;
    }
};
