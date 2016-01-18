#ifndef LIST
#define LIST

/* Вариант 6:
 * Очередь на основе односвязного списка, в которой хранится список пациентов (ФИО, возраст).
 *
 * Особенности:
 * Добавление только в конец и удаление только из начала
 *
 * Реализовать операции:
 *
 * 1. получить доступ к элементу по индексу (номеру): check
 * 2. добавить новый элемент в конец: check
 * 3. удалить элемент по значению с начала: check
 * 4. объединить два набора в один: check
 * 5. разбить один набор на несколько: check
 * 6. определить число элементов: check
 * 7. создать копию: check
*/

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

// Метод вставки нового элемента в очередь.
// Так как очередь, можно вставлять лишь в конец.
// На вход подаём указатель на голову списка и элемент для вставки.
patientList* insertPatient(patientList* head, const Patient& human)
{
    // Создаём новый список с элементом, который вставляем
    patientList *newPatient = new patientList;
    newPatient->person = human;
    newPatient->next = NULL;

    // Сравниваем с исходным списком
    if (head == NULL)
    {
        // Список пуст, первым элементом становится входящий пациент
        head = newPatient;
    }
    else
    {
        // Список непустой, вставляем элемент
        // в конец очереди
        patientList *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newPatient;
    }
    return head;
}

// Метод удаления элемента по значению
// На вход подаем указатель на первый элемент списка и
// значение - объект Patient, который необходимо удалить
patientList* deletePatient(patientList* head, Patient person)
{
    // Так как очередь, то можно удалять только из начала
    // Сравниваем поданное на вход значение со значением
    // в первом элементе списка
    if (head->person == person)
    {
        // Если равны, то создадим и вернём указатель
        // на новое начало списка и удалим старый головной элемент
        patientList *newHead=head->next;
        delete head;
        cout << "Пациент получил лечение." << endl;
        return newHead;
    }
    else
    {
        // Если не равны, возвращаем старый указатель с пометкой,
        // что входное значение отсутствует/не первый пациент в очереди
        cout << "Этот пациент не первый." << endl;
        return head;
    }
}

// Метод поиска (доступа по индексу)
patientList* searchPatient(patientList* head,
                           size_t index, size_t size)
{
    size_t number=1;
    if (index > size)
    {
        cout << "Список меньше, чем входной номер!";
        // TODO: исключения
        return head;
    }
    while (number != index)
    {
        number++;
        head=head->next;
    }
    return head;
}

// Метод копирования списка
patientList* copyList(patientList* parent)
{
    patientList *copy=NULL;
    while (parent != NULL)
    {
        copy=insertPatient(copy, parent->person);
        parent=parent->next;
    }
    return copy;
}

// Метод подсчёта элементов в списке
size_t countList(patientList* head)
{
    size_t number=0;
    if (head != NULL)
    {
        while (head != NULL)
        {
            number++;
            head=head->next;
        }
    }
    return number;
}

// Объединить два списка в один
// На вход подается 2 указателя, first и second
// Возвращает указатель на готовый список
patientList* combineLists(patientList* first, patientList* second)
{
    patientList *combine = first;
    while(first->next != NULL)
    {
        first=first->next;
    }
    first->next=second;
    return combine;
}

// Метод разделения списка на 2 части
// На вход подается указатель на список и количество элементов, которые нужно взять в 1 часть
void divideList(patientList* list, size_t last, patientList* &list1, patientList* &list2)
{
    size_t i=1;
    list1=list;
    while (i!=last)
    {

        list=list->next;
        ++i;
    }
    list2 = list->next;
    list->next=NULL;
}

// Показать содержимое списка
void print(patientList* head)
{
    if (head != NULL)
    {
        while (head != NULL)
        {
            cout << head->person << endl;
            head=head->next;
        }
    }
    else
        cout << "Очередь пуста." << endl;
    cout << endl;
}


#endif // LIST
