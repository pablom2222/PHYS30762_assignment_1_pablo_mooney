// Assignment_1_TheBohrAtom.cpp
// Calculates the energy transition in J and eV from user inputs
// Student ID: 10706596
// February 2025

#include<iostream>
#include <limits>
#include <cmath>
#include <iomanip>

double calculate_energy_in_ev(int init, int final, int z);
const double electron_volt_to_joule = 1.602e-19;
const double rydberg_energy = 13.6;

double calculate_energy_in_ev(int init, int final, int z)
{
    return rydberg_energy* std::pow(z, 2) * (std::pow(final, -2) - std::pow(init, -2));
}

double ev_to_j(double energy_in_ev) 
{
    return electron_volt_to_joule * energy_in_ev;
}

int main()
{   
    int calculations_count = 0;
    char repeat;
do { 
    std::string atomic_number_input;
    int atomic_number;
    while (true) {
        std::cout << "Enter the atomic number (Z): ";
        std::cin >> atomic_number_input;

        bool isNumeric = true;
        bool hasDecimalPoint = false;
        for (size_t i = 0; i < atomic_number_input.length(); i++) {
            if (!std::isdigit(atomic_number_input[i])) {
                // Allow one '-' at the start
                if (i == 0 && atomic_number_input[i] == '-') continue;
                // Allow one decimal point
                if (atomic_number_input[i] == '.' && !hasDecimalPoint) {
                    hasDecimalPoint = true;
                    continue;
                }
                isNumeric = false;
                break;
            }
        }

        if (!isNumeric) {
            std::cout << "Error: The input contains non-numeric characters. Please enter a positive integer.\n";
            continue;
        }

        if (hasDecimalPoint) {
            std::cout << "Error: Floating-point numbers are not allowed. Please enter a positive integer.\n";
            continue;
        }

        atomic_number = std::stoi(atomic_number_input);

        if (atomic_number <= 0) {
            std::cout << "Error: The atomic number must be a positive integer greater than zero.\n";
            continue;
        }

        break;
    }
    std::cout << "Valid input received: " << atomic_number << std::endl;
    std::string initial_quantum_number_input;
    int initial_quantum_number;
    while (true) {
        std::cout << "Enter the initial principle quantum number: ";
        std::cin >> initial_quantum_number_input;
        bool isNumeric = true;
        bool hasDecimalPoint = false;
        for (size_t i = 0; i < initial_quantum_number_input.length(); i++) {
            if (!std::isdigit(initial_quantum_number_input[i])) {
                // Allow one '-' at the start
                if (i == 0 && initial_quantum_number_input[i] == '-') continue;
                // Allow one decimal point
                if (initial_quantum_number_input[i] == '.' && !hasDecimalPoint) {
                    hasDecimalPoint = true;
                    continue;
                }
                isNumeric = false;
                break;
            }
        }
        if (!isNumeric) {
            std::cout << "Error: The input contains non-numeric characters. Please enter a positive integer.\n";
            continue;
        }
        if (hasDecimalPoint) {
            std::cout << "Error: Floating-point numbers are not allowed. Please enter a positive integer.\n";
            continue;
        }
        initial_quantum_number = std::stoi(initial_quantum_number_input);
        if (initial_quantum_number < 2) {
            std::cout << "Error: The initial quantum number must be a positive integer at least 2 to represent a state above the ground state.\n";
            continue;
        }
        break;
    }
    std::cout << "Valid input received: " << initial_quantum_number << std::endl;
    std::string final_quantum_number_input;
    int final_quantum_number;
    while (true) {
        std::cout << "Enter the final principle quantum number: ";
        std::cin >> final_quantum_number_input;
        bool isNumeric = true;
        bool hasDecimalPoint = false;
        for (size_t i = 0; i < final_quantum_number_input.length(); i++) {
            if (!std::isdigit(final_quantum_number_input[i])) {
                // Allow one '-' at the start
                if (i == 0 && final_quantum_number_input[i] == '-') continue;
                // Allow one decimal point
                if (final_quantum_number_input[i] == '.' && !hasDecimalPoint) {
                    hasDecimalPoint = true;
                    continue;
                }
                isNumeric = false;
                break;
            }
        }
        if (!isNumeric) {
            std::cout << "Error: The input contains non-numeric characters. Please enter a positive integer.\n";
            continue;
        }
        if (hasDecimalPoint) {
            std::cout << "Error: Floating-point numbers are not allowed. Please enter a positive integer.\n";
            continue;
        }
        final_quantum_number = std::stoi(final_quantum_number_input);
        if (final_quantum_number < 1) {
            std::cout << "Error: The quantum number must be a positive integer.\n";
            continue;
        }
        if (final_quantum_number > initial_quantum_number) {
            std::cout << "Error: The quantum number must be smaller than the initial quantum number.\n";
            continue;
        }
        if (final_quantum_number == initial_quantum_number) {
            std::cout << "Error: The quantum number cannot be the same. It must represent a change in state.\n";
            continue;
        }
        break;
    }
    std::cout << "Valid input received: " << final_quantum_number << std::endl;

    double calculated_energy_in_ev = calculate_energy_in_ev(initial_quantum_number, final_quantum_number, atomic_number);
    std::string energy_unit;
    std::cout << "Type J for energy in joules or type any other key for energy in electron volts" << std::endl;
    std::cin >> energy_unit;

    std::cout << "The energy for Z=" << atomic_number << " with transition from n=" << initial_quantum_number << " to n=" << final_quantum_number << " is:" << std::endl;
    if (energy_unit == "j" || energy_unit == "J") {
        double joule_energy = ev_to_j(calculated_energy_in_ev);
        std::cout << std::scientific << std::setprecision(4) << joule_energy << " J\n";
    } else {
    std::cout << std::fixed << std::setprecision(2) << calculated_energy_in_ev << " eV\n";
    }


calculations_count++;
std::cout << "Type y to peform another calculation. Type n or any other character to exit: ";
    std::cin >> repeat;
} 

while (repeat == 'y' || repeat == 'Y');

if (calculations_count == 1) {
    std::cout << "Thanks. You performed " << calculations_count << " energy calculation.\n";
} else {
    std::cout << "Thanks. You performed " << calculations_count << " energy calculations.\n";
}
    return 0;
}


