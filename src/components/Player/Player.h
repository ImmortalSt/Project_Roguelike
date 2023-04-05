#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include "../items/items.h"
#include "../inventory/inventory.h"


class Player {
private:
	std::string m_name;
	int m_max_hp;
	int m_cur_hp;
	int m_armor;
	int m_x;
	int m_y;
	int m_damage;
	Inventory m_inventory;
public:

	Player(std::string name, int max_hp, int cur_hp, int damage, int armor, Inventory inventory, int x, int y)
		: m_name(name), m_max_hp(max_hp), m_cur_hp(cur_hp), m_damage(damage), m_armor(armor), m_inventory(inventory), m_x(x), m_y(y) {}

	std::string getName() const {
		return m_name;
	}


	Assets* AssetsInstance = Assets::GetInstance();

	std::vector<std::wstring> GetAssetsName(int num) {
		if (num == 1) {
			return AssetsInstance->GetAsset(Assets::AssetsName::Player1);
		}
		else if (num == 2) {
			return AssetsInstance->GetAsset(Assets::AssetsName::Player2);
		}
		else if (num == 3) {
			return AssetsInstance->GetAsset(Assets::AssetsName::Player3);
		}
		else {
			return AssetsInstance->GetAsset(Assets::AssetsName::Player1);
		}
	}

	int getMaxHP() {
		return m_max_hp;
	}

	int getCurHP() {
		return m_cur_hp ;
	}

	void Heal() {
		m_cur_hp = m_max_hp;
	}

	void addHP(int hp) {
		m_max_hp += hp;
		m_cur_hp = m_max_hp;
	}

	int takeDamage(int damage) {
		m_cur_hp -= damage;
		if (m_cur_hp <= 0) {
			return 1;
		}
		return 0;
	}

	int getDamage() {
		return m_damage;
	}

	void addDamage(int damage) {
		m_damage += damage;
	}

	int getArmor() {
		return m_armor;
	}

	void addArmor(int armor) {
		m_armor += armor;
	}

	void addItem(Item* item) {
		m_inventory.addItem(item);
		if (item->getId() == ItemsName::armorUp) addArmor(item->getParam());
		if (item->getId() == ItemsName::damageUp) addDamage(item->getParam());
		if (item->getId() == ItemsName::hpUp) addHP(item->getParam());

	}

	bool removeItem(Item* item) {
		if (m_inventory.removeItem(item) == 0)
			return false;
		if (item->getId() == ItemsName::armorUp) addArmor(-(item->getParam()));
		if (item->getId() == ItemsName::damageUp) addDamage(-(item->getParam()));
		if (item->getId() == ItemsName::hpUp) addHP(-(item->getParam()));
		return true;
	}

	int getCount(ItemsName item) {
		int count = m_inventory.getCount(item);

		return count;
	}

	bool removeCoins(int coins) {
		if (m_inventory.removeCoinsI(coins) == false)
			throw exception("Not enough money");
		return true;
	}

	void addCoins(int coins) {
		m_inventory.addCoinsI(coins);
	}

	int getCoins() {
		return m_inventory.getCoinsI();
	}


	void GetSprite() {
		throw std::exception("It is not realized yet");
	}

	void SetX(int x) {
		m_x = x;
	}

	int GetX() {
		return m_x;
	}

	void SetY(int y) {
		m_y = y;
	}

	int GetY() {
		return m_y;
	}

	void SetXY(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

#endif