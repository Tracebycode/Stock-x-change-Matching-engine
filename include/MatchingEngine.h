#pragma once 
#include "OrderBook.h"


class MatchingEngine {
    private:
        OrderBook orderBook;
        void matchOrders();

    public:
        void processOrder(const Order& order);
        void displayOrderBook() const;
};

