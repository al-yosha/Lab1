#include <iostream>
#include "lab1.h"

namespace lab1 {
	Col* matrix_create(int m, int n) {
		Col* matrix = new Col;
		Col* cur_m = matrix;
		Line* cur_n = nullptr;
		int flag = 0;
		matrix->pos = -1;
		matrix->next = nullptr;
		matrix->l = nullptr;
		int tmp;
		for (int i = 0; i < m; i++) {
			std::cout << "Enter numbers in line" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < n; j++) {
				while (getInt(tmp) == -1)
					std::cout << "Incorrect input, try again:" << std::endl;		//Проверка корректности ввода
				if (tmp) {						//Если введён не ноль
					if (!flag) {
						cur_m->next = new Col;
						cur_m = cur_m->next;
						*cur_m = { i, new Line, nullptr };
						cur_n = cur_m->l;
						*cur_n = { j, tmp, nullptr };
						flag = 1;
					}
					else {
						cur_n->next = new Line;
						cur_n = cur_n->next;
						*cur_n = { j, tmp, nullptr };
					}
				}
			}
			flag = 0;
		}
		if (matrix->next == nullptr)
			return nullptr;
		cur_m = matrix;
		matrix = matrix->next;
		delete[] cur_m;
		return matrix;
	}

	void output(const char* msg, Col* mx, int m, int n) {
		std::cout << msg << std::endl;
		Line* cur = nullptr;
		int p = 0;
		int p1 = 0;
		while (mx != nullptr) {

			for (int i = 0; i < (mx->pos - p1); i++) {
				pz(n);
				std::cout << std::endl;
			}
			p1 = mx->pos + 1;
			
			cur = mx->l;
			while (cur != nullptr) {
				pz(cur->pos - p);
				std::cout << cur->number << " ";
				p = cur->pos + 1;
				cur = cur->next;
			}
			pz(n - p);
			std::cout << std::endl;
			mx = mx->next;
			p = 0;
		}
		for (int i = 0; i < (m - p1); i++) {
			pz(n);
			std::cout << std::endl;
		}
	}

	void pz(int q) {
		for (int i = 0; i < q; i++)
			std::cout << "0 ";
	}

	Col* modify (Col* mx, int n) {
		Col* mn = new Col;
		Col* ptr1 = mn;
		Line* prev = nullptr;
		Line* cur = nullptr;
		Line* ptr2;
		while (mx != nullptr) {
			ptr1->next = new Col;
			ptr1 = ptr1->next;
			ptr1->pos = mx->pos;
			ptr1->next = nullptr;
			ptr2 = mx->l;
			prev = nullptr;
			while (ptr2 != nullptr) {
				cur = new Line;
				cur->number = ptr2->number;
				cur->pos = n - ptr2->pos - 1;
				cur->next = prev;
				prev = cur;
				ptr2 = ptr2->next;
			}
			ptr1->l = cur;
			mx = mx->next;
		} ;
		ptr1 = mn;
		mn = mn->next;
		delete[] ptr1;
		return mn;
	}

	void erase(Col* mx) {
		Col* tmp0;
		Line* tmp1;
		Line* tmp2;
		while (mx != nullptr) {
			tmp0 = mx;
			tmp1 = tmp0->l;
			tmp2 = tmp1;
			while (tmp2 != nullptr) {
				tmp2 = tmp2->next;
				delete[] tmp1;
				tmp1 = tmp2;
			}
			mx = mx->next;
			delete[] tmp0;
			tmp0 = mx;
		}
	}

	

	int getInt(int &a) {
		std::cin >> a;
		if (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return -1;
		}
		if (a <= 0)
			return -2;
		return 1;
	}
}