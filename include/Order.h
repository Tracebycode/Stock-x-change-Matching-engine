#pragma once
#include <string>

enum OrderType {
    BUY,
    SELL
};

struct Order {
    int orderId;
    std::string symbol;
    double price;
    int quantity;
    OrderType type;
    long timestamp;

    Order(int id, std::string sym, double p, int qty, OrderType t, long time);
};