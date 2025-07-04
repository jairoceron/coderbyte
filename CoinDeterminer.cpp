#include <iostream>

int main()
{


    /**
 * Using the Java language, have the function CoinDeterminer(num) take the input, which will be an integer ranging
 * from 1 to 250, and return an integer output that will specify the least number of coins, that when added,
 * equal the input integer. Coins are based on a system as follows: there are coins representing the integers
 * 1, 5, 7, 9, and 11. So for example: if num is 16, then the output should be 2 because you can achieve the
 * number 16 with the coins 9 and 7. If num is 25, then the output should be 3 because you can achieve 25 with
 * either 11, 9, and 5 coins or with 9, 9, and 7 coins.
 *
 * @author jairo ceron jairoceron@gmail.com
 */

    int arrCoin[6] = {11,9, 7, 5,  1};
    int num = 196;
   // num = 8;
     num = 25;
    int coint = -1;
    int sumCoint = 0;

    std::cout << " input " << num << " " << std::endl;

    for (int i = 0; i < 5; i++)
    {

        coint = 0;
        while (coint * arrCoin[i] <= num)
        {

            coint++;
        }
        coint--;
        sumCoint += coint;
        num = num - (coint * arrCoin[i]);
    }
    std::cout << " output " << sumCoint << std::endl;

    return 0;
}