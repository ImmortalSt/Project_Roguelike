#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>


class Player {
private:
	std::string name;
	int hp;
	int shield;
	

public:

	Player(std::string _name, int _hp, int _shield) {
		name = _name;
		hp = _hp;
		shield = _shield;
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

	void AddHP(int _hp) {
		hp += _hp;
	}

	int GetShield() {
		re
	}

	void SetShield(int _shield) {
		shield = _shield;
	}

	std::string GetName() {
		return name;
	}

	void GetSprite() {
		throw std::Exception("It is not realized yet");
	}

	
};

#endif
