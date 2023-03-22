#include "enemies.h"

class Weak_Zombie : public Enemy {
public:
    Zombie() : Enemy(10, 3, 5) {}

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

class Common_Zombie : public Enemy {
public:
    Zombie() : Enemy(10, 3, 5) {}

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

class Evovled_Zombie : public Enemy {
public:
    Zombie() : Enemy(10, 3, 5) {}

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
            std::cout << "Зомби уклонился от атаки!" << std::endl;
        }
        Enemy::takeDamage(damage);
    }

    // Дополнительные методы и свойства, уникальные для зомби
};