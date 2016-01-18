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

    while(data_list >> human.surname >> human.name >> human.patronymic >> human.age)
    {
        Patient person(human.surname, human.name, human.patronymic, human.age);
        head=insertPatient(head, person);
    }

    // Тестирование операций:

    // Вывод готового списка:
    cout << "Вывод готового списка:" << endl;
    print(head);

    // Подсчёт числа элементов в списке:
    cout << "Подсчёт числа элементов в списке:" << endl;
    size_t listsize=countList(head);
    cout << "Элементов в списке: " << listsize << endl << endl;

    // Поиск элемента в списке:
    cout << "Поиск элемента в списке:" << endl;
    patientList *check_search=searchPatient(head, 2, listsize);
    cout << "Второй элемент списка: " << endl << check_search->person << endl << endl;

    // Копирование списка:
    cout << "Копирование списка:" << endl;
    patientList *copy1=copyList(head); // для тестирования удаления
    patientList *copy2=copyList(head); // для тестирования склейки
    patientList *copy3=copyList(head); // для тестирования склейки
    patientList *copy4=copyList(head); // для тестирования разделения
    cout << "Копия списка:" << endl;
    print(copy1);

    // Удалить элемент по значению:
    // Пациент, которого нет в списке
    cout << "Удалить элемент по значению:" << endl;
    Patient a("ffffff", "fffff", "ffffff", 18);
    // Первый пациент в очереди
    Patient b("Fmhsaxtljj", "Cwpatrwcym", "Bhpshnfyji", 86);
    patientList *check_delete;
    cout << a << endl;
    check_delete = deletePatient(copy1, a);
    cout << endl << b << endl;
    check_delete = deletePatient(copy1, b);
    cout << endl;
    print(check_delete);

    // Объединить 2 списка в 1:
    cout << "Объединить 2 списка в 1:" << endl;
    patientList *combine=combineLists(copy2, copy3);
    print(combine);

    // Разделить список на 2 части:
    cout << "Разделить список на 2 части:" << endl;
    patientList *copy5=NULL, *copy6=NULL;
    divideList(copy4, 3, copy5, copy6);
    cout << "1 часть:" << endl;
    print(copy5);
    cout << "2 часть:" << endl;
    print(copy6);

    return 0;
}

