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

enum class Operation {
    PERMUTATION,
    COMBINATION
};

Operation operationChoice()
{
    std::cout << "Select from available operations\n";
    std::cout << "1. Permutation (without repetition)\n";
    std::cout << "2. Combination (without repetition)\n";
    std::cout << "(enter option number): ";

    char option{};
    while (true)
    {
        std::cin >> option;
        switch (option)
        {
        case '1':
            return Operation::PERMUTATION;
        case '2':
            return Operation::COMBINATION;
        default:
            std::cout << "Wrong input, try again: ";
        }
    }
}

int factorial(int x)
{
    if (x == 0)
        return 1;

    int i{ x };

    while (i > 1)
    {
        --i;
        x *= i;
    }

    return x;
}

int permutation(int x, int y)
{
    return factorial(x) / factorial(x - y);
}

int calculate(int x, int y, Operation op)
{
    int result{};
    switch (op)
    {
    case Operation::PERMUTATION:
        result = permutation(x, y);
        break;
    case Operation::COMBINATION:
        result = permutation(x, y) / factorial(y);
        break;
    default:
        break;
    }

    return result;
}

void printResult(int x, int y, int result, Operation op)
{
    switch (op)
    {
    case Operation::PERMUTATION:
        std::cout << "A number of " << y << "-element permutations (without repetition) from "
            << x << "-element set equals " << result << '\n';
        break;
    case Operation::COMBINATION:
        std::cout << "A number of " << y << "-element combinations (without repetition) from "
            << x << "-element set equals " << result << '\n';
        break;
    }
}

int main()
{
    // wrap everything in loop and ask for repetition

    // numbers input
    std::cout << "Enter two natural numbers\n";
    std::cout << "First number (n): ";
    int x{};
    numInput(x);

    std::cout << "Second number (k): ";
    int y{};
    numInput(y);
    std::cout << std::endl;

    // calculation choice
    Operation oper{ operationChoice() };
    // calculation execution
    int result{ calculate(x, y, oper) };
    // print result
    printResult(x, y, result, oper);

    // everyone happy
    
    return 0;
}

