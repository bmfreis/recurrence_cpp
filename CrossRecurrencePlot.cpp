/* 
 * File:   CrossRecurrencePlot.cpp
 * Author: Barbara Reis
 * Date:   11.06.2020
 */

#include <valarray>

#include "CrossRecurrencePlot.h"

CrossRecurrencePlot::CrossRecurrencePlot(CrossRecurrencePlot& crp) {
    time_series_1           = crp.get_time_series_1();
    time_series_1_length    = crp.get_time_series_1_length();
    delay_time_series_1     = crp.get_delay_time_series_1();
    time_series_2           = crp.get_time_series_2();
    time_series_2_length    = crp.get_time_series_2_length();
    delay_time_series_2     = crp.get_delay_time_series_2();
    dimension               = crp.get_dimension();
    norm                    = crp.get_norm();
    threshold               = crp.get_threshold();
    number_of_vectors_1     = crp.get_number_of_vectors_1();
    number_of_vectors_2     = crp.get_number_of_vectors_2();
    cross_distance_matrix   = crp.get_cross_distance_matrix();
    cross_recurrence_matrix = crp.get_cross_recurrence_matrix();
}

CrossRecurrencePlot::CrossRecurrencePlot(double* time_series_1, double* time_series_2, 
        int time_series_1_length, int time_series_2_length, int dimension, 
        int delay_time_series_1, int delay_time_series_2, double threshold, 
        string norm){
    
    calculate_cross_recurrence_matrix(time_series_1, time_series_2, 
                    time_series_1_length, time_series_2_length, dimension, 
                    delay_time_series_1, delay_time_series_2, threshold, norm);
}


CrossRecurrencePlot::~CrossRecurrencePlot() {
    for(int i = 0; i < number_of_vectors_1; i++){
        delete[] cross_distance_matrix[i];
        delete[] cross_recurrence_matrix[i];
    }
    delete[] cross_distance_matrix;
    delete[] cross_recurrence_matrix;    
}

/*
 * Setters
 */
void CrossRecurrencePlot::set_delay_time_series_1(int value){
    try{
        if (value < 1)
            throw 1;
        delay_time_series_1 = value;
    } catch (int type){
        if (type == 1)
            cout << "The delay must be greater than or equal to 1" << endl;
    }       
}

void CrossRecurrencePlot::set_delay_time_series_2(int value){
    try{
        if (value < 1)
            throw 1;
        delay_time_series_2 = value;
    } catch (int type){
        if (type == 1)
            cout << "The delay must be greater than or equal to 1" << endl;
    }       
}

void CrossRecurrencePlot::set_dimension(int value){
    try{
        if (value < 1)
            throw 1;
        dimension = value;
    } catch(int type){
        if (type == 1)
            cout << "The dimension must be greater than or equal to 1" << endl;
    }    
}

void CrossRecurrencePlot::set_norm(string value){
    try{
        if (value.compare("manhattan") != 0 and value.compare("euclidean") != 0 and value.compare("supremum") != 0)
            throw 1;
        norm = value;
    } catch(int type){
        if (type == 1)
            cout << "Norm must be equals to \'manhattan\', \'euclidean\' or \'supremum\'" 
                 << endl;
    }    
}

void CrossRecurrencePlot::set_number_of_vectors_1(int value){
    try{
        if(value < 1)
            throw 1;
        if(value > time_series_1_length)
            throw 2;
        number_of_vectors_1 = value;
    } catch(int type){
        if(type == 1)
            cout << "Number of vectors must be greater than or equals to 1" 
                 << endl;
        if(type == 2)
            cout << "Number of vectors must be less than or equals to" 
                 << time_series_1_length << endl;
    }        
}

void CrossRecurrencePlot::set_number_of_vectors_2(int value){
    try{
        if(value < 1)
            throw 1;
        if(value > time_series_2_length)
            throw 2;
        number_of_vectors_2 = value;
    } catch(int type){
        if(type == 1)
            cout << "Number of vectors must be greater than or equals to 1" 
                 << endl;
        if(type == 2)
            cout << "Number of vectors must be less than or equals to" 
                 << time_series_2_length << endl;
    }    
}

void CrossRecurrencePlot::set_threshold(double value){
    try{
        if (value < 0)
            throw 1;
        threshold = value;
    } catch(int type){
        if (type == 1)
            cout << "The threshold must be greater than 0" << endl;                    
    }    
}

void CrossRecurrencePlot::set_time_series_1(double* value){
    try{
        if(value == NULL)        
            throw 1;
        time_series_1 = value;
    } catch(int type){
        if(type == 1)
            cout << "Time series 1 is empty" << endl;
    }    
}   

void CrossRecurrencePlot::set_time_series_2(double* value){
    try{
        if(value == NULL)        
            throw 1;
        time_series_2 = value;
    } catch(int type){
        if(type == 1)
            cout << "Time series 2 is empty" << endl;
    }    
}   

