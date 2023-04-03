﻿class Enemy {
protected:
    int m_hp;
    int m_damage;
    int m_armor;

public:
    Enemy(int hp, int damage, int armor)
        : m_hp(hp), m_damage(damage), m_armor(armor) {}

    virtual ~Enemy() {}

    virtual void update() {}

    virtual void render() {}

    virtual void takeDamage(int damage) {
        // Вычисляем получаемый урон, учитывая защиту врага
        int actualDamage = damage - m_armor;
        if (actualDamage > 0) {
            m_hp -= actualDamage;
        }
    }

    virtual int getHp() const {
        return m_hp;
    }

    virtual int getDamage() const {
        return m_damage;
    }

    virtual int getArmor() const {
        return m_armor;
    }
};
