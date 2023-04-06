#include "enemies.h"

class MutantZombie : public Enemy {   // Мутировавший зомби, урон атака защита умножены на int
private:
    int m_hpMultiplier;
    int m_damageMultiplier;
    int m_armorMultiplier;

public:
    MutantZombie(int x, int y) : Enemy(30, 30, 10, x, y), m_hpMultiplier(1), m_damageMultiplier(1), m_armorMultiplier(1) {}

    std::vector<std::wstring> GetSprite() override {
        return AssetsInstance->GetAsset(Assets::AssetsName::ZombieMutant);
    }

    int GetFOV() override { return 9; }

    std::wstring GetName() {
        return L"Nicado Avocado";
    }

    virtual int getHp() const {
        return m_hp * m_hpMultiplier;
    }

    virtual int getDamage() const {
        return m_damage * m_damageMultiplier;
    }

    virtual int getArmor() const {
        return m_armor * m_armorMultiplier;
    }
};
