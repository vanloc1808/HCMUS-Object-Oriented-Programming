#ifndef _NORMALTHEATER_H_
#define _NORMALTHEATER_H_

const int CENTER_PRICE = 80;
const int REDUCE_PER_ROW = 3;

class NormalTheater {
protected:
    int m_row;
    int m_column;

    int** m_seatPrice;

    bool** m_seatStatus;

public:
    static double totalIncome;

public:
    //default constructor
    NormalTheater();
    //fully-parameterized constructor
    NormalTheater(int row, int column);
    //copy constructor
    NormalTheater(const NormalTheater& p);

    //destructor
    ~NormalTheater();

    //assigning operator
    NormalTheater& operator=(const NormalTheater& p);

    //show that if a set is available for booking
    bool isEmptySeat(int row, int column);

    double price(int row, int column);

    bool bookSeat(int row, int column, double discount = 0);

    int totalMoney();
};

void setPriceAndStatus(int** price, bool** status, int row, int column, int centerPrice, int reducePrice);

#endif