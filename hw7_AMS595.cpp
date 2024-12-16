/***********************************************************************/
/*
* This code was created by Axi Aguilera (axi.aguilera@stonybrook.edu), implemented in
* VS Code and executed from the Ubuntu terminal, to run it again follow the following 
* steps:
*
* 1. Open Ubuntu terminal and locate the directory:
*     For example: cd /mnt/d/HW7
* 2. Compile the code: g++ hw7_AMS595.cpp -o hw7_AMS595
* 3. Run the code: ./hw7_AMS595
* 4. If you want to save the results run the following command and it will be saved in a 
     .txt file:  ./hw7_AMS595 > results.txt
/***********************************************************************/



#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>

// Function declarations for core functionalities
void conditionalStatements();
void print_vector(const std::vector<int>& v);
void fibonacci_sequence(int limit);
bool isprime(int n);
std::vector<int> factorize(int n);
std::vector<int> prime_factorize(int n);
void pascal_triangle(int n);

// Function declarations for testing the core functionalities
void test_conditionalStatements();
void test_print_vector();
void test_fibonacci_sequence();
void test_isprime();
void test_factorize();
void test_prime_factorize();
void test_pascal_triangle();

// Entry point of the program
int main() {
    std::cout << "Testing all functions:\n";

    // Call test functions for each core functionality
    test_conditionalStatements();
    test_print_vector();
    test_fibonacci_sequence();
    test_isprime();
    test_factorize();
    test_prime_factorize();
    test_pascal_triangle();

    return 0;
}


/*************************************************************************** */

/***************          Function Implementations         *******************/

/*****************************************************************************/




/*****************          Conditional Statements          *******************/
/**
 * @brief Checks if a given number is positive, negative, or zero.
 * 
 * conditionalStatements: Prompts the user to enter a number and then checks if the 
 * number is positive, negative, or zero. Based on the result, it outputs 
 * the corresponding message to the standard output.
 *
 * @return void conditionalStatements does not return any value. It prints the 
 * result to the standard output.
 */
void conditionalStatements() {
    int x;  // Declare an integer variable to store the user input
    
    // Prompt the user to enter a number
    std::cout << "Enter a number: ";
    std::cin >> x;  // Read the user input into variable x
    
    // Check if the entered number is greater than zero (positive)
    if (x > 0) {
        std::cout << x << " is positive.\n";      } 
    // Check if the entered number is less than zero (negative)
    else if (x < 0) {
        std::cout << x << " is negative.\n";  
    } 
    // Case when the entered number is zero
    else {
        std::cout << "You entered zero.\n";  
    }
}


/*****************              Printing a Vector             *******************/
/**
 * @brief Prints the elements of a vector of integers.
 * 
 * print_vector: Iterates over the provided vector and prints each element to the
 * standard output, separated by spaces. After printing all elements, a newline is added.
 *
 * @param v A constant reference to a vector of integers. This vector contains the
 * values to be printed.
 * 
 * @return void print_vector does not return a value. It simply prints the vector
 * elements to the standard output.
 */
void print_vector(const std::vector<int>& v) {
    // Iterate through each element of the vector and print it
    for (int num : v) {
        std::cout << num << " ";  // Print each element 
    }
    
    std::cout << std::endl;  // Print a newline after the vector is fully printed
}




/*****************      Fibonacci sequence with While Loops      *******************/
/**
 * @brief Generates and prints the Fibonacci sequence up to a specified limit.
 * 
 * fibonacci_sequence: Calculates and prints the Fibonacci sequence starting from 0, 
 * where each subsequent number is the sum of the two preceding ones. The sequence
 * continues until the last number in the sequence exceeds the provided limit.
 *
 * @param limit The upper bound for the Fibonacci sequence. The sequence will
 * stop when the next number exceeds this value.
 * 
 * @return void fibonacci_sequence does not return a value. It prints the Fibonacci 
 * sequence to the standard output.
 */
