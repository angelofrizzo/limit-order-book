#include <iostream>
#include <queue>

using OrderId = unsigned int;
using Price = double;
using Volume = unsigned int;

enum class Side{
    Buy,
    Sell
};

class Order{
    Price _price;
    Volume _volume;
    Side _side;

    public:
        Order(Price price, Volume volume, Side side) : _price{price}, _volume{volume}, _side{side} {}

        Price getPrice() const {return _price;}
        Volume getVolume() const {return _volume;}
        Side getSide() const {return _side;}
};

struct compareBid{
    bool operator()(const Order& firstOrder, const Order& secondOrder){
        return firstOrder.getPrice() <= secondOrder.getPrice();
    };
};

struct compareAsk{
    bool operator()(const Order& firstOrder, const Order& secondOrder){
        return secondOrder.getPrice() <= firstOrder.getPrice();
    };
};

class OrderBook{
    std::priority_queue<Order, std::vector<Order>, compareBid> bestBid;
    std::priority_queue<Order, std::vector<Order>, compareAsk> bestAsk;

    public:
        void PlaceOrder(Order order){
            switch(order.getSide()){
                case Side::Buy:
                    bestBid.push(order);
                    std::cout << "Best bid is: " << bestBid.top().getPrice() << std::endl;
                    break;
                case Side::Sell:
                    bestAsk.push(order);
                    std::cout << "Best ask is: " << bestAsk.top().getPrice() << std::endl;
            }
        };

        void CancelOrder(OrderId orderId){

        };

        void GetVolumeAtPrice(Price price, Side side){

        };
};

int main(){
    OrderBook orderBook;

    orderBook.PlaceOrder(Order(100, 50, Side::Buy));
    orderBook.PlaceOrder(Order(200, 20, Side::Buy));
    orderBook.PlaceOrder(Order(150, 100, Side::Sell));
    orderBook.PlaceOrder(Order(250, 50, Side::Sell));
    orderBook.PlaceOrder(Order(150, 200, Side::Buy));
}