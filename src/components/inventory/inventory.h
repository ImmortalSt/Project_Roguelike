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

	std::vector<Item> _inventory;
	int _coins;

	public:

	int getCoins(int coins) {
			return _coins;
	}

	void addCoins(int coins) {
		coins += _coins;
	}

	bool removeCoins(int coins) {
		if (coins > _coins) {
			return false;
		}
		else {
			_coins -= coins;
			return true;
		}
	}

	bool AddItem(Item item, Player player) {
		_inventory.push_back(item);
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

		std::vector<Item>::iterator it = find(_inventory.begin(), _inventory.end(), target);

		if (it == _inventory.end())
			return false;
		else
			//int idx = std::distance(_inventory.begin(), it);
			_inventory.erase(it);
			return true;
	}

	int getCount(Item item) {
		std::string target = item.getName();

		int count = std::count(_inventory.begin(), _inventory.end(), target);

		return count;
	}


};