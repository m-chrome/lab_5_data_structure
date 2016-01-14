#include <iostream>
#include "patient.hpp"

using namespace std;

namespace patient {

    // Конструкторы
    Patient::Patient()
        :
          surname(""),
          name(""),
          patronymic(""),
          age(0)
    {}

    Patient::Patient(string pSurname, string pName, string pPatronymic, size_t pAge)
        :
          surname(pSurname),
          name(pName),
          patronymic(pPatronymic),
          age(pAge)
    {}


    // Деструктор
    Patient::~Patient()
    {
        surname.clear();
        name.clear();
        patronymic.clear();
    }

    // Геттеры
    string Patient::getSurname() const
    {
        return surname;
    }

    string Patient::getName() const
    {
        return name;
    }

    string Patient::getPatronymic() const
    {
        return patronymic;
    }

    size_t Patient::getAge() const
    {
        return age;
    }

    // Перегрузка оператора вывода для билета
    ostream& operator<<(ostream& person, const Patient& data)
    {
            person << data.getSurname() << ' ' << data.getName() << ' '
                    << data.getPatronymic() << ' ' << data.getAge();
            return person;
    }
}
