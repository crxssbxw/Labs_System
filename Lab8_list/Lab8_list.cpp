#include <iostream>
#include <string>
#include <L5_SP/city.h>
#include <L5_SP/citytime.h>
#include <L5_SP/cities_arr.h>

int main() {
	system("chcp 1251");

	//Объявление списка
	CitiesList list;

	//Проверка на пустой список
	cout << "Список пуст, если 1: " << list.is_empty() << endl;

	//Создание экземпляра города
	citytime date = StringToDate("01.01.903");

	City city ("Moscow", date, 5000, 1600);
	
	//Добавление города в конец
	list.AddBack(city);

	//Повторно другой город
	City city1 ("Vladimir", StringToDate("05.04.1342"), 400, 340);

	list.AddBack(city1);

	City city2("Kovrov", StringToDate("14.12.1567"), 300, 130);

	//Добавление в указанную позицию
	//С исключением
	try {
		list.AddPos(city2, 15);
	}
	catch (const char* message) {
		cout << message << endl;
	}
	list.AddBack(city2);

	//Без исключения
	list.AddPos(city2, 1);

	cout << endl;
	//Вывод списка
	list.print();

	//Поиск элемента по позиции
	cout << "Элемент на позиции 1: ";
	City* findcity = list.find(1);

	cout << findcity->name << endl;

	//Поиск позиций с указанной датой
	int* positions;
	int lenght;

	positions = list.FindByDate("14.12.1567", lenght);

	cout << "\nПозиции по указанной дате (14.12.1567): ";
	for (int i = 0; i < lenght; i++) {
		cout << positions[i] << ", ";
	}
	cout << endl;

	delete[] positions;

	//Удаление
	//С исключением
	try {
		list.Remove(15);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	//Без исключения
	list.Remove(2);

	//Вывод имен
	cout << "\nВывод имен в массиве: " << endl;
	string* names = list.GetNames();

	for (int i = 0; i < list.GetLenght(); i++) {
		cout << names[i] << endl;
	}

	delete[] names;

	
}