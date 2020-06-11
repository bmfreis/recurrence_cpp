/* 
 * File:   test_recurrence_plot_euclidean.cpp
 * Author: Barbara Reis
 * Date:   11.06.2020
 */
#include <stdlib.h>
#include <iostream>
#include "../../RecurrencePlot.h"

void test_delay(int rp_delay){
    int delay = 2;
    if(delay == rp_delay)
        cout << "test_delay() passed" << endl;
    else
        cout << "test_delay() failed: " << delay << " != " << rp_delay << endl;
}

void test_dimension(int rp_dimension){
    int dimension = 3;    
    if(dimension == rp_dimension)
        cout << "test_dimension() passed" << endl;
    else
        cout << "test_dimension() failed: " << dimension << " != " 
             << rp_dimension << endl;
}

void test_time_series_length(int rp_time_series_length){
    int time_series_length = 20;    
    if(time_series_length == rp_time_series_length)
        cout << "test_time_series_length() passed" << endl;
    else    
        cout << "test_time_series_length() failed: " << time_series_length 
             << " != " << rp_time_series_length << endl;    
}

void test_time_series(double* rp_time_series){
    double time_series[] = {0.1382232581, 0.4764703560, 0.9977854234, 0.0088386889, 0.0350422661, 0.1352572226, 0.4678508254, 0.9958657223, 0.0164687418, 0.0647900894, 0.2423693348, 0.7345057614, 0.7800281914, 0.6863368481, 0.8611143162, 0.4783858026, 0.9981313059, 0.0074608084, 0.0296205790, 0.1149728010};
    bool found_error = false;
    int i;    
    for(i = 0; i < 20; i++){
        if(time_series[i] != rp_time_series[i]){
            found_error = true;
            break;
        }
    }
    if(!found_error)
        cout << "test_time_series() passed" << endl;
    else
        cout << "test_time_series() failed: time series value error at " 
             << i << " ( " << time_series[i] << " != " << rp_time_series[i] 
             << " )" << endl;
}

void test_threshold(double rp_threshold){
    double threshold = 0.7;
    if(threshold == rp_threshold)
        cout << "test_threshold() passed" << endl;
    else
        cout << "test_threshold() failed: " << threshold << " != " 
             << rp_threshold << endl;
}

void test_norm(string rp_norm){
    string norm = "euclidean";
    if(norm.compare(rp_norm) == 0)
        cout << "test_norm() passed" << endl;
    else
        cout << "test_norm() failed: " << norm << " != " << rp_norm << endl;
}

void test_number_of_vectors(int rp_number_of_vectors){
    int number_of_vectors = 16;    
    if(number_of_vectors == rp_number_of_vectors)
        cout << "test_number_of_vectors() passed" << endl;
    else
        cout << "test_number_of_vectors failed: " << number_of_vectors << " != " 
             << rp_number_of_vectors << endl;
}

