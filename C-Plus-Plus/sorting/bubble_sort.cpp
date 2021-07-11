#include <iostream>
#include <vector>

int main()
{
    int n;
    bool swap_check = true;
    std::cout << "Enter the amount of numbers to sort: ";
    std::cin >> n;
    std::vector<int> numbers;
    std::cout << "Enter " << n << " numbers: ";
    int num;

    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        numbers.push_back(num);
    }

    for (int i = 0; (i < n) && (swap_check); i++)
    {
        swap_check = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap_check = true;
                std::swap(numbers[j],
                          numbers[j + 1]);
            }
        }
    }

    std::cout << "\nSorted Array : ";
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i != numbers.size() - 1)
        {
            std::cout << numbers[i] << ", ";
        }
        else
        {
            std::cout << numbers[i] << std::endl;
        }
    }
    return 0;
}
