#include "enemies.h"

class Common_Zombie : public Enemy {
public:
    Common_Zombie(int x, int y) : Enemy(20, 6, 7, x, y) {}

    std::vector<std::wstring> GetSprite() override {
        return AssetsInstance->GetAsset(Assets::AssetsName::Zombie_Common);
    }

    int GetFOV() override { return 3; }

    std::wstring GetName() override {
        return L"office worker";
    }

    virtual void takeDamage(int damage) override {
        // Вызываем метод базового класса для вычисления получаемого урона
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};
