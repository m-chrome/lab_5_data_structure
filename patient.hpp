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
            // Данные пациента
            string surname;
            string name;
            string patronymic;
            size_t age;

        public:


            // Конструкторы:
            Patient();
            Patient(string pSurname, string pName, string pPatronymic, size_t pAge);

            // Деструктор
            ~Patient();

            // Геттеры
            string getSurname() const;
            string getName() const;
            string getPatronymic() const;
            size_t getAge() const;

            friend ostream& operator<<(ostream& person, const Patient& data)
            {
                person << data.getSurname() << ' ' << data.getName() << ' '
                       << data.getPatronymic() << ' ' << data.getAge();
                return person;
            }

            bool operator==(Patient& person)
            {
                return (surname==person.surname) &&
                        (name==person.name) &&
                        (patronymic==person.patronymic) &&
                        (age==person.age);
            }
    };
}
#endif // PATIENT_HPP
