#ifndef MAP_H
#define MAP_H
#include "../Field/Field.h"
#include "../utills/utils.h"
#include "../Player/Player.h"
#include "../enemies/enemies.h"
class Map {
private:
	Field* field;
	Field field_copy;
	Player* player_;
	std::vector<Enemy>* enemies;
public:
	Map(Field *_field, Player *_player, std::vector<Enemy> *_enemies) {
		field = _field;
		player_ = _player;
		field_copy = *_field;
		enemies = _enemies;
		field->SetCell(player_->GetY(), player_->GetX(), player);
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
	}
	void MovePlayer(char side) {

		if (side == 'l') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() - 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != empt) && (field->GetCellState(player_->GetY(), player_->GetX() - 1) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() - 1);
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(player_->GetY(), player_->GetX() + 1) != wall) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != empt) && (field->GetCellState(player_->GetY(), player_->GetX() + 1) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetX(player_->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(player_->GetY() - 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != empt) && (field->GetCellState(player_->GetY() - 1, player_->GetX()) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() - 1);
			}
		}
		else if (side == 'd') {
			
			if ((field->GetCellState(player_->GetY() + 1, player_->GetX()) != wall) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != empt) && (field->GetCellState(player_->GetY() + 1, player_->GetX()) != enemy)) {
				field->SetCell(player_->GetY(), player_->GetX(), field_copy.GetCellState(player_->GetY(), player_->GetX()));
				player_->SetY(player_->GetY() + 1);
			}
		}
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);
	}

	void MoveEnemy(int id, char side) {

		Enemy* e = &enemies->at(id);

		if (side == 'l') {
			if ((field->GetCellState(e->GetY(), e->GetX() - 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() - 1) != empt) && (field->GetCellState(e->GetY(), e->GetX() - 1) != player)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() - 1);
				std::cout << e->GetX();
			}
		}
		else if (side == 'r') {
			if ((field->GetCellState(e->GetY(), e->GetX() + 1) != wall) && (field->GetCellState(e->GetY(), e->GetX() + 1) != empt) && (field->GetCellState(e->GetY(), e->GetX() + 1) != player)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetX(e->GetX() + 1);
			}
		}
		else if (side == 'u') {
			if ((field->GetCellState(e->GetY() - 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() - 1, e->GetX()) != empt) && (field->GetCellState(e->GetY() - 1, e->GetX()) != player)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() - 1);
			}
		}
		else if (side == 'd') {
			if ((field->GetCellState(e->GetY() + 1, e->GetX()) != wall) && (field->GetCellState(e->GetY() + 1, e->GetX()) != empt) && (field->GetCellState(e->GetY() + 1, e->GetX()) != player)) {
				field->SetCell(e->GetY(), e->GetX(), field_copy.GetCellState(e->GetY(), e->GetX()));
				e->SetY(e->GetY() + 1);
			}
		}
		for (auto en : *enemies) {
			field->SetCell(en.GetY(), en.GetX(), enemy);
		}
		field->SetCell(player_->GetY(), player_->GetX(), player);

	}

	int GetCatchByEnemy() {
		int enemy_id = 0;
		int check = 0;
		for (auto en : *enemies) {
			int x = en.GetX();
			int y = en.GetY();
			if ((field->GetCellState(y, x - 1) == player) || (field->GetCellState(y, x + 1) == player) || (field->GetCellState(y + 1, x - 1) == player) || (field->GetCellState(y + 1, x) == player) || (field->GetCellState(y + 1, x + 1) == player) || (field->GetCellState(y - 1, x - 1) == player) || (field->GetCellState(y - 1, x) == player) || (field->GetCellState(y - 1, x + 1) == player)) {
				check = 1;
				break;
			}
			enemy_id++;
		}
		if (check == 0) {
			return -1;
		}
		else {
			return enemy_id;
		}

	}

	Field RebuildFieldWithFOV() {
		int x = player_->GetX();
		int y = player_->GetY();
		int x_new;
		int y_new;
		Field pole = Field(field->GetHeight(), field->GetWidth());
		for (int i = 0; i < pole.GetHeight(); i++) {
			for (int j = 0; j < pole.GetWidth(); j++) {
				pole.SetCell(i, j, empt);
			}
		}
		pole.SetCell(y, x, player);
		if (y - 4 >= 0) {
			int l;
			int r;
			if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y - 4, i, field->GetCellState(y - 4, i));
			}
		}
		
		if (y - 3 >= 0) {
			int l;
			int r;
			if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y - 3, i, field->GetCellState(y - 3, i));
			}
		}
		if (y - 2 >= 0) {
			int l;
			int r;
			if (x - 3 >= 0) {
				l = x - 3;
			}
			else if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 3 <= field->GetWidth() - 1) {
				r = x + 3;
			}
			else if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y - 2, i, field->GetCellState(y - 2, i));
			}
		}
		if (y - 1 >= 0) {
			int l;
			int r;
			if (x - 4 >= 0) {
				l = x - 4;
			}
			else if (x - 3 >= 0) {
				l = x - 3;
			}
			else if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 4 <= field->GetWidth() - 1) {
				r = x + 4;
			}
			else if (x + 3 <= field->GetWidth() - 1) {
				r = x + 3;
			}
			else if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y - 1, i, field->GetCellState(y - 1, i));
			}
		}
		if (y + 1 <= field->GetHeight() - 1) {
			int l;
			int r;
			if (x - 4 >= 0) {
				l = x - 4;
			}
			else if (x - 3 >= 0) {
				l = x - 3;
			}
			else if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 4 <= field->GetWidth() - 1) {
				r = x + 4;
			}
			else if (x + 3 <= field->GetWidth() - 1) {
				r = x + 3;
			}
			else if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y + 1, i, field->GetCellState(y + 1, i));
			}
		}
		if (y + 2 <= field->GetHeight() - 1) {
			int l;
			int r;
			if (x - 3 >= 0) {
				l = x - 3;
			}
			else if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 3 <= field->GetWidth() - 1) {
				r = x + 3;
			}
			else if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y + 2, i, field->GetCellState(y + 2, i));
			}
		}
		if (y + 3 <= field->GetHeight() - 1) {
			int l;
			int r;
			if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y + 3, i, field->GetCellState(y + 3, i));
			}
		}
		if (y + 4 <= field->GetHeight() - 1) {
			int l;
			int r;
			if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y + 4, i, field->GetCellState(y + 4, i));
			}
		}
		if (1 == 1) {
			int l;
			int r;
			if (x - 4 >= 0) {
				l = x - 4;
			}
			else if (x - 3 >= 0) {
				l = x - 3;
			}
			else if (x - 2 >= 0) {
				l = x - 2;
			}
			else if (x - 1 >= 0) {
				l = x - 1;
			}
			else {
				l = x;
			}
			if (x + 4 <= field->GetWidth() - 1) {
				r = x + 4;
			}
			else if (x + 3 <= field->GetWidth() - 1) {
				r = x + 3;
			}
			else if (x + 2 <= field->GetWidth() - 1) {
				r = x + 2;
			}
			else if (x + 1 <= field->GetWidth() - 1) {
				r = x + 1;
			}
			else {
				r = x;
			}
			for (int i = l; i <= r; i++) {
				pole.SetCell(y, i, field->GetCellState(y, i));
			}
		}

		
		return pole;


	}

};






#endif