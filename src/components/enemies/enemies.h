#pragma once
#include "../Screen/Assets/Assets.h"
#include <cmath>

class Enemy {
protected:
    int m_hp;
    int m_damage;
    int m_armor;

    int x;
    int y;

public:
    Assets* AssetsInstance = Assets::GetInstance();

    Enemy(int health, int attack, int defense, int _x, int _y) {
        m_damage = attack;
        m_armor = defense;
        m_hp = health;
        x = _x;
        y = _y;
    }
    Enemy(int health, int attack, int defense) {
        m_damage = attack;
        m_armor = defense;
        m_hp = health;
    }


    virtual std::vector<std::wstring> GetSprite() = 0;

    virtual void takeDamage(int damage) {
        // Вычисляем получаемый урон, учитывая защиту врага
        int actualDamage = damage - m_armor;
        if (actualDamage > 0) {
            m_hp -= actualDamage;
        }
        if (m_hp < 0) m_hp = 0;
    }

    virtual int GetFOV() = 0;

    virtual std::string GetName() = 0;

    virtual int getHp() const {
        return m_hp;
    }

    virtual int getDamage() const {
        return m_damage;
    }

    virtual int getArmor() const {
        return m_armor;
    }


    char StepToGo(int _x, int _y) {
        if (abs(x - _x) > abs(y - _y)) {
            if (x - _x < 0) {
                return 'r';
            }
            else if (x - _x > 0) {
                return 'l';
            }
        }
        else if (abs(x - _x) < abs(y - _y)) {
            if (y - _y < 0) {
                return 'd';
            }
            else if (y - _y > 0) {
                return 'u';
            }
        }
        else {
            if (x - _x < 0) {
                return 'r';
            }
            else if (x - _x > 0) {
                return 'l';
            }
        }
    }


    void SetX(int _x) {
        x = _x;
    }

    void SetY(int _y) {
        y = _y;
    }

    void SetXY(int _x, int _y) {
        x = _x;
        y = _y;
    }

    int GetX() {
        return x;
    }

    int GetY() {
        return y;
    }
};
