#pragma once
#include <string>

class Item {
private:
     std::string m_name;
     int m_id;

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
