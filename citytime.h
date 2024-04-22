#pragma once
#include <iostream>
#include <string>

using namespace std;

struct citytime
{
	unsigned int day;
	unsigned int month;
	unsigned int year;

	citytime() {
		day = 1;
		month = 1;
		year = 988;
	}

	citytime(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	//Возвращает дату в виде строки
	string GetDate() {
		if (day > 10 && month > 10) {
			return to_string(day) + "." + to_string(month) + "." + to_string(year);
		}
		else if (day < 10 && month > 10) {
			return "0" + to_string(day) + "." + to_string(month) + "." + to_string(year);
		}
		else if (day > 10 && month < 10) {
			return to_string(day) + ".0" + to_string(month) + "." + to_string(year);
		}
		else return "0" + to_string(day) + ".0" + to_string(month) + "." + to_string(year);
	}
};

//Приводит строку длиной 10 символов в дату типа citytime
citytime StringToDate(string stringdate) {
	if (stringdate.length() == 10) {
		int iday, imonth, iyear;
		string sday, smonth, syear;

		sday = stringdate.substr(0, 2);
		smonth = stringdate.substr(3, 2);
		syear = stringdate.substr(6);

		iday = stoi(sday);
		imonth = stoi(smonth);
		iyear = stoi(syear);

		if (iday > 31) iday = 31;
		if (imonth > 12) imonth = 12;
		if (iyear > 9999) iyear = 9999;

		return citytime(iday, imonth, iyear);
	}
	else {
		return citytime();
	}
}