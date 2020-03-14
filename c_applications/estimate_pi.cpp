/**
 * Matthew Carter - University of Liverpool
 * 14 Mar 2020
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 3) {
        std::cerr << "usage: " << argv[0] << " <worker_id> <n_throws>\n";
        exit(0);
    }

    int worker = atoi(argv[1]);
    int n_throws = atoi(argv[2]);
    int in_circle = 0;
    double x, y, pi_estimate = 0;

    // Set up random number generator
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    /**
     * We will perform n_runs in parallel on the HTCondor
     * pool, where n_runs is the number of workers we will
     * request when submitting a job
     */

    // // Perform Monte Carlo estimate n_runs times
    // for(int i = 0;  i < n_runs; i++) {
    //     // Throw the dart n_throws times
    //     for(int i = 0; i < n_throws; i++) {
    //         x = distribution(generator);
    //         y = distribution(generator);

    //         // Check if the dart hit the board
    //         if((x * x) + (y * y) <= 1)
    //             in_circle += 1;
    //     }

    //     // Increment estimate of pi
    //     pi_estimate += 4 * (double)in_circle / (double)n_throws;
    //     in_circle = 0;
    // }

    for(int i = 0; i < n_throws; i++) {
        x = distribution(generator);
        y = distribution(generator);

        // Check if the dart hit the board
        if((x * x) + (y * y) <= 1)
            in_circle += 1;
    }

    pi_estimate = 4 * (double)in_circle / (double)n_throws;

    // Write result to file to send back to host
    ofstream output_file;
    output_file.open("output" + std::to_string(worker) + ".txt", std::ios::app);
    output_file << pi_estimate;
    output_file.close();


    return 0;
}