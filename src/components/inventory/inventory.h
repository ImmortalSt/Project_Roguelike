#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "../items/items.h"

using namespace std;

class Inventory {
	private:

	std::vector<Item> m_inventory;
	int m_coins;

	public:
		Inventory(std::vector<Item> inventory, int coins) : m_inventory(inventory), m_coins(coins) {}

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

	bool addItemI(Item item) {
		m_inventory.push_back(item);
		return true;
	}

	bool removeItemI(Item item) {
		return false;;/////////////////////////////////////////;/////////////////////////////////////////
		std::string target = item.getName();
	
		std::vector<Item>::iterator it;// = find(m_inventory.begin(), m_inventory.end(), target);
	
		if (it == m_inventory.end())
			return false;
		else
			m_inventory.erase(it);
			return true;
	}

	int getCountI(Item item) {
		return false;/////////////////////////////////////////;/////////////////////////////////////////


		int count = 0; // std::count(m_inventory.begin(), m_inventory.end(), item);
	
		return count;
	}


};