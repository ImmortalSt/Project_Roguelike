#include <string>


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

class Weak_Zombie : public Enemy {
public:
    Zombie() : Enemy(10, 3, 5) {}

    virtual void update() override {
        // Дополнительный код обновления для зомби
    }

    virtual void render() override {
        // Дополнительный код рендеринга для зомби
    }

    virtual void takeDamage(int damage) override {
        // Вызываем метод базового класса для вычисления получаемого урона
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};

class Common_Zombie : public Enemy {
public:
    Zombie() : Enemy(20, 6, 7) {}

    virtual void update() override {
        // Дополнительный код обновления для зомби
    }

    virtual void render() override {
        // Дополнительный код рендеринга для зомби
    }

    virtual void takeDamage(int damage) override {
        // Вызываем метод базового класса для вычисления получаемого урона
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};

class Evovled_Zombie : public Enemy {
public:
    Zombie() : Enemy(30, 10, 3) {}

    virtual void update() override {
        // Дополнительный код обновления для зомби
    }

    virtual void render() override {
        // Дополнительный код рендеринга для зомби
    }

    virtual void takeDamage(int damage) override {
        // При получении урона, зомби может иметь шанс не получить полный урон благодаря своей мутации
        if (rand() % 2 == 0) {
            damage /= 2; // Уменьшаем полученный урон на половину
            std::cout << "Зомби уклонился от атаки!" << std::endl;
        }
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};