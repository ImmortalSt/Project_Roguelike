class Item {
protected:
    virtual std::string m_name;
    virtual int m_id;

public:
    Item(std::string name, int id) : m_name(name), m_id(id) {}

    virtual ~Item() {}

    std::string getName() const {
        return m_name;
    }

    int getId() const {
        return m_id;
    }
};

class Weapon : public Item {
protected:
    int m_damage;

public:
    Weapon(std::string name, int id, int damage) : Item(name, id), m_damage(damage) {}

    virtual ~Weapon() {}

    int getDamage() const {
        return m_damage;
    }

};

class MedKit : public Item {
protected:
    int m_healAmount;

public:
    MedKit(std::string name, int id, int healAmount) : Item(name, id), m_healAmount(healAmount) {}

    virtual ~MedKit() {}

    int getHealAmount() const {
        return m_healAmount;
    }

};

class Armor : public Item {
protected:
    int m_armorAmount;

public:
    Armor(std::string name, int id, int armorAmount) : Item(name, id), m_armorAmount(armorAmount) {}

    virtual ~Armor() {}

    int getArmorAmount() const {
        return m_armorAmount;
    }

};