void fibonacci_sequence(int limit) {
    int Fn = 0, Fn_plus_1 = 1;  // Initialize the first two Fibonacci numbers (0 and 1)
    
    // Continue generating Fibonacci numbers as long as the current number is less than or equal to the limit
    while (Fn <= limit) {
        std::cout << Fn << " ";  // Print the current Fibonacci number
        
        // Calculate the next Fibonacci number by summing the last two
        int next = Fn + Fn_plus_1;
        
        // Update a and b to the next two numbers in the sequence
        Fn = Fn_plus_1;
        Fn_plus_1 = next;
    }
    
    std::cout << std::endl;  // Print a newline after the sequence is complete
}




/*****************              If Prime            *******************/
/**
 * @brief Checks whether a given integer is prime.
 * 
 * isprime: Determines if a number is prime by checking if it is divisible 
 * by any integer other than 1 and itself. It uses an efficient approach by 
 * checking divisibility up to the square root of the number, which reduces 
 * the number of iterations required.
 *
 * @param n An integer to be checked for primality.
 * 
 * @return bool Returns `true` if the number is prime, and `false` otherwise.
 */
bool isprime(int n) {
    // If the number is less than or equal to 1, it is not prime
    if (n <= 1) return false;
    
    // Iterate from 2 to the square root of n
    for (int i = 2; i <= sqrt(n); ++i) {
        // If n is divisible by any i, it is not prime
        if (n % i == 0) return false;
    }
    
    // If no divisors were found, n is prime
    return true;
}





/*****************              Factorize            *******************/
/**
 * @brief Factorizes a given integer into its divisors.
 * 
 * factorize: Finds all divisors of the given integer `n` by iterating 
 * through all integers from 1 to `n` and checking if they divide `n` evenly. 
 * The divisors are stored in a vector and returned.
 *
 * @param n An integer to be factorized.
 * 
 * @return std::vector<int> A vector containing the divisors of the input integer `n`.
 */
std::vector<int> factorize(int n) {
    std::vector<int> factors;  // Vector to store the factors of n
    
    // Iterate from 1 to n/2 to find divisors
    for (int i = 1; i <= n/2; ++i) {
        // If i divides n evenly, i is a factor
        if (n % i == 0) {
            factors.push_back(i);  // Add the divisor to the factors vector
        }
    }
    factors.push_back(n); // Add n as the last factor
    
    return factors;  // Return the vector containing the divisors
}




/*****************              Prime Factorization            *******************/
/**
 * @brief Computes the prime factorization of a given integer.
 * 
 * prime_factorize: Computes the prime factors of a given integer `n` by first 
 * obtaining all divisors of `n` using the `factorize` function, then filtering 
 * those divisors to only include prime numbers. The prime factors are stored in 
 * a vector and returned.
 *
 * @param n An integer to be prime factorized.
 * 
 * @return std::vector<int> A vector containing the prime factors of the input integer `n`.
 */
std::vector<int> prime_factorize(int n) {
    // Get all divisors of n using the factorize function
    std::vector<int> factors = factorize(n);
    
    // Vector to store prime factors
    std::vector<int> prime_factors;
    
    // Iterate through the factors and check if they are prime
    for (int factor : factors) {
        if (isprime(factor)) {  
            prime_factors.push_back(factor);  
        }
    }
    
    return prime_factors;  // Return the vector of prime factors
}





/*****************              Pascal's Triangle            *******************/
/**
 * @brief Generates and prints Pascal's Triangle up to a specified number of rows.
 * 
 * pascal_triangle: Constructs Pascal's Triangle, which is a triangular array 
 * of binomial coefficients. The function generates the triangle row by row, 
 * using the values from the previous row to compute the values in the current row. 
 * After constructing the triangle, it prints the values row by row.
 *
 * @param n The number of rows of Pascal's Triangle to generate.
 * 
 * @return void pascal_triangle does not return a value. It prints the triangle 
 * to the standard output.
 */
void pascal_triangle(int n) {
    // Create a 2D vector to store the triangle values
    std::vector<std::vector<int>> triangle(n);
    
    // Build the triangle row by row
    for (int i = 0; i < n; ++i) {
        // Resize each row to have i+1 elements (first and last elements are always 1)
        triangle[i].resize(i + 1);
        
        // Set the first and last elements of each row to 1
        triangle[i][0] = triangle[i][i] = 1;
        
        // Calculate the inner values of the row (if any)
        for (int j = 1; j < i; ++j) {
            // The value is the sum of the two numbers directly above it
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Print the triangle
    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";  // Print each number 
        }
        std::cout << std::endl;  // Print a newline after each row
    }
}





