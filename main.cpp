#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    double salary;

public:
    Employee(std::string n, double s) {
        name = n;
        salary = s;
    }

    void showInfo() const {
        std::cout << "Працівник: " << name << ", Базова заробітна плата: " << salary << " грн\n";
    }

    void work() const {
        std::cout << "Працівник виконує загальні обов'язки.\n";
    }
};

class Programmer : public Employee {
private:
    std::string mainLanguage;

public:
    Programmer(std::string n, double s, std::string language)
        : Employee(n, s), mainLanguage(language) {}

    void work() {
        std::cout << name << " пише програмний код на мові " << mainLanguage << ".\n";
    }
};

class Designer : public Employee {
private:
    std::string designTool;

public:
    Designer(std::string n, double s, std::string tool)
        : Employee(n, s), designTool(tool) {}

    void work() {
        std::cout << name << " створює інтерфейси та графіку у програмі " << designTool << ".\n";
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(std::string n, double s, int size)
        : Employee(n, s), teamSize(size) {}

    void work() const {
        std::cout << name << " організовує роботу команди з " << teamSize << " осіб.\n";
    }
};

int main() {
    Programmer programmer("Sanya", 48000, "C++");
    Designer designer("Julia", 42000, "Figma");
    Manager manager("Vasya", 55000, 6);

    programmer.showInfo();
    programmer.work();
    std::cout << "=== programmer ===\n";

    designer.showInfo();
    designer.work();
    std::cout << "=== designer ===\n";

    manager.showInfo();
    manager.work();
    std::cout << "=== manager ===\n";

    return 0;
}
