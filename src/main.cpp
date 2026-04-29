#include "MatchingEngine.h"
#include "Order.h"
#include "OrderBook.h"

using namespace std;


 int main(){

    MatchingEngine engine;

    engine.processOrder(Order(1, "AAPL", 150.0, 100, BUY, 1));
    engine.processOrder(Order(2, "AAPL", 149.0, 50, SELL, 2));
    engine.processOrder(Order(3, "AAPL", 151.0, 200, BUY, 3));
    engine.processOrder(Order(4, "AAPL", 148.0, 100, SELL, 4));

        engine.displayOrderBook();



    













    return 0;
}