void CrossRecurrencePlot::set_time_series_1_length(int value){
    try{
        if (value < 0)
            throw 1;
        time_series_1_length = value;
    } catch(int type){
        if (type == 1)
            cout << "The time series 1 length must be greater than or equal to 1" 
                 << endl;
    }    
}

void CrossRecurrencePlot::set_time_series_2_length(int value){
    try{
        if (value < 0)
            throw 1;
        time_series_2_length = value;
    } catch(int type){
        if (type == 1)
            cout << "The time series 2 length must be greater than or equal to 1" 
                 << endl;
    }        
}

/*
 * Getters
 */
double** CrossRecurrencePlot::get_cross_distance_matrix(){
    return cross_distance_matrix;
}

int** CrossRecurrencePlot::get_cross_recurrence_matrix(){
    return cross_recurrence_matrix;
}

int CrossRecurrencePlot::get_delay_time_series_1(){
    return delay_time_series_1;
}

int CrossRecurrencePlot::get_delay_time_series_2(){
    return delay_time_series_2;
}

int CrossRecurrencePlot::get_dimension(){
    return dimension;
}

string CrossRecurrencePlot::get_norm(){
    return norm;
}

int CrossRecurrencePlot::get_number_of_vectors_1(){
    return number_of_vectors_1;
}

int CrossRecurrencePlot::get_number_of_vectors_2(){
    return number_of_vectors_2;
}

double CrossRecurrencePlot::get_threshold(){
    return threshold;
}

double* CrossRecurrencePlot::get_time_series_1(){
    return time_series_1;
}

double* CrossRecurrencePlot::get_time_series_2(){
    return time_series_2;
}

int CrossRecurrencePlot::get_time_series_1_length(){
    return time_series_1_length;
}

int CrossRecurrencePlot::get_time_series_2_length(){
    return time_series_2_length;
}

/*
 *
 */
void CrossRecurrencePlot::calculate_cross_distance_matrix(){
    cross_distance_matrix = new double*[number_of_vectors_1];
    for(int i = 0; i < number_of_vectors_1; i++)
        cross_distance_matrix[i] = new double[number_of_vectors_2];
        
    if (norm.compare("manhattan") == 0){
        double temp;
        for (int i = 0; i < number_of_vectors_1; i++){
            for (int j = 0; j < number_of_vectors_2; j++){
                temp = 0.0;
                for (int k = 0; k < dimension; k++)
                     temp += fabs(time_series_1[i+k*delay_time_series_1] - time_series_2[j+k*delay_time_series_2]);               
                cross_distance_matrix[i][j] = temp;
            }
        }
    }        
    else if (norm.compare("euclidean") == 0){
        double temp;
        for(int i = 0; i < number_of_vectors_1; i++){
            for(int j = 0; j < number_of_vectors_2; j++){
                temp = 0.0;
                for(int k = 0; k < dimension; k++)
                     temp += pow(time_series_1[i+k*delay_time_series_1] - time_series_2[j+k*delay_time_series_2], 2);
                cross_distance_matrix[i][j] = sqrt(temp);
            }
        }
    }
    else if (norm.compare("supremum") == 0){
        double max, temp;
        for (int i = 0; i < number_of_vectors_1; i++){
            for(int j = 0; j < number_of_vectors_2; j++){
                max = fabs(time_series_1[i] - time_series_2[j]);
                for (int k = 1; k < dimension; k++){
                    temp = fabs(time_series_1[i+k*delay_time_series_1] - time_series_2[j+k*delay_time_series_2]);
                    if (temp > max)
                        max = temp;
                }
                cross_distance_matrix[i][j] = max;
            }
        }
    }
}    
    
/*
 * Calculating the cross recurrence matrix
 */
void CrossRecurrencePlot::calculate_cross_recurrence_matrix(){
    cross_recurrence_matrix = new int*[number_of_vectors_1];
    for(int i = 0; i < number_of_vectors_1; i++)
        cross_recurrence_matrix[i] = new int[number_of_vectors_2];
                
    for (int i = 0; i < number_of_vectors_1; i++){
        for (int j = 0; j < number_of_vectors_2; j++){
            if (cross_distance_matrix[i][j] <= threshold){
                cross_recurrence_matrix[i][j] = 1;
            } else {
                cross_recurrence_matrix[i][j] = 0;
            }
        }
    }    
}

void CrossRecurrencePlot::calculate_cross_recurrence_matrix(double* time_series, 
        int time_series_length, int delay, int which_time_series){
    if(which_time_series == 1)
        calculate_cross_recurrence_matrix(time_series, time_series_2, 
                    time_series_length, time_series_2_length, dimension, 
                    delay, delay_time_series_2, threshold, norm);
    else
        calculate_cross_recurrence_matrix(time_series_1, time_series, 
                    time_series_1_length, time_series_length, dimension, 
                    delay_time_series_1, delay, threshold, norm);
}

