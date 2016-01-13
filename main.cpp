#include <iostream>
#include <fstream>
#include <string>

#include "patient.hpp"

using namespace std;
using namespace patient;

int main()
{
    // Открытие файла с данными по всем билетам
    ifstream data_list;
    data_list.open("patient_list.txt");
    // Проверка на правильное открытие файла
    if (!data_list)
    {
        cout << "Can't open file!"<< endl;
        return 1;
    }

    struct form
    {
        string surname;
        string name;
        string patronymic;
        size_t age;
    } human_being;


    return 0;
}

