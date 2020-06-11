/* 
 * File:   RecurrencePlot.cpp
 * Author: Barbara Reis
 * Date:   11.06.2020
 */

#include "RecurrencePlot.h"

/*
 * Constructors
 */
RecurrencePlot::RecurrencePlot(RecurrencePlot& rp){
    delay = rp.get_delay();
    dimension = rp.get_dimension();
    distance_matrix = rp.get_distance_matrix();
    norm = rp.get_norm();
    number_of_vectors = rp.get_number_of_vectors();
    recurrence_matrix = rp.get_recurrence_matrix();
    threshold = rp.get_threshold();
    time_series = rp.get_time_series();
    time_series_length = rp.get_time_series_length();
}

RecurrencePlot::RecurrencePlot(double* time_series, int time_series_length, int dimension, int delay, double threshold, string norm){
    calculate_recurrence_matrix(time_series, time_series_length, dimension, delay, threshold, norm);
}

/*
 * destructor
 */
RecurrencePlot::~RecurrencePlot() {
    for(int i = 0; i < number_of_vectors; i++){
        delete[] distance_matrix[i];
        delete[] recurrence_matrix[i];
    }
    delete[] distance_matrix;
    delete[] recurrence_matrix;
}

/*
 *  Setters
 */
void RecurrencePlot::set_delay(int value) {
    try{
        if (value < 1)
            throw 1;
        delay = value;
    } catch (int type){
        if (type == 1)
            cout << "The delay must be greater than or equal to 1" << endl;
    }   
}

void RecurrencePlot::set_dimension(int value) {
    try{
        if (value < 1)
            throw 1;
        dimension = value;
    } catch(int type){
        if (type == 1)
            cout << "The dimension must be greater than or equal to 1" << endl;
    }
}

void RecurrencePlot::set_norm(string value) {
    try{
        if (value.compare("manhattan") != 0 and value.compare("euclidean") != 0 and value.compare("supremum") != 0)
            throw 1;
        norm = value;
    } catch(int type){
        if (type == 1)
            cout << "Norm must be equals to \'manhattan\', \'euclidean\' or \'supremum\'" << endl;
    }
}

void RecurrencePlot::set_number_of_vectors(int value){
    try{
        if (value < 1)
            throw 1;
        if (value > time_series_length)
            throw 2;
        number_of_vectors = value;
    } catch(int type){
        if(type == 1)
            cout << "Number of vectors must be greater than or equals to 1" << endl;
        if(type == 2)
            cout << "Number of vectors must be less than or equals to" << time_series_length << endl;
    }    
}

void RecurrencePlot::set_threshold(double value) {
    try{
        if (value < 0)
            throw 1;
        threshold = value;
    } catch(int type){
        if (type == 1)
            cout << "The threshold must be greater than 0" << endl;                    
    }
}

void RecurrencePlot::set_time_series(double* value) {
    time_series = value;
}

void RecurrencePlot::set_time_series_length(int value) {
    try{
        if (value < 0)
            throw 1;
        time_series_length = value;
    } catch(int type){
        if (type == 1)
            cout << "The time series length must be greater than or equal to 1" << endl;
    }
}


/*
 * Getters
 */
int RecurrencePlot::get_delay(){
    return delay;
}

int RecurrencePlot::get_dimension(){
    return dimension;
}

double** RecurrencePlot::get_distance_matrix(){
    return distance_matrix;
}

string RecurrencePlot::get_norm(){
    return norm;
}

int RecurrencePlot::get_number_of_vectors(){
    return number_of_vectors;
}

int** RecurrencePlot::get_recurrence_matrix(){
    return recurrence_matrix;
}

double RecurrencePlot::get_threshold(){
    return threshold;
}

double* RecurrencePlot::get_time_series(){
    return time_series;
}

int RecurrencePlot::get_time_series_length(){
    return time_series_length;
}


/************************************************************
 *  Calculating the recurrence matrix                       *
 ************************************************************/ 
void RecurrencePlot::calculate_recurrence_matrix(){
    recurrence_matrix = new int*[number_of_vectors];
    for(int i = 0; i < number_of_vectors; i++)
        recurrence_matrix[i] = new int[number_of_vectors];
                
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = i; j < number_of_vectors; j++){
            if (distance_matrix[i][j] <= threshold){
                recurrence_matrix[i][j] = 1;
                recurrence_matrix[j][i] = 1;
            } else {
                recurrence_matrix[i][j] = 0;
                recurrence_matrix[j][i] = 0;
            }
        }
    }
}

