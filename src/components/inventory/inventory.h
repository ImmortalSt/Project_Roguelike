#include "../items/items.h"
#include "../Player/Player.h"
#include "../shop/shop.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Inventory {
	private:

	std::vector<Item> m_inventory;
	int m_coins;

	public:
		Inventory(std::vector<Item> inventory, int coins) : m_inventory(inventory), m_coins(coins) {}

	int getCoins(int coins) {
			return m_coins;
	}

	void addCoins(int coins) {
		coins += m_coins;
	}

	bool removeCoins(int coins) {
		if (coins > m_coins) {
			return false;
		}
		else {
			m_coins -= coins;
			return true;
		}
	}

	bool addItem(Item item, Player player) {
		m_inventory.push_back(item);
		if (item.getName() == "DamageUp") {
			player.addDamage(10);
			return true;
		}
		if (item.getName() == "ArmorUp") {
			player.addArmor(10);
			return true;
		}
		if (item.getName() == "HealthUp") {
			player.addHP(30);
			return true;
		}
		else {
			return false;
		}
	}
	bool removeItem(Item item) {

		std::string target = item.getName();

		std::vector<Item>::iterator it = find(m_inventory.begin(), m_inventory.end(), target);

		if (it == m_inventory.end())
			return false;
		else
			//int idx = std::distance(_inventory.begin(), it);
			m_inventory.erase(it);
			return true;
	}

	int getCount(Item item) {
		std::string target = item.getName();

		int count = std::count(m_inventory.begin(), m_inventory.end(), target);

		return count;
	}


};