#include <iostream>
#include <fstream>
#include <L5_SP/city.h>
#include <L5_SP/citytime.h>
#include <vector>

using namespace std;

void load(string filename, vector<City> &cities);
void sort(vector<City> &cities, bool asc = true);

int main() 
{
    system("chcp 1251");

    vector<City> cities;
    string filename;

    cout << "Введите название файла без расширения и без посфикса \"_clear\":\n";
    cin >> filename;
    try {
        load(filename, cities);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    sort(cities);

    for (City& city : cities) {
        cout << "----===== Город =====----\n"
            << city.name << endl 
            << "Основан " << city.foundation.GetDate() << endl
            << "Население: " << city.population << " тыс. человек" << endl
            << "Площадь: " << city.area << " кв. км" << endl;
    }
}

void sort(vector<City> &cities, bool asc) {
    if (asc == true) {
        for (int i = 1; i < cities.size(); i++) {
            City temp = cities[i];
            int j = i - 1;
            while (j >= 0 && (cities[j].population > temp.population || cities[j].area > temp.area)) {
                cities[j + 1] = cities[j];
                j--;
            }
            cities[j + 1] = temp;
        }
    }
    else {
        for (int i = 1; i < cities.size(); i++) {
            City temp = cities[i];
            int j = i - 1;
            while (j >= 0 && (cities[j].population < temp.population || cities[j].area < temp.area)) {
                cities[j + 1] = cities[j];
                j--;
            }
            cities[j + 1] = temp;
        }
    }
}

void load(string filename, vector<City>& cities) {
    string clearfile = filename + "_clear.txt";
    string path = "..\\L5_SP\\" + clearfile;

    ifstream read(path);

    read.exceptions(ios::badbit | ios::failbit);

    string name, date;
    double population, area;

    cout << "Файл открыт. Чтение...\n";
    while (!read.eof() && read >> name >> date >> population >> area) {
        City city(name, StringToDate(date), population, area);
        cities.push_back(city);  
    }

    cout << "Чтение завершено. Добавлено " << cities.size() << " записей\n";
    read.close();
}