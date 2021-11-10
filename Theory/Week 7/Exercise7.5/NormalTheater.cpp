#include <iostream>
#include <cmath>
#include "NormalTheater.h"

NormalTheater::NormalTheater() {
    this->m_row = 0;
    this->m_column = 0;
    this->m_seatPrice = nullptr;
    this->m_seatStatus = nullptr;
}

//this is a subfunction of the fully-parameterized constructor
void setPriceAndStatus(int** price, bool** status, int row, int column, int centerPrice, int reducePrice) {
    if (row % 2 == 0) {
        //if row is even, we have two central rows, so price in these two rows are equal to CENTER_PRICE
        for (int i = 0; i < row / 2 - 1; i++) {
            int priceThisRow = centerPrice - (row / 2 - 1 - i) * reducePrice;
            for (int j = 0; j < column; j++) {
                price[i][j] = priceThisRow;
                status[i][j] = true;
            }
        }
        for (int i = row / 2; i < row; i++) {
            int priceThisRow = centerPrice - (i - row / 2) * reducePrice;
            for (int j = 0; j < column; j++) {
                price[i][j] = priceThisRow;
                status[i][j] = true;
            }
        }
    } else {
        //if row is odd, we have only one central rows
        for (int i = 0; i < row; i++) {
            int priceThisRow = centerPrice - (abs(i - row / 2)) * reducePrice;
            for (int j = 0; j < column; j++) {
                price[i][j] = priceThisRow;
                status[i][j] = true;
            }
        }
    }
}

NormalTheater::NormalTheater(int row, int column) {
    //ensure that row and column are nonnegative
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
    setPriceAndStatus(this->m_seatPrice, this->m_seatStatus, row, column, CENTER_PRICE, REDUCE_PER_ROW);
}

NormalTheater::NormalTheater(const NormalTheater& p) {
    this->m_row = p.m_row;
    this->m_column = p.m_column;

    //allocate memory
    this->m_seatPrice = new int*[this->m_row];
    this->m_seatStatus = new bool*[this->m_row];
    for (int i = 0; i < this->m_row; i++) {
        this->m_seatPrice[i] = new int[this->m_column];
        this->m_seatStatus[i] = new bool[this->m_column];
    }

    //copy the data
    for (int i = 0; i < this->m_row; i++) {
        for (int j = 0; j < this->m_column; j++) {
            this->m_seatPrice[i][j] = p.m_seatPrice[i][j];
            this->m_seatStatus[i][j] = p.m_seatStatus[i][j];
        }
    } 
}

NormalTheater::~NormalTheater() {
    //deallocate memory
    for (int i = 0; i < this->m_row; i++) {
        if(this->m_seatPrice[i]) {
            delete[] this->m_seatPrice[i];
        }
        if (this->m_seatStatus[i]) {
            delete[] this->m_seatStatus[i];
        }
    }

    if (this->m_seatPrice) {
        delete[] this->m_seatPrice;
    }

    if (this->m_seatStatus) {
        delete[] this->m_seatStatus;
    }
}


NormalTheater& NormalTheater::operator=(const NormalTheater& p) {
    if (this != &p) {
        //deallocate memory
        for (int i = 0; i < this->m_row; i++) {
            if (this->m_seatPrice[i]) {
               delete[] this->m_seatPrice[i]; 
            }

            if (this->m_seatStatus[i]) {
                delete[] this->m_seatStatus[i];
            }
        }

        if (this->m_seatPrice) {
            delete[] this->m_seatPrice;
        }

        if (this->m_seatStatus) {
            delete[] this->m_seatStatus;
        }

        this->m_row = p.m_row;
        this->m_column = p.m_column;

        //allocate memory
        this->m_seatPrice = new int*[this->m_row];
        this->m_seatStatus = new bool*[this->m_row];
        for (int i = 0; i < this->m_row; i++) {
            this->m_seatPrice[i] = new int[this->m_column];
            this->m_seatStatus[i] = new bool[this->m_column];
        }

        //copy the data
        for (int i = 0; i < this->m_row; i++) {
            for (int j = 0; j < this->m_column; j++) {
                this->m_seatPrice[i][j] = p.m_seatPrice[i][j];
                this->m_seatStatus[i][j] = p.m_seatStatus[i][j];
            }
        } 
    }
}

bool NormalTheater::isEmptySeat(int row, int column) {
    return this->m_seatStatus[row][column];
}

double NormalTheater::price(int row, int column) {
    return (double)this->m_seatPrice[row][column];
}

bool NormalTheater::bookSeat(int row, int column, double discount) {
    if (row < 0 || row >= this->m_row || column < 0 || column >= this->m_column) {
        return false;
    }

    if (this->m_seatStatus[row][column] == false) {
        return false;
    }

    NormalTheater::totalIncome += 1.00 * (1 - discount) * this->m_seatPrice[row][column];
    this->m_seatStatus[row][column] = false;

    return true;
}

int NormalTheater::totalMoney() {
    return NormalTheater::totalIncome;
}