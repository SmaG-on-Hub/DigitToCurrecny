#include <iostream>
#include <cmath>
#include <map>

std::map<long long, std::string> base_nums = {
        {1, "one"}, {2, "two"}, {3, "tree"}, {4, "four"}, {5, "five"},
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
        {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
        {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"},
        {19, "nineteen"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"},
        {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}
    };

std::map<long long, std::string> places = {
        {0, "hundred"}, {1, "thousand"}, {2, "million"}, {3, "billion"}, {4, "trillion"}, {5, "quadrillion"}
    };

std::string make_str(long long number)
{
    std::string result;
    long long cur_numb = number;
    int place = 0;

    while (cur_numb >= 1000)
    {
        cur_numb /= 1000;
        place++;
    }

    int hundreds = cur_numb / 100;
    int dozens = cur_numb / 10 % 10;
    int ones = cur_numb % 10;

    if (hundreds)
    {
        result += base_nums[hundreds] + " ";
        result += places[0] + " ";
    }

    if ( base_nums.find(dozens * 10 + ones) != base_nums.end() && dozens == 1)
        result += base_nums[dozens * 10 + ones] + " ";
    else if (dozens && ones)
    {
        result += base_nums[dozens * 10];
        result += "-" + base_nums[ones] + " ";
    }
    else if (dozens)
        result += base_nums[dozens * 10] + " ";
    else if (ones)
        result +=  base_nums[ones] + " ";

    if (place)
    {
        long long tail = 1;
        for (int i = 0; i < place; i++)
            tail *= 1000;

        result += places[place] + " ";
        result += make_str(number % tail);
    }

    return result;
};

int main()
{
    long double numb;

    std::cin>> numb;

    std::string solid_part = make_str((long long)(numb));
    std::string partial_part = make_str((int)std::round((std::fmod(numb, 1.00) * 100)));
    if (solid_part.length() > 1)
        std::cout << solid_part << "dollars ";
    if (partial_part.length() > 1)
        std::cout << partial_part<< "cents";

    return 0;
}
