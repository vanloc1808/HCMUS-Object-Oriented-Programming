#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <iostream>
#include <vector>
#include "Land.h"

class Company {
private:
    std::vector<Land*> landList;

public:
    void input() {
        int n;
        std::cin >> n;

        Land* c;
        
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (x == 0) {
                c = new RectangleLand();
            } else {
                c = new TrapeziumLand();
            }

            c->input();

            this->landList.push_back(c);
        }
    }

    float totalArea() {
        float sum = 0;
        
        for (int i = 0; i < this->landList.size(); i++) {
            sum += this->landList[i]->area();
        }

        return sum;
    }

    float totalPrice() {
        float sum = 0;
        
        for (int i = 0; i < this->landList.size(); i++) {
            sum += this->landList[i]->price();
        }

        return sum;
    }
};

#endif // _COMPANY_H_