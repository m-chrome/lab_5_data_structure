/* Вариант 6:
 * Очередь на основе односвязного списка, в которой хранится список пациентов (ФИО, возраст).
 *
 * Особенности:
 * Добавление только в конец и удаление только из начала
 *
 * Реализовать операции:
 *
 * 1. получить доступ к элементу по индексу (номеру);
 * 2. добавить новый элемент;
 * 3. удалить элемент по значению;
 * 4. объединить два набора в один;
 * 5. разбить один набор на несколько;
 * 6. определить число элементов;
 * 7. создать копию.
*/

#include <iostream>
#include <fstream>
#include <string>

#include "patient.hpp"
#include "list.hpp"

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
    } human;

    // Создадим пустой указатель на будущий список
    patientList *head = NULL;
    // Переменнная для дальнейших элементов списка
    // Индекс, по умолчанию равен 1
    size_t index=1;

    while(data_list >> human.surname >> human.name >> human.patronymic >> human.age)
    {
        Patient person(human.surname, human.name, human.patronymic, human.age);
        insertPatient(index, head,person);
        index++;
    }

    return 0;
}

