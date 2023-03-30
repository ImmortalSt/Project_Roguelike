#include "enemies.h"

class Common_Zombie : public Enemy {
public:
    Common_Zombie() : Enemy(20, 6, 7) {}

    virtual void update() override {
        // Дополнительный код обновления для зомби
    }

    virtual void render() override {
        // Дополнительный код рендеринга для зомби
    }

    virtual void takeDamage(int damage) override {
        // Вызываем метод базового класса для вычисления получаемого урона
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};
