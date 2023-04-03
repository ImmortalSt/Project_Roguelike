class Enemy {
protected:
    int m_health;
    int m_attack;
    int m_defense;

    int x;
    int y;

public:
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
