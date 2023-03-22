class Enemy {
private:
    int m_health;
    int m_attack;
    int m_defense;

public:
    Enemy(int health, int attack, int defense)
        : m_health(health), m_attack(attack), m_defense(defense) {}

    virtual ~Enemy() {}

    virtual void update() {}

    virtual void render() {}

    virtual void takeDamage(int damage) {
        // Вычисляем получаемый урон, учитывая защиту врага
        int actualDamage = damage - m_defense;
        if (actualDamage > 0) {
            m_health -= actualDamage;
        }
    }

    virtual int getHealth() const {
        return m_health;
    }

    virtual int getAttack() const {
        return m_attack;
    }

    virtual int getDefense() const {
        return m_defense;
    }
};


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