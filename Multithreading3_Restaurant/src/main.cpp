#include <thread>
#include <vector>
#include "restaurant.h"


int main()
{
    std::vector <dishes> orders;
    std::vector <dishes> readyDishes;

    std::thread order(newOrder, &orders);
    std::thread kitchen(kitchenWork, &orders, &readyDishes);
    std::thread delivery(deliveryWork, &readyDishes);

    order.detach();
    kitchen.detach();
    delivery.join();
    return 0;
}
