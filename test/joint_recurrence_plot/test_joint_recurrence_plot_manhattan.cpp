/* 
 * File:   test_joint_recurrence_plot_manhattan.cpp
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
        cout << "test_number_of_vectors() failed: " << number_of_vectors 
             << " != " << rp_number_of_vectors << endl;
}

void test_distance_matrix_1(double** jrp_distance_matrix){
    double distance_matrix[16][16] = 
           {{0.000000,1.293856,0.892068,1.144208,0.920605,1.131288,1.623309,0.099321,1.154160,0.897564,0.519489,0.739980,1.333801,0.643025,1.230414,0.892232},
            {1.293856,0.000000,1.224808,0.824512,0.906040,0.606390,0.854031,1.244001,0.237874,1.022887,0.774366,1.014478,0.588352,1.057251,0.108310,1.161343},
            {0.892068,1.224808,0.000000,1.641920,0.546434,1.045242,0.958907,0.991389,1.127295,0.233163,1.115380,0.210330,1.088725,0.327096,1.179720,0.077890},
            {1.144208,0.824512,1.641920,0.000000,1.323152,1.271542,0.765564,1.094353,1.020205,1.439999,0.624719,1.431590,0.553195,1.474363,0.914469,1.578454},
            {0.920605,0.906040,0.546434,1.323152,0.000000,1.395252,0.785255,0.839508,1.026737,0.493689,0.820441,0.543522,0.769957,0.277579,0.897173,0.546598},
            {1.131288,0.606390,1.045242,1.271542,1.395252,0.000000,1.460420,1.230609,0.368515,1.077921,1.080390,0.851730,1.194741,1.117673,0.498079,1.008194},
            {1.623309,0.854031,0.958907,0.765564,0.785255,1.460420,0.000000,1.573454,1.091905,0.725744,1.103819,1.042869,0.289508,0.994708,0.962341,0.881017},
            {0.099321,1.244001,0.991389,1.094353,0.839508,1.230609,1.573454,0.000000,1.104306,0.938644,0.469635,0.839301,1.283946,0.664292,1.180559,0.991553},
            {1.154160,0.237874,1.127295,1.020205,1.026737,0.368515,1.091905,1.104306,0.000000,0.925374,0.829053,0.916965,0.826226,0.959738,0.129564,1.063829},
            {0.897564,1.022887,0.233163,1.439999,0.493689,1.077921,0.725744,0.938644,0.925374,0.000000,0.913460,0.317125,0.886804,0.274351,0.977799,0.155273},
            {0.519489,0.774366,1.115380,0.624719,0.820441,1.080390,1.103819,0.469635,0.829053,0.913460,0.000000,0.905051,0.814312,0.947824,0.723317,1.051915},
            {0.739980,1.014478,0.210330,1.431590,0.543522,0.851730,1.042869,0.839301,0.916965,0.317125,0.905051,0.000000,0.878395,0.265943,0.969390,0.161851},
            {1.333801,0.588352,1.088725,0.553195,0.769957,1.194741,0.289508,1.283946,0.826226,0.886804,0.814312,0.878395,0.000000,0.921169,0.696662,1.025260},
            {0.643025,1.057251,0.327096,1.474363,0.277579,1.117673,0.994708,0.664292,0.959738,0.274351,0.947824,0.265943,0.921169,0.000000,1.012163,0.327261},
            {1.230414,0.108310,1.179720,0.914469,0.897173,0.498079,0.962341,1.180559,0.129564,0.977799,0.723317,0.969390,0.696662,1.012163,0.000000,1.116254},
            {0.892232,1.161343,0.077890,1.578454,0.546598,1.008194,0.881017,0.991553,1.063829,0.155273,1.051915,0.161851,1.025260,0.327261,1.116254,0.000000}};
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
           {{0.000000,1.309548,0.970034,1.135406,1.094845,1.331236,1.958862,0.417761,1.137789,1.959333,0.885254,1.852253,1.828750,0.980402,0.878091,0.119603},
            {1.309548,0.000000,1.200593,1.119541,1.050234,0.605814,0.868781,1.253178,0.784744,1.130588,1.720671,0.763740,0.662485,1.025014,1.183698,1.375611},
            {0.970034,1.200593,0.000000,1.728290,0.820715,1.058329,1.286808,1.387795,1.213225,1.287278,1.855288,1.964332,1.156696,1.592018,1.649163,0.850431},
            {1.135406,1.119541,1.728290,0.000000,1.205555,1.615360,0.912876,0.967996,1.421913,0.823926,0.601130,0.906247,1.782026,1.442716,0.547826,1.201469},
            {1.094845,1.050234,0.820715,1.205555,0.000000,1.656048,0.963035,0.852451,1.834978,0.963505,1.034573,1.441597,1.348583,2.075248,1.126428,1.200413},
            {1.331236,0.605814,1.058329,1.615360,1.656048,0.000000,1.474595,1.748996,0.268351,1.736402,2.216490,0.906003,0.771460,0.723090,1.679516,1.211633},
            {1.958862,0.868781,1.286808,0.912876,0.963035,1.474595,0.000000,1.791451,1.653525,0.285841,1.514007,0.876522,0.869149,1.893794,1.371282,2.024924},
            {0.417761,1.253178,1.387795,0.967996,0.852451,1.748996,1.791451,0.000000,1.555550,1.791922,0.556914,1.684842,1.915663,1.222797,0.535313,0.537364},
            {1.137789,0.784744,1.213225,1.421913,1.834978,0.268351,1.653525,1.555550,0.000000,1.915332,2.023044,1.063314,1.039811,0.529644,1.486070,1.018187},
            {1.959333,1.130588,1.287278,0.823926,0.963505,1.736402,0.285841,1.791922,1.915332,0.000000,1.309912,1.138330,1.154991,2.155602,1.371752,2.025395},
            {0.885254,1.720671,1.855288,0.601130,1.034573,2.216490,1.514007,0.556914,2.023044,1.309912,0.000000,1.507378,2.383156,1.779711,0.741538,1.004857},
            {1.852253,0.763740,1.964332,0.906247,1.441597,0.906003,0.876522,1.684842,1.063314,1.138330,1.507378,0.000000,0.957525,1.403564,1.264672,1.918315},
            {1.828750,0.662485,1.156696,1.782026,1.348583,0.771460,0.869149,1.915663,1.039811,1.154991,2.383156,0.957525,0.000000,1.380061,1.846182,1.894812},
            {0.980402,1.025014,1.592018,1.442716,2.075248,0.723090,1.893794,1.222797,0.529644,2.155602,1.779711,1.403564,1.380061,0.000000,1.038173,0.901043},
            {0.878091,1.183698,1.649163,0.547826,1.126428,1.679516,1.371282,0.535313,1.486070,1.371752,0.741538,1.264672,1.846182,1.038173,0.000000,0.958188},
            {0.119603,1.375611,0.850431,1.201469,1.200413,1.211633,2.024924,0.537364,1.018187,2.025395,1.004857,1.918315,1.894812,0.901043,0.958188,0.000000}};
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
    double recurrence_matrix[16][16] = {{1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0},
                                        {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1},
                                        {0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0},
                                        {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0},
                                        {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
                                        {1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0},
                                        {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1},
                                        {1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0},
                                        {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1},
                                        {0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0},
                                        {1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0},
                                        {0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1}};
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
    double recurrence_matrix[16][16] = {{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
                                        {0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
                                        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                        {0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0},
                                        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                                        {1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1},
                                        {0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                                        {0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                                        {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                                        {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0},
                                        {0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0},
                                        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}};
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
                                     {0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
                                     {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
                                     {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                                     {0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0},
                                     {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                                     {1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
                                     {0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                                     {0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                                     {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};
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
    string norm = "manhattan";
    JointRecurrencePlot jrp(time_series_1, time_series_2, time_series_length, 
                            dimension, delay, threshold, norm);
    
    cout << "test_joint_recurrence_plot_manhattan.cpp" << endl << endl;
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
