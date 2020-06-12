/* 
 * File:   JointRecurrencePlot.h
 * Author: Barbara Reis
 * Date:   12.06.2020
 */

#include "JointRecurrencePlot.h"

JointRecurrencePlot::JointRecurrencePlot(double* time_series_1, double* time_series_2, 
                   int time_series_length, int dimension, int delay, 
                   double threshold, string norm){
    calculate_joint_recurrence_matrix(time_series_1, time_series_2, time_series_length, 
                                    dimension, delay, threshold, norm);
}

JointRecurrencePlot::JointRecurrencePlot(JointRecurrencePlot& jrp) {
    delay                   = jrp.get_delay();
    dimension               = jrp.get_dimension();
    distance_matrix_1       = jrp.get_distance_matrix_1();
    distance_matrix_2       = jrp.get_distance_matrix_2();    
    norm                    = jrp.get_norm();
    number_of_vectors       = jrp.get_number_of_vectors();
    recurrence_matrix_1     = jrp.get_recurrence_matrix_1();
    recurrence_matrix_2     = jrp.get_recurrence_matrix_2();
    joint_recurrence_matrix = jrp.get_joint_recurrence_matrix();
    threshold               = jrp.get_threshold();
    time_series_1           = jrp.get_time_series_1();
    time_series_2           = jrp.get_time_series_2();
    time_series_length      = jrp.get_time_series_length();
}

JointRecurrencePlot::~JointRecurrencePlot() {
    for(int i = 0; i < number_of_vectors; i++){
        delete[] distance_matrix_1[i];
        delete[] distance_matrix_2[i];
        delete[] recurrence_matrix_1[i];        
        delete[] recurrence_matrix_2[i];
        delete[] joint_recurrence_matrix[i];
    }
    delete[] distance_matrix_1;
    delete[] distance_matrix_2;
    delete[] recurrence_matrix_1;        
    delete[] recurrence_matrix_2;
    delete[] joint_recurrence_matrix;    
}

/*
 *  Calculating the distance matrix
 */ 
void JointRecurrencePlot::calculate_distance_matrix(){
    distance_matrix_1 = new double*[number_of_vectors];
    distance_matrix_2 = new double*[number_of_vectors];    
    for(int i = 0; i < number_of_vectors; i++){
        distance_matrix_1[i] = new double[number_of_vectors];
        distance_matrix_2[i] = new double[number_of_vectors];
    }        
    if (norm.compare("manhattan") == 0){
        double temp1, temp2;
        for (int i = 0; i < number_of_vectors; i++){
            for (int j = 0; j < number_of_vectors; j++){
                temp1 = 0.0;
                temp2 = 0.0;
                for (int k = 0; k < dimension; k++){
                     temp1 += fabs(time_series_1[i+k*delay] - time_series_1[j+k*delay]);
                     temp2 += fabs(time_series_2[i+k*delay] - time_series_2[j+k*delay]);
                }
                distance_matrix_1[i][j] = temp1;
                distance_matrix_2[i][j] = temp2;
            }
        }
    }
    else if (norm.compare("euclidean") == 0){
        double temp1, temp2;
        for(int i = 0; i < number_of_vectors; i++){
            for(int j = 0; j < number_of_vectors; j++){
                temp1 = 0.0;
                temp2 = 0.0;
                for(int k = 0; k < dimension; k++){
                     temp1 += pow(time_series_1[i+k*delay] - time_series_1[j+k*delay], 2);
                     temp2 += pow(time_series_2[i+k*delay] - time_series_2[j+k*delay], 2);                     
                }
                distance_matrix_1[i][j] = sqrt(temp1);
                distance_matrix_2[i][j] = sqrt(temp2);
            }
        }
    }
    else if (norm.compare("supremum") == 0){
        double max1, max2, temp1, temp2;
        for (int i = 0; i < number_of_vectors; i++){
            for(int j = 0; j < number_of_vectors; j++){
                max1 = fabs(time_series_1[i] - time_series_1[j]);
                max2 = fabs(time_series_2[i] - time_series_2[j]);                
                for (int k = 1; k < dimension; k++){
                    temp1 = fabs(time_series_1[i+k*delay] - time_series_1[j+k*delay]);
                    temp2 = fabs(time_series_2[i+k*delay] - time_series_2[j+k*delay]);
                    if (temp1 > max1)
                        max1 = temp1;
                    if (temp2 > max2)
                        max2 = temp2;
                }
                distance_matrix_1[i][j] = max1;
                distance_matrix_2[i][j] = max2;
            }
        }
    }    
}

/*
 *  Calculating the recurrence matrix
 */ 
void JointRecurrencePlot::calculate_recurrence_matrix(){
    recurrence_matrix_1 = new int*[number_of_vectors];
    recurrence_matrix_2 = new int*[number_of_vectors];    
    for(int i = 0; i < number_of_vectors; i++){
        recurrence_matrix_1[i] = new int[number_of_vectors];
        recurrence_matrix_2[i] = new int[number_of_vectors];
    }
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            if (distance_matrix_1[i][j] <= threshold)
                recurrence_matrix_1[i][j] = 1;
            else
                recurrence_matrix_1[i][j] = 0;

            if (distance_matrix_2[i][j] <= threshold)
                recurrence_matrix_2[i][j] = 1;
            else
                recurrence_matrix_2[i][j] = 0;            
        }
    }    
} 

