/* 
 * File:   CrossRecurrencePlot.h
 * Author: Barbara Reis
 * Date:   11.06.2020
 */

#ifndef CROSSRECURRENCEPLOT_H
#define CROSSRECURRENCEPLOT_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class CrossRecurrencePlot {
public:
    CrossRecurrencePlot(double* time_series_1, double* time_series_2, 
                       int time_series_1_length, int time_series_2_length, 
                       int dimension, int delay_time_series_1, 
                       int delay_time_series_2, double threshold, string norm);
    CrossRecurrencePlot(CrossRecurrencePlot& crp);
    virtual ~CrossRecurrencePlot();

    // Getters
    double** get_cross_distance_matrix();
    int** get_cross_recurrence_matrix();
    int get_delay_time_series_1();
    int get_delay_time_series_2();
    int get_dimension();
    string get_norm();
    int get_number_of_vectors_1();
    int get_number_of_vectors_2();
    double get_threshold();
    double* get_time_series_1();
    double* get_time_series_2();
    int get_time_series_1_length();
    int get_time_series_2_length();
    
    // Calculating the cross recurrence matrix
    void calculate_cross_recurrence_matrix(string norm);
    void calculate_cross_recurrence_matrix(double threshold);
    void calculate_cross_recurrence_matrix(double* time_series, 
                      int time_series_length, int delay, int which_time_series);
    void calculate_cross_recurrence_matrix(double* time_series_1, 
        double* time_series_2, int time_series_1_length, int time_series_2_length, 
        int dimension, int delay_time_series_1, int delay_time_series_2, 
        double threshold, string norm);
        
    // Printing details
    void print_details();
    void print_cross_distance_matrix();
    void print_cross_recurrence_matrix();
    void print_time_series_1();
    void print_time_series_2();

    // Saving details
    void write_cross_distance_matrix(string file_name);
    void write_cross_recurrence_matrix(string file_name);
    void write_cross_recurrence_adjacency_list(string file_name);
    void write_time_series_1(string file_name);
    void write_time_series_2(string file_name);
    
private:
    double** cross_distance_matrix;
    int**    cross_recurrence_matrix;    
    int      delay_time_series_1;
    int      delay_time_series_2;
    int      dimension;
    string   norm;
    int      number_of_vectors_1;
    int      number_of_vectors_2;
    double   threshold;
    double*  time_series_1;
    double*  time_series_2;
    int      time_series_1_length;
    int      time_series_2_length;
    
    // Setter
    void set_delay_time_series_1(int value);
    void set_delay_time_series_2(int value);
    void set_dimension(int value);    
    void set_norm(string value);
    void set_number_of_vectors_1(int value);
    void set_number_of_vectors_2(int value);
    void set_threshold(double value);
    void set_time_series_1(double* value);    
    void set_time_series_2(double* value);    
    void set_time_series_1_length(int value);
    void set_time_series_2_length(int value);
    
    // Calculating the cross distance matrix
    void calculate_cross_distance_matrix();    
    
    // Calculating the cross recurrence matrix
    void calculate_cross_recurrence_matrix();    
};

#endif /* CROSSRECURRENCEPLOT_H */

