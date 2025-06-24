#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

class BlackjackHighest
{
public:
    string val = "";
    int valueMin = 0;
    int valueMax = 0;

    void setInput(string val, int valueMin, int valueMax)
    {
        this->val = val;
        this->valueMin = valueMin;
        this->valueMax = valueMax;
    }
};

string cardMajor(BlackjackHighest arrBlackJack[], int sizeArBlck, string testCase[3], int sizetest, bool ace)
{
    int major = 0;
    string majorStr = "";
    for (int i = 0; i < sizetest; i++)
    {
       // std::cout << " input " << testCase[i] << " " << std::endl;
        for (int j = 0; j < sizeArBlck; j++)
        {

            if (ace && (testCase[i] == "ace"))
            {
                arrBlackJack[j].valueMax = arrBlackJack[j].valueMin; // if ace is present, we count it as 1
            }

            if (testCase[i] == arrBlackJack[j].val)
            {
                // sum += arrBlackJack[j].valueMin;
                if (arrBlackJack[j].valueMax > major)
                {
                    major = arrBlackJack[j].valueMax;
                    majorStr = arrBlackJack[j].val;
                }
            }
        }
    }
    return majorStr;
}

bool findAce(string testCase[3], int sizetest, string ace)
{

    bool returnX = false;
    for (int i = 0; i < sizetest; i++)
    {

        if (ace == testCase[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{

    /**
  * Using the Java language, have the function BlackjackHighest(strArr) take the strArr parameter being passed which will
  * be an array of numbers and letters representing blackjack cards. Numbers in the array will be written out.
  * So for example strArr may be ["two","three","ace","king"]. The full list of possibilities for strArr is: two, three,
  * four, five, six, seven, eight, nine, ten, jack, queen, king, ace. Your program should output below, above,
  * or blackjack signifying if you have blackjack (numbers add up to 21) or not and the highest card in your hand in
  * relation to whether or not you have blackjack. If the array contains an ace but your hand will go above 21, you must
  * count the ace as a 1. You must always try and stay below the 21 mark. So using the array mentioned above, the output
  * should be below king. The ace is counted as a 1 in this example because if it wasn't you would be above the 21 mark.
  * Another example would be if strArr was ["four","ten","king"], the output here should be above king. If you have a
  * tie between a ten and a face card in your hand, return the face card as the "highest card". If you have multiple
  * face cards, the order of importance is jack, queen, then king.
  *

  * @author jairo ceron jairoceron@gmail.com
  */

    //   string arr[13] = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
   // string testCase[3] = {"four", "ten", "king"};
    string testCase[2] ={"jack","ace"};
    int num = 21;

    BlackjackHighest blackjackHighest1;
    blackjackHighest1.setInput("two", 2, 2);
    BlackjackHighest blackjackHighest2;
    blackjackHighest2.setInput("three", 3, 3);
    BlackjackHighest blackjackHighest3;
    blackjackHighest3.setInput("four", 4, 4);
    BlackjackHighest blackjackHighest4;
    blackjackHighest4.setInput("five", 5, 5);
    BlackjackHighest blackjackHighest5;
    blackjackHighest5.setInput("six", 6, 6);
    BlackjackHighest blackjackHighest6;
    blackjackHighest6.setInput("seven", 7, 7);
    BlackjackHighest blackjackHighest7;
    blackjackHighest7.setInput("eight", 8, 8);
    BlackjackHighest blackjackHighest8;
    blackjackHighest8.setInput("nine", 9, 9);
    BlackjackHighest blackjackHighest9;
    blackjackHighest9.setInput("ten", 10, 10);
    BlackjackHighest blackjackHighest10;
    blackjackHighest10.setInput("jack", 10, 14);
    BlackjackHighest blackjackHighest11;
    blackjackHighest11.setInput("queen", 10, 13);
    BlackjackHighest blackjackHighest12;
    blackjackHighest12.setInput("king", 10, 12);
    BlackjackHighest blackjackHighest13;
    blackjackHighest13.setInput("ace", 11, 15);
    BlackjackHighest arrBlackJack[13] = {blackjackHighest1, blackjackHighest2, blackjackHighest3, blackjackHighest4, blackjackHighest5,
                                         blackjackHighest6, blackjackHighest7, blackjackHighest8, blackjackHighest9,
                                         blackjackHighest10, blackjackHighest11, blackjackHighest12, blackjackHighest13};

  //  std::cout << " input " << num << " " << std::endl;
    int sum = 0;

    for (int i = 0; i < size(testCase); i++)
    {
       // std::cout << " input " << testCase[i] << " " << std::endl;
        for (int j = 0; j < size(arrBlackJack); j++)
        {
            if (testCase[i] == arrBlackJack[j].val)
            {
                sum += arrBlackJack[j].valueMin;
             //   std::cout << " outputXX " << arrBlackJack[j].val << std::endl;
            }
        }
    }

    bool boolAce = findAce(testCase, size(testCase), "ace");
    string majorX = "";
    if ((sum > num) && boolAce)
    {
        sum = sum - 10; // if the sum is above 21 and there is an ace, we count it as 1
        majorX = cardMajor(arrBlackJack, size(arrBlackJack), testCase, size(testCase), true);
    } else {

       majorX = cardMajor(arrBlackJack, size(arrBlackJack), testCase, size(testCase), false);

    }

    if (sum > num)
    {
        std::cout << "above " << majorX << std::endl;
    }
    else if (sum == num)
    {
        std::cout << "" << "blackjack " << majorX << std::endl;
    }
    else
    {
        std::cout << "below " << majorX << std::endl;
    }
    return 0;
}