#pragma once
#include <iostream>
#include <string>
#include <L5_SP/citytime.h>

using namespace std;

struct City 
{
	string name;
	citytime foundation; //структура, которая хранит дату создания
	double population;
	double area;

	City* next;

	City() {
		name = "undefined";
		population = 0;
		area = 0;
		next = nullptr;
	}

	City(string n, citytime t, double p, double a) {
		name = n;
		foundation = t;
		population = p;
		area = a;
		next = nullptr;
	}
};