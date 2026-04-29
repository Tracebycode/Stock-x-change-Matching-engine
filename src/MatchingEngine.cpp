#include <MatchingEngine.h>
#include <iostream>
using namespace std;


void MatchingEngine::processOrder(const Order& order) {
    orderBook.addOrder(order);
    matchOrders();
}

void MatchingEngine::displayOrderBook() const {
    orderBook.displayOrderBook();
}

void MatchingEngine::matchOrders() {
    while(orderBook.hasBuyOrders() && orderBook.hasSellOrders()) {
        Order topBuy = orderBook.getTopBuyOrder();
        Order topSell = orderBook.getTopSellOrder();

        if(topBuy.price>= topSell.price){
            int tradequantity = min(topBuy.quantity, topSell.quantity);
            double tradePrice = topSell.price; // Trade at the sell price
            // Update quantities
            topBuy.quantity -= tradequantity;
            topSell.quantity -= tradequantity;
            // Remove orders if fully filled
            if(topBuy.quantity == 0) {
                orderBook.removeTopBuyOrder();
            } else {
                // Update the top buy order with the remaining quantity
                orderBook.removeTopBuyOrder();
                orderBook.addOrder(topBuy);
            }

            //sell order is fully filled
            if(topSell.quantity == 0) {
                orderBook.removeTopSellOrder();
            } else {
                // Update the top sell order with the remaining quantity
                orderBook.removeTopSellOrder();
                orderBook.addOrder(topSell);
            }


            cout << "Trade executed: " << tradequantity << " shares at $" << tradePrice << endl;


        }else{
            break; // No more matches possible
        }

      
    }
}