/*************************************************************************** */

/***************       Test function implementations       *******************/

/*****************************************************************************/



// Tests the conditionalStatements function with various inputs.
void test_conditionalStatements() {
     // Print a header message to indicate the start of the test
    std::cout << "\nTesting conditionalStatements:\n"; 
    
    // Define a vector of test inputs (positive, negative, and zero values)
    std::vector<int> test_inputs = {1, -1, 0, 5};
    
    // Iterate over each test input and check the output based on the conditions
    for (int input : test_inputs) {
        std::cout << "Input: " << input << ", Output: ";  // Print the input and the corresponding output
        
        // Apply the conditional statements logic and print the result
        if (input > 0) {
            std::cout << input << " is positive\n";  // Print if the input is positive
        } else if (input < 0) {
            std::cout << input << " is negative\n";  // Print if the input is negative
        } else {
            std::cout << "You entered zero\n";  // Print if the input is zero
        }
    }
}


// Tests the print_vector function with a sample vector.
void test_print_vector() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting print_vector:\n"; 
    
    // Create a vector containing the integers 1 to 5
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    
    // Print a message indicating that the contents of the vector will be displayed
    std::cout << "The vector contains: ";
    
    // Call the print_vector function to display the contents of the vector
    print_vector(my_vector);
}


// Tests the fibonacci_sequence function with a specific limit.
void test_fibonacci_sequence() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting fibonacci_sequence:\n";  
    
    // Set a small limit for the Fibonacci sequence terms to be generated (for testing)
    int limit = 4000000;  
    
    // Print a message indicating the limit up to which Fibonacci terms will be printed
    std::cout << "Fibonacci sequence terms up to " << limit << ":\n";
    
    // Call the fibonacci_sequence function to generate and print the terms up to the limit
    fibonacci_sequence(limit);
}


// Tests the isprime function with a series of numbers.
void test_isprime() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting isprime:\n";  
    
    // Define a vector of test cases (prime and non-prime numbers)
    std::vector<int> test_cases = {2, 10, 17};
    
    // Iterate over each test case and check if the number is prime
    for (int n : test_cases) {
        // Print the result of isprime for each test case
        std::cout << "isprime(" << n << ") = " << (isprime(n) ? "true" : "false") << '\n';
    }
}


// Tests the factorize function with multiple test cases.
void test_factorize() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting factorize:\n";  
    
    // Define a vector of test cases (numbers to be factorized)
    std::vector<int> test_cases = {2, 19, 72, 196};
    
    // Iterate over each test case and print its factors
    for (int n : test_cases) {
        std::cout << "Factors of " << n << ": ";  // Print a message before listing the factors
        print_vector(factorize(n));  // Call the factorize function and print the result using print_vector
    }
}


// Tests the prime_factorize function with various inputs.
void test_prime_factorize() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting prime_factorize:\n";  
    
    // Define a vector of test cases (numbers to be prime factorized)
    std::vector<int> test_cases = {2, 19, 72, 196};
    
    // Iterate over each test case and print its prime factors
    for (int n : test_cases) {
        std::cout << "Prime factors of " << n << ": ";  // Print a message before listing the prime factors
        print_vector(prime_factorize(n));  // Call the prime_factorize function and print the result using print_vector
    }
}



// Tests the pascal_triangle function by generating a small triangle.
void test_pascal_triangle() {
    // Print a header message to indicate the start of the test
    std::cout << "\nTesting print_pascals_triangle:\n";  
    
    // Set the number of rows for Pascal's Triangle (example value)
    int rows = 5;  // Example number of rows
    
    // Print a message indicating the number of rows in the triangle
    std::cout << "Pascal's Triangle with " << rows << " rows:\n";
    
    // Call the pascal_triangle function to generate and print the triangle
    pascal_triangle(rows);
}
