/* 
 * File:   test_joint_recurrence_plot_supremum.cpp
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
    string norm = "supremum";
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
           {{0.000000,0.581057,0.705677,0.642231,0.633119,0.714789,0.746952,0.074588,0.630146,0.721298,0.234296,0.558531,0.530933,0.603998,0.603491,0.712889},
            {0.581057,0.000000,0.508499,0.337432,0.622332,0.392978,0.338952,0.596678,0.167694,0.433911,0.371394,0.479378,0.274203,0.588269,0.076699,0.476684},
            {0.705677,0.508499,0.000000,0.756064,0.360043,0.642231,0.671422,0.714789,0.557589,0.142954,0.630146,0.147146,0.644766,0.145648,0.530933,0.038863},
            {0.642231,0.337432,0.756064,0.000000,0.508499,0.730410,0.622332,0.567643,0.505126,0.613110,0.407935,0.722001,0.371394,0.610416,0.414132,0.717201},
            {0.633119,0.622332,0.360043,0.508499,0.000000,0.756064,0.360043,0.642231,0.671422,0.217089,0.557589,0.325980,0.348129,0.214395,0.644766,0.321180},
            {0.714789,0.392978,0.642231,0.730410,0.756064,0.000000,0.645767,0.730410,0.225284,0.567643,0.505126,0.613110,0.619112,0.722001,0.316278,0.610416},
            {0.746952,0.338952,0.671422,0.622332,0.360043,0.645767,0.000000,0.756064,0.420483,0.528468,0.671422,0.637358,0.250938,0.525774,0.348129,0.632559},
            {0.074588,0.596678,0.714789,0.567643,0.642231,0.730410,0.756064,0.000000,0.645767,0.730410,0.225284,0.567643,0.505126,0.613110,0.619112,0.722001},
            {0.630146,0.167694,0.557589,0.505126,0.671422,0.225284,0.420483,0.645767,0.000000,0.483001,0.420483,0.528468,0.393828,0.637358,0.090994,0.525774},
            {0.721298,0.433911,0.142954,0.613110,0.217089,0.567643,0.528468,0.730410,0.483001,0.000000,0.645767,0.162767,0.501812,0.154358,0.456345,0.104091},
            {0.234296,0.371394,0.630146,0.407935,0.557589,0.505126,0.671422,0.225284,0.420483,0.645767,0.000000,0.483001,0.420483,0.528468,0.393828,0.637358},
            {0.558531,0.479378,0.147146,0.722001,0.325980,0.613110,0.637358,0.567643,0.528468,0.162767,0.483001,0.000000,0.610703,0.111585,0.501812,0.154358},
            {0.530933,0.274203,0.644766,0.371394,0.348129,0.619112,0.250938,0.505126,0.393828,0.501812,0.420483,0.610703,0.000000,0.499118,0.302834,0.605904},
            {0.603998,0.588269,0.145648,0.610416,0.214395,0.722001,0.525774,0.613110,0.637358,0.154358,0.528468,0.111585,0.499118,0.000000,0.610703,0.111585},
            {0.603491,0.076699,0.530933,0.414132,0.644766,0.316278,0.348129,0.619112,0.090994,0.456345,0.393828,0.501812,0.302834,0.610703,0.000000,0.499118},
            {0.712889,0.476684,0.038863,0.717201,0.321180,0.610416,0.632559,0.722001,0.525774,0.104091,0.637358,0.154358,0.605904,0.111585,0.499118,0.000000}};    
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
           {{0.000000,0.632469,0.721563,0.709765,0.622082,0.809246,0.771072,0.292586,0.764536,0.808211,0.767337,0.907692,0.866818,0.714546,0.467931,0.092832},
            {0.632469,0.000000,0.532988,0.472700,0.681978,0.374039,0.427989,0.669961,0.411491,0.571145,0.707413,0.377999,0.356494,0.626143,0.585269,0.612716},
            {0.721563,0.532988,0.000000,0.858755,0.572244,0.709765,0.814045,0.809246,0.665055,0.957201,0.916327,0.808211,0.767337,0.907692,0.866818,0.714546},
            {0.709765,0.472700,0.858755,0.000000,0.532988,0.846738,0.681978,0.417179,0.884191,0.669961,0.411491,0.571145,0.707413,0.789494,0.241835,0.802598},
            {0.622082,0.681978,0.572244,0.532988,0.000000,0.858755,0.572244,0.709765,0.814045,0.441576,0.665055,0.957201,0.916327,0.808211,0.767337,0.615065},
            {0.809246,0.374039,0.709765,0.846738,0.858755,0.000000,0.802028,0.846738,0.186188,0.945184,0.904310,0.752038,0.411491,0.571145,0.604903,0.789494},
            {0.771072,0.427989,0.814045,0.681978,0.572244,0.802028,0.000000,0.858755,0.839480,0.143156,0.814045,0.441576,0.499631,0.957201,0.916327,0.764055},
            {0.292586,0.669961,0.809246,0.417179,0.709765,0.846738,0.858755,0.000000,0.802028,0.846738,0.474751,0.945184,0.904310,0.752038,0.302397,0.385418},
            {0.764536,0.411491,0.665055,0.884191,0.814045,0.186188,0.839480,0.802028,0.000000,0.982636,0.941763,0.789490,0.597679,0.384957,0.642356,0.744783},
            {0.808211,0.571145,0.957201,0.669961,0.441576,0.945184,0.143156,0.846738,0.982636,0.000000,0.802028,0.515625,0.642787,0.945184,0.904310,0.901043},
            {0.767337,0.707413,0.916327,0.411491,0.665055,0.904310,0.814045,0.474751,0.941763,0.802028,0.000000,0.982636,0.941763,0.847065,0.339849,0.860170},
            {0.907692,0.377999,0.808211,0.571145,0.957201,0.752038,0.441576,0.945184,0.789490,0.515625,0.982636,0.000000,0.467011,0.694793,0.642787,0.887939},
            {0.866818,0.356494,0.767337,0.707413,0.916327,0.411491,0.499631,0.904310,0.597679,0.642787,0.941763,0.467011,0.000000,0.982636,0.941763,0.847065},
            {0.714546,0.626143,0.907692,0.789494,0.808211,0.571145,0.957201,0.752038,0.384957,0.945184,0.847065,0.694793,0.982636,0.000000,0.547659,0.694793},
            {0.467931,0.585269,0.866818,0.241835,0.767337,0.604903,0.916327,0.302397,0.642356,0.904310,0.339849,0.642787,0.941763,0.547659,0.000000,0.560763},
            {0.092832,0.612716,0.714546,0.802598,0.615065,0.789494,0.764055,0.385418,0.744783,0.901043,0.860170,0.887939,0.847065,0.694793,0.560763,0.000000}};
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
    double recurrence_matrix[16][16] = {{1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0},
                                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1},
                                        {1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,0},
                                        {1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,1,0,0,1,1,0,1,1,1,1,1,0,1,1},
                                        {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
                                        {1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0},
                                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
                                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                        {0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1}};
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
    double recurrence_matrix[16][16] = {{1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1},
                                        {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
                                        {0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
                                        {0,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0},
                                        {1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1},
                                        {0,1,0,0,0,1,0,0,1,0,0,0,1,1,1,0},
                                        {0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0},
                                        {1,1,0,1,0,0,0,1,0,0,1,0,0,0,1,1},
                                        {0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0},
                                        {0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0},
                                        {0,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0},
                                        {0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0},
                                        {0,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0},
                                        {0,1,0,0,0,1,0,0,1,0,0,1,0,1,1,1},
                                        {1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1},
                                        {1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1}};
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
    int recurrence_matrix[16][16] = {{1,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0},
                                     {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
                                     {0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
                                     {0,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0},
                                     {1,1,1,1,1,0,1,0,0,1,1,0,0,0,0,1},
                                     {0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0},
                                     {0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0},
                                     {1,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0},
                                     {0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0},
                                     {0,1,0,1,1,0,1,0,0,1,0,1,1,0,0,0},
                                     {0,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0},
                                     {0,1,0,0,0,0,1,0,0,1,0,1,1,1,1,0},
                                     {0,1,0,0,0,1,1,0,1,1,0,1,1,0,0,0},
                                     {0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1},
                                     {1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1},
                                     {0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1}};
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
    string norm = "supremum";
    JointRecurrencePlot jrp(time_series_1, time_series_2, time_series_length, 
                            dimension, delay, threshold, norm);
    
    cout << "test_joint_recurrence_plot_supremum.cpp" << endl << endl;
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
