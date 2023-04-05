#pragma once
#include <iostream>
#include <map>
#include <string>
#include "../items/items.h"
#include "../Player/Player.h"


class Store {
public:
    Store() {}
    Store(int damageBoosts, int healthBoosts, int armorBoosts, int healthPotions)
        : damageBoosts(damageBoosts), healthBoosts(healthBoosts), armorBoosts(armorBoosts), healthPotions(healthPotions) {}

    virtual ~Store() {};
    //void showItems() const {
    //    std::cout << "Available items:" << std::endl;
    //    std::cout << "- Damage boost x1 (ID: 1, price: 100, remaining: " << damageBoosts << ")" << std::endl;
    //    std::cout << "- Health boost x1 (ID: 2, price: 50, remaining: " << healthBoosts << ")" << std::endl;
    //    std::cout << "- Armor boost x1 (ID: 3, price: 75, remaining: " << armorBoosts << ")" << std::endl;
    //    std::cout << "- Health potion x1 (ID: 4, price: 25, remaining: " << healthPotions << ")" << std::endl;
    //}


    bool buyItem(Item* item, Player* player) {
        int id = item->getId();
        switch (id) {
        case 1:
            if (damageBoosts > 0) {
                player->removeCoins(100);
                player->addItem(item);
                damageBoosts--;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts > 0) {
                player->removeCoins(100);
                player->addItem(item);
                healthBoosts--;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts > 0) {
                player->removeCoins(100);
                player->addItem(item);
                armorBoosts--;
                return true;
            }
            return false;

        case 4:
            if (healthPotions > 0) {
                player->removeCoins(50);
                player->Heal();
                healthPotions--;
                return true;
            }
            return false;

        default:
            return false;  // Товар не найден
        }
    }

    bool sellItem(Item* item, Player* player) {
        int id = item->getId();
        switch (id) {
        case 1:
            if (damageBoosts < 5) {
                player->removeItem(item);
                player->addCoins(50);
                damageBoosts++;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts < 5) {
                player->removeItem(item);
                player->addCoins(50);
                healthBoosts++;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts < 5) {
                player->removeItem(item);
                player->addCoins(50);
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

    void SetX(int _x) {
        x = _x;
    }

    int GetX() {
        return x;
    }

    void SetY(int _y) {
        y = _y;
    }

    int GetY() {
        return y;
    }

    void SetXY(int _x, int _y) {
        x = _x;
        y = _y;
    }

private:
    int damageBoosts;
    int healthBoosts;
    int armorBoosts;
    int healthPotions;
    int x;
    int y;
};
