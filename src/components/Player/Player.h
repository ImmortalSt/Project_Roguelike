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
	int m_hp;
	int m_armor;
	int m_x;
	int m_y;
	int m_damage;
	Inventory m_inventory;
public:

	Player(std::string name, int hp, int damage, int armor, Inventory inventory, int x, int y)
		: m_name(name), m_hp(hp), m_damage(damage), m_armor(armor), m_inventory(inventory), m_x(x), m_y(y) {}

	std::string getName() const {
		return m_name;
	}

	int getHP() {
		return m_hp;
	}

	void addHP(int hp) {
		m_hp += hp;
	}

	int takeDamage(int damage) {
		m_hp -= damage;
		if (m_hp <= 0) {
			return 1;
		}
		return 0;
	}

	int getDamage(int damage) {
		m_damage = damage;
	}

	int addDamage(int damage) {
		m_damage += damage;
	}

	int getArmor() {
		return m_armor;
	}

	int addArmor(int armor) {
		m_armor += armor;
	}

	bool addItem(Item* item) {
		m_inventory.addItem(item);
	}

	bool removeItem(ItemsName item) {
		m_inventory.removeItem(item);		
	}

	int getCount(ItemsName item) {
		int count = m_inventory.getCount(item);

		return count;
	}

	void removeCoins(int coins) {
		m_inventory.removeCoinsI(coins);
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