void RecurrencePlot::calculate_recurrence_matrix(double* time_series, int time_series_length){
    calculate_recurrence_matrix(time_series, time_series_length, dimension, delay, threshold, norm);    
}

void RecurrencePlot::calculate_recurrence_matrix(int dimension, int delay, double threshold, string norm){
    calculate_recurrence_matrix(time_series, time_series_length, dimension, delay, threshold, norm);
}

void RecurrencePlot::calculate_recurrence_matrix(double* time_series, int time_series_length, int dimension, int delay, double threshold, string norm){
    set_time_series(time_series);
    set_time_series_length(time_series_length);
    set_dimension(dimension);
    set_delay(delay);
    set_threshold(threshold);
    set_norm(norm);
    set_number_of_vectors((int)(this->time_series_length - (this->dimension-1) * this->delay));
    calculate_distance_matrix();
    calculate_recurrence_matrix();
}

/*
 * Calculating the distance matrix
 */
void RecurrencePlot::calculate_distance_matrix(){
    distance_matrix = new double*[number_of_vectors];
    for(int i = 0; i < number_of_vectors; i++)
        distance_matrix[i] = new double[number_of_vectors];
        
    if (norm.compare("manhattan") == 0){
        double temp;
        for (int i = 0; i < number_of_vectors; i++){
            for (int j = i; j < number_of_vectors; j++){
                temp = 0.0;
                for (int k = 0; k < dimension; k++)
                     temp += fabs(time_series[i+k*delay] - time_series[j+k*delay]);
                distance_matrix[i][j] = temp;
                distance_matrix[j][i] = temp;
            }
        }
    }
    else if (norm.compare("euclidean") == 0){
        double temp;
        for(int i = 0; i < number_of_vectors; i++){
            for(int j = i; j < number_of_vectors; j++){
                temp = 0.0;
                for(int k = 0; k < dimension; k++)
                     temp += pow(time_series[i+k*delay] - time_series[j+k*delay], 2);
                distance_matrix[i][j] = sqrt(temp);
                distance_matrix[j][i] = sqrt(temp);
            }
        }
    }
    else if (norm.compare("supremum") == 0){
        double max, temp;
        for (int i = 0; i < number_of_vectors; i++){
            for(int j = i; j < number_of_vectors; j++){
                max = fabs(time_series[i] - time_series[j]);
                for (int k = 1; k < dimension; k++){
                    temp = fabs(time_series[i+k*delay] - time_series[j+k*delay]);
                    if (temp > max)
                        max = temp;
                }
                distance_matrix[i][j] = max;
                distance_matrix[j][i] = max;
            }
        }
    }
}

/*
 *  Printing details
 */        
void RecurrencePlot::print_details(){
    cout << "=============================================" << endl;
    cout << "    Recurrence plot configurations"            << endl;
    cout << "=============================================" << endl;
    cout << "Dimension: "                                   << dimension          << endl;
    cout << "Delay: "                                       << delay              << endl;
    cout << "Threshold: "                                   << threshold          << endl;
    cout << "Norm: "                                        << norm               << endl;
    cout << "Time series length: "                          << time_series_length << endl;
    cout << "Number of vectors: "                           << number_of_vectors  << endl;    
    print_time_series();
    print_distance_matrix();
    print_recurrence_matrix();
}

void RecurrencePlot::print_distance_matrix(){
    cout << "=============================================" << endl;
    cout << "    Distance matrix"                           << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << distance_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void RecurrencePlot::print_recurrence_matrix(){
    cout << "=============================================" << endl;
    cout << "    Recurrence matrix"                         << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << recurrence_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void RecurrencePlot::print_time_series(){
    cout << "=============================================" << endl;
    cout << "    Time series"                               << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < time_series_length; i++)
            cout << time_series[i] << " ";
    cout << endl;
}

/*
 *  Saving details
 */                
void RecurrencePlot::write_distance_matrix(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << distance_matrix[i][j] << ",";
            }
            myfile << distance_matrix[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";
}

void RecurrencePlot::write_recurrence_matrix(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << recurrence_matrix[i][j] << ",";
            }
            myfile << recurrence_matrix[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";
}

void RecurrencePlot::write_recurrence_adjacency_list(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < number_of_vectors; i++){
            for(int j = 0; j < number_of_vectors; j++){
                if (recurrence_matrix[i][j] == 1)
                    myfile << i << "," << j << endl;
            }
        }
        myfile.close();
    } else 
        cout << "Unable to open file"; 
}

void RecurrencePlot::write_time_series(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < time_series_length; i++)
            myfile << time_series[i] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";     
}