/*
 * Calculating the joint recurrence matrix 
 */
void JointRecurrencePlot::calculate_joint_recurrence_matrix(){
    joint_recurrence_matrix = new int*[number_of_vectors];
    for(int i = 0; i < number_of_vectors; i++)
        joint_recurrence_matrix[i] = new int[number_of_vectors];
                
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            if (recurrence_matrix_1[i][j] == 1 and recurrence_matrix_2[i][j] == 1)
                joint_recurrence_matrix[i][j] = 1;
            else
                joint_recurrence_matrix[i][j] = 0;
        }
    }
}

void JointRecurrencePlot::calculate_joint_recurrence_matrix(int dimension, 
                                      int delay, double threshold, string norm){
    calculate_joint_recurrence_matrix(time_series_1, time_series_2, time_series_length, 
                                    dimension, delay, threshold, norm);    
}

void JointRecurrencePlot::calculate_joint_recurrence_matrix(double* time_series, 
                                 int time_series_length, int which_time_series){
    if(which_time_series == 1)
        calculate_joint_recurrence_matrix(time_series, time_series_2, 
                                        time_series_length, dimension, delay, 
                                        threshold, norm);
    else
        calculate_joint_recurrence_matrix(time_series_1, time_series, 
                                        time_series_length, dimension, delay, 
                                        threshold, norm);        
}    

void JointRecurrencePlot::calculate_joint_recurrence_matrix(double* time_series_1, 
                    double* time_series_2, int time_series_length, int dimension, 
                    int delay, double threshold, string norm){
    set_delay(delay);
    set_dimension(dimension);
    set_threshold(threshold);
    set_norm(norm);
    set_time_series_length(time_series_length);
    set_time_series_1(time_series_1);
    set_time_series_2(time_series_2);
    set_number_of_vectors((int)(time_series_length - (dimension-1) * delay));
    calculate_distance_matrix();
    calculate_recurrence_matrix();    
    calculate_joint_recurrence_matrix();
}

// Setter
void JointRecurrencePlot::set_delay(int value){
    try{
        if (value < 1)
            throw 1;
        delay = value;
    } catch (int type){
        if (type == 1)
            cout << "The delay must be greater than or equal to 1" << endl;
    }      
}

void JointRecurrencePlot::set_dimension(int value){
    try{
        if (value < 1)
            throw 1;
        dimension = value;
    } catch(int type){
        if (type == 1)
            cout << "The dimension must be greater than or equal to 1" << endl;
    }    
}    

void JointRecurrencePlot::set_norm(string value){
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

void JointRecurrencePlot::set_number_of_vectors(int value){
    try{
        if(value < 1)
            throw 1;
        if(value > time_series_length)
            throw 2;
        number_of_vectors = value;
    } catch(int type){
        if(type == 1)
            cout << "Number of vectors must be greater than or equals to 1" 
                 << endl;
        if(type == 2)
            cout << "Number of vectors must be less than or equals to" 
                 << time_series_length << endl;
    }    
}

void JointRecurrencePlot::set_threshold(double value){
    try{
        if (value < 0)
            throw 1;
        threshold = value;
    } catch(int type){
        if (type == 1)
            cout << "The threshold must be greater than 0" << endl;                    
    }        
}

void JointRecurrencePlot::set_time_series_1(double* value){
    try{
        if(value == NULL)        
            throw 1;
        time_series_1 = value;
    } catch(int type){
        if(type == 1)
            cout << "Time series 1 is empty" << endl;
    }        
}    

void JointRecurrencePlot::set_time_series_2(double* value){
    try{
        if(value == NULL)        
            throw 1;
        time_series_2 = value;
    } catch(int type){
        if(type == 1)
            cout << "Time series 2 is empty" << endl;
    }        
}    

void JointRecurrencePlot::set_time_series_length(int value){
    try{
        if (value < 0)
            throw 1;
        time_series_length = value;
    } catch(int type){
        if (type == 1)
            cout << "The time series length must be greater than or equal to 1" 
                 << endl;
    }        
}

/*
 *  Getters
 */ 
int** JointRecurrencePlot::get_joint_recurrence_matrix(){
    return joint_recurrence_matrix;
}

int JointRecurrencePlot::get_delay(){
    return delay;
}

int JointRecurrencePlot::get_dimension(){
    return dimension;
}

double** JointRecurrencePlot::get_distance_matrix_1(){
    return distance_matrix_1;
}

double** JointRecurrencePlot::get_distance_matrix_2(){
    return distance_matrix_2;
}

string JointRecurrencePlot::get_norm(){
    return norm;
}

int JointRecurrencePlot::get_number_of_vectors(){
    return number_of_vectors;
}

int** JointRecurrencePlot::get_recurrence_matrix_1(){
    return recurrence_matrix_1;
}

int** JointRecurrencePlot::get_recurrence_matrix_2(){
    return recurrence_matrix_2;
}

double JointRecurrencePlot::get_threshold(){
    return threshold;
}

double* JointRecurrencePlot::get_time_series_1(){
    return time_series_1;
}

double* JointRecurrencePlot::get_time_series_2(){
    return time_series_2;
}

int JointRecurrencePlot::get_time_series_length(){
    return time_series_length;
}

/*
 * Printing details
 */
void JointRecurrencePlot::print_details(){
    cout << "=============================================" << endl;
    cout << "    Joint recurrence plot configurations"      << endl;
    cout << "=============================================" << endl;
    cout << "Dimension: "                                   << dimension          << endl;
    cout << "Delay: "                                       << delay              << endl;
    cout << "Threshold: "                                   << threshold          << endl;
    cout << "Norm: "                                        << norm               << endl;
    cout << "Time series length: "                          << time_series_length << endl;
    cout << "Number of vectors: "                           << number_of_vectors  << endl;
    print_time_series_1();
    print_time_series_2();
    print_distance_matrix_1();
    print_distance_matrix_2();    
    print_recurrence_matrix_1();
    print_recurrence_matrix_2();    
    print_joint_recurrence_matrix();    
}

void JointRecurrencePlot::print_distance_matrix_1(){
    cout << "=============================================" << endl;
    cout << "    Distance matrix - Time series 1"           << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << distance_matrix_1[i][j] << " ";
        }
        cout << endl;
    }    
}

