#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "MatConv.h" // This header defines KER_ROWS, KER_COLS, INP_ROWS, INP_COLS, OUTP_ROWS, OUTP_COLS
                     // and data types: mat_ker, mat_inp, mat_outp

using namespace std;

template<typename T, int R, int C>
void print_matrix(T matrix[R][C], const string& name) {
    cout << "--- " << name << " ---" << endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << (int)matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    // Initialize the random number generator
    srand(123456);

    // Declare kernel, input matrix, and output matrices for HW and SW
    mat_ker kernel[KER_ROWS][KER_COLS];
    mat_inp input[INP_ROWS][INP_COLS];
    mat_outp hw_res[OUTP_ROWS][OUTP_COLS];
    mat_outp sw_res[OUTP_ROWS][OUTP_COLS];
    int err_cnt = 0;

    // --- Generate random kernel values ---
    // Values are between 0 and 255
    cout << "Generating random kernel..." << endl;
    for (int i = 0; i < KER_ROWS; i++) {
        for (int j = 0; j < KER_COLS; j++) {
            kernel[i][j] = rand() % 256;  // [0, 255]

        }
    }
    // Optionally print the generated kernel
    // print_matrix<mat_ker, KER_ROWS, KER_COLS>(kernel, "Kernel");

    // --- Generate random input matrix ---
    // Values between 0 and 255
    cout << "Generating random input matrix..." << endl;
    for (int i = 0; i < INP_ROWS; i++) {
        for (int j = 0; j < INP_COLS; j++) {
            input[i][j] = rand() % 256;  // [0, 255]
        }
    }

    // Print the generated kernel for debugging
    print_matrix<mat_ker, KER_ROWS, KER_COLS>(kernel, "Kernel");

    // Print the generated input matrix for debugging
    print_matrix<mat_inp, INP_ROWS, INP_COLS>(input, "Input");

    // Optionally print the generated input matrix
    // print_matrix<mat_inp, INP_ROWS, INP_COLS>(input, "Input");

    // --- Compute software reference result (convolution) ---
    cout << "Calculating software reference result..." << endl;
    for (int i = 0; i < OUTP_ROWS; i++) {
        for (int j = 0; j < OUTP_COLS; j++) {
            sw_res[i][j] = 0; // Initialize output element
            for (int y = 0; y < KER_ROWS; y++) {
                for (int x = 0; x < KER_COLS; x++) {
                    sw_res[i][j] += kernel[y][x] * input[i + y][j + x];
                }
            }
        }
    }

    // --- Run hardware simulation (if HW_COSIM is defined) ---
#ifdef HW_COSIM
    cout << "Running hardware simulation (MatConv)..." << endl;
    MatConv(kernel, input, hw_res);
#endif

    // --- Output comparison between hardware and software ---
    cout << "\n--- Output Comparison ---" << endl;
    cout << "Format: HW_Result (SW_Result)" << endl;
    for (int i = 0; i < OUTP_ROWS; i++) {
        for (int j = 0; j < OUTP_COLS; j++) {
#ifdef HW_COSIM
            cout << hw_res[i][j] << " (" << sw_res[i][j] << ")";
            if (hw_res[i][j] != sw_res[i][j]) {
                cout << "*"; // Mark mismatch
                err_cnt++;
            }
#else
            // If not running co-simulation, print software result only
            cout << sw_res[i][j];
#endif
            cout << "\t"; // Use tab for cleaner alignment
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;

#ifdef HW_COSIM
    if (err_cnt)
        cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
    else
        cout << "SUCCESS: Test passed. No mismatches detected." << endl;
#else
    cout << "INFO: Software result calculated. Define HW_COSIM to run hardware simulation and compare." << endl;
#endif

    return err_cnt; // Return the number of mismatches (0 means success)
}
