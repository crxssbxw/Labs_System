#pragma once
#include <L5_SP/city.h>
#include <string>

using namespace std;

class CitiesList {
public:
	///�����������
	CitiesList() : first(nullptr), last(nullptr), lenght(0) {}

	///���������� �������� � �����
	void AddBack(City insert) {
		City* c = new City(insert);
		if (is_empty()) {
			first = c;
			last = c;
			lenght++;
			return;
		}
		last->next = c;
		last = c;
		lenght++;
	}

	///��������� �� �������
	City* operator[] (const int index) {
		if (is_empty()) return nullptr;
		City* c = first;
		for (int i = 0; i < index; i++) {
			c = c->next;
			if (!c) return nullptr;
		}
	}

	///����� �������� �� �������
	City* find(int pos) {

		if (pos > lenght) {
			throw "������� ������ ���������� ���������";
		}

		City* c = first;
		int k = 0; //count
		while (c && k != pos) 
		{
			c = c->next;
			k++;
		}
		
		return (c && k == pos) ? c : nullptr;
	}

	///���������� � ��������� �������
	void AddPos(City insert, int pos) {
		City* c = new City(insert);
		City* f = first;
		City *finder, *finderprev;
		if (pos == lenght) {
			AddBack(insert);
			return;
		}
		if (is_empty()) {
			first = c;
			last = c;
			lenght++;
			return;
		}
		if (find(pos) == nullptr) {
			AddBack(insert);
			return;
		}
		finder = find(pos);
		finderprev = find(pos - 1);
		finderprev->next = c;
		c->next = finder;
		finder = c;
		lenght++;
		return;
	}

	///�������� ������� ����
	void RemoveFirst() {
		if (is_empty()) return;
		City* p = first;
		first = p->next;
		delete p;
	}

	///�������� ���������� ����
	void RemoveLast() {
		if (is_empty()) return;
		if (first == last) {
			RemoveFirst();
			return;
		}
		City* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}
	
	///�������� �� ��������� �������
	void Remove(int pos) {
		if (is_empty()) return;
		if (pos == 0) {
			RemoveFirst();
			lenght--;
			return;
		}
		else if (pos == lenght) {
			RemoveLast();
			lenght--;
			return;
		}
		City* slow = first;
		City* fast = first->next;
		int k = 0;
		while (fast && k != pos-1) {
			fast = fast->next;
			slow = slow->next;
			k++;
		}
		if (!fast) {
			throw "�������� �� ����������";
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	///�������� �� �������������
	bool is_empty() {
		return first == nullptr;
	}

	///����� � ������ ������ � ��������� ����� ���������
	int* FindByDate(citytime date, int &count) {
		int* city_pos = new int[lenght];
		int pos = 0;
		count = 0;

		City* p = first;
		while (p)
		{
			if (p->foundation.GetDate() == date.GetDate()) {
				city_pos[count] = pos;
				count++;
			}
			p = p->next;
			pos++;
		}

		if (count == 0) {
			city_pos[count] = -1;
			count++;
		}
		return city_pos;
	}

	int* FindByDate(string date, int &count) {
		int* city_pos = new int[lenght];
		int pos = 0;
		count = 0;

		City* p = first;
		while (p)
		{
			if (p->foundation.GetDate() == date) {
				city_pos[count] = pos;
				count++;
			}
			p = p->next;
			pos++;
		}

		if (count == 0) {
			city_pos[count] = -1;
			count++;
		}
		return city_pos;
	}

	///����� ������
	void print() {
		if (is_empty()) return;
		City* p = first;
		while (p) {
			cout << p->name << endl << p->area << endl << p->foundation.GetDate() << endl << p->population << endl;
			p = p->next;
		}
		cout << endl;
	}

	///����� ���� �������� �������
	string* GetNames() {

		if (is_empty()) {
			throw "������ ����";
		}

		City* p = first;
		string* names = new string[lenght];

		for (int i = 0; i < lenght && p; i++) {
			names[i] = p->name;
			p = p->next;
		}
		return names;
	}

	int GetLenght() 
	{
		return lenght;
	}
private:
	unsigned int lenght;
	City* first;
	City* last;
};