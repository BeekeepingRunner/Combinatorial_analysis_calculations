// Combinatorial_Analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <vector>

int toInt(std::vector<char> number)
{
    int numLength = number.size();
    int multiplier{ 1 };
    int outInt{ 0 };

    for (int i = 0; i < numLength; ++i)
    {
        int digit{ static_cast<int>(number.back()) - 48 };
        number.pop_back();

        outInt += digit * multiplier;
        multiplier *= 10;
    }

    return outInt;
}

void numInput(int& x)
{
    std::vector<char> number;
    bool isCorrect{ false };

    while (!isCorrect)
    {
        char c{};
        std::cin.get(c);

        if (c == '0')
        {
            std::cout << "Wrong input, try again\n:";
            continue;
        }

        while (c != '\n')
        {
            if (c < 48 || c > 57)
            {
                number.clear();
                isCorrect = false;
                std::cout << "Wrong input, try again\n:";
                break;
            }

            number.push_back(c);
            std::cin.get(c);
        }

        isCorrect = true;
    }

    x = toInt(number);
}

int main()
{

    std::cout << "Enter two numbers\n";
    std::cout << "First number: ";
    int x{};
    numInput(x);

    std::cout << "Second number: ";
    int y{};
    numInput(y);

    // calculation choice
    // calculation execution
    // result printing

    // everyone happy
    
    return 0;
}

