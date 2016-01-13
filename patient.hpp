#ifndef PATIENT_HPP
#define PATIENT_HPP

// Данные для пациента: ФИО, возраст

#include <iostream>
#include <string>

using namespace std;

namespace patient {

    class Patient
    {
        private:
            struct FIO
            {
                string surname;
                string name;
                string patronymic;
            } human;
            size_t age;

        public:
            // Конструкторы:
            Patient();
            Patient(string pSurname, string pName, string pPatronymic, size_t pAge);

            // Деструктор
            ~Patient();
    };

}
#endif // PATIENT_HPP
