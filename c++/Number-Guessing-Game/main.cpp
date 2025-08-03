#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to print the welcome message
void printWelcomeMessage() {
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;
    std::cout << "You have N chances to guess the correct number." << std::endl;
}

// Function to prompt user to play or quit
int playOrQuitMessage() {
    int choice;
    std::cout << "Press 1 to Play" << std::endl;
    std::cout << "Press 2 to Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    return choice;
}

// Function to select the difficulty level
int difficultyMessage() {
    int difficultyLevel = 0;
    std::cout << "Please select the difficulty level:" << std::endl;
    std::cout << "1 Easy (10 chances)" << std::endl;
    std::cout << "2 Medium (5 chances)" << std::endl;
    std::cout << "3 Hard (3 chances)" << std::endl;
    std::cout << std::endl;
    std::cout << "Difficulty level: ";
    std::cin >> difficultyLevel;
    return difficultyLevel;
}

// Function to return the number of chances based on difficulty
int numberOfChances(int input) {
    int chance = 0;
    switch (input) {
        case 1: chance = 10; break;
        case 2: chance = 5; break;
        case 3: chance = 3; break;
        default: chance = 0;
    }
    return chance;
}

// Function to generate a random number between 1 and 100
int getRandomNumber() {
    srand(time(0)); // Seed the random number generator
    int randomNumber = (std::rand() % 100) + 1;
    return randomNumber;
}

// Function to give feedback on the user's guess
void guessed(int n, int rn, int a, int c) {
    if (n < rn && c != 0) {
        std::cout << "Incorrect, the number is greater than " << n << std::endl;
    } else if (n > rn && c != 0) {
        std::cout << "Incorrect, the number is less than " << n << std::endl;
    } else if (n == rn && c != 0) {
        std::cout << "Congratulations! You guessed the correct number in " << a << " attempts." << std::endl;
    } else {
        std::cout << "Sorry, you ran out of chances." << std::endl;
    }
}

// Main game logic
void startGame() {
    int guess = 0, chances = 0, dl = 0, attempts = 0, rn = 0, choice = 0;
    std::string difficultyLevel[] = {"Easy", "Medium", "Hard"};
    char again = '\0';
    rn = getRandomNumber(); // Generate a random number at the start
    bool playing = true;

    do {
    	
        printWelcomeMessage();
        std::cout << std::endl;

        // Prompt to play or quit
        choice = playOrQuitMessage();
        std::cout << std::endl;

        if (choice == 2) {
            std::cout << "Exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        }

        std::cout << std::endl;

        // Select difficulty
        dl = difficultyMessage();
        std::cout << std::endl;

        // Validate difficulty selection
        while (dl < 1 || dl > 3) {
            std::cout << std::endl;
            std::cout << "Difficulty Level: Unknown  // Press 1, 2 or 3 to select difficulty";
            std::cout << std::endl << std::endl;
            dl = difficultyMessage();
            std::cout << std::endl;
        }

        // Assign number of chances based on difficulty
        chances = numberOfChances(dl);
        std::cout << "Great! You have selected the " << difficultyLevel[dl - 1] << " difficulty level." << std::endl;
        std::cout << "Let's start the game!" << std::endl << std::endl;

        // Game loop
        do {
            std::cout << "You have " << chances << " chances" << std::endl;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            std::cout << std::endl;

            attempts++;
            chances--;

            guessed(guess, rn, attempts, chances);
            std::cout << std::endl;

            // Check if guess is correct or chances are exhausted
            if (guess == rn || chances == 0) {
                std::cout << "Do you want to play again? (Y or N): ";
                std::cin >> again;
                if (again == 'Y' || again == 'y') {
                    std::cout << std::endl;
                    startGame(); // Recursively restart the game
                } else {
                    std::cout << "Exiting..." << std::endl;
                    exit(EXIT_SUCCESS);
                }
            }

        } while (chances != 0);

    } while (playing); // This condition never actually becomes false
}

// Entry point of the program
int main() {
    startGame();
    return 0;
}

