// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 23, 2022
// This program is a basic physics calculator that can calculate E=MC^2
// the acceleration of an object, and power.

#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cmath>

const int speedOfLight = 299792458;

float EnergyCalculation(float mass) {
    // This function calculates E=MC^2 and then
    // returns energy back to main
    float energy = mass * pow(speedOfLight, 2);
    return(energy);
}


float CalculateAcceleration(float starting, float finishing,
                            float timePassing) {
    // This function calculates acceleration
    // and then returns the result back to main
    float acceleration = (finishing - starting) / timePassing;
    return(acceleration);
}


float PowerCalculation(float totalWork, float time_) {
    // This function calculates power and
    // then returns the result to main
    float power = totalWork / time_;
    return(power);
}


float WorkCalculation(float forceN, float displacementM) {
    // This function calculates a returns work
    // to main to be used to calculate power
    float workDone = forceN * displacementM;
    return(workDone);
}


int main() {
    // Declare variables
    std::string equationChoice;
    std::string workQuestion;
    std::string objectMass;
    std::string calculateAgainAnswer;
    std::string startingVelocity;
    std::string finalVelocity;
    std::string timePassed;
    std::string userWork;
    std::string userForce;
    std::string userDisplacement;

    float objectMassFloat;
    float finalEnergy;
    float startingVelocityFloat;
    float finalVelocityFloat;
    float timePassedFloat;
    float finalAcceleration;
    float userWorkFloat;
    float totalPower;
    float userForceFloat;
    float userDisplacementFloat;

    // Print intro message
    std::cout << "Welcome!\n";
    sleep(1);
    std::cout << " \n";
    std::cout << "This program is a basic physics calculator that can";
    std::cout << " calculate the amount of \nenergy contained within a ";
    std::cout << "certain amount of mass, the amount of energy \nused over ";
    std::cout << "time (Power), and the average acceleration of an object.\n";
    std::cout << " \n";

    do {
        // Allow user to pick equation
        sleep(1);
        std::cout << "Which equation would you like to choose?\n";
        std::cout << " \n";
        sleep(0.5);
        std::cout << "E = MC² (Calculates the amount of energy ";
        std::cout << "contain in something at rest)\n";
        sleep(0.5);
        std::cout << "a = Δv/Δt (Calculates the acceleration of ";
        std::cout << "something over a certain amount of time)\n";
        sleep(0.5);
        std::cout << "P = W/Δt (Calculates power which is the ";
        std::cout << "amount of energy used over time)\n";
        sleep(0.5);
        std::cout << " \n";

        std::cout << "Enter your choice here (E/a/P): ";
        std::cin >> equationChoice;

        // If energy equation is picked than ask for required inputs
        if (equationChoice == "E" || equationChoice == "e") {
            std::cout << " \n";
            std::cout << "---------------------------------------------";
            std::cout << "--------------------------------------\n";
            std::cout << "You chose E = MC², good choice!\n";
            std::cout << " \n";
            sleep(1.5);
            std::cout << "In order to calculate the energy contained within ";
            std::cout << "an object at a resting state it \nrequires the mass ";
            std::cout << "of the object in kilograms.\n";
            std::cout << " \n";
            sleep(1.5);

            do {
               // Ask user for mass
               std::cout << "Enter the mass of your object in kg: ";
               std::cin >> objectMass;
               // Make sure that mass input is valid
               try {
                   objectMassFloat = std::stof(objectMass);

                   if (objectMassFloat > 0) {
                       std::cout << " \n";
                       // Call function to calculate energy
                       finalEnergy = EnergyCalculation(objectMassFloat);
                       // Print final result
                       std::cout << "An object at rest with a mass of ";
                       std::cout << objectMassFloat << " kg has ";
                       std::cout << finalEnergy;
                       std::cout << " J of energy contained within it.\n";
                       std::cout << " \n";
                       sleep(1.5);
                       std::cout << "---------------------------------------";
                       std::cout << "--------------------------";
                       std::cout << "------------------\n";
                       break;
                   } else {
                       std::cout << objectMass << " is an ivalid input. ";
                       std::cout << "Your input must be a positive number.\n";
                   }
                // If input is invalid ask again
               } catch (std::invalid_argument) {
                   std::cout << objectMass << " is not a valid input. ";
                   std::cout << "Your input must be a number.\n";
                   std::cout << " \n";
               }
            // Ask user if they'd like to calculate again
            } while (calculateAgainAnswer != "n");
            std::cout << " \n";
            std::cout << "Would you like to calculate again? y/n: ";
            std::cin >> calculateAgainAnswer;
            std::cout << " \n";

            if (calculateAgainAnswer == "n" || calculateAgainAnswer == "N"
                || calculateAgainAnswer == "no") {
                break;
            }
        // If acceleration equation is picked than ask for required inputs
        } else if (equationChoice == "a" || equationChoice == "A") {
            std::cout << " \n";
            std::cout << "--------------------------------------------";
            std::cout << "---------------------------------------\n";
            std::cout << "You chose a = Δv/Δt, good choice!\n";
            std::cout << " \n";
            sleep(1.5);
            std::cout << "In order to calculate acceleration over time it ";
            std::cout << "requires the starting velocity, the \nfinishing ";
            std::cout << "velocity, and the amount of elapsed time.\n";
            std::cout << " \n";
            sleep(1.5);

            do {
                // Get velocity and time input from the user
                // Make sure that all of the inputs are valid
                std::cout << "Enter the starting velocity of your ";
                std::cout << "object (m/s): ";
                std::cin >> startingVelocity;
                sleep(1.5);
                std::cout << " \n";

                try {
                    startingVelocityFloat = std::stof(startingVelocity);

                    do {
                        std::cout << "Enter the final velocity of your ";
                        std::cout << "object (m/s): ";
                        std::cin >> finalVelocity;
                        sleep(1.5);
                        std::cout << " \n";
                        try {
                            finalVelocityFloat = std::stof(finalVelocity);

                            do {
                                std::cout << "Enter the amout ";
                                std::cout << "of time passed (s): ";
                                std::cin >> timePassed;

                                try {
                                    timePassedFloat = std::stof(timePassed);

                                    if (timePassedFloat > 0) {
                                        // Call function to
                                        // calculate acceleration
                                        finalAcceleration =
                                            CalculateAcceleration(
                                            startingVelocityFloat,
                                            finalVelocityFloat,
                                            timePassedFloat);
                                        // Print final result
                                        std::cout << " \n";
                                        std::cout << "An object that ";
                                        std::cout << "has changed ";
                                        std::cout << "velocity from ";
                                        std::cout << startingVelocityFloat;
                                        std::cout << " m/s to ";
                                        std::cout << finalVelocityFloat;
                                        std::cout << " m/s in ";
                                        std::cout << timePassedFloat;
                                        std::cout << " seconds \nhas an ";
                                        std::cout << "acceleration rate of ";
                                        std::cout << finalAcceleration;
                                        std::cout << "m/s²\n";
                                        break;
                                    } else {
                                        std::cout << timePassedFloat;
                                        std::cout << " is not a valid time. ";
                                        std::cout << "Time cannot be ";
                                        std::cout << "negative or 0!\n";
                                    }
                                // If input is invalid ask to user again
                                } catch (std::invalid_argument) {
                                    std::cout << timePassed << " is not a ";
                                    std::cout << "valid input. Your input ";
                                    std::cout << "must be a number.\n";
                                    std::cout << " \n";
                                }
                                std::cout << " \n";
                            } while (calculateAgainAnswer != "n");
                            break;
                        // If input is invalid ask to user again
                        } catch (std::invalid_argument) {
                            std::cout << finalVelocity << " is not a valid ";
                            std::cout << "input. Your input must ";
                            std::cout << "be a number.\n";
                            std::cout << " \n";
                        }
                    } while (calculateAgainAnswer != "n");

                    std::cout << " \n";
                    std::cout << " \n";
                    sleep(1.5);
                    std::cout << "--------------------------------------";
                    std::cout << "----------------------------";
                    std::cout << "-----------------\n";

                    break;
                // If input is invalid ask to user again
                } catch (std::invalid_argument) {
                    std::cout << startingVelocity << " is not a valid ";
                    std::cout << "input. Your input must be a number.\n";
                    std::cout << " \n";
                }
            // Ask the user if they'd like to calculate again
            } while (calculateAgainAnswer != "n");
            std::cout << " \n";
            std::cout << "Would you like to calculate again? y/n: ";
            std::cin >> calculateAgainAnswer;
            std::cout << " \n";

            if (calculateAgainAnswer == "n" || calculateAgainAnswer == "N"
                || calculateAgainAnswer == "no") {
                break;
            }
        // If power equation is picked than ask for required inputs
        } else if (equationChoice == "P" || equationChoice == "p") {
            std::cout << " \n";
            std::cout << "--------------------------------------------";
            std::cout << "---------------------------------------\n";
            std::cout << "You chose P = W/Δt, good choice!\n";
            std::cout << " \n";
            sleep(1.5);
            std::cout << "In order to calculate power it requires the ";
            std::cout << "amount of work in joules, \n over the elapsed ";
            std::cout << "time in seconds.\n";
            std::cout << " \n";
            sleep(1.5);
            // Ask the user if they want to calculate work
            std::cout << "Would you like to calculate work first? y/n: ";
            std::cin >> workQuestion;
            sleep(1.5);
            std::cout << " \n";
            // If yes then call function to calculate work
            // and get work inputs from user
            if (workQuestion == "n" || workQuestion == "N" || workQuestion ==
                "no") {
                do {
                    std::cout << "Enter the amount of work done in joules: ";
                    std::cin >> userWork;
                    std::cout << " \n";
                    // Make sure that work inputs are valid
                    try {
                        userWorkFloat = std::stof(userWork);

                        do {
                            std::cout << "Enter the amount of ";
                            std::cout << "time elapsed is seconds: ";
                            std::cin >> timePassed;
                            std::cout << " \n";
                            // Make sure that work inputs are valid
                            try {
                                timePassedFloat = std::stof(timePassed);

                                if (timePassedFloat > 0) {
                                    totalPower = PowerCalculation(
                                        userWorkFloat,
                                        timePassedFloat);
                                    sleep(1.5);
                                    std::cout << "The total power, or energy ";
                                    std::cout << "spent, in ";
                                    std::cout << timePassedFloat;
                                    std::cout << " seconds is ";
                                    std::cout << totalPower << " W.\n";
                                    sleep(1.5);
                                    std::cout << " \n";
                                    break;
                                } else {
                                    std::cout << timePassedFloat;
                                    std::cout <<  " is invalid.";
                                    std::cout << " Time cannot be ";
                                    std::cout << "negative or 0!\n";
                                }
                            // If the input is invalid ask the question again
                            } catch (std::invalid_argument) {
                                std::cout << timePassed;
                                std::cout << " is not a valid input. ";
                                std::cout << "Your input must be a number.\n";
                                std::cout << " \n";
                            }
                        } while (calculateAgainAnswer != "n");
                        break;
                    // If the input is invalid ask the question again
                    } catch (std::invalid_argument) {
                        std::cout << userWork << " is not a valid input.";
                        std::cout << " Your input must be a number.\n";
                        std::cout << " \n";
                    }
                } while (calculateAgainAnswer != "n");
            } else {
                do {
                    // Continue the power calculation
                    std::cout << "In order to calculate work you need the ";
                    std::cout << "amount of force in newtons ";
                    std::cout << "and displacement in meters.\n";
                    std::cout << " \n";
                    sleep(1.5);
                    // Get the user inputs for force and displacement
                    std::cout << "Enter the amount of force in newtons: ";
                    std::cin >> userForce;
                    std::cout << " \n";
                    // Make sure that the inputs are valid
                    try {
                        userForceFloat = std::stof(userForce);

                        do {
                            std::cout << "Enter the displacement in meters: ";
                            std::cin >> userDisplacement;
                            std::cout << " \n";

                            try {
                                // Call the function to calculate work
                                userDisplacementFloat = std::stof(
                                    userDisplacement);
                                userWorkFloat = WorkCalculation(
                                    userForceFloat, userDisplacementFloat);
                                break;
                            // If the input is invalid ask the user again
                            } catch (std::invalid_argument) {
                                std::cout << userDisplacement;
                                std::cout << " is not a valid input. ";
                                std::cout << "Your input must be a number.\n";
                                std::cout << " \n";
                            }
                        } while (calculateAgainAnswer != "n");
                        break;
                    // If the input is invalid ask the user again
                    } catch (std::invalid_argument) {
                        std::cout << userForce << " is not a valid input.";
                        std::cout << " Your input must be a number.\n";
                        std::cout << " \n";
                    }
                } while (calculateAgainAnswer != "n");

                do {
                    // Ask the user for the time that has passed
                    std::cout << "Enter the amount of time ";
                    std::cout << "elapsed in seconds: ";
                    std::cin >> timePassed;

                    try {
                        // Make sure that the input is valid
                        timePassedFloat = std::stof(timePassed);
                        if (timePassedFloat > 0) {
                            // Call the function the calculate power
                            totalPower = PowerCalculation(userWorkFloat,
                                                          timePassedFloat);
                            // Print the final result
                            std::cout << " \n";
                            sleep(1.5);
                            std::cout << "The total power, or ";
                            std::cout << "energy spent, in ";
                            std::cout << timePassedFloat << " seconds is ";
                            std::cout << totalPower << " W.\n";
                            std::cout << " \n";
                            sleep(1.5);
                            break;
                        } else {
                            std::cout << timePassedFloat << " is invalid. ";
                            std::cout << "Time cannot be negative or 0!\n";
                        }
                    // If the user input is invalid ask the question again
                    } catch (std::invalid_argument) {
                        std::cout << timePassed << " is not a valid ";
                        std::cout << "input. Your ";
                        std::cout << "input must be a number.\n";
                        std::cout << " \n";
                    }
                } while (calculateAgainAnswer != "n");
            }
            // Ask the user if they'd like to calculate again
            std::cout << " \n";
            std::cout << "Would you like to calculate again? y/n: ";
            std::cin >> calculateAgainAnswer;
            std::cout << " \n";

            if (calculateAgainAnswer == "n" || calculateAgainAnswer == "N"
                || calculateAgainAnswer == "no") {
                break;
            }

        } else {
                // If the user input is invalid ask the question again
                std::cout << " \n";
                sleep(0.5);
                std::cout << equationChoice << " is not a valid input\n";
                sleep(0.5);
                std::cout << "Your input must be either E, a, or P\n";
                std::cout << "----------------------------------------------";
                std::cout << "-------------------------------------\n";
                std::cout << " \n";
                sleep(1);
        }
    } while (calculateAgainAnswer != "n");
}
