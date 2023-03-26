#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "../inventory/inventory.h"

class Player {
private:
	std::string name;
	int hp;
	int armor;
	int damage;
	Inventory inventory;

public:

	Player(std::string _name, int _hp, int _damage, int _armor) {
		name = _name;
		hp = _hp;
		armor = _armor;
		damage = _damage;
	}

	Player(std::string _name) {
		name = _name;
	}

	int GetHP() {
		return hp;
	}

	void TakeDamage(int damage) {
		hp -= damage;
	}

	void addHP(int _hp) {
		hp += _hp;
	}
	

	int GetArmor() {
		return armor;
	}

	void setArmor(int _armor) {
		armor = _armor;
	}

	int addArmor(int _armor) {
		armor += _armor;
	}

	std::string GetName() {
		return name;
	}
	
	int getDamage(int _damage) {
		damage = _damage;
	}
	int addDamage(int _damage) {
		damage += _damage;
	}

	void GetSprite() {
		throw std::exception("It is not realized yet");
	}

	
};

#endif
