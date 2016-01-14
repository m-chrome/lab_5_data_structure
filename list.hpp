#ifndef LIST
#define LIST

#include <iostream>
#include "patient.hpp"

using namespace std;
using namespace patient;

struct patientList
{
    Patient person;
    patientList *next;
};

// Методы

// Метод вставки нового элемента
patientList* insertPatient(size_t number, patientList* head, const Patient& human)
{
    number--;
    // Создаём новый список с элементом, который вставляем
    patientList *newPatient = new patientList;
    newPatient->person = human;
    newPatient->next = NULL;

    // Сравниваем с исходным списком
    if (head == NULL)
    {
        // Список пуст, первым элементом становится подающийся пациент
        head = newPatient;
    }
    else
    {
        // Список непустой, вставляем элемент в него по номеру
        patientList *current = head;
        for(size_t i=1; i < number && current->next != NULL; i++)
            current = current->next;
        if (number == 0)
        {
            // Вставляем в начало
            newPatient->next = head;
            head = newPatient;
        }
        else
        {
            // Вставляем на number позицию
            newPatient->next = current->next;
            current->next = newPatient;
            current = newPatient;
        }
    }
    return head;
}

// Метод удаления элемента по значению
void deletePatient()
{

}

// Метод поиска (доступа по индексу)
void searchPatient()
{

}

// Показать содержимое списка
void print(patientList* head)
{
    if (head != NULL)
    {
        cout << head->person << endl;
        // Переход на следующий элемент списка
        print(head->next);
    }
    else cout << "\n";
}


#endif // LIST

