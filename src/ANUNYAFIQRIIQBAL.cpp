#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace chrono;

int main()
{
    const int N = 500;

    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 1));
    vector<vector<int>> C(N, vector<int>(N, 0));

    auto start_seq = high_resolution_clock::now();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end_seq = high_resolution_clock::now();

    double seq_time =
        duration<double>(end_seq - start_seq).count();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            C[i][j] = 0;
        }
    }

    auto start_par = high_resolution_clock::now();

#pragma omp parallel for collapse(2)
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int sum = 0;

            for(int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }

            C[i][j] = sum;
        }
    }

    auto end_par = high_resolution_clock::now();

    double par_time =
        duration<double>(end_par - start_par).count();

    cout << "Matrix Size : "
         << N << " x " << N << endl;

    cout << "Sequential Time : "
         << seq_time << " sec" << endl;

    cout << "Parallel Time   : "
         << par_time << " sec" << endl;

    cout << "Speedup : "
         << seq_time / par_time
         << "x" << endl;

    return 0;
}