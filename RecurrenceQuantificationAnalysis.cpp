/* 
 * File:   RecurrenceQuantificationAnalysis.cpp
 * Author: Barbara Reis
 * Date:   15.06.2020
 */

#include "RecurrenceQuantificationAnalysis.h"

/*
 *  Constructors
 */
RecurrenceQuantificationAnalysis::RecurrenceQuantificationAnalysis(int** matrix, 
                                        int size, int lmin, int vmin, int wmin){
    cout << "construtor" << endl;
    calculateRQA(matrix, size, lmin, vmin, wmin);
}

RecurrenceQuantificationAnalysis::RecurrenceQuantificationAnalysis(
                                        RecurrenceQuantificationAnalysis& rqa) {
    recurrence_matrix = rqa.get_recurrence_matrix();
    number_of_vectors = rqa.get_number_of_vectors();
    minimum_diagonal_line_length       = rqa.get_minimum_diagonal_line_length();
    minimum_vertical_line_length       = rqa.get_minimum_vertical_line_length();
    minimum_white_vertical_line_length = rqa.get_minimum_white_vertical_line_length();
    diagonal_frequency_distribution       = rqa.get_diagonal_frequency_distribution();
    vertical_frequency_distribution       = rqa.get_vertical_frequency_distribution();
    white_vertical_frequency_distribution = rqa.get_white_vertical_frequency_distribution();
    recurrence_rate = rqa.get_recurrence_rate();
    determinism                  = rqa.get_determinism();
    average_diagonal_line_length = rqa.get_average_diagonal_line_length();
    longest_diagonal_line_length = rqa.get_longest_diagonal_line_length();
    divergence                   = rqa.get_divergence();
    entropy_diagonal_lines       = rqa.get_entropy_diagonal_lines();
    laminarity                   = rqa.get_laminarity();
    average_vertical_line_length = rqa.get_average_vertical_line_length();
    longest_vertical_line_length = rqa.get_longest_vertical_line_length();
    entropy_vertical_lines       = rqa.get_entropy_vertical_lines();
    average_white_vertical_line_length = rqa.get_average_white_vertical_line_length();
    longest_white_vertical_line_length = rqa.get_longest_white_vertical_line_length();
    entropy_white_vertical_lines       = rqa.get_entropy_white_vertical_lines();
    ratio_determinism_recurrence_rate = rqa.get_ratio_determinism_recurrence_rate();
    ratio_laminarity_determinism      = rqa.get_ratio_laminarity_determinism();
}

/*
 *  Destructor
 */ 
RecurrenceQuantificationAnalysis::~RecurrenceQuantificationAnalysis() {
}

/*
 *  Getters
 */
int RecurrenceQuantificationAnalysis::get_minimum_diagonal_line_length(){
    return minimum_diagonal_line_length;
}

int RecurrenceQuantificationAnalysis::get_minimum_vertical_line_length(){
    return minimum_vertical_line_length;
}

int RecurrenceQuantificationAnalysis::get_minimum_white_vertical_line_length(){
    return minimum_white_vertical_line_length;
}

int* RecurrenceQuantificationAnalysis::get_diagonal_frequency_distribution(){
    return diagonal_frequency_distribution;
}

int* RecurrenceQuantificationAnalysis::get_vertical_frequency_distribution(){
    return vertical_frequency_distribution;
}

int* RecurrenceQuantificationAnalysis::get_white_vertical_frequency_distribution(){
    return white_vertical_frequency_distribution;
}

int** RecurrenceQuantificationAnalysis::get_recurrence_matrix(){
    return recurrence_matrix;
}

int RecurrenceQuantificationAnalysis::get_number_of_vectors(){
    return number_of_vectors;
}

double RecurrenceQuantificationAnalysis::get_recurrence_rate(){
    return recurrence_rate;
}

double RecurrenceQuantificationAnalysis::get_determinism(){
    return determinism;
}

double RecurrenceQuantificationAnalysis::get_average_diagonal_line_length(){
    return average_diagonal_line_length;
}

