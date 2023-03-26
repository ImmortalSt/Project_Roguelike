#include <string>

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
