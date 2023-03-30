#include "../Field/Field.h"
#include <time.h>
#include "../utills/utils.h"

//void PrintField(Field* _field) {
//	for (int i = 0; i < _field->GetHeight(); i++) {
//		for (int j = 0; j < _field->GetWidth(); j++) {
//			std::cout << _field->GetCellChar(i, j);
//		}
//		std::cout << std::endl;
//	}
//}

class Map_gen {
public:
	Field* Generate(const int num_en, const int num_rm) {
		const int* arr_l = Massive_of_rand_l();
		const int* arr_h = Massive_of_rand_h();
		Field* ma = Make_border(arr_h, arr_l);
		int mid_l1 = arr_l[0] / 2;
		int mid_l2 = arr_l[1] / 2;
		int mid_l3 = arr_l[2] / 2;
		int mid_l4 = arr_l[3] / 2;
		int mid_h1 = arr_h[0] / 2;
		int mid_h2 = arr_h[1] / 2;
		int mid_h3 = arr_h[2] / 2;
		int* arr = new int[num_rm];
		int* arr_rm = rand_arr(num_rm);
		//FillSquare(ma, 0, 0, 22, 134, shop);

		for (int i = 0; i < num_rm; i++) {
			if (arr_rm[i] == 1) {
				FillSquare(ma, 1, 1, arr_h[0] - 1, arr_l[0] - 1, wall);
				FillSquare(ma, 2, 2, arr_h[0] - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 2) {
				FillSquare(ma, 1, 1 + arr_l[0], arr_h[0] - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, 2, 2 + arr_l[0], arr_h[0] - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 3) {
				FillSquare(ma, 1, 1 + (arr_l[0] + arr_l[1]), arr_h[0] - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, 2, 2 + (arr_l[0] + arr_l[1]), arr_h[0] - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 4) {
				FillSquare(ma, 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), arr_h[0] - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), arr_h[0] - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}
			else if (arr_rm[i] == 5) {
				FillSquare(ma, arr_h[0] + 1, 1, (arr_h[0] + arr_h[1]) - 1, arr_l[0] - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2, (arr_h[0] + arr_h[1]) - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 6) {
				FillSquare(ma, arr_h[0] + 1, 1 + arr_l[0], (arr_h[0] + arr_h[1]) - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + arr_l[0], (arr_h[0] + arr_h[1]) - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 7) {
				FillSquare(ma, arr_h[0] + 1, 1 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1]) - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1]) - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 8) {
				FillSquare(ma, arr_h[0] + 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1]) - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1]) - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}
			else if (arr_rm[i] == 9) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1, (arr_h[0] + arr_h[1] + arr_h[2]) - 1, arr_l[0] - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2, (arr_h[0] + arr_h[1] + arr_h[2]) - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 10) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + arr_l[0], (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + arr_l[0], (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 11) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 12) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}

		}
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 134; j++) {

				if (i == mid_h1 && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
					/*ma->SetCell(i-1, j, wall);
					ma->SetCell(i+ 1, j, wall);*/
				}
				else if (i == mid_h2 + arr_h[0] && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (i == mid_h3 + arr_h[1] + arr_h[0] && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l1 && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == (mid_l2 + arr_l[0]) && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l3 + arr_l[1] + arr_l[0] && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l4 + arr_l[0] + arr_l[1] + arr_l[2] && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);

				}

			}
		}
		/*int a = 0;
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 134; j++) {
				int l =  1 + rand() % 22;
				int k = 1 +  rand() % 134;
				if (ma->GetCellChar(l, k) == pass) {
					ma->SetCell(l, k, enemy);
					a++;
					if (a >= num_en) {
						break;
					}
				}
			}
		}*/
		return ma;
	}
};









//int main() {
//	srand(time(0));
//	Map_gen* a = new Map_gen;
//	Field* b = a->Generate(6, 10);
//	PrintField(b);
//}