/*
 * test-hunt.cpp
 *   A quick exploration of hunt-the-dragon strategies
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#include <iostream>
#include <string>

#include "World.hpp"
#include "hunt.hpp"

using namespace std;

// +---------+-------------------------------------------------------
// | Globals |
// +---------+

int hunts = 0;
int successes = 0;

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

void reportFailure(int n, int k, string reason) {
  cerr << "For n=" << n << ", k=" << k << ": " << reason << endl;
} // reportFailure

void runTest(int n, int k) {
    // Set up the world
    World w = World(n, k);

    // Run the algorithm
    ++hunts;
    try { 
        bool found = huntDragon(w);
        if (found) {
            if (w.dragonFound()) {
                ++successes;
            } else {
                reportFailure(n, k, 
                    "algorithm incorrectly claims it found dragon");
            }
        } else {
            reportFailure(n, k, 
                "algorithm failed to find dragon");
        } // if !found
    } catch (out_of_range &e) {
        string err = "algorithm failed with an out-of-range index: ";
        err += e.what();
        reportFailure(n, k, err);
    } catch (runtime_error &e) {
        string err = "algorithm failed because: ";
        err += e.what();
        reportFailure(n, k, err);
    } // try/catch
} // runTest(int, int)

// +------+----------------------------------------------------------
// | Main |
// +------+

/* 
 * Try a lot of hunts, reporting on how many succeeded.
 */
int main(int argc, char* argv[]) {
    if (argc > 2) {
        cerr << "Invalid number of arguments." << endl;
        cerr << "Usage: ./test-hunt" << endl;
        cerr << "   or: ./test-hunt n" << endl;
        exit(1);
    } // if

    if (argc == 2) {
        int n = stoi(argv[1]);
        for (int k = 0; k < n; k++) {
            runTest(n, k);
        } // for
    } else { 
        for (int n = 1; n <= 16; n++) {
            for (int k = 0; k < n/2; k++) {
                runTest(n, k);
            } // for k
        } // for n
    } // if/else

    cout << "Passed " << successes << " of " << hunts << " tests." << endl;
    
    if (successes == hunts)
        exit(0);
    else
        exit(1);
} // main
