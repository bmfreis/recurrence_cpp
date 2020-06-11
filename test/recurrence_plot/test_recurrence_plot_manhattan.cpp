/* 
 * File:   test_recurrence_plot_manhattan.cpp
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
            {{0.00000,1.42741,2.25511,1.95274,0.65169,0.03463,1.51827,2.49010,1.62216,0.98801,1.14798,1.35107,1.74157,1.09509,0.72866,1.41042},
             {1.42741,0.00000,0.88011,1.45466,1.01923,1.39871,0.12336,1.17460,1.33830,1.68843,1.73115,1.27866,2.01871,0.80721,1.47957,0.02358},
             {2.25511,0.88011,0.00000,1.61718,1.84693,2.22641,0.77399,0.29832,1.50082,1.85094,1.89367,0.92511,1.57411,1.21518,1.53799,0.89986},
             {1.95274,1.45466,1.61718,0.00000,1.33819,1.91810,1.33130,1.31885,0.33058,0.96473,1.01305,1.79423,1.49931,2.00903,2.68139,1.47824},
             {0.65169,1.01923,1.84693,1.33819,0.00000,0.67655,1.11009,2.08192,1.00761,0.96627,1.36415,1.37987,2.11991,0.67084,1.36950,1.00224},
             {0.03463,1.39871,2.22641,1.91810,0.67655,0.00000,1.48957,2.46140,1.58752,0.95337,1.11927,1.32237,1.71286,1.12589,0.76329,1.38172},
             {1.51827,0.12336,0.77399,1.33130,1.11009,1.48957,0.00000,1.06847,1.21494,1.56507,1.60779,1.17254,1.91258,0.91531,1.58767,0.14694},
             {2.49010,1.17460,0.29832,1.31885,2.08192,2.46140,1.06847,0.00000,1.20250,1.64896,1.59534,1.13903,1.27579,1.45017,1.77298,1.19434},
             {1.62216,1.33830,1.50082,0.33058,1.00761,1.58752,1.21494,1.20250,0.00000,0.63415,0.84465,1.46365,1.60041,1.67845,2.35082,1.36188},
             {0.98801,1.68843,1.85094,0.96473,0.96627,0.95337,1.56507,1.64896,0.63415,0.00000,0.39788,0.92584,1.15364,1.55654,1.71667,1.71200},
             {1.14798,1.73115,1.89367,1.01305,1.36415,1.11927,1.60779,1.59534,0.84465,0.39788,0.00000,0.96856,0.75576,1.59926,1.66834,1.75473},
             {1.35107,1.27866,0.92511,1.79423,1.37987,1.32237,1.17254,1.13903,1.46365,0.92584,0.96856,0.00000,0.74005,0.72705,0.88717,1.29841},
             {1.74157,2.01871,1.57411,1.49931,2.11991,1.71286,1.91258,1.27579,1.60041,1.15364,0.75576,0.74005,0.00000,1.46709,1.18661,2.03845},
             {1.09509,0.80721,1.21518,2.00903,0.67084,1.12589,0.91531,1.45017,1.67845,1.55654,1.59926,0.72705,1.46709,0.00000,0.71668,0.78639},
             {0.72866,1.47957,1.53799,2.68139,1.36950,0.76329,1.58767,1.77298,2.35082,1.71667,1.66834,0.88717,1.18661,0.71668,0.00000,1.45875},
             {1.41042,0.02358,0.89986,1.47824,1.00224,1.38172,0.14694,1.19434,1.36188,1.71200,1.75473,1.29841,2.03845,0.78639,1.45875,0.00000}};
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
                                     {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                     {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},
                                     {1,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0},
                                     {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
                                     {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                     {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                                     {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                     {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1}};     
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
    string norm = "manhattan";
    RecurrencePlot rp(time_series, time_series_length, dimension, delay, threshold, norm);
    
    cout << "test_recurrence_plot_manhattan.cpp" << endl << endl;
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

