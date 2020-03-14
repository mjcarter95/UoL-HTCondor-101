/**
 * Matthew Carter - University of Liverpool
 * 14 Mar 2020
 */

#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 3) {
        std::cerr << "usage: " << argv[0] << " <n_throws> <n_runs>\n";
        exit(0);
    }

    int n_throws = atoi(argv[1]);
    int n_runs = atoi(argv[2]);
    int in_circle = 0;
    double x, y, pi_estimate = 0;

    // Set up random number generator
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    // Perform Monte Carlo estimate n_runs times
    for(int i = 0;  i < n_runs; i++) {
        // Throw the dart n_throws times
        for(int i = 0; i < n_throws; i++) {
            x = distribution(generator);
            y = distribution(generator);

            // Check if the dart hit the board
            if((x * x) + (y * y) <= 1)
                in_circle += 1;
        }

        // Increment estimate of pi
        pi_estimate += 4 * (double)in_circle / (double)n_throws;
        in_circle = 0;
    }

    // Output result
    cout << "Estimate of pi: " << (pi_estimate / (double)n_runs) << "\n";

    return 0;
}