void CrossRecurrencePlot::calculate_cross_recurrence_matrix(double threshold){
    calculate_cross_recurrence_matrix(time_series_1, time_series_2, 
                    time_series_1_length, time_series_2_length, dimension, 
                    delay_time_series_1, delay_time_series_2, threshold, norm);    
}

void CrossRecurrencePlot::calculate_cross_recurrence_matrix(string norm){
    calculate_cross_recurrence_matrix(time_series_1, time_series_2, 
                    time_series_1_length, time_series_2_length, dimension, 
                    delay_time_series_1, delay_time_series_2, threshold, norm);    
}

void CrossRecurrencePlot::calculate_cross_recurrence_matrix(double* time_series_1, 
        double* time_series_2, int time_series_1_length, int time_series_2_length, 
        int dimension, int delay_time_series_1, int delay_time_series_2, 
        double threshold, string norm){
    
    set_time_series_1_length(time_series_1_length);
    set_time_series_1(time_series_1);
    set_time_series_2_length(time_series_2_length);
    set_time_series_2(time_series_2);
    set_dimension(dimension);
    set_delay_time_series_1(delay_time_series_1);
    set_delay_time_series_2(delay_time_series_2);
    set_threshold(threshold);
    set_norm(norm);
    set_number_of_vectors_1((int)(time_series_1_length - (dimension-1) * delay_time_series_1));
    set_number_of_vectors_2((int)(time_series_2_length - (dimension-1) * delay_time_series_2));
    calculate_cross_distance_matrix();
    calculate_cross_recurrence_matrix();
}


/*
 * Printing details
 */
void CrossRecurrencePlot::print_details(){
    cout << "=============================================" << endl;
    cout << "    Cross recurrence plot configurations"      << endl;
    cout << "=============================================" << endl;
    cout << "Dimension: "                                   << dimension            << endl;
    cout << "Delay time series 1: "                         << delay_time_series_1  << endl;
    cout << "Delay time series 2: "                         << delay_time_series_2  << endl;
    cout << "Threshold: "                                   << threshold            << endl;
    cout << "Norm: "                                        << norm                 << endl;
    cout << "Time series 1 length: "                        << time_series_1_length << endl;
    cout << "Time series 2 length: "                        << time_series_2_length << endl;
    cout << "Number of vectors 1: "                         << number_of_vectors_1  << endl;
    cout << "Number of vectors 2: "                         << number_of_vectors_2  << endl;    
    print_time_series_1();
    print_time_series_2();
    print_cross_distance_matrix();    
    print_cross_recurrence_matrix();    
}

void CrossRecurrencePlot::print_cross_distance_matrix(){
    cout << "=============================================" << endl;
    cout << "    Cross distance matrix"                     << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors_1; i++){
        for (int j = 0; j < number_of_vectors_2; j++){
            cout << cross_distance_matrix[i][j] << " ";
        }
        cout << endl;
    }    
}

void CrossRecurrencePlot::print_cross_recurrence_matrix(){
    cout << "=============================================" << endl;
    cout << "    Cross recurrence matrix"                   << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors_1; i++){
        for (int j = 0; j < number_of_vectors_2; j++){
            cout << cross_recurrence_matrix[i][j] << " ";
        }
        cout << endl;
    }    
}

void CrossRecurrencePlot::print_time_series_1(){
    cout << "=============================================" << endl;
    cout << "    Time series 1"                             << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < time_series_1_length; i++)
            cout << time_series_1[i] << " ";
    cout << endl;    
}

void CrossRecurrencePlot::print_time_series_2(){
    cout << "=============================================" << endl;
    cout << "    Time series 2"                             << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < time_series_2_length; i++)
            cout << time_series_2[i] << " ";
    cout << endl;    
}


/*
 * Saving details
 */
void CrossRecurrencePlot::write_cross_distance_matrix(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors_1; i++){
            for(j = 0; j < number_of_vectors_2-1; j++){
                myfile << cross_distance_matrix[i][j] << ",";
            }
            myfile << cross_distance_matrix[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void CrossRecurrencePlot::write_cross_recurrence_matrix(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors_1; i++){
            for(j = 0; j < number_of_vectors_2-1; j++){
                myfile << cross_recurrence_matrix[i][j] << ",";
            }
            myfile << cross_recurrence_matrix[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void CrossRecurrencePlot::write_cross_recurrence_adjacency_list(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < number_of_vectors_1; i++){
            for(int j = 0; j < number_of_vectors_2; j++){
                if (cross_recurrence_matrix[i][j] == 1)
                    myfile << i << "," << j << endl;
            }
        }
        myfile.close();
    } else 
        cout << "Unable to open file";     
}

void CrossRecurrencePlot::write_time_series_1(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < time_series_1_length; i++)
            myfile << time_series_1[i] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";      
}

void CrossRecurrencePlot::write_time_series_2(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < time_series_2_length; i++)
            myfile << time_series_2[i] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";      
}
