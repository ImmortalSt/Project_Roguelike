#include "items.h"

class ArmorUp : public Item {
protected:
    int m_armorAmount;

public:
    ArmorUp(std::string name, int armorAmount) : Item(name, ItemsName::armorUp), m_armorAmount(armorAmount) {}

    virtual ~ArmorUp() {}

    virtual int getParam() override {
        return m_armorAmount;
    }

};