void test_distance_matrix(double** rp_distance_matrix){
    double distance_matrix[16][16] = 
        {{0.00000,1.04999,1.36127,1.29764,0.54021,0.02996,1.05576,1.44751,1.06793,0.70632,0.86062,0.80567,1.16539,0.75562,0.72291,1.05016},
         {1.04999,0.00000,0.61893,0.98758,0.64781,1.04672,0.10773,0.79499,0.82575,0.99988,1.08462,0.80207,1.25023,0.52995,1.06668,0.02042},
         {1.36127,0.61893,0.00000,1.12555,1.14802,1.35263,0.57621,0.26832,1.05044,1.18637,1.13151,0.70258,1.00549,0.71099,1.06690,0.62854},
         {1.29764,0.98758,1.12555,0.00000,1.03466,1.27418,0.89026,1.02347,0.24108,0.67679,0.69887,1.04789,1.05906,1.24647,1.55066,1.00637},
         {0.54021,0.64781,1.14802,1.03466,0.00000,0.53961,0.66491,1.26539,0.79637,0.72161,0.92405,0.86623,1.29357,0.65144,0.98172,0.64670},
         {0.02996,1.04672,1.35263,1.27418,0.53961,0.00000,1.04946,1.43390,1.04567,0.67793,0.83198,0.79118,1.14237,0.75813,0.72671,1.04747},
         {1.05576,0.10773,0.57621,0.89026,0.66491,1.04946,0.00000,0.72342,0.73747,0.93549,1.00832,0.75864,1.17561,0.56239,1.07869,0.12815},
         {1.44751,0.79499,0.26832,1.02347,1.26539,1.43390,0.72342,0.00000,0.99641,1.14793,1.04659,0.72127,0.86615,0.89189,1.17735,0.80926},
         {1.06793,0.82575,1.05044,0.24108,0.79637,1.04567,0.73747,0.99641,0.00000,0.50330,0.58880,0.89648,1.00670,1.04942,1.35931,0.84312},
         {0.70632,0.99988,1.18637,0.67679,0.72161,0.67793,0.93549,1.14793,0.50330,0.00000,0.25329,0.70291,0.79045,0.95540,1.06532,1.01297},
         {0.86062,1.08462,1.13151,0.69887,0.92405,0.83198,1.00832,1.04659,0.58880,0.25329,0.00000,0.63044,0.56074,1.00837,1.05915,1.09968},
         {0.80567,0.80207,0.70258,1.04789,0.86623,0.79118,0.75864,0.72127,0.89648,0.70291,0.63044,0.00000,0.55023,0.51704,0.56092,0.81150},
         {1.16539,1.25023,1.00549,1.05906,1.29357,1.14237,1.17561,0.86615,1.00670,0.79045,0.56074,0.55023,0.00000,1.06616,0.98151,1.26479},
         {0.75562,0.52995,0.71099,1.24647,0.65144,0.75813,0.56239,0.89189,1.04942,0.95540,1.00837,0.51704,1.06616,0.00000,0.54879,0.52590},
         {0.72291,1.06668,1.06690,1.55066,0.98172,0.72671,1.07869,1.17735,1.35931,1.06532,1.05915,0.56092,0.98151,0.54879,0.00000,1.06545},
         {1.05016,0.02042,0.62854,1.00637,0.64670,1.04747,0.12815,0.80926,0.84312,1.01297,1.09968,0.81150,1.26479,0.52590,1.06545,0.00000}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if(fabs(distance_matrix[i][j]-rp_distance_matrix[i][j]) > 0.00001){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_distance_matrix() passed" << endl;
    else
        cout << "test_distance_matrix() failed: distance value error at " 
             << i  << "," << j << " ( " << distance_matrix[i][j] << " != " 
             << rp_distance_matrix[i][j] << " )" << endl;  
    
}

void test_recurrence_matrix(int** rp_recurrence_matrix){
    int recurrence_matrix[16][16] = {{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                                     {0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1},
                                     {0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1},
                                     {0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0},
                                     {1,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1},
                                     {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
                                     {0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1},
                                     {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0},
                                     {0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0},
                                     {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
                                     {0,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1},
                                     {0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0},
                                     {0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1}};     
    bool found_error = false;
    int i,j;
    for(i = 0; i < 16; i++){
        for(j = 0; j < 16; j++){
            if(recurrence_matrix[i][j] != rp_recurrence_matrix[i][j]){
                found_error = true;
                break;
            }
        }
    }
    if(!found_error)
        cout << "test_recurrence_matrix() passed" << endl;
    else
        cout << "test_recurrence_matrix() failed: recurrence value error at " 
             << i  << "," << j << " ( " << recurrence_matrix[i][j] << " != " 
             << rp_recurrence_matrix[i][j] << " )" << endl;    
}

int main(int argc, char** argv) {
    double time_series[] = {0.1382232581, 0.4764703560, 0.9977854234, 0.0088386889, 0.0350422661, 0.1352572226, 0.4678508254, 0.9958657223, 0.0164687418, 0.0647900894, 0.2423693348, 0.7345057614, 0.7800281914, 0.6863368481, 0.8611143162, 0.4783858026, 0.9981313059, 0.0074608084, 0.0296205790, 0.1149728010};
    int time_series_length = 20;
    int dimension = 3;
    int delay = 2;
    double threshold = 0.7;
    string norm = "euclidean";
    RecurrencePlot rp(time_series, time_series_length, dimension, delay, threshold, norm);
    
    cout << "test_recurrence_plot_euclidean.cpp" << endl << endl;
    test_delay(rp.get_delay());
    test_dimension(rp.get_dimension());
    test_threshold(rp.get_threshold());
    test_norm(rp.get_norm());
    test_time_series_length(rp.get_time_series_length());
    test_time_series(rp.get_time_series());
    test_number_of_vectors(rp.get_number_of_vectors());
    test_distance_matrix(rp.get_distance_matrix());
    test_recurrence_matrix(rp.get_recurrence_matrix());
    
    return (EXIT_SUCCESS);
}

