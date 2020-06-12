/* 
 * File:   test_joint_recurrence_plot_euclidean.cpp
 * Author: Barbara Reis
 * Date:   12.06.2020
 */

#include <stdlib.h>
#include <iostream>
#include "../../JointRecurrencePlot.h"


void test_delay(int rp_delay){
    int delay = 2;
    if(delay == rp_delay)
        cout << "test_delay() passed" << endl;
    else
        cout << "test_delay() failed: " << delay << " != " 
             << rp_delay << endl;
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

void test_time_series_1(double* rp_time_series_1){
    double time_series_1[] = {0.20000000, 0.60800000, 0.90567680, 0.32462007, 
                              0.83311914, 0.52832022, 0.94695227, 0.19088795, 
                              0.58690901, 0.92129793, 0.27553060, 0.75853125, 
                              0.69601406, 0.80399826, 0.59882321, 0.91288909, 
                              0.30218586, 0.80130435, 0.60501961, 0.90808935};
    bool found_error = false;
    int i;    
    for(i = 0; i < 20; i++){
        if(time_series_1[i] != rp_time_series_1[i]){
            found_error = true;
            break;
        }
    }
    if(!found_error)
        cout << "test_time_series_1() passed" << endl;
    else
        cout << "test_time_series_1() failed: time series value error at " 
             << i << " ( " << time_series_1[i] << " != " << rp_time_series_1[i] 
             << " )" << endl;
}

void test_time_series_2(double* rp_time_series_2){
    double time_series_2[] = {0.20001000, 0.64002400, 0.92157312, 0.28910442, 
                              0.82209222, 0.58502640, 0.97108205, 0.11232682, 
                              0.39883801, 0.95906501, 0.15703728, 0.52950629, 
                              0.99651751, 0.01388143, 0.05475495, 0.20702737, 
                              0.65666815, 0.90182036, 0.35416159, 0.91492463};
    bool found_error = false;
    int i;    
    for(i = 0; i < 20; i++){
        if(time_series_2[i] != rp_time_series_2[i]){
            found_error = true;
            break;
        }
    }
    if(!found_error)
        cout << "test_time_series_2() passed" << endl;
    else
        cout << "test_time_series_2() failed: time series value error at " 
             << i << " ( " << time_series_2[i] << " != " << rp_time_series_2[i] 
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
        cout << "test_number_of_vectors() failed: " << number_of_vectors 
             << " != " << rp_number_of_vectors << endl;
}

void test_distance_matrix_1(double** jrp_distance_matrix){
    double distance_matrix[16][16] = 
           {{0.000000,0.772653,0.718472,0.755241,0.680561,0.791513,0.985117,0.076749,0.752051,0.736730,0.323354,0.573288,0.788720,0.604879,0.758479,0.724379},
            {0.772653,0.000000,0.722797,0.485447,0.664386,0.422687,0.497581,0.763547,0.176000,0.602024,0.503428,0.632737,0.366157,0.677492,0.080438,0.681476},
            {0.718472,0.722797,0.000000,1.001081,0.384518,0.745330,0.716331,0.744447,0.689556,0.161998,0.732855,0.153819,0.717340,0.194718,0.702116,0.050740},
            {0.755241,0.485447,1.001081,0.000000,0.768542,0.829972,0.630789,0.703232,0.622776,0.885960,0.443782,0.886320,0.394070,0.866201,0.545737,0.966933},
            {0.680561,0.664386,0.384518,0.768542,0.000000,0.881108,0.489434,0.665262,0.723416,0.300675,0.611569,0.363679,0.470169,0.219029,0.686255,0.361571},
            {0.791513,0.422687,0.745330,0.829972,0.881108,0.000000,0.865506,0.820885,0.247689,0.700293,0.650419,0.654960,0.760153,0.782101,0.342622,0.721579},
            {0.985117,0.497581,0.716331,0.630789,0.489434,0.865506,0.000000,0.957465,0.635133,0.556229,0.753146,0.699182,0.252631,0.634931,0.557516,0.668772},
            {0.076749,0.763547,0.744447,0.703232,0.665262,0.820885,0.957465,0.000000,0.760103,0.749706,0.288832,0.599837,0.753255,0.614658,0.757150,0.747029},
            {0.752051,0.176000,0.689556,0.622776,0.723416,0.247689,0.635133,0.760103,0.000000,0.597299,0.532174,0.596462,0.521078,0.681498,0.095564,0.653970},
            {0.736730,0.602024,0.161998,0.885960,0.300675,0.700293,0.556229,0.749706,0.597299,0.000000,0.680456,0.201041,0.572778,0.193889,0.593156,0.112850},
            {0.323354,0.503428,0.732855,0.443782,0.611569,0.650419,0.753146,0.288832,0.532174,0.680456,0.000000,0.586163,0.523685,0.606062,0.509566,0.716210},
            {0.573288,0.632737,0.153819,0.886320,0.363679,0.654960,0.699182,0.599837,0.596462,0.201041,0.586163,0.000000,0.647274,0.162406,0.610005,0.154456},
            {0.788720,0.366157,0.717340,0.394070,0.470169,0.760153,0.252631,0.753255,0.521078,0.572778,0.523685,0.647274,0.000000,0.599514,0.434912,0.674650},
            {0.604879,0.677492,0.194718,0.866201,0.219029,0.782101,0.634931,0.614658,0.681498,0.193889,0.606062,0.162406,0.599514,0.000000,0.673486,0.188975},
            {0.758479,0.080438,0.702116,0.545737,0.686255,0.342622,0.557516,0.757150,0.095564,0.593156,0.509566,0.610005,0.434912,0.673486,0.000000,0.663029},
            {0.724379,0.681476,0.050740,0.966933,0.361571,0.721579,0.668772,0.747029,0.653970,0.112850,0.716210,0.154456,0.674650,0.188975,0.663029,0.000000}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if(fabs(distance_matrix[i][j]-jrp_distance_matrix[i][j]) > 0.00001){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_distance_matrix_1() passed" << endl;
    else
        cout << "test_distance_matrix_1() failed: distance value error at " 
             << i  << "," << j << " ( " << distance_matrix[i][j] << " != " 
             << jrp_distance_matrix[i][j] << " )" << endl;  
}

void test_distance_matrix_2(double** jrp_distance_matrix){
    double distance_matrix[16][16] = 
           {{0.000000,0.806120,0.743470,0.790549,0.754043,0.906575,1.144597,0.307734,0.808994,1.176047,0.772185,1.144892,1.188765,0.742682,0.556985,0.095170},
            {0.806120,0.000000,0.715811,0.658908,0.730006,0.417349,0.552101,0.854631,0.494911,0.696984,1.007421,0.480463,0.432597,0.706505,0.728657,0.819597},
            {0.743470,0.715811,0.000000,1.092555,0.599631,0.785605,0.918839,0.932003,0.846284,1.001621,1.206066,1.179280,0.832634,1.098638,1.076722,0.721170},
            {0.790549,0.658908,1.092555,0.000000,0.717777,1.013894,0.708349,0.587532,0.988438,0.679427,0.435983,0.626871,1.038233,0.917568,0.344291,0.866752},
            {0.754043,0.730006,0.599631,0.717777,0.000000,1.052385,0.638850,0.721793,1.095004,0.601616,0.749225,1.019132,0.967758,1.220646,0.830457,0.805883},
            {0.906575,0.417349,0.785605,1.013894,1.052385,0.000000,0.935081,1.060628,0.195110,1.098779,1.335195,0.760483,0.513890,0.581766,0.971290,0.876431},
            {1.144597,0.552101,0.918839,0.708349,0.638850,0.935081,0.000000,1.090893,1.044346,0.194196,1.015062,0.587945,0.607183,1.227895,0.972106,1.187924},
            {0.307734,0.854631,0.932003,0.587532,0.721793,1.060628,1.090893,0.000000,0.971307,1.080442,0.478321,1.082314,1.271118,0.844908,0.354266,0.400989},
            {0.808994,0.494911,0.846284,0.988438,1.095004,0.195110,1.044346,0.971307,0.000000,1.190866,1.284567,0.812935,0.695112,0.399572,0.883541,0.773402},
            {1.176047,0.696984,1.001621,0.679427,0.601616,1.098779,0.194196,1.080442,1.190866,0.000000,0.928988,0.698352,0.799979,1.336338,0.974545,1.231283},
            {0.772185,1.007421,1.206066,0.435983,0.749225,1.335195,1.015062,0.478321,1.284567,0.928988,0.000000,1.061835,1.397835,1.166751,0.464331,0.866809},
            {1.144892,0.480463,1.179280,0.626871,1.019132,0.760483,0.587945,1.082314,0.812935,0.698352,1.061835,0.000000,0.649574,0.886517,0.812534,1.180486},
            {1.188765,0.432597,0.832634,1.038233,0.967758,0.513890,0.607183,1.271118,0.695112,0.799979,1.397835,0.649574,0.000000,1.024139,1.157897,1.186386},
            {0.742682,0.706505,1.098638,0.917568,1.220646,0.581766,1.227895,0.844908,0.399572,1.336338,1.166751,0.886517,1.024139,0.000000,0.709773,0.721259},
            {0.556985,0.728657,1.076722,0.344291,0.830457,0.971290,0.972106,0.354266,0.883541,0.974545,0.464331,0.812534,1.157897,0.709773,0.000000,0.630668},
            {0.095170,0.819597,0.721170,0.866752,0.805883,0.876431,1.187924,0.400989,0.773402,1.231283,0.866809,1.180486,1.186386,0.721259,0.630668,0.000000}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if(fabs(distance_matrix[i][j]-jrp_distance_matrix[i][j]) > 0.00001){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_distance_matrix_2() passed" << endl;
    else
        cout << "test_distance_matrix_2() failed: distance value error at " 
             << i  << "," << j << " ( " << distance_matrix[i][j] << " != " 
             << jrp_distance_matrix[i][j] << " )" << endl;  
}

void test_recurrence_matrix_1(int** jrp_recurrence_matrix){
    double recurrence_matrix[16][16] = {{1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0},
                                        {0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1},
                                        {0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1},
                                        {0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0},
                                        {1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1},
                                        {0,1,0,0,0,1,0,0,1,0,1,1,0,0,1,0},
                                        {0,1,0,1,1,0,1,0,1,1,0,1,1,1,1,1},
                                        {1,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0},
                                        {0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1},
                                        {0,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1},
                                        {1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0},
                                        {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1},
                                        {1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1},
                                        {0,1,1,0,1,0,1,0,1,1,0,1,1,1,1,1}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if(recurrence_matrix[i][j] != jrp_recurrence_matrix[i][j]){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_recurrence_matrix_1() passed" << endl;
    else
        cout << "test_recurrence_matrix_1() failed: recurrence value error at " 
             << i  << "," << j << " ( " << recurrence_matrix[i][j] << " != " 
             << jrp_recurrence_matrix[i][j] << " )" << endl;  
}

void test_recurrence_matrix_2(int** jrp_recurrence_matrix){
    double recurrence_matrix[16][16] = {{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1},
                                        {0,1,0,1,0,1,1,0,1,1,0,1,1,0,0,0},
                                        {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                        {0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0},
                                        {0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0},
                                        {0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,0},
                                        {1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0},
                                        {0,1,0,1,1,0,1,0,0,1,0,1,0,0,0,0},
                                        {0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
                                        {0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,0},
                                        {0,1,0,0,0,1,1,0,1,0,0,1,1,0,0,0},
                                        {0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0},
                                        {1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1},
                                        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 16; i++){
        for (j = 0; j < 16; j++){
            if(recurrence_matrix[i][j] != jrp_recurrence_matrix[i][j]){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_recurrence_matrix_2() passed" << endl;
    else
        cout << "test_recurrence_matrix_2() failed: recurrence value error at " 
             << i  << "," << j << " ( " << recurrence_matrix[i][j] << " != " 
             << jrp_recurrence_matrix[i][j] << " )" << endl;  
}

void test_joint_recurrence_matrix(int** jrp_recurrence_matrix){
    int recurrence_matrix[16][16] = {{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
                                     {0,1,0,1,0,1,1,0,1,1,0,1,1,0,0,0},
                                     {0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                     {0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0},
                                     {0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0},
                                     {0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0},
                                     {0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,0},
                                     {1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
                                     {0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0},
                                     {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0},
                                     {0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
                                     {0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0},
                                     {0,1,0,0,0,0,1,0,1,0,0,1,1,0,0,0},
                                     {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},
                                     {0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}};    
    bool found_error = false;
    int i,j;
    for(i = 0; i < 16; i++){
        for(j = 0; j < 16; j++){
            if(recurrence_matrix[i][j] != jrp_recurrence_matrix[i][j]){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_joint_recurrence_matrix() passed" << endl;
    else
        cout << "test_joint_recurrence_matrix() failed: recurrence value error at " 
             << i  << "," << j << " ( " << recurrence_matrix[i][j] << " != " 
             << jrp_recurrence_matrix[i][j] << " )" << endl;    
}

int main(int argc, char** argv) {
    double time_series_1[] = {0.20000000, 0.60800000, 0.90567680, 0.32462007, 
                              0.83311914, 0.52832022, 0.94695227, 0.19088795, 
                              0.58690901, 0.92129793, 0.27553060, 0.75853125, 
                              0.69601406, 0.80399826, 0.59882321, 0.91288909, 
                              0.30218586, 0.80130435, 0.60501961, 0.90808935};

    double time_series_2[] = {0.20001000, 0.64002400, 0.92157312, 0.28910442, 
                              0.82209222, 0.58502640, 0.97108205, 0.11232682, 
                              0.39883801, 0.95906501, 0.15703728, 0.52950629, 
                              0.99651751, 0.01388143, 0.05475495, 0.20702737, 
                              0.65666815, 0.90182036, 0.35416159, 0.91492463};
    int time_series_length = 20;
    int dimension = 3;
    int delay = 2;
    double threshold = 0.7;
    string norm = "euclidean";
    JointRecurrencePlot jrp(time_series_1, time_series_2, time_series_length, 
                            dimension, delay, threshold, norm);
    
    cout << "test_joint_recurrence_plot_euclidean.cpp" << endl << endl;
    test_delay(jrp.get_delay());
    test_dimension(jrp.get_dimension());
    test_threshold(jrp.get_threshold());
    test_norm(jrp.get_norm());
    test_time_series_length(jrp.get_time_series_length());
    test_time_series_1(jrp.get_time_series_1());
    test_time_series_2(jrp.get_time_series_2());    
    test_number_of_vectors(jrp.get_number_of_vectors());    
    test_distance_matrix_1(jrp.get_distance_matrix_1());
    test_distance_matrix_2(jrp.get_distance_matrix_2());  
    test_recurrence_matrix_1(jrp.get_recurrence_matrix_1());
    test_recurrence_matrix_2(jrp.get_recurrence_matrix_2());      
    test_joint_recurrence_matrix(jrp.get_joint_recurrence_matrix());
    
    return (EXIT_SUCCESS);
}
