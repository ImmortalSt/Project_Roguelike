#include "../items/items.h"
#include "../Player/Player.h"
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

	void AddItem(Item item) {
		_inventory.push_back(item);
		if (item.getName == "damageUp")
		}
	}
	void removeItem(Item item) {

		std::string target = item.getName();

		std::vector<Item>::iterator it = find( _inventory.begin(), _inventory.end(), target);

		if (it == _inventory.end())
			throw::exception("Item was not found");
		else
			cout << "item removed" << endl;
	}

	int getCount(Item item) {
		std::string target = item.getName();

		int count = std::count(_inventory.begin(), _inventory.end(), target);

		return count;
	}


};