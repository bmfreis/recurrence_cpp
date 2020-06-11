/* 
 * File:   test_recurrence_plot_supremum.cpp
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
    string norm = "manhattan";
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
            {{0.00000,0.98895,0.96274,0.96082,0.52994,0.02975,0.98132,0.93300,0.75542,0.65130,0.82607,0.59628,0.96309,0.54811,0.72289,0.99033},
             {0.98895,0.00000,0.52132,0.86061,0.45901,0.98703,0.10711,0.59925,0.64477,0.72567,0.77119,0.67750,0.86287,0.46955,0.98929,0.02028},
             {0.96274,0.52132,0.00000,0.98895,0.96274,0.96082,0.52994,0.26666,0.98132,0.93300,0.75542,0.65130,0.82607,0.46039,0.96309,0.51940},
             {0.96082,0.86061,0.98895,0.00000,0.97940,0.93108,0.75350,0.98703,0.21584,0.59925,0.64477,0.72567,0.77119,0.98841,0.96625,0.88089},
             {0.52994,0.45901,0.96274,0.97940,0.00000,0.52801,0.45138,0.96082,0.76356,0.66987,0.84465,0.69946,0.98166,0.65130,0.82607,0.46039},
             {0.02975,0.98703,0.96082,0.93108,0.52802,0.00000,0.97940,0.93108,0.75350,0.62155,0.79632,0.59925,0.93334,0.55108,0.72586,0.98841},
             {0.98132,0.10711,0.52994,0.75350,0.45138,0.97940,0.00000,0.52802,0.53766,0.71804,0.76356,0.66987,0.84465,0.46192,0.98166,0.12740},
             {0.93300,0.59925,0.26666,0.98703,0.96082,0.93108,0.52802,0.00000,0.97940,0.93108,0.75350,0.62155,0.79632,0.72705,0.93334,0.61953},
             {0.75542,0.64477,0.98132,0.21584,0.76356,0.75350,0.53766,0.97940,0.00000,0.49214,0.53766,0.71804,0.76356,0.77257,0.84465,0.66506},
             {0.65130,0.72567,0.93300,0.59925,0.66987,0.62155,0.71804,0.93108,0.49214,0.00000,0.17758,0.66972,0.71524,0.67888,0.79632,0.72705},
             {0.82607,0.77119,0.75542,0.64477,0.84465,0.79632,0.76356,0.75350,0.53766,0.17758,0.00000,0.49214,0.53766,0.85365,0.83149,0.77257},
             {0.59628,0.67750,0.65130,0.72567,0.69946,0.59925,0.66987,0.62155,0.71804,0.66972,0.49214,0.00000,0.51975,0.47093,0.44877,0.67888},
             {0.96309,0.86287,0.82607,0.77119,0.98166,0.93334,0.84465,0.79632,0.76356,0.71524,0.53766,0.51975,0.00000,0.99067,0.96851,0.88316},
             {0.54811,0.46955,0.46039,0.98841,0.65130,0.55108,0.46192,0.72705,0.77257,0.67888,0.85365,0.47093,0.99067,0.00000,0.51975,0.47093},
             {0.72289,0.98929,0.96309,0.96625,0.82607,0.72586,0.98166,0.93334,0.84465,0.79632,0.83149,0.44877,0.96851,0.51975,0.00000,0.99067},
             {0.99033,0.02028,0.51940,0.88089,0.46039,0.98841,0.12740,0.61953,0.66506,0.72705,0.77257,0.67888,0.88316,0.47093,0.99067,0.00000}};
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
    int recurrence_matrix[16][16] = {{1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0},
                                     {0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1},
                                     {0,1,1,0,0,0,1,1,0,0,0,1,0,1,0,1},
                                     {0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0},
                                     {1,1,0,0,1,1,1,0,0,1,0,1,0,1,0,1},
                                     {1,0,0,0,1,1,0,0,0,1,0,1,0,1,0,0},
                                     {0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1},
                                     {0,1,1,0,0,0,1,1,0,0,0,1,0,0,0,1},
                                     {0,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1},
                                     {1,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0},
                                     {0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0},
                                     {1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1},
                                     {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
                                     {1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1},
                                     {0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0},
                                     {0,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1}};    
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
    string norm = "supremum";
    RecurrencePlot rp(time_series, time_series_length, dimension, delay, threshold, norm);
    
    cout << "test_recurrence_plot_supremum.cpp" << endl << endl;
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
