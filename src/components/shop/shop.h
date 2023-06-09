﻿#pragma once
#define FMT_HEADER_ONLY
#include <iostream>
#include <map>
#include <string>
#include "../items/items.h"
#include "../Player/Player.h"
#include "include/fmt/core.h"
#include "include/fmt/format.h"
#include "include/fmt/xchar.h"


class Store {
public:
    Store() {}
    Store(int damageBoosts, int healthBoosts, int armorBoosts, int healthPotions)
        : damageBoosts(damageBoosts), healthBoosts(healthBoosts), armorBoosts(armorBoosts), healthPotions(healthPotions) {}

    virtual ~Store() {};

    void tokenize(std::wstring const& str, const char delim,
        std::vector<std::wstring>& out)
    {
        size_t start;
        size_t end = 0;

        while ((start = str.find_first_not_of(delim, end)) != std::wstring::npos)
        {
            end = str.find(delim, start);
            out.push_back(str.substr(start, end - start));
        }
    }


    std::vector<wstring> countItems() {
        int countDamage = damageBoosts;
        int countHealth = healthBoosts;
        int countArmor = armorBoosts;
        int countMeds = healthPotions;
        std::wstring show = fmt::format(L"Items left:*DamageUps = {}*HealthUps = {}*ArmorUps = {}*Medkits = {}", countDamage, countHealth, countArmor, countMeds);
        const char delim = '*';
        std::vector<std::wstring> out;
        tokenize(show, delim, out);

        return out;
    }


    bool buyItem(Item* item, Player* player) {
        int id = item->getId();
        switch (id) {
        case 1:
            if (damageBoosts > 0) {
                if (player->removeCoins(100) == false) {
                    return false;
                }
                player->addItem(item);
                damageBoosts--;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts > 0) {
                if (player->removeCoins(100) == false) {
                    return false;
                }
                player->addItem(item);
                healthBoosts--;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts > 0) {
                if (player->removeCoins(100) == false) {
                    return false;
                }
                player->addItem(item);
                armorBoosts--;
                return true;
            }
            return false;

        case 4:
            if (healthPotions > 0) {
                if (player->removeCoins(50) == false) {
                    return false;
                }
                player->addItem(item);
                healthPotions--;
                return true;
            }
            return false;

        default:
            return false; 
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
            if (healthPotions < 5) {
                player->removeItem(item);
                player->addCoins(25);
                healthPotions++;
                return true;
            }
            return false;

        default:
            return false; 
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
    int x;
    int y;
    int damageBoosts;
    int healthBoosts;
    int armorBoosts;
    int healthPotions;
};
