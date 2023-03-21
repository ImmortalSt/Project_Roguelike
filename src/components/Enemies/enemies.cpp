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
        m_health -= damage;
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

class Zombie : public Enemy {
private:
    int m_toughness;

public:
    Zombie(int health, int attack, int defense, int toughness)
        : Enemy(health, attack, defense), m_toughness(toughness) {}

    virtual ~Zombie() {}

    virtual void update() {
        // Implement zombie-specific behavior here
    }

    virtual void render() {
        // Implement zombie-specific rendering here
    }

    virtual void takeDamage(int damage) {
        if (damage > m_toughness) {
            Enemy::takeDamage(damage - m_toughness);
        }
    }

    virtual int getToughness() const {
        return m_toughness;
    }
};

class MutantZombie : public Enemy {
private:
    int m_healthMultiplier;
    int m_attackMultiplier;
    int m_defenseMultiplier;

public:
    MutantZombie(int health, int attack, int defense, int healthMultiplier, int attackMultiplier, int defenseMultiplier)
        : Enemy(health, attack, defense), m_healthMultiplier(healthMultiplier), m_attackMultiplier(attackMultiplier), m_defenseMultiplier(defenseMultiplier) {}

    virtual ~MutantZombie() {}

    virtual void update() {
        // Implement mutant zombie-specific behavior here
    }

    virtual void render() {
        // Implement mutant zombie-specific rendering here
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

class SpecialZombie : public Enemy {
private:
    int m_specialAbility;

public:
    SpecialZombie(int health, int attack, int defense, int specialAbility)
        : Enemy(health, attack, defense), m_specialAbility(specialAbility) {}

    virtual ~SpecialZombie() {}

    virtual void update() {
        // Implement special zombie-specific behavior here
    }

    virtual void render() {
        // Implement special zombie-specific rendering here
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

    virtual int getSpecialAbility() const {
        return m_specialAbility;
    }
};