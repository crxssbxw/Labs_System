#include <iostream>
#include <string>
#include <fstream>
#include <L5_SP/city.h>
#include <L5_SP/citytime.h>

void save(string filename, City* array, int N, bool clear = false);

int main() 
{
    system("chcp 1251");
	int N;
    string filename;

    cout << "Введите количество городов: ";

	cin >> N;

	City* cities = new City[N];

    for (int i = 0; i < N; i++) {
        string name, sdate;
        unsigned int population;
        double area;

        cout << "\nВведите название города: ";
        cin >> name;

        cout << "Введите дату основания: ";
        cin >> sdate;
        citytime date = StringToDate(sdate);

        cout << "Введите количество населения в тысячах человек: ";
        cin >> population;

        cout << "Введите площадь территории (кв. км): ";
        cin >> area;

        cities[i] = City(name, date, population, area);
    }

    cout << "\nВведите название файла для записи без расширения: ";
    cin >> filename;

    string clearfile = filename + "_clear.txt";
    filename += ".txt";
    try {
        save(filename, cities, N);

        save(clearfile, cities, N, true);
    }
    catch (const char* message) {
        cout << message << endl;
        return 1;
    }
    catch (exception e) {
        cout << e.what();
        return 1;
    }

    return 0;
}

void save(string filename, City* array, int N, bool clear) {
    ofstream write(filename);
    write.exceptions(ios::badbit | ios::failbit | ios::eofbit);

    if (N <= 0) throw "Количество городов меньше 1!"; //Если городов на вводе меньше 0

    try {
        if (!clear) {
            cout << "\nФайл " << filename << " успешно открыт\nКоличество городов к записи в файл: " << N << endl;
        
            for (int i = 0; i < N; i++) {
                write << "Город " << array[i].name
                    << "\nДата основания: " << array[i].foundation.GetDate()
                    << "\nНаселение " << array[i].population << " тыс. человек"
                    << "\nПлощадь " << array[i].area << " кв. километров\n"
                    << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
            }

            cout << "Данные были успешно записаны.\n";
        }
        else if (clear) {
            cout << "\nФайл " << filename << " успешно открыт в режиме чистой записи\nКоличество городов к записи в файл: " << N << endl;
        
            for (int i = 0; i < N; i++) {
                if (i > 0) write << endl;
                write << array[i].name << endl
                    << array[i].foundation.GetDate() << endl
                    << array[i].population << endl
                    << array[i].area;
            }

            cout << "Данные были успешно записаны.\n";
        }
    }
    catch (exception e) {
        cout << "Ошибка при работе с файлом" << endl;
    }
    write.close();
}