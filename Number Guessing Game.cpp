#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int secretNumber = std::rand() % 111 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Number Guessing Game!!!" << std::endl;
    std::cout << "I've picked a random number between 1 and 111. Try to guess it." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "You've guessed the Secret number " << secretNumber << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}

