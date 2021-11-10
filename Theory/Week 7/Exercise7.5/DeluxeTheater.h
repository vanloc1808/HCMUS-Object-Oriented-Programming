#ifndef _DELUXETHEATER_H_
#define _DELUXETHEATER_H_

#include "NormalTheater.h"
#include <ctime>

const int DELUXE_CENTER_PRICE = 120;
const double DISCOUNT_ON_THURSDAY = 0.2;

class DeluxeTheater : public NormalTheater
{
public:
    DeluxeTheater() : NormalTheater()
    {
        
    }

    DeluxeTheater(int row, int column) : NormalTheater() {
    if (row < 0) {
        row = 0;
    }
    if (column < 0) {
        column = 0;
    }

    this->m_row = row;
    this->m_column = column;

    //allocate memory for seatPrice and seatStatus
    this->m_seatPrice = new int*[row];
    for (int i = 0; i < row; i++) {
        this->m_seatPrice[i] = new int[column];
    }
    this->m_seatStatus = new bool*[row];
    for (int i = 0; i < row; i++) {
        this->m_seatStatus[i] = new bool[column];
    }

    //set the price and status of each seat
    setPriceAndStatus(this->m_seatPrice, this->m_seatStatus, row, column, DELUXE_CENTER_PRICE, REDUCE_PER_ROW);
    }

    DeluxeTheater(const DeluxeTheater& p) : NormalTheater(p)
    {
        
    }

    double price(int row, int column) {
        double ans = NormalTheater::price(row, column);

        double discount = 0;
        
        time_t now = time(0);
        tm* local = localtime(&now);
        if (local->tm_wday == 4) {
            discount = DISCOUNT_ON_THURSDAY;
        }
        else {
            discount = 0;
        }

        ans = ans * (1 - discount);

        return ans;
    }

    bool bookSeat(int row, int column, double discount = DISCOUNT_ON_THURSDAY) {
        time_t now = time(0);
        tm* local = localtime(&now);
        if (local->tm_wday == 4) {
            discount = DISCOUNT_ON_THURSDAY;
        }
        else {
            discount = 0;
        }

        return NormalTheater::bookSeat(row, column, discount);
    }
};

#endif
