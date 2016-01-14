#include <iostream>
#include "patient.hpp"

using namespace std;

namespace patient {

    // Конструкторы
    Patient::Patient()
    {
        human.surname="";
        human.name="";
        human.patronymic="";
        age=0;
    }

    Patient::Patient(string pSurname, string pName, string pPatronymic, size_t pAge)
    {
        human.surname=pSurname;
        human.name=pName;
        human.patronymic=pPatronymic;
        age=pAge;
    }

    // Деструктор
    Patient::~Patient()
    {
        human.surname.clear();
        human.name.clear();
        human.patronymic.clear();
    }

}
