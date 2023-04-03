class Enemy {
protected:
    int m_hp;
    int m_damage;
    int m_armor;

    int x;
    int y;

public:

    Enemy(int hp, int damage, int armor)
        : m_hp(hp), m_damage(damage), m_armor(armor) {}

    Enemy() {

    }
    Enemy(int health, int attack, int defense, int _x, int _y)
        : m_health(health), m_attack(attack), m_defense(defense) {
        x = _x;
        y = _y;
    }


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

    void SetX(int _x) {
        x = _x;
    }

    void SetY(int _y) {
        y = _y;
    }

    void SetXY(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int GetX() {
        return x;
    }

    int GetY() {
        return y;
    }
};
