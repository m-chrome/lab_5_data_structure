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
            string FIO;
            size_t age;

        public:
            // Конструкторы:
            Patient();
            Patient(string pFIO, size_t pAge);

            // Деструктор
            ~Patient();

            // Геттеры для данных класса:
            string getFIO() const;
            size_t getAge() const;
    };

}
#endif // PATIENT_HPP
