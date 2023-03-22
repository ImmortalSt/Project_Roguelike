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

    void print() const {
        std::cout << "Name: " << m_name << "\n";
        std::cout << "ID: " << m_id << "\n";
        std::cout << "Damage: " << m_damage << "\n";
    }
};

