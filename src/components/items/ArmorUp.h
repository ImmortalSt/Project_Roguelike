#include "items.h"

class ArmorUp : public Item {
protected:
    int m_armorAmount;

public:
    ArmorUp(std::string name, int id, int armorAmount) : Item(name, id), m_armorAmount(armorAmount) {}

    virtual ~ArmorUp() {}

    int getArmorAmount() const {
        return m_armorAmount;
    }

};
