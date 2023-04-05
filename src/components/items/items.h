#pragma once
#include <string>

enum ItemsName {
    damageUp = 1,
    hpUp,
    armorUp,
    medKit
};

class Item {
private:
    std::string m_name;
    int m_id;
    int m_param;

public:
    Item(std::string name, int id) : m_name(name), m_id(id) {}

    virtual ~Item() {}

    std::string getName() const {
        return m_name;
    }

    int getId() const {
        return m_id;
    }
    virtual int getParam() {
        return m_param;
    }
};