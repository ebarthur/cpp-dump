#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

typedef int two_dpi;
enum selection { DOUBLE_NUMBER = 1, REVERSE_DIGITS, RAISE_TO_POWER, SUM_DIGITS, RAISE_FIRST_TO_SECOND};

int random() {

    return rand() % 90 + 10;
    // Generate a random two-digit positive integer
}

bool is_prime(two_dpi num) {

    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void double_number(two_dpi & num) {
    num *= 2;
    if (num < 10) {
        num += 10;
    }
}

void reverse_digits(two_dpi & num) {
    int reverse_num = 0;
    int digit;
    while (num > 0) {
        digit = num % 10;
        reverse_num = reverse_num * 10 + digit;
        num /= 10;
    }
    num = reverse_num;
    if (num < 10) {
        num += 10;
    }
}

void raise_power(two_dpi & num) {
    int exponent;
    std::cout << "Enter the exponent (2, 3, or 4): ";
    std::cin >> exponent;
    num = pow(num, exponent);
    if (num < 10) {
        num += 10;
    }
}

void sum_digits(two_dpi & num) {
    int sum = 0;
    int digit;
    while (num > 0) {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }
    num = sum;
    if (num < 10) {
        num += 10;
    }
}

void raise_1st_to_2nd(two_dpi & num) {
    if (num >= 10 && num <= 99) {
        int first_digit = num / 10;
        int second_digit = num % 10;
        num = pow(first_digit, second_digit);
        if (num < 10) {
            num += 10;
        }
    } else {
        std::cout << "Invalid operation for the current number!" << std::endl;
    }
}

void raise_1st2_to_last(two_dpi & num) {
    if (num >= 100 && num <= 999) {
        int first_two_digits = num / 10;
        int last_digit = num % 10;
        if (last_digit <= 4) {
            num = pow(first_two_digits, last_digit);
            if (num < 10) {
                num += 10;
            }
        } else {
            std::cout << "Invalid operation for the current number!" << std::endl;
        }
    } else {
        std::cout << "Invalid operation for the current number!" << std::endl;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    two_dpi num = random();
    std::cout << "Initial two-digit positive integer: " << num << std::endl;

    bool isExit = false;
    while (!isExit) {
        std::cout << "Select an operation:" << std::endl;
        std::cout << "1. Double the number" << std::endl;
        std::cout << "2. Reverse number digits" << std::endl;
        std::cout << "3. Raise to power of 2, 3, or 4" << std::endl;
        std::cout << "4. Sum the number digits" << std::endl;

        if (num >= 10 && num <= 99) {
            std::cout << "5. If the number is a two-digit number, raise the first digit to the power of the second digit" << std::endl;
        } else if (num >= 100 && num <= 999) {
            std::cout << "5. If the number is a two-digit number, raise the first digit to the power of the second digit" << std::endl;
            std::cout << "6. If the number is a three-digit number and the last digit is less than or equal to 4, raise the first two digits to the power of the last digit" << std::endl;
        }

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case DOUBLE_NUMBER:
                double_number(num);
                break;
            case REVERSE_DIGITS:
                reverse_digits(num);
                break;
            case RAISE_TO_POWER:
                raise_power(num);
                break;
            case SUM_DIGITS:
                sum_digits(num);
                break;
            case RAISE_FIRST_TO_SECOND:
                raise_1st_to_2nd(num);
                break;
            case 6:
                raise_1st2_to_last(num);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }

        std::cout << "Current number: " << num << std::endl;
    }
}
