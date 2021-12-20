#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductEmployee.h"
#include "DailyEmployee.h"
#include "Manager.h"

using namespace std;


int main(){
    const int count = 6;
    auto a = new Employee*[count];

    a[0] = new ProductEmployee("Long", 2500, 400);
    a[1] = new ProductEmployee("Minh", 3000, 150);
    a[2] = new DailyEmployee("Tuan", 250000, 25);
    a[3] = new DailyEmployee("Kiet", 380000, 18);
    a[4] = new Manager("Chinh", 3300000, 2);
    a[5] = new Manager("Vu", 3700000, 3);

    cout << "Luong cua cac nhan vien la: " << endl;

    for (auto i = 0; i < count; i++){
        cout << a[i]->FullName() << ": ";
        cout << a[i]->CalcSalary() << endl;
    }

    cout << "Thuong cua cac nhan vien la: " << endl;

    for (auto i = 0; i < count; i++) {
        cout << a[i]->FullName() << ": ";
        cout << a[i]->CalcBonus() << endl;
    }

    cout << "Phat cua cac nhan vien la: " << endl;

    for (auto i = 0; i < count; i++) {
        cout << a[i]->FullName() << ": ";
        cout << a[i]->CalcPenalty() << endl;
    }
    
    for (auto i = 0; i < count; i++){
        delete a[i];
    }

    delete[] a;

}