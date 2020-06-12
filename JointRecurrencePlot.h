/* 
 * File:   JointRecurrencePlot.h
 * Author: Barbara Reis
 * Date:   12.06.2020
 */

#ifndef JOINTRECURRENCEPLOT_H
#define JOINTRECURRENCEPLOT_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class JointRecurrencePlot {
public:
    JointRecurrencePlot(double* time_series_1, double* time_series_2, 
                   int time_series_length, int dimension, int delay, 
                   double threshold, string norm);
    JointRecurrencePlot(JointRecurrencePlot& orig);
    ~JointRecurrencePlot();
    
    // Getters
    double** get_distance_matrix_1();
    double** get_distance_matrix_2();    
    int** get_joint_recurrence_matrix();
    int get_delay();
    int get_dimension();
    string get_norm();
    int get_number_of_vectors();
    int** get_recurrence_matrix_1();
    int** get_recurrence_matrix_2();    
    double get_threshold();
    double* get_time_series_1();
    double* get_time_series_2();
    int get_time_series_length();
    
    // Calculating the cross recurrence matrix
    void calculate_joint_recurrence_matrix(int dimension, int delay, double threshold, 
                                           string norm);
    void calculate_joint_recurrence_matrix(double* time_series, int time_series_length, 
                                           int which_time_series);    
    void calculate_joint_recurrence_matrix(double* time_series_1, double* time_series_2, 
                                int time_series_length, int dimension, int delay, 
                                double threshold, string norm);
        
    // Printing details
    void print_details();
    void print_distance_matrix_1();
    void print_distance_matrix_2();    
    void print_recurrence_matrix_1();
    void print_recurrence_matrix_2();    
    void print_joint_recurrence_matrix();
    void print_time_series_1();
    void print_time_series_2();

    // Saving details
    void write_distance_matrix_1(string file_name);
    void write_distance_matrix_2(string file_name);    
    void write_recurrence_matrix_1(string file_name);
    void write_recurrence_matrix_2(string file_name);    
    void write_joint_recurrence_matrix(string file_name);
    void write_joint_recurrence_adjacency_list(string file_name);
    void write_time_series_1(string file_name);
    void write_time_series_2(string file_name);    
    
private:
    int      delay;
    int      dimension;
    double** distance_matrix_1;    
    double** distance_matrix_2;        
    int**    joint_recurrence_matrix;    
    string   norm;
    int      number_of_vectors;
    int**    recurrence_matrix_1;    
    int**    recurrence_matrix_2;    
    double   threshold;
    double*  time_series_1;
    double*  time_series_2;
    int      time_series_length;

    // Setter
    void set_delay(int value);
    void set_dimension(int value);    
    void set_norm(string value);
    void set_number_of_vectors(int value);
    void set_threshold(double value);
    void set_time_series_1(double* value);    
    void set_time_series_2(double* value);    
    void set_time_series_length(int value);
    
    // Calculating the distance matrix
    void calculate_distance_matrix();

    // Calculating the recurrence matrix
    void calculate_recurrence_matrix();    
    
    // Calculating the joint recurrence matrix
    void calculate_joint_recurrence_matrix();
};

#endif /* JOINTRECURRENCEPLOT_H */

