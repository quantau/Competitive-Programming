#include <iostream>
#include <string.h>
using namespace std;

// M is number of applicants
// and N is number of timeslots
#define M 6
#define N 6

// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible
bool bpm(bool bpGraph[M][N], int u,
         bool seen[], int matchR[])
{
    // Try every timeslot one by one
    for (int v = 0; v < N; v++)
    {
        // If customer u is interested in
        // timeslot v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true;

            // If timeslot 'v' is not assigned to an
            // customer OR previously assigned
            // customer for timeslot v (which is matchR[v])
            // has an alternate timeslot available.
            // Since v is marked as visited in
            // the above line, matchR[v] in the following
            // recursive call will not get timeslot 'v' again
            if (matchR[v] > 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v]--;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM(bool bpGraph[M][N], int matchR[])
{
    // Count of customers who have been mapped to some time slot
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        // Mark all time slots as not visited
        // for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a timeslot
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

int main()
{
    // construction of bipartite graph
    bool bpGraph[M][N] = {{0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0}};

    // The array stores the capacity of ith shop
    //  if it is 0 then the capacity at this time is 0
    // construction of matchR
    int matchR[N] = {2, 3, 2, 2, 2, 2};

    cout << "Maximum number of customer who can visit their desired shop is "
         << maxBPM(bpGraph, matchR);

    return 0;
}

