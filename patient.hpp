#ifndef PATIENT_HPP
#define PATIENT_HPP

// Данные для пациента: ФИО, возраст

#include <iostream>
#include <string>

using namespace std;

namespace patient {

    class Patient
    {
        public:
            struct FIO
            {
                string surname;
                string name;
                string patronymic;
            } human;
            size_t age;

            // Конструкторы:
            Patient();
            Patient(string pSurname, string pName, string pPatronymic, size_t pAge);

            // Деструктор
            ~Patient();
    };

    ostream& operator<<(ostream& person, const Patient& data);
}
#endif // PATIENT_HPP
