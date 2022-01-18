#ifndef _ROOM_H
#define _ROOM_H

const int DAY_LIMITS = 10;

class Room {
private:
    int unit;

    int days;

protected:
    float discount;

public:
    Room() {

    }

    Room(int u, float di) {
        this->unit = u;
        this->discount = di;
    }

    void setDays(int d) {
        if (d > 0) {
            this->days = d;
        } else {
            this->days = 0;
        }
    }

    float price() {
        float price;
        if (this->days >= DAY_LIMITS) {
            price = (1 - this->discount) * this->unit * this->days;
        } else {
            price = this->unit * this->days;
        }

        return price;
    }


};

class RoomA : public Room {
public:
    RoomA() : Room(300, 0.1) {

    }
};

class RoomB : public Room {
public:
    RoomB() : Room(200, 0.1) {

    }

};

class RoomC : public Room {
public:
    RoomC() : Room(100, 0) {

    }
};

#endif // _ROOM_H