#include "patient.hpp"

using namespace std;

namespace patient {

    // Конструкторы
    Patient::Patient()
        :
          FIO(""),
          age(0)
    {}

    Patient::Patient(string pFIO, size_t pAge)
        :
          FIO(pFIO),
          age(pAge)
    {}

    // Деструктор
    Patient::~Patient()
    {
        FIO.clear();
    }

    // Геттеры для данных пациента
    string Patient::getFIO() const
    {
        return FIO;
    }

    size_t Patient::getAge() const
    {
        return age;
    }
}
