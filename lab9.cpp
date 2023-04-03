#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>

using namespace std;
void _1task();
void _2task();

struct student
{
    char stud_name[80];
    int grade1;
    int grade2;
    int grade3;
    int grade4;
    struct student* next;
};  student *head, *p, *pred, *tail, *t1, *t2;


struct students
{
    char stud_name[80];
    int grade1;
    int grade2;
    int grade3;
    int grade4;
    struct students* next;
    struct students* prev;
};  students *head_, *p_, *pred_, *tail_, *_t;

int main()
{
    srand(time(NULL));
    int key = -1;
    while (key != 0)
    {
        cout << "Enter Key: ";
        cin >> key;
        switch (key)
        {
        case 1:
            _1task();
            break;
        case 2:
            _2task();
        default:
            break;
        }
    }
}
void _1task()
{
    bool flag = true;
    head = tail = new student;
    tail -> next = NULL;
    while (flag)
    {
        p = new student;
        cout << "Enter: ";
        cin >> p -> stud_name;
        p -> grade1 = rand()%10;
        p -> grade2 = rand()%10;
        p -> grade3 = rand()%10;
        p -> grade4 = rand()%10;   
        tail -> next = p;
        tail = p;
        cout << "Should we go? 1/0? ";
        cin >> flag;
    }
    tail -> next = NULL;
    bool f = 0;
    do
    {
        f = 0;
        for (p = head; p -> next -> next; p = p -> next)
        {
            t1 = p -> next;
            t2 = t1 -> next;
            if (strcmp(t1 -> stud_name, t2 -> stud_name) > 0)
            {
                p -> next = t2; 
                t1 -> next = t2 -> next;
                t2 -> next = t1;
                f = 1;
            }
        }
    }
    while(f);
    //print
    for (p = head -> next; p; p = p -> next)
    {
        cout << p -> stud_name << "\n";
        cout << p -> grade1 << "\n";
        cout << p -> grade2 << "\n";
        cout << p -> grade3 << "\n";
        cout << p -> grade4 << "\n";        
    }
    //free
    for (p = head; p; p = pred)
    {
        pred = p -> next;
        delete(p);
    }
    //
    return;
}

void _2task()
{
    head_ = tail_ = new students, head_ -> next = head_ -> prev = NULL;
    bool flag = 0;
    do
    {
        p_ = new students;
        cout << "ENTER NAME: ";
        cin >> p_ -> stud_name;
        p_ -> grade1 = 2 + rand()%4;
        p_ -> grade2 = 2 + rand()%4;
        p_ -> grade3 = 2 + rand()%4;
        p_ -> grade4 = 2 + rand()%4;
        p_ -> next = NULL;
        p_ -> prev = tail_;
        tail_ -> next = p_;
        tail_ = p_;
        cout << "Enter: flag - 1/0: ";
        cin >> flag;
    } while (flag);
    p_ = new students;
    p_ -> next = NULL;
    p_ -> prev = tail_;
    tail_ -> next = p_;
    tail_ = p_;
    flag = 0;
    for (p_ = head_ -> next; p_ -> next;)
    {
        flag += (p_ -> grade1 < 4) + (p_ -> grade2 < 4) + (p_ -> grade3 < 4) + (p_ -> grade4 < 4);
        if (flag)
        {
            _t = p_;
            p_ = p_ -> next;
            _t -> next -> prev = _t -> prev;    
            _t -> prev -> next = _t -> next;
            delete(_t);
        }
        else
        {
            p_ = p_ -> next;
        }
    }

    for (p_ = head_ -> next; p_ -> next; p_ = p_ -> next)
    {
        cout << "Name: " << p_ -> stud_name << "\n";
        cout << p_ -> grade1 << p_ -> grade2 << p_ -> grade3 << p_ -> grade4 << "\n";
    }


    for (p_ = head_; p_; p_ = pred_)
    {
        pred_ = p_ -> next;
        delete(p_);
    }

    return;
}