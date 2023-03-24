#pragma once
#include "../items/items.h"
#include "../Player/Player.h"
#include <iostream>
#include <map>
#include <string>

class Store {
public:
    Store() : damageBoosts(5), healthBoosts(5), armorBoosts(5), healthPotions(10) {}

    void showItems() const {
        std::cout << "Available items:" << std::endl;
        std::cout << "- Damage boost x1 (ID: 1, price: 100, remaining: " << damageBoosts << ")" << std::endl;
        std::cout << "- Health boost x1 (ID: 2, price: 50, remaining: " << healthBoosts << ")" << std::endl;
        std::cout << "- Armor boost x1 (ID: 3, price: 75, remaining: " << armorBoosts << ")" << std::endl;
        std::cout << "- Health potion x1 (ID: 4, price: 25, remaining: " << healthPotions << ")" << std::endl;
    }

    bool buyItem(int id, Player& player, int& playerMoney) {
        switch (id) {
        case 1:
            if (damageBoosts > 0) {
                player.addDamage(10);
                playerMoney -= 100;
                damageBoosts--;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts > 0) {
                player.addHP(50);
                playerMoney -= 50;
                healthBoosts--;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts > 0) {
                player.addArmor(10);
                playerMoney -= 75;
                armorBoosts--;
                return true;
            }
            return false;

        case 4:
            if (healthPotions > 0) {
                player.addHP(25);
                playerMoney -= 25;
                healthPotions--;
                return true;
            }
            return false;

        default:
            return false;  // Товар не найден
        }
    }

    bool sellItem(int id, Player& player, int& playerMoney) {
        switch (id) {
        case 1:
            if (damageBoosts < 5) {
                player.addDamage(-10);
                playerMoney += 50;  // Возвращаем половину стоимости товара
                damageBoosts++;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts < 5) {
                player.addHP(-25);
                playerMoney += 25;  // Возвращаем половину стоимости товара
                healthBoosts++;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts < 5) {
                player.addArmor(-5);
                playerMoney += 35;  // Возвращаем половину стоимости товара
                armorBoosts++;
                return true;
            }
            return false;

        case 4:
            return false;  // Зелья нельзя продавать

        default:
            return false;  // Товар не найден
        }
    }

private:
    int damageBoosts;
    int healthBoosts;
    int armorBoosts;
    int healthPotions;

};
