#ifndef LIST
#define LIST

#include "patient.hpp"

using namespace std;
using namespace patient;

struct patientList
{
    Patient person;
    patientList *next;
};

// Методы
// Метод создания списка (с пустым полем Patient)
// Нужна ли она?
// Ведь можно запилить просто нулевой указатель
void createPatientList(size_t size, patientList** head)
{
    if (size > 0)
    {
        *head = new patientList;
        // создаем пустую "форму"
        Patient human;
        (*head)->person = human;
        (*head)->next = NULL;
        createPatientList(size-1, &((*head)->next));
    }
    else
        *head = NULL;
}

// Метод вставки нового элемента
patientList* insertPatient(size_t number, patientList* head, Patient human)
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

#endif // LIST

