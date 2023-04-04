#pragma once
#include "../Screen/Assets/Assets.h"

class Enemy {
protected:
    int m_hp;
    int m_damage;
    int m_armor;

    int x;
    int y;

public:
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
    }

   /////////////////////////////// int MoveToPoint(int x, int y) {
   ///////////////////////////////
   /////////////////////////////// }


    virtual int getHp() const {
        return m_hp;
    }

    virtual int getDamage() const {
        return m_damage;
    }

    virtual int getArmor() const {
        return m_armor;
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
