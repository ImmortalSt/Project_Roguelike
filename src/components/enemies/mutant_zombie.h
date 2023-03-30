#include "enemies.h"

class MutantZombie : public Enemy {   // Мутировавший зомби, урон атака защита умножены на int
private:
    int m_healthMultiplier;
    int m_attackMultiplier;
    int m_defenseMultiplier;
public:
    MutantZombie(int health, int attack, int defense, int healthMultiplier, int attackMultiplier, int defenseMultiplier)
        : Enemy(health, attack, defense), m_healthMultiplier(healthMultiplier), m_attackMultiplier(attackMultiplier), m_defenseMultiplier(defenseMultiplier) {}

    virtual ~MutantZombie() {}

    virtual void update() {
        // Для будущего использования
    }

    virtual void render() {
        // Для будущего использования
    }

    virtual int getHealth() const {
        return m_health * m_healthMultiplier;
    }

    virtual int getAttack() const {
        return m_attack * m_attackMultiplier;
    }

    virtual int getDefense() const {
        return m_defense * m_defenseMultiplier;
    }
};
