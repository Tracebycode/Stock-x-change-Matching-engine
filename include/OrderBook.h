#pragma once
#include <vector>
#include <queue>
#include "Order.h"
using namespace std;


struct BuyComparator {
    bool operator()(const Order& a, const Order& b) {
        if(a.price == b.price) {
            return a.timestamp > b.timestamp; // Earlier orders have higher priority
        }
        return a.price < b.price; // Higher price has higher priority
       
    }
};


struct SellComparator {
    bool operator()(const Order& a, const Order& b) {

        if(a.price == b.price) {
            return a.timestamp > b.timestamp; // Earlier orders have higher priority
        }
        return a.price > b.price; // Lower price has higher priority
        
    }
};


class OrderBook {
    private:
        std::priority_queue<Order, std::vector<Order>, BuyComparator> buyOrders;
        std::priority_queue<Order, std::vector<Order>, SellComparator> sellOrders;


    public:
    void addOrder(const Order& order);
    void matchOrders();
    

    bool hasBuyOrders() const;
    bool hasSellOrders() const;

    Order getTopBuyOrder() const;
    Order getTopSellOrder() const;

    void removeTopBuyOrder();
    void removeTopSellOrder();

};


void OrderBook::addOrder(const Order& order) {
    if(order.type == BUY) {
        buyOrders.push(order);
    } else {
        sellOrders.push(order);
    }
}

bool OrderBook::hasBuyOrders() const {
    return !buyOrders.empty();
}


bool OrderBook::hasSellOrders() const {
    return !sellOrders.empty();
}


Order OrderBook::getTopBuyOrder() const {
    try
    {
        if(!buyOrders.empty()) {
            return buyOrders.top();
        }
    }
    catch(const std::exception& e)
    {
       
    }
    
   
    
}

Order OrderBook::getTopSellOrder() const {
    if(!sellOrders.empty()) {
        return sellOrders.top();
    }
}