int RecurrenceQuantificationAnalysis::get_longest_diagonal_line_length(){
    return longest_diagonal_line_length;
}

double RecurrenceQuantificationAnalysis::get_divergence(){
    return divergence;
}

double RecurrenceQuantificationAnalysis::get_entropy_diagonal_lines(){
    return entropy_diagonal_lines;
}

double RecurrenceQuantificationAnalysis::get_laminarity(){
    return laminarity;
}

double RecurrenceQuantificationAnalysis::get_average_vertical_line_length(){
    return average_vertical_line_length;
}

int RecurrenceQuantificationAnalysis::get_longest_vertical_line_length(){
    return longest_vertical_line_length;
}

double RecurrenceQuantificationAnalysis::get_entropy_vertical_lines(){
    return entropy_vertical_lines;
}

double RecurrenceQuantificationAnalysis::get_average_white_vertical_line_length(){
    return average_white_vertical_line_length;
}

int RecurrenceQuantificationAnalysis::get_longest_white_vertical_line_length(){
    return longest_white_vertical_line_length;
}

double RecurrenceQuantificationAnalysis::get_entropy_white_vertical_lines(){
    return entropy_white_vertical_lines;
}

double RecurrenceQuantificationAnalysis::get_ratio_determinism_recurrence_rate(){
    return ratio_determinism_recurrence_rate;
}

double RecurrenceQuantificationAnalysis::get_ratio_laminarity_determinism(){
    return ratio_laminarity_determinism;
}

/*
 *  Calculating RQA measures
 */
