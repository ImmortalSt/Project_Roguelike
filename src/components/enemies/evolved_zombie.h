#include <string>
#include <ostream>
#include <iostream>
#include "enemies.h"

class Evolved_Zombie : public Enemy {
public:
    Evolved_Zombie() : Enemy(30, 10, 3) {}

    virtual void update() override {
        // Дополнительный код обновления для зомби
    }

    virtual void render() override {
        // Дополнительный код рендеринга для зомби
    }

    virtual void takeDamage(int damage) override {
        // При получении урона, зомби может иметь шанс не получить полный урон благодаря своей мутации
        if (rand() % 2 == 0) {
            damage /= 2; // Уменьшаем полученный урон на половину
        }
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};