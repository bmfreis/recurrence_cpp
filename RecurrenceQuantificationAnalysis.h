/* 
 * File:   RecurrenceQuantificationAnalysis.h
 * Author: Barbara Reis
 * Date:   15.06.2020
 */

#ifndef RECURRENCEQUANTIFICATIONANALYSIS_H
#define RECURRENCEQUANTIFICATIONANALYSIS_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class RecurrenceQuantificationAnalysis {
public:
    // Constructors
    RecurrenceQuantificationAnalysis(int** matrix, int size, int lmin, int vmin, int wmin);
    RecurrenceQuantificationAnalysis(RecurrenceQuantificationAnalysis& rqa);
    
    // Destructor
    ~RecurrenceQuantificationAnalysis();
    
    // Getters
    int    get_minimum_diagonal_line_length();            // l_min
    int    get_minimum_vertical_line_length();            // v_min
    int    get_minimum_white_vertical_line_length();      // w_min 
    int*   get_diagonal_frequency_distribution();         // P(l)
    int*   get_vertical_frequency_distribution();         // P(v)
    int*   get_white_vertical_frequency_distribution();   // P(w) 
    int**  get_recurrence_matrix();                       // R
    int    get_number_of_vectors();                       // N
    double get_recurrence_rate();                         // RR
    double get_determinism();                             // DET
    double get_average_diagonal_line_length();            // L
    int    get_longest_diagonal_line_length();            // L_max
    double get_divergence();                              // DIV
    double get_entropy_diagonal_lines();                  // L_entr
    double get_laminarity();                              // LAM
    double get_average_vertical_line_length();            // V or TT
    int    get_longest_vertical_line_length();            // V_max
    double get_entropy_vertical_lines();                  // V_entr
    double get_average_white_vertical_line_length();      // W
    int    get_longest_white_vertical_line_length();      // W_max
    double get_entropy_white_vertical_lines();            // W_entr
    double get_ratio_determinism_recurrence_rate();       // DET/RR
    double get_ratio_laminarity_determinism();            // LAM/DET   
    
    // Calculating RQA measures
    void calculateRQA(int** matrix, int size);
    void calculateRQA(int lmin, int vmin, int wmin);
    void calculateRQA(int** matrix, int size, int lmin, int vmin, int wmin);

    // Printing details
    void print_details();
    void print_recurrence_matrix();
    void print_diagonal_frequency_distribution();
    void print_vertical_frequency_distribution();
    void print_white_vertical_frequency_distribution();
    void print_rqa_measures();

    // Saving details    
    void write_recurrence_matrix(string file_name);
    void write_recurrence_adjacency_list(string file_name);    
    void write_diagonal_frequency_distribution(string file_name);
    void write_vertical_frequency_distribution(string file_name);
    void write_white_vertical_frequency_distribution(string file_name);
    void write_measures(string file_name);    
    
private:
    int    minimum_diagonal_line_length;            // l_min
    int    minimum_vertical_line_length;            // v_min
    int    minimum_white_vertical_line_length;      // w_min 
    int*   diagonal_frequency_distribution;         // P(l)
    int*   vertical_frequency_distribution;         // P(v)
    int*   white_vertical_frequency_distribution;   // P(w) 
    int**  recurrence_matrix;                       // R
    int    number_of_vectors;                       // N
    double recurrence_rate;                         // RR
    double determinism;                             // DET
    double average_diagonal_line_length;            // L
    int    longest_diagonal_line_length;            // L_max
    double divergence;                              // DIV
    double entropy_diagonal_lines;                  // L_entr
    double laminarity;                              // LAM
    double average_vertical_line_length;            // V or TT
    int    longest_vertical_line_length;            // V_max
    double entropy_vertical_lines;                  // V_entr
    double average_white_vertical_line_length;      // W
    int    longest_white_vertical_line_length;      // W_max
    double entropy_white_vertical_lines;            // W_entr
    double ratio_determinism_recurrence_rate;       // DET/RR
    double ratio_laminarity_determinism;            // LAM/DET

    // Calculating RQA measures    
    void calculate_diagonal_frequency_distribution();         // P(l)
    void calculate_vertical_frequency_distribution();         // P(v)
    void calculate_white_vertical_frequency_distribution();   // P(w) 
    void calculate_recurrence_rate();                         // RR
    void calculate_determinism();                             // DET
    void calculate_average_diagonal_line_length();            // L
    void calculate_longest_diagonal_line_length();            // L_max
    void calculate_divergence();                              // DIV
    void calculate_entropy_diagonal_lines();                  // L_entr
    void calculate_laminarity();                              // LAM
    void calculate_average_vertical_line_length();            // V or TT
    void calculate_longest_vertical_line_length();            // V_max
    void calculate_entropy_vertical_lines();                  // V_entr
    void calculate_average_white_vertical_line_length();      // W
    void calculate_longest_white_vertical_line_length();      // W_max
    void calculate_entropy_white_vertical_lines();            // W_entr
    void calculate_ratio_determinism_recurrence_rate();       // DET/RR
    void calculate_ratio_laminarity_determinism();            // LAM/DET
    void calculateRQA();
    void update_diagonal_measures();
    void update_vertical_measures();
    void update_white_vertical_measures();
    
    // Setters
    void set_minimum_diagonal_line_length(int value);
    void set_minimum_vertical_line_length(int value);
    void set_minimum_white_vertical_line_length(int value);    
    void set_recurrence_matrix(int** matrix, int size);    
};

#endif /* RECURRENCEQUANTIFICATIONANALYSIS_H */

