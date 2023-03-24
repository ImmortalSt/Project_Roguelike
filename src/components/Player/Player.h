#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>


class Player {
private:
	std::string name;
	int hp;
	int armor;
	int coins;
	int damage;

public:

	Player(std::string _name, int _hp, int _damage, int _armor, int _coins) {
		name = _name;
		hp = _hp;
		armor = _armor;
		coins = _coins;
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
	
	int getCoins(int _coins) {
		return coins;
	}
	
	int addCoins(int _coins) {
		coins += _coins;
	}

	int removeCoins(int _coins) {
		if (coins < _coins) {
			std::cout << "Not enough money" << std::endl;
		}
		else {
			coins -= _coins;
		}
	}

	int getDamage(int _damage) {
		damage = _damage;
	}
	int addDamage(int _damage) {
		damage += _damage;
	}

	void GetSprite() {
		throw std::Exception("It is not realized yet");
	}

	
};

#endif
