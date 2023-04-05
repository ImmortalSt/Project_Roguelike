#include "enemies.h"

class Weak_Zombie : public Enemy {
public:
    Weak_Zombie(int x, int y) : Enemy(10, 3, 5, x, y) {}

    std::vector<std::wstring> GetSprite() override {
        return AssetsInstance->GetAsset(Assets::AssetsName::Zombie_Waek);
    }

    int GetFOV() override { return 3; }

    std::string GetName() {
        return "Strongest fighter in Redan";
    }
 
    virtual void takeDamage(int damage) override {
        // Вызываем метод базового класса для вычисления получаемого урона
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};
