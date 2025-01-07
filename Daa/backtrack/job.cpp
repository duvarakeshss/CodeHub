#include <iostream>
#include <algorithm> // for sorting
#include <cstring>   // for memset

using namespace std;

// Structure to represent a job
struct Job {
    char id;      // Job ID
    int profit;   // Profit if the job is completed before its deadline
    int deadline; // Deadline of the job
};

// Comparison function to sort jobs in decreasing order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize total profit
void jobScheduling(Job jobs[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(jobs, jobs + n, compare);

    // Array to keep track of free time slots
    bool slot[n];
    // Array to store result (sequence of jobs)
    char result[n];

    // Initialize all time slots to be free
    memset(slot, false, sizeof(slot));

    int totalProfit = 0; // Variable to store total profit

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
                slot[j] = true;           // Mark this slot as occupied
                result[j] = jobs[i].id;   // Store the job id in result
                totalProfit += jobs[i].profit; // Add profit
                break;
            }
        }
    }

    // Print the result
    cout << "The selected jobs are: ";
    for (int i = 0; i < n; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }
    cout << "\nMaximum Profit: " << totalProfit << endl;
}

int main() {
    Job jobs[] = { {'A', 100, 2}, {'B', 19, 1}, {'C', 27, 2}, {'D', 25, 1}, {'E', 15, 3} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

    return 0;
}