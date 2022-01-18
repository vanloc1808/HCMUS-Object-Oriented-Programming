#ifndef _HOTEL_H_
#define _HOTEL_H_

#include <iostream>
#include <vector>
#include "Room.h"

class Hotel {
private:
    std::vector<Room*> roomList;
public:
    Hotel() {

    };

    void input() {
        int n;
        std::cin >> n;

        Room* r;

        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;

            if (x == 1) {
                r = new RoomA();
            } else if (x == 2) {
                r = new RoomB();
            } else if (x == 3) {
                r = new RoomC();
            } else {
                std::cout << "Room type is invalid!\n";
            }

            int days;
            std::cin >> days;

            r->setDays(days);

            this->roomList.push_back(r);
        }
    }

    float totalIncome() {
        float sum = 0;
        for (int i = 0; i < this->roomList.size(); i++) {
            sum += this->roomList[i]->price();
        }

        return sum;
    }

};

#endif // _HOTEL_H_