void JointRecurrencePlot::print_distance_matrix_2(){
    cout << "=============================================" << endl;
    cout << "    Distance matrix - Time series 2"           << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << distance_matrix_2[i][j] << " ";
        }
        cout << endl;
    }    
}

void JointRecurrencePlot::print_recurrence_matrix_1(){
    cout << "=============================================" << endl;
    cout << "    Recurrence matrix - Time series 1"         << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << recurrence_matrix_1[i][j] << " ";
        }
        cout << endl;
    }    
}

void JointRecurrencePlot::print_recurrence_matrix_2(){
    cout << "=============================================" << endl;
    cout << "    Recurrence matrix - Time series 2"         << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << recurrence_matrix_2[i][j] << " ";
        }
        cout << endl;
    }    
}

void JointRecurrencePlot::print_joint_recurrence_matrix(){
    cout << "=============================================" << endl;
    cout << "    Joint recurrence matrix"                   << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < number_of_vectors; i++){
        for (int j = 0; j < number_of_vectors; j++){
            cout << joint_recurrence_matrix[i][j] << " ";
        }
        cout << endl;
    }    
}

void JointRecurrencePlot::print_time_series_1(){
    cout << "=============================================" << endl;
    cout << "    Time series 1"                             << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < time_series_length; i++)
            cout << time_series_1[i] << " ";
    cout << endl;    
}

void JointRecurrencePlot::print_time_series_2(){
    cout << "=============================================" << endl;
    cout << "    Time series 2"                             << endl;
    cout << "=============================================" << endl;
    for (int i = 0; i < time_series_length; i++)
            cout << time_series_2[i] << " ";
    cout << endl;    
}


/*
 * Saving details
 */
void JointRecurrencePlot::write_distance_matrix_1(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << distance_matrix_1[i][j] << ",";
            }
            myfile << distance_matrix_1[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void JointRecurrencePlot::write_distance_matrix_2(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << distance_matrix_2[i][j] << ",";
            }
            myfile << distance_matrix_2[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void JointRecurrencePlot::write_recurrence_matrix_1(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << recurrence_matrix_1[i][j] << ",";
            }
            myfile << recurrence_matrix_1[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void JointRecurrencePlot::write_recurrence_matrix_2(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << recurrence_matrix_2[i][j] << ",";
            }
            myfile << recurrence_matrix_2[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void JointRecurrencePlot::write_joint_recurrence_matrix(string file_name){
    int i, j;
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(i = 0; i < number_of_vectors; i++){
            for(j = 0; j < number_of_vectors-1; j++){
                myfile << joint_recurrence_matrix[i][j] << ",";
            }
            myfile << joint_recurrence_matrix[i][j] << endl;
        } 
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void JointRecurrencePlot::write_joint_recurrence_adjacency_list(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < number_of_vectors; i++){
            for(int j = 0; j < number_of_vectors; j++){
                if (joint_recurrence_matrix[i][j] == 1)
                    myfile << i << "," << j << endl;
            }
        }
        myfile.close();
    } else 
        cout << "Unable to open file";     
}

void JointRecurrencePlot::write_time_series_1(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < time_series_length; i++)
            myfile << time_series_1[i] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";      
}

void JointRecurrencePlot::write_time_series_2(string file_name){
    ofstream myfile(file_name);
    if (myfile.is_open()){
        for(int i = 0; i < time_series_length; i++)
            myfile << time_series_2[i] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";      
}