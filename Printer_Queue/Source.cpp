#include<iostream>
#include<assert.h>

using namespace std;

template<typename T>
class Worker_Queue {
    T* data;
    int capacity;
    int front;
    int rear;
    int count;
public:

    Worker_Queue()
    {

    }
    Worker_Queue(int size) {

        data = new T[size];

        capacity = size;
        front = 0;
        rear = 0;
        count = 0;
    }



    Worker_Queue& operator=(const Worker_Queue& other)
    {

        this->data = new T[other.count];
        for (int i = 0; i < other.count; i++) {
            this->data[i] = other.data[i];
        }

        this->capacity = other.capacity;
        this->front = other.front;
        this->rear = other.rear;
        this->count = other.count;



        return *this;
    }




    void enqueue(T value) {
        assert(!isFull() && " Queue is full ");
        data[rear] = value;
        ++rear;
        count++;
    }





    void dequeue() {
        if (!isEmpty()) {
            auto temp = new T[size() - 1];
            for (size_t i = 0; i < count - 1; i++)
            {
                temp[i] = data[i + 1];
            }
            // delete[]data;
            data = temp;
            temp = nullptr;
            count--;
        }
    }



    T& peek() {
        return data[front];
    }



    int size() {
        return count;
    }



    bool isEmpty() {
        return size() == 0;
    };



    bool isFull() {
        return size() == capacity;
    }

    void queueDisplay()
    {
        int i;
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        // traverse front to rear and print elements 
        for (i = front; i < count; i++) {
            printf(" %d ", data[i]);
        }
        return;
    }



    ~Worker_Queue()
    {
        delete[]data;
    }
};


class Worker {
    int worker_id;

    int age;
    char* name;
    char* surname;
    int pagecount;
public:
    static int id;
    Worker() :worker_id(0), name(nullptr), surname(nullptr), age(0), pagecount(0) {}

    Worker(const char* name, const char* surname, int age, int pagecount)
    {
        this->worker_id = ++id;
        setName(name);
        setSurname(surname);
        setAge(age);
        setPagecount(pagecount);
    }

    Worker(const Worker& other)
    {

        this->worker_id = other.worker_id;
        setName(other.name);
        setSurname(other.surname);
        setAge(other.age);
        setPagecount(other.pagecount);
    }

    Worker& operator=(const Worker& other)
    {

        this->worker_id = other.worker_id;
        setName(other.name);
        setSurname(other.surname);
        setAge(other.age);
        setPagecount(other.pagecount);


        return *this;
    }

    Worker(Worker&& other) {

        setName(other.name);
        setSurname(other.surname);
        setAge(other.age);
        setPagecount(other.pagecount);

        delete other.name;
        other.name = nullptr;

        delete other.surname;
        other.surname = nullptr;

        other.age = 0;

        other.pagecount = 0;
    }

    static int getCurrentId() {
        return id;
    }

    void setCurrentId(static int id) {
        assert(id > 0);
        this->worker_id = ++id;
    }

    char* getName() const {
        return name;
    }

    void setName(const char* name) {
        assert(name != nullptr);
        int l = strlen(name);
        this->name = new char[l + 1];
        strcpy_s(this->name, l + 1, name);
    }

    char* getSurname() const {
        return surname;
    }

    void setSurname(const char* surname) {
        assert(surname != nullptr);
        int l = strlen(surname);
        this->surname = new char[l + 1];
        strcpy_s(this->surname, l + 1, surname);
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;

    }

    int getPagecount() const {
        return pagecount;
    }

    void setPagecount(int pagecount) {
        this->pagecount = pagecount;

    }

    void show() {
        cout << " Worker's ID: \t\t\t" << this->worker_id << endl;
        cout << " Worker's name: \t\t" << getName() << endl;
        cout << " Worker's surname: \t\t" << getSurname() << endl;
        cout << " Worker's age: \t\t\t" << getAge() << endl;
        cout << " Worker's pagecount: \t\t" << getPagecount() << endl;
        cout << endl;

    }

    ~Worker()
    {
        delete[]name;
        delete[]surname;
    }
};


int Worker::id = 0;


template<typename Worker_Queue>
class Printer_Queue {

    Worker_Queue* data;
    int capacity;
    int front;
    int rear;
    int count;

public:


    Printer_Queue(int size) {

        data = new Worker_Queue[size];

        capacity = size;
        front = 0;
        rear = 0;
        count = 0;
    }



    Printer_Queue& operator=(const Printer_Queue& other)
    {

        this->data = new Worker_Queue[other.count];
        for (int i = 0; i < other.count; i++) {
            this->data[i] = other.data[i];
        }

        this->capacity = other.capacity;
        this->front = other.front;
        this->rear = other.rear;
        this->count = other.count;



        return *this;
    }




    void enqueue(Worker_Queue value) {
        assert(!isFull() && " Queue is full ");
        data[rear] = value;
        ++rear;
        count++;
    }





    void dequeue() {
        if (!isEmpty()) {
            auto temp = new Worker_Queue[size() - 1];
            for (size_t i = 0; i < count - 1; i++)
            {
                temp[i] = data[i + 1];
            }
            delete[]data;
            data = temp;
            temp = nullptr;
            count--;
        }
    }



    Worker_Queue& peek() {
        return data[front];
    }



    int size() {
        return count;
    }



    bool isEmpty() {
        return size() == 0;
    };



    bool isFull() {
        return size() == capacity;
    }

    void queueDisplay()
    {
        int i;
        if (front == rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        // traverse front to rear and print elements 
        for (i = front; i < count; i++) {
            printf(" %d ", data[i]);
        }
        return;
    }

    void showPrinter() {
        while (!isEmpty())
        {

            for (size_t i = 0; i < size(); i++)
            {

            }


        }
    }


    ~Printer_Queue()
    {

        if (data != nullptr) {
            delete[]data;
            data = nullptr;
        }
    }
};


void print() {
    Worker w1("Elcin", "Mahirli", 27, 200);
    Worker w2("Arif", "Zeynalli", 22, 120);
    Worker_Queue<Worker>* morning_shift = new Worker_Queue<Worker>(2);
    morning_shift->enqueue(w1);
    morning_shift->enqueue(w2);


    Worker w3("Hesen", "Memmedov", 25, 100);
    Worker w4("Aynure", "Mahirli", 23, 100);
    Worker_Queue<Worker>* noon_shift = new Worker_Queue<Worker>(2);
    noon_shift->enqueue(w3);
    noon_shift->enqueue(w4);
    Worker_Queue<Worker>** shift_Table = new Worker_Queue<Worker> *[2]{ morning_shift, noon_shift };

    Printer_Queue < Worker_Queue<Worker>>* printer = new Printer_Queue< Worker_Queue<Worker>>(2);
    printer->enqueue(*morning_shift);
    printer->enqueue(*noon_shift);



    cout << " Table of using for printer " << endl << endl;
    while (!printer->isEmpty()) {
        Worker_Queue<Worker > shift = printer->peek();
        while (!shift.isEmpty()) {
            Worker workers = shift.peek();
            workers.show();
            shift.dequeue();
        }
        printer->dequeue();
    }
    cout << " ================================================================== \n";

}





int main() {

    print();
}






