#include <iostream>
#include <cstring>
#include <locale.h>
#include <vector>
#include "LinkedList.h"

class Bus {
protected:
    int number = 0;
    char name[100]{};
    int route = 0;
public:
    Bus() = default;

    Bus(int number, const char* name, int route) {
        this->number = number;
        this->route = route;
        this->name[0] = '\0';
        strcpy_s(this->name, name);
    }

    friend bool operator==(const Bus& lhs, const Bus& rhs) {
        return lhs.number == rhs.number;
    }

    friend bool operator!=(const Bus& lhs, const Bus& rhs) {
        return !(lhs.number == rhs.number);
    }

    friend std::ostream& operator<<(std::ostream& out, const Bus& bus) {
        out << "[" << bus.number << ' ' << bus.name << ' ' << bus.route << "]";
        return out;
    }
};

class Park {
    LinkedList<Bus> onpark;
    LinkedList<Bus> onroute;
public:
    Park() = default;
    ~Park() = default;

    // Функция для въезда автобуса в парк
    void enterPark(int number) {
        auto node = onroute.find(Bus(number, "", 0));
        if (node != nullptr) {
            Bus bus = node->d;
            onroute.remove(bus);
            onpark.add(bus);
        }
    }

    // Функция для выезда автобуса из парка
    void leavePark(int number) {
        auto node = onpark.find(Bus(number, "", 0));
        if (node != nullptr) {
            Bus bus = node->d;
            onpark.remove(bus);
            onroute.add(bus);
        }
    }

    // Функция для добавления автобуса в парк
    void add(Bus const& bus) {
        onpark.add(bus);
    }

    // Функция для вывода информации о парке и маршруте
    void print() {
        std::cout << "На маршруте: ";
        onroute.print();
        std::cout << "В парке: ";
        onpark.print();
    }

};


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Park park;

    std::vector<Bus> buses = {
        Bus(101, "Иванов И.И.", 7),
        Bus(102, "Петров П.П.", 3),
        Bus(103, "Сидоров С.С.", 1),
        Bus(104, "Кузнецов К.К.", 25)
    };

    for (const auto& bus : buses) {
        park.add(bus);
    }

    park.print();

    std::cout << std::endl;
    park.leavePark(101);

    park.print();

    std::cout << std::endl;
    park.enterPark(101);

    park.print();

    return 0;
}