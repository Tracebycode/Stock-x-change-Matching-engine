#include "OrderBook.h"
#include <iostream>
using namespace std;






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


void OrderBook::removeTopBuyOrder() {
    if(!buyOrders.empty()) {
        buyOrders.pop();
    }
}

void OrderBook::removeTopSellOrder() {
    if(!sellOrders.empty()) {
        sellOrders.pop();
    }
}


void OrderBook::displayOrderBook() const {
    cout << "Buy Orders:" << endl;
    auto tempBuy = buyOrders; // Create a copy to display without modifying the original
    while(!tempBuy.empty()) {
        Order o = tempBuy.top();
        cout << "ID: " << o.orderId << ", Symbol: " << o.symbol << ", Price: $" << o.price 
             << ", Quantity: " << o.quantity << ", Timestamp: " << o.timestamp << endl;
        tempBuy.pop();
    }

    cout << "\nSell Orders:" << endl;
    auto tempSell = sellOrders; // Create a copy to display without modifying the original
    while(!tempSell.empty()) {
        Order o = tempSell.top();
        cout << "ID: " << o.orderId << ", Symbol: " << o.symbol << ", Price: $" << o.price 
             << ", Quantity: " << o.quantity << ", Timestamp: " << o.timestamp << endl;
        tempSell.pop();
    }
}

