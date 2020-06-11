/* 
 * File:   RecurrencePlot.h
 * Author: Barbara Reis
 * Date:   11.06.2020
 */

#ifndef RECURRENCEPLOT_H
#define RECURRENCEPLOT_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class RecurrencePlot {
public:
    // Constructors
    RecurrencePlot(RecurrencePlot& rp);
    RecurrencePlot(double* time_series, int time_series_length, int dimension, int delay, double threshold, string norm);

    // Destructor
    ~RecurrencePlot();
    
    // Getters
    int get_delay();
    int get_dimension();
    double** get_distance_matrix();
    string get_norm();
    int get_number_of_vectors();
    int** get_recurrence_matrix();
    double get_threshold();
    double* get_time_series();
    int get_time_series_length();
        
    // Calculating the recurrence matrix
    void calculate_recurrence_matrix(double* time_series, int time_series_length);
    void calculate_recurrence_matrix(int dimension, int delay, double threshold, string norm);
    void calculate_recurrence_matrix(double* time_series, int time_series_length, int dimension, int delay, double threshold, string norm);
        
    // Printing details
    void print_details();
    void print_distance_matrix();
    void print_recurrence_matrix();
    void print_time_series();

    // Saving details
    void write_distance_matrix(string file_name);
    void write_recurrence_matrix(string file_name);
    void write_recurrence_adjacency_list(string file_name);
    void write_time_series(string file_name);

private:
    int     delay;
    int     dimension;
    double** distance_matrix;
    string  norm;
    int     number_of_vectors;
    int**   recurrence_matrix;
    double  threshold;
    double* time_series;
    int     time_series_length;
    
    // Setter
    void set_delay(int value);
    void set_dimension(int value);    
    void set_norm(string value);
    void set_number_of_vectors(int value);
    void set_threshold(double value);
    void set_time_series(double* value);    
    void set_time_series_length(int value);

    // Calculating the distance matrix
    void calculate_distance_matrix();
    
    // Calculating the recurrence matrix
    void calculate_recurrence_matrix();
};

#endif /* RECURRENCEPLOT_H */

