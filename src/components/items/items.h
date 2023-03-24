class Item {
private:
     std::string m_name;
     int m_id;
     int m_money;

public:
    Item(std::string name, int id, int money) : m_name(name), m_id(id), m_money(money) {}

    virtual ~Item() {}

    std::string getName() const {
        return m_name;
    }

    int getId() const {
        return m_id;
    }
};

class DamageUp : public Item {
protected:
    int m_damage;

public:
    DamageUp(std::string name, int id,int money, int damage) : Item(name, id, money), m_damage(damage) {}

    virtual ~DamageUp() {}

    int getDamage() const {
        return m_damage;
    }

};

class HealthUp : public Item {
protected:
    int m_healAmount;

public:
    HealthUp(std::string name, int id, int money, int healAmount) : Item(name, id, money), m_healAmount(healAmount) {}

    virtual ~HealthUp() {}

    int getHealAmount() const {
        return m_healAmount;
    }

};

class ArmorUp : public Item {
protected:
    int m_armorAmount;

public:
    ArmorUp(std::string name, int id, int money, int armorAmount) : Item(name, id, money), m_armorAmount(armorAmount) {}

    virtual ~ArmorUp() {}

    int getArmorAmount() const {
        return m_armorAmount;
    }

};
