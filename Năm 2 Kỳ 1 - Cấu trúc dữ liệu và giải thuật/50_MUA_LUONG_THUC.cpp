#include <iostream>
#include <cmath>

int leastDaysNeedToBuyFood(const int foodBuyPerDay, const int daysNeedToEat, const int foodEatenPerDay)
{
    const int totalFoodNeeded = foodEatenPerDay * daysNeedToEat;
    const int daysBuyingFood = std::ceil((double)totalFoodNeeded / foodBuyPerDay);

    const int sundays = daysNeedToEat / 7;
    const int maxDaysCanBuyFood = daysNeedToEat - sundays;

    if (daysBuyingFood <= maxDaysCanBuyFood)
        return daysBuyingFood;
    return -1;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        int FoodBuyPerDay, daysNeedToEat, FoodEatenPerDay;
        std::cin >> FoodBuyPerDay >> daysNeedToEat >> FoodEatenPerDay;
        std::cout << leastDaysNeedToBuyFood(FoodBuyPerDay, daysNeedToEat, FoodEatenPerDay) << std::endl;
    }
}