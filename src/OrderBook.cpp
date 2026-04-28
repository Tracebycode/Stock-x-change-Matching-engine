#include "Order.h"

Order::Order(int id, std::string sym, double p, int qty, OrderType t, long time)
    : orderId(id), symbol(sym), price(p), quantity(qty), type(t), timestamp(time) {}