#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "../items/items.h"

using namespace std;

class Inventory {
private:

	std::vector<Item*> m_inventory;
	int m_coins;

public:
	Inventory(std::vector<Item*> inventory, int coins) : m_inventory(inventory), m_coins(coins) {}

	int getCoinsI() {
		return m_coins;
	}

	void addCoinsI(int coins) {
		coins += m_coins;
	}

	bool removeCoinsI(int coins) {
		if (coins > m_coins) {
			return false;
		}
		else {
			m_coins -= coins;
			return true;
		}
	}

	bool addItem(Item* item) {
		if (item == 0) throw exception("Null item");

		m_inventory.push_back(item);
	}
	bool removeItem(ItemsName itemName) {

		for (int i = 0; i < m_inventory.size(); i++) {
			if (m_inventory[i]->getId() == itemName) {
				m_inventory.erase(m_inventory.begin() + i);
				return true;
			}
		}
		return false;

	}

	int getCount(ItemsName itemName) {
		int count = 0;

		for (int i = 0; i < m_inventory.size(); i++) {
			if (m_inventory[i]->getId() == itemName) {
				count++;
			}
		}

		return count;
	}


};