void RecurrenceQuantificationAnalysis::calculate_diagonal_frequency_distribution(){
    int i, j, k, diagonal_line_length;
    diagonal_frequency_distribution = new int[number_of_vectors+1];

    for(i = 0; i < number_of_vectors+1; i++)
        diagonal_frequency_distribution[i] = 0;                

    for(i = number_of_vectors-1; i > -1; i--){
        diagonal_line_length = 0;
        for (j = 0; j < number_of_vectors-i; j++){
            if (recurrence_matrix[i+j][j] == 1){
                diagonal_line_length += 1;
                if (j == (number_of_vectors-i-1))
                    diagonal_frequency_distribution[diagonal_line_length] += 1;
            } else {
                if (diagonal_line_length != 0){
                    diagonal_frequency_distribution[diagonal_line_length] += 1;
                    diagonal_line_length = 0;
                }
            }
        }
    }

    for (k = 1; k < number_of_vectors; k++){
        diagonal_line_length = 0;
        for (i = 0; i < number_of_vectors-k; i++){
            j = i + k;
            if (recurrence_matrix[i][j] == 1){
                diagonal_line_length += 1;
                if (j == (number_of_vectors-1))
                    diagonal_frequency_distribution[diagonal_line_length] += 1;
            } else {
                if (diagonal_line_length != 0){
                    diagonal_frequency_distribution[diagonal_line_length] += 1;
                    diagonal_line_length = 0;
                }
            }
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_vertical_frequency_distribution(){
    int i, j, vertical_line_length;
    vertical_frequency_distribution = new int[number_of_vectors+1];

    for (i = 0; i < number_of_vectors; i++){
        vertical_line_length = 0;
        for (j = 0; j < number_of_vectors; j++){
            if (recurrence_matrix[i][j] == 1){
                vertical_line_length += 1;
                if (j == (number_of_vectors-1))
                    vertical_frequency_distribution[vertical_line_length] += 1;
            } else{
                if (vertical_line_length != 0){
                    vertical_frequency_distribution[vertical_line_length] += 1;
                    vertical_line_length = 0;
                }
            }
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_white_vertical_frequency_distribution(){
    int i, j, white_vertical_line_length;
    white_vertical_frequency_distribution = new int[number_of_vectors+1];

    for (i = 0; i < number_of_vectors; i++){
        white_vertical_line_length = 0;
        for (j = 0; j < number_of_vectors; j++){
            if (recurrence_matrix[i][j] == 0){
                white_vertical_line_length += 1;
                if (j == (number_of_vectors-1))
                    white_vertical_frequency_distribution[white_vertical_line_length] += 1;
            } else{
                if (white_vertical_line_length != 0){
                    white_vertical_frequency_distribution[white_vertical_line_length] += 1;
                    white_vertical_line_length = 0;
                }
            }
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_recurrence_rate(){
    double sum_recurrence_points = 0.0;
    for(int i = 0; i < number_of_vectors; i++){
        for(int j = 0; j < number_of_vectors; j++){
            sum_recurrence_points += recurrence_matrix[i][j];
        }
    }
    recurrence_rate = sum_recurrence_points/pow(number_of_vectors,2);    
}

void RecurrenceQuantificationAnalysis::calculate_determinism(){
    double numerator   = 0.0;
    double denominator = 0.0;
    for (int l = minimum_diagonal_line_length; l < number_of_vectors; l++)
        numerator += l * diagonal_frequency_distribution[l];
    for (int l = 1; l < number_of_vectors; l++)
        denominator += l * diagonal_frequency_distribution[l];
    determinism = numerator / denominator;    
}

void RecurrenceQuantificationAnalysis::calculate_average_diagonal_line_length(){
    double numerator   = 0.0;
    double denominator = 0.0;
    for (int l = minimum_diagonal_line_length; l < number_of_vectors; l++){
        numerator   += l * diagonal_frequency_distribution[l];
        denominator +=     diagonal_frequency_distribution[l];
    }
    average_diagonal_line_length = numerator / denominator;    
}

void RecurrenceQuantificationAnalysis::calculate_longest_diagonal_line_length(){
    for (int l = number_of_vectors-1; l >= 0; l--){
        if (diagonal_frequency_distribution[l] != 0){
            longest_diagonal_line_length = l;
            break;
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_divergence(){
    divergence = 1.0 / longest_diagonal_line_length;    
}   

void RecurrenceQuantificationAnalysis::calculate_entropy_diagonal_lines(){
    double sum_diagonal_frequency_distribution = 0.0;
    for(int l = minimum_diagonal_line_length; l < number_of_vectors; l++)
        sum_diagonal_frequency_distribution += diagonal_frequency_distribution[l];
    entropy_diagonal_lines = 0.0;
    for (int l = minimum_diagonal_line_length; l < number_of_vectors; l++){
        if (diagonal_frequency_distribution[l] != 0)
            entropy_diagonal_lines += (diagonal_frequency_distribution[l]/sum_diagonal_frequency_distribution) * log(diagonal_frequency_distribution[l]/sum_diagonal_frequency_distribution);
    }
    entropy_diagonal_lines *= -1.0;    
}

void RecurrenceQuantificationAnalysis::calculate_laminarity(){
    double numerator   = 0.0;
    double denominator = 0.0;
    for(int v = minimum_vertical_line_length; v < number_of_vectors+1; v++)
        numerator   += v * vertical_frequency_distribution[v];
    for(int v = 1; v < number_of_vectors+1; v++)
        denominator += v * vertical_frequency_distribution[v];
    laminarity = numerator / denominator;        
}

void RecurrenceQuantificationAnalysis::calculate_average_vertical_line_length(){
    double numerator   = 0.0;
    double denominator = 0.0;
    for(int v = minimum_vertical_line_length; v < number_of_vectors+1; v++){
        numerator   += v * vertical_frequency_distribution[v];
        denominator +=     vertical_frequency_distribution[v];
    }
    average_vertical_line_length = numerator / denominator;    
}

void RecurrenceQuantificationAnalysis::calculate_longest_vertical_line_length(){
    for (int v = number_of_vectors; v >= 0; v--){
        if (vertical_frequency_distribution[v] != 0){
            longest_vertical_line_length = v;
            break;
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_entropy_vertical_lines(){
    double sum_vertical_frequency_distribution = 0.0;
    for (int v = minimum_vertical_line_length; v < number_of_vectors+1; v++)
        sum_vertical_frequency_distribution += vertical_frequency_distribution[v];
    entropy_vertical_lines = 0.0;
    for (int v = minimum_vertical_line_length; v < number_of_vectors+1; v++){
        if (vertical_frequency_distribution[v] != 0)
            entropy_vertical_lines += (vertical_frequency_distribution[v]/sum_vertical_frequency_distribution) * log(vertical_frequency_distribution[v]/sum_vertical_frequency_distribution);
    }
    entropy_vertical_lines *= -1.0;    
}

void RecurrenceQuantificationAnalysis::calculate_average_white_vertical_line_length(){
    double numerator   = 0.0;
    double denominator = 0.0;
    for(int w = minimum_white_vertical_line_length; w < number_of_vectors+1; w++){
        numerator   += w * white_vertical_frequency_distribution[w];
        denominator +=     white_vertical_frequency_distribution[w];
    }
    average_white_vertical_line_length = numerator / denominator;    
}

void RecurrenceQuantificationAnalysis::calculate_longest_white_vertical_line_length(){
    for (int w = number_of_vectors; w >= 0; w--){
        if (white_vertical_frequency_distribution[w] != 0){
            longest_white_vertical_line_length = w;
            break;
        }
    }    
}

void RecurrenceQuantificationAnalysis::calculate_entropy_white_vertical_lines(){
    double sum_white_vertical_frequency_distribution = 0.0;
    for (int w = minimum_white_vertical_line_length; w < number_of_vectors+1; w++)
        sum_white_vertical_frequency_distribution += white_vertical_frequency_distribution[w];
    entropy_white_vertical_lines = 0.0;
    for (int w = minimum_white_vertical_line_length; w < number_of_vectors+1; w++){
        if (white_vertical_frequency_distribution[w] != 0)
            entropy_white_vertical_lines += (white_vertical_frequency_distribution[w]/sum_white_vertical_frequency_distribution) * log(white_vertical_frequency_distribution[w]/sum_white_vertical_frequency_distribution);
    }
    entropy_white_vertical_lines *= -1.0;                
}

void RecurrenceQuantificationAnalysis::calculate_ratio_determinism_recurrence_rate(){
    ratio_determinism_recurrence_rate = determinism / recurrence_rate;    
}

void RecurrenceQuantificationAnalysis::calculate_ratio_laminarity_determinism(){
    ratio_laminarity_determinism = laminarity / determinism;
}

void RecurrenceQuantificationAnalysis::update_diagonal_measures(){
    calculate_diagonal_frequency_distribution();
    calculate_determinism();
    calculate_average_diagonal_line_length();
    calculate_longest_diagonal_line_length();
    calculate_divergence();
    calculate_entropy_diagonal_lines();
    calculate_ratio_determinism_recurrence_rate();
    calculate_ratio_laminarity_determinism();
}

void RecurrenceQuantificationAnalysis::update_vertical_measures(){
    calculate_vertical_frequency_distribution();
    calculate_laminarity();
    calculate_average_vertical_line_length();
    calculate_longest_vertical_line_length();
    calculate_entropy_vertical_lines();
    calculate_ratio_laminarity_determinism();
}

void RecurrenceQuantificationAnalysis::update_white_vertical_measures(){
    calculate_white_vertical_frequency_distribution();
    calculate_average_white_vertical_line_length();
    calculate_longest_white_vertical_line_length();
    calculate_entropy_white_vertical_lines();
}

void RecurrenceQuantificationAnalysis::calculateRQA(){
    calculate_recurrence_rate();
    update_diagonal_measures();
    update_vertical_measures();
    update_white_vertical_measures();
}

void RecurrenceQuantificationAnalysis::calculateRQA(int** matrix, int size){
   set_recurrence_matrix(matrix, size);
   calculateRQA();    
}

void RecurrenceQuantificationAnalysis::calculateRQA(int lmin, int vmin, int wmin){
   set_minimum_diagonal_line_length(lmin);
   set_minimum_vertical_line_length(vmin);
   set_minimum_white_vertical_line_length(wmin);
   calculateRQA();    
}

void RecurrenceQuantificationAnalysis::calculateRQA(int** matrix, int size, 
                                                  int lmin, int vmin, int wmin){
   cout << "calculate" << endl;
   set_recurrence_matrix(matrix, size);
   set_minimum_diagonal_line_length(lmin);
   set_minimum_vertical_line_length(vmin);
   set_minimum_white_vertical_line_length(wmin);
   calculateRQA();
}

/*
 *  Setters
 */
void RecurrenceQuantificationAnalysis::set_minimum_diagonal_line_length(int value){
    try{
        if (value < 1)
            throw 1;
        minimum_diagonal_line_length = value;
    } catch(int type){
        if (type == 1)
            cout << "Minimum diagonal line length must be greater than or equals to 1" << endl;
    }
}

void RecurrenceQuantificationAnalysis::set_minimum_vertical_line_length(int value){
    try{
        if (value < 1)
            throw 1;
        minimum_vertical_line_length = value;
    } catch(int type){
        if (type == 1)
            cout << "Minimum vertical line length must be greater than or equals to 1" << endl;
    }

}

void RecurrenceQuantificationAnalysis::set_minimum_white_vertical_line_length(int value){
    try{
        if (value < 1)
            throw 1;
        minimum_white_vertical_line_length = value;
    } catch(int type){
        if(type == 1)
            cout << "Minimum white vertical line length must be greater than or equals to 1" << endl;
    }
}

void RecurrenceQuantificationAnalysis::set_recurrence_matrix(int** matrix, int size){
    try{
        if (matrix == NULL)
            throw 1;
        if (size < 1)
            throw 2;
        if (matrix != NULL and size > 0){
            bool only_zero = true;
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(i != j  and matrix[i][j] == 1){
                        only_zero = false;
                        break;
                    }
                if(!only_zero)
                    break;
                }
            }
            if(only_zero)
               throw 3; 
        }
        recurrence_matrix = matrix;
        number_of_vectors = size;        
    } catch(int type){
        if (type == 1)
            cout << "Recurrence matrix is empty" << endl;            
        else if(type == 2)
            cout << "Number of vectors must be greater than or equals to 1" << endl;
        else if(type == 3)
            cout << "Recurrence matrix contains only zero values" << endl;            
    }
}


/*
 *  Printing details
 */ 
void RecurrenceQuantificationAnalysis::print_details(){
    print_recurrence_matrix();
    print_diagonal_frequency_distribution();
    print_vertical_frequency_distribution();
    print_white_vertical_frequency_distribution();
    print_rqa_measures();
}

void RecurrenceQuantificationAnalysis::print_recurrence_matrix(){
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

void RecurrenceQuantificationAnalysis::print_diagonal_frequency_distribution(){
    cout << "============================================="             << endl;
    cout << "    Diagonal frequency distribution"                       << endl;
    cout << "============================================="             << endl;
    for(int i = 0; i <= number_of_vectors; i++){
        cout << diagonal_frequency_distribution[i] << " ";
    }
    cout << endl;    
}

void RecurrenceQuantificationAnalysis::print_vertical_frequency_distribution(){
    cout << "============================================="             << endl;
    cout << "    Vertical frequency distribution"                       << endl;
    cout << "============================================="             << endl;
    for(int i = 0; i <= number_of_vectors; i++){
        cout << vertical_frequency_distribution[i] << " ";
    }
    cout << endl;    
}

void RecurrenceQuantificationAnalysis::print_white_vertical_frequency_distribution(){
    cout << "============================================="             << endl;
    cout << "    White vertical frequency distribution"                 << endl;
    cout << "============================================="             << endl;
    for(int i = 0; i <= number_of_vectors; i++){
        cout << white_vertical_frequency_distribution[i] << " ";
    }
    cout << endl;    
}  

void RecurrenceQuantificationAnalysis::print_rqa_measures(){
    cout << "============================================="             << endl;
    cout << "    Recurrence Quantification Analysis"                    << endl;
    cout << "============================================="             << endl;
    cout << "Minimum diagonal line length (L_min): "                    << minimum_diagonal_line_length       << endl;
    cout << "Minimum vertical line length (V_min): "                    << minimum_vertical_line_length       << endl;
    cout << "Minimum white vertical line length (W_min): "              << minimum_white_vertical_line_length << endl << endl;
    cout << "Recurrence rate (RR): "                                    << recurrence_rate                    << endl << endl;
    cout << "Determinism (DET): "                                       << determinism                        << endl;
    cout << "Average diagonal line length (L): "                        << average_diagonal_line_length       << endl;
    cout << "Longest diagonal line length (L_max): "                    << longest_diagonal_line_length       << endl;
    cout << "Divergence (DIV): "                                        << divergence                         << endl;
    cout << "Entropy diagonal lines (L_entr): "                         << entropy_diagonal_lines             << endl << endl;
    cout << "Laminarity (LAM): "                                        << laminarity                         << endl;
    cout << "Average diagonal line length (V) or Trapping time (TT): "  << average_vertical_line_length       << endl;
    cout << "Longest vertical line length (V_max): "                    << longest_vertical_line_length       << endl;
    cout << "Entropy vertical lines (V_entr): "                         << entropy_vertical_lines << endl     << endl;
    cout << "Average white vertical line length (W): "                  << average_white_vertical_line_length << endl;
    cout << "Longest white vertical line length (W_max): "              << longest_white_vertical_line_length << endl;
    cout << "Entropy white vertical lines (W_entr): "                   << entropy_white_vertical_lines       << endl << endl;
    cout << "Ratio determinism / recurrence rate (DET/RR): "            << ratio_determinism_recurrence_rate  << endl;
    cout << "Ratio laminarity / determinism (LAM/DET): "                << ratio_laminarity_determinism       << endl;        
}

/*
 *  Saving details 
 */    
void RecurrenceQuantificationAnalysis::write_recurrence_matrix(string file_name){
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

void RecurrenceQuantificationAnalysis::write_recurrence_adjacency_list(string file_name){
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

void RecurrenceQuantificationAnalysis::write_diagonal_frequency_distribution(string file_name){
    ofstream myfile(file_name);
    if(myfile.is_open()){
        for(int l = 1; l <= number_of_vectors+1; l++)
            myfile << l << "," << diagonal_frequency_distribution[l] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void RecurrenceQuantificationAnalysis::write_vertical_frequency_distribution(string file_name){
    ofstream myfile(file_name);
    if(myfile.is_open()){
        for(int v = 1; v <= number_of_vectors+1; v++)
            myfile << v << "," << vertical_frequency_distribution[v] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";    
}

void RecurrenceQuantificationAnalysis::write_white_vertical_frequency_distribution(string file_name){
    ofstream myfile(file_name);
    if(myfile.is_open()){
        for(int w = 1; w <= number_of_vectors+1; w++)
            myfile << w << "," << white_vertical_frequency_distribution[w] << endl;
        myfile.close();
    } else 
        cout << "Unable to open file";
}  

void RecurrenceQuantificationAnalysis::write_measures(string file_name){
    bool file_exists = ifstream(file_name).good();
    ofstream myfile(file_name, ios_base::app);
    if(myfile.is_open()){
        if(!file_exists)
            myfile << "RR,DET,L,L_MAX,DIV,L_ENTR,LAM,V,V_MAX,V_ENTR,W,W_MAX,W_ENTR,DET_RR,LAM_DET" << endl;
        myfile << recurrence_rate << "," 
               << determinism << "," 
               << average_diagonal_line_length << "," 
               << longest_diagonal_line_length << "," 
               << divergence << "," 
               << entropy_diagonal_lines << "," 
               << laminarity << "," 
               << average_vertical_line_length << "," 
               << longest_vertical_line_length << "," 
               << entropy_vertical_lines << "," 
               << average_white_vertical_line_length << "," 
               << longest_white_vertical_line_length << "," 
               << entropy_white_vertical_lines << ","
               << ratio_determinism_recurrence_rate << "," 
               << ratio_laminarity_determinism << endl;
        myfile.close();
    } else 
            cout << "Unable to open file";    
}    