/* 
 * File:   test_cross_recurrence_plot_euclidean.cpp
 * Author: Barbara Reis
 * Date:   12.06.2020
 */
#include <stdlib.h>
#include <iostream>
#include "../../CrossRecurrencePlot.h"

void test_delay_time_series_1(int rp_delay){
    int delay = 2;
    if(delay == rp_delay)
        cout << "test_delay_time_series_1() passed" << endl;
    else
        cout << "test_delay_time_series_1() failed: " << delay << " != " 
             << rp_delay << endl;
}

void test_delay_time_series_2(int rp_delay){
    int delay = 3;
    if(delay == rp_delay)
        cout << "test_delay_time_series_2() passed" << endl;
    else
        cout << "test_delay_time_series_2() failed: " << delay << " != " 
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

void test_time_series_1_length(int rp_time_series_1_length){
    int time_series_1_length = 40;    
    if(time_series_1_length == rp_time_series_1_length)
        cout << "test_time_series_1_length() passed" << endl;
    else    
        cout << "test_time_series_1_length() failed: " << time_series_1_length 
             << " != " << rp_time_series_1_length << endl;    
}

void test_time_series_2_length(int rp_time_series_2_length){
    int time_series_2_length = 39;    
    if(time_series_2_length == rp_time_series_2_length)
        cout << "test_time_series_2_length() passed" << endl;
    else    
        cout << "test_time_series_2_length() failed: " << time_series_2_length 
             << " != " << rp_time_series_2_length << endl;    
}

void test_time_series_1(double* rp_time_series_1){
    double time_series_1[] = {0.20000000, 0.60800000, 0.90567680, 0.32462007, 
                              0.83311914, 0.52832022, 0.94695227, 0.19088795, 
                              0.58690901, 0.92129793, 0.27553060, 0.75853125, 
                              0.69601406, 0.80399826, 0.59882321, 0.91288909, 
                              0.30218586, 0.80130435, 0.60501961, 0.90808935, 
                              0.31715971, 0.82296382, 0.55363861, 0.93906702, 
                              0.21743658, 0.64660007, 0.86833200, 0.43445986, 
                              0.93367706, 0.23531199, 0.68377297, 0.82166448, 
                              0.55682146, 0.93773102, 0.22188790, 0.65608392, 
                              0.85742368, 0.46454358, 0.94522280, 0.19675130};
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
                              0.65666815, 0.90182036, 0.35416159, 0.91492463, 
                              0.31135020, 0.85764502, 0.48836017, 0.99945806, 
                              0.00216660, 0.00864760, 0.03429129, 0.13246159, 
                              0.45966208, 0.99349141, 0.02586492, 0.10078369, 
                              0.36250535, 0.92438088, 0.27960346, 0.80570146, 
                              0.62618647, 0.93630790, 0.23854168};
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
    double threshold = 0.5;
    if(threshold == rp_threshold)
        cout << "test_threshold() passed" << endl;
    else
        cout << "test_threshold() failed: " << threshold << " != " 
             << rp_threshold << endl;
}

void test_norm(string rp_norm){
    string norm = "euclidean";
    if(norm.compare(rp_norm) == 0)
        cout << "test_norm() passed" << endl;
    else
        cout << "test_norm() failed: " << norm << " != " << rp_norm << endl;
}

void test_number_of_vectors_1(int rp_number_of_vectors_1){
    int number_of_vectors_1 = 36;    
    if(number_of_vectors_1 == rp_number_of_vectors_1)
        cout << "test_number_of_vectors_1() passed" << endl;
    else
        cout << "test_number_of_vectors_1() failed: " << number_of_vectors_1 
             << " != " << rp_number_of_vectors_1 << endl;
}

void test_number_of_vectors_2(int rp_number_of_vectors_2){
    int number_of_vectors_2 = 33;    
    if(number_of_vectors_2 == rp_number_of_vectors_2)
        cout << "test_number_of_vectors_2() passed" << endl;
    else
        cout << "test_number_of_vectors_2() failed: " << number_of_vectors_2 
             << " != " << rp_number_of_vectors_2 << endl;
}

void test_cross_distance_matrix(double** crp_distance_matrix){
    double distance_matrix[36][33] = 
       {{0.631819,0.848616,0.901157,0.167570,1.213874,0.705203,0.790011,1.113238,0.887069,0.988141,0.910099,0.915075,1.162735,0.321462,0.541622,0.552105,0.572267,0.934583,0.846496,1.168342,0.811985,1.318995,1.013550,1.193384,1.135191,0.878556,0.506604,0.887107,1.010770,0.961985,0.271098,0.642230,0.624440},
        {0.603121,0.649272,0.427674,0.839731,0.478283,0.077701,0.868077,0.733773,0.556769,0.823360,0.562494,0.467430,0.441707,0.782749,0.828442,0.519718,0.593654,0.555407,0.790814,0.625358,0.887396,0.568333,0.344770,0.673732,0.810198,0.748497,0.896674,0.687208,0.366015,0.476423,0.841530,0.652494,0.612926},
        {0.891347,0.875952,0.601857,0.631935,1.072611,0.682406,0.150323,1.398968,1.070085,0.759630,1.147117,0.865674,0.866974,0.909648,1.064320,0.851755,0.528208,0.524418,1.094253,0.999680,1.101745,1.164553,1.044681,0.805659,1.468214,1.288461,1.061419,1.118048,1.086554,0.499140,0.940898,0.976906,0.893103},
        {0.825503,0.438125,0.634675,0.887353,0.649365,0.446362,1.119148,0.462872,0.155055,0.788663,0.713920,0.878446,0.762452,0.798286,0.476278,0.699088,0.590092,1.016869,0.380714,0.619086,0.496658,0.751244,0.607544,1.159156,0.536575,0.335665,0.574567,0.909614,0.457050,0.923515,0.660003,0.817076,0.283983},
        {0.990545,0.527356,0.417355,0.659571,0.938888,0.604379,0.432388,1.213206,0.803772,0.403273,1.154372,0.993663,0.792691,0.928983,0.826934,0.903709,0.204628,0.760859,0.761117,0.742553,0.761831,1.048687,1.007703,1.012881,1.291761,1.074022,0.831053,1.205492,0.974632,0.644335,0.808524,1.050595,0.602320},
        {0.346284,1.032149,0.763516,0.816917,0.822538,0.447168,0.889827,0.998800,0.939321,1.159639,0.489092,0.137524,0.735604,0.694002,1.049631,0.365977,0.853310,0.400153,1.148781,1.034835,1.219689,0.875405,0.497912,0.501702,1.040217,1.007741,1.095667,0.428889,0.651617,0.509116,0.936784,0.436902,0.933620},
        {1.063204,0.419704,0.125906,1.023510,0.504836,0.480484,0.811729,0.974602,0.593689,0.415474,1.047660,0.921785,0.391088,1.133275,0.946820,0.969803,0.486986,0.775913,0.706701,0.286294,0.795225,0.608579,0.760656,0.907530,1.077718,0.962883,1.002908,1.182866,0.688321,0.577585,1.041753,1.116720,0.625153},
        {0.667031,0.793187,0.881112,0.228777,1.189390,0.693370,0.816558,1.069939,0.831892,0.948636,0.913743,0.941324,1.150103,0.354710,0.467849,0.575958,0.538502,0.967216,0.776400,1.128711,0.738338,1.296661,1.005357,1.223018,1.093013,0.823985,0.431939,0.912535,0.987347,0.979105,0.211559,0.671934,0.559647},
        {0.474908,0.801400,0.544152,0.801046,0.610281,0.207203,0.839709,0.839389,0.714904,0.947328,0.504775,0.307235,0.537899,0.722183,0.907410,0.420259,0.675878,0.438783,0.935122,0.790799,1.018764,0.682362,0.369866,0.562926,0.900829,0.850053,0.965444,0.566575,0.469176,0.430006,0.860612,0.542287,0.735336},
        {0.876661,0.749376,0.440748,0.684757,0.919772,0.563741,0.282411,1.280825,0.941691,0.643769,1.077174,0.811401,0.715659,0.919829,1.007041,0.822542,0.440585,0.488421,0.987118,0.840009,1.011203,1.013460,0.931841,0.752689,1.357298,1.190279,1.018284,1.083307,0.959546,0.402556,0.927860,0.959230,0.796376},
        {0.556647,0.620830,0.685334,0.453454,0.913562,0.434633,0.843296,0.811966,0.582185,0.843223,0.694760,0.753342,0.904870,0.412224,0.416820,0.434217,0.453199,0.837086,0.623142,0.894568,0.641917,1.018712,0.732895,1.057219,0.848882,0.612480,0.450039,0.758654,0.700075,0.818226,0.339460,0.563764,0.386521},
        {0.761871,0.809488,0.582048,0.500411,1.026529,0.584158,0.276075,1.282323,0.970113,0.758629,1.025538,0.783544,0.851580,0.759087,0.930978,0.713836,0.450450,0.520315,0.997902,0.970432,1.005042,1.123310,0.954458,0.810550,1.345311,1.157760,0.929168,0.998793,0.992413,0.511480,0.795921,0.841528,0.782038},
        {0.888464,0.298380,0.245782,0.857696,0.523109,0.322470,0.829176,0.786756,0.392862,0.486222,0.870810,0.826618,0.496495,0.918749,0.709299,0.779424,0.368957,0.781784,0.523320,0.382477,0.616638,0.641038,0.645156,0.942697,0.880495,0.729658,0.772838,1.016366,0.551739,0.630767,0.812443,0.926451,0.397589},
        {0.884722,0.714018,0.532256,0.541655,1.027768,0.621346,0.261070,1.292190,0.931919,0.619842,1.117002,0.906556,0.857462,0.838358,0.895289,0.819588,0.345896,0.640846,0.918709,0.905999,0.915699,1.131214,1.016858,0.920367,1.361362,1.152704,0.889657,1.119340,1.024819,0.582108,0.797678,0.955922,0.723261},
        {0.541502,0.717458,0.476106,0.817738,0.535335,0.123427,0.850492,0.779225,0.628060,0.877649,0.530058,0.392578,0.479735,0.750903,0.861286,0.469068,0.626422,0.497467,0.855468,0.700172,0.945812,0.616694,0.345681,0.619020,0.848661,0.792060,0.924885,0.629157,0.407215,0.446850,0.846083,0.598586,0.666093},
        {0.880064,0.841502,0.553343,0.648483,1.023237,0.642494,0.189985,1.362200,1.032619,0.729197,1.120071,0.839260,0.816697,0.910594,1.050045,0.837091,0.504709,0.498524,1.065855,0.952331,1.079183,1.115021,1.004797,0.776593,1.433557,1.259410,1.051918,1.100290,1.044576,0.457739,0.938845,0.965652,0.866738},
        {0.733387,0.450790,0.625069,0.739064,0.733954,0.409391,1.017004,0.573334,0.289655,0.772587,0.696978,0.834442,0.801164,0.665665,0.386454,0.603415,0.501007,0.954638,0.407114,0.695872,0.485469,0.840286,0.640802,1.126652,0.631011,0.392571,0.474061,0.856121,0.529588,0.880562,0.523300,0.727876,0.223813},
        {0.875578,0.733765,0.546550,0.533704,1.037848,0.626283,0.248080,1.301301,0.946282,0.641939,1.114604,0.899040,0.865663,0.831688,0.905055,0.813144,0.364590,0.630358,0.936050,0.923143,0.932956,1.140466,1.019273,0.912068,1.369520,1.162298,0.898679,1.111736,1.031359,0.578702,0.800183,0.947930,0.737955},
        {0.582305,0.671519,0.442631,0.831738,0.496356,0.087484,0.861502,0.748147,0.580075,0.840842,0.550710,0.442481,0.452980,0.771517,0.838643,0.502182,0.603533,0.535611,0.811896,0.649897,0.906363,0.583464,0.342959,0.655032,0.822247,0.762262,0.905366,0.667543,0.378210,0.465298,0.842259,0.634114,0.629899},
        {0.887360,0.869114,0.590460,0.636774,1.060175,0.672304,0.160599,1.390203,1.061820,0.754057,1.139492,0.857238,0.853997,0.909860,1.062274,0.847286,0.524220,0.515204,1.088954,0.988780,1.098120,1.151896,1.033979,0.795811,1.459941,1.282070,1.060673,1.112286,1.075883,0.486931,0.941541,0.973134,0.888085},
        {0.807269,0.432847,0.631828,0.851504,0.673321,0.439435,1.094967,0.490595,0.183627,0.779931,0.714074,0.873131,0.774829,0.767517,0.445989,0.679549,0.564972,1.006027,0.374340,0.636535,0.482007,0.776831,0.620482,1.156509,0.559741,0.342957,0.542706,0.901348,0.478800,0.916522,0.624002,0.799181,0.256977},
        {0.956980,0.576713,0.443232,0.619407,0.960818,0.601808,0.380501,1.231628,0.835406,0.463733,1.139968,0.966055,0.807170,0.897976,0.839002,0.875233,0.230818,0.724400,0.801062,0.786497,0.800198,1.069263,1.006273,0.984938,1.307529,1.091263,0.840045,1.178089,0.984578,0.621946,0.797495,1.019984,0.629540},
        {0.375163,0.971913,0.700659,0.803861,0.767500,0.385609,0.860641,0.963582,0.885019,1.099391,0.493486,0.167837,0.678691,0.697448,1.013654,0.372756,0.800927,0.383724,1.095400,0.971074,1.168711,0.824783,0.463536,0.497958,1.010491,0.972018,1.062000,0.466081,0.607487,0.467374,0.914850,0.462129,0.882736},
        {0.980802,0.473280,0.073255,0.896075,0.613265,0.442453,0.643870,1.048836,0.670622,0.417813,1.030184,0.858165,0.450525,1.042553,0.928602,0.894700,0.393259,0.658029,0.757319,0.454905,0.823816,0.716329,0.781508,0.831315,1.144146,1.005965,0.971664,1.129578,0.742782,0.470630,0.973581,1.043675,0.629381},
        {0.580696,0.924843,0.928506,0.127822,1.241097,0.720348,0.761684,1.167481,0.959278,1.046166,0.900260,0.871958,1.174789,0.294258,0.644110,0.519866,0.627218,0.884837,0.941552,1.219241,0.913733,1.342407,1.018404,1.144884,1.188263,0.950955,0.612735,0.846793,1.037119,0.935147,0.366595,0.600180,0.712868},
        {0.872885,0.406728,0.353583,0.969322,0.375092,0.302672,0.979762,0.641438,0.320968,0.643695,0.770778,0.775964,0.433927,0.954768,0.757950,0.766140,0.543122,0.814992,0.564768,0.355359,0.687041,0.491931,0.506645,0.927081,0.741866,0.652469,0.838818,0.951895,0.385029,0.671458,0.882110,0.901827,0.467483},
        {0.971944,0.625401,0.453409,0.642409,0.976834,0.624590,0.330169,1.274154,0.882860,0.489354,1.163056,0.966877,0.808143,0.927497,0.895333,0.896322,0.288686,0.698620,0.857169,0.810106,0.858127,1.082483,1.024834,0.960216,1.350937,1.141764,0.895776,1.193114,1.011966,0.597301,0.844484,1.039575,0.685908},
        {0.283171,0.943254,0.733731,0.762473,0.779175,0.367107,0.917799,0.873161,0.822174,1.110146,0.391431,0.219225,0.731620,0.602598,0.921320,0.259124,0.788886,0.505785,1.032145,0.977689,1.104098,0.841691,0.430497,0.623824,0.911456,0.866786,0.972521,0.381604,0.559073,0.573541,0.824607,0.355591,0.818874},
        {0.930399,0.550400,0.186698,0.812293,0.706278,0.451100,0.520113,1.116625,0.749614,0.469904,1.030482,0.823433,0.521830,0.987419,0.938246,0.852736,0.367222,0.579345,0.820799,0.582265,0.871772,0.806504,0.814580,0.785388,1.205641,1.055403,0.970865,1.099950,0.800885,0.410770,0.941715,1.000537,0.665136},
        {0.534770,0.919285,0.904078,0.160232,1.207043,0.683908,0.750794,1.144706,0.944322,1.043226,0.858858,0.822186,1.139195,0.277084,0.656794,0.475156,0.623035,0.841703,0.943769,1.198399,0.923902,1.306650,0.976514,1.098629,1.166558,0.939629,0.633102,0.802529,1.001566,0.896156,0.389203,0.558507,0.710844},
        {0.931123,0.290321,0.297751,0.933169,0.470014,0.359637,0.918911,0.727767,0.331463,0.518979,0.872507,0.859172,0.487505,0.969032,0.722974,0.820088,0.447191,0.844047,0.497409,0.321853,0.608127,0.588108,0.628663,0.983904,0.826495,0.692748,0.795161,1.038920,0.511397,0.688856,0.855219,0.962872,0.406733},
        {0.952048,0.584840,0.447837,0.613620,0.964541,0.602018,0.372392,1.234936,0.840849,0.473272,1.138081,0.961972,0.809727,0.893593,0.841594,0.871183,0.236379,0.718807,0.807825,0.793603,0.806757,1.072733,1.006414,0.980641,1.310424,1.094488,0.842172,1.174088,0.986542,0.618704,0.796473,1.015543,0.634508},
        {0.380461,0.960384,0.689358,0.802057,0.756910,0.373680,0.856965,0.955691,0.873994,1.088516,0.493353,0.175073,0.668451,0.697943,1.006268,0.373968,0.791503,0.383668,1.084769,0.958992,1.158628,0.815072,0.456479,0.499634,1.003558,0.964124,1.055156,0.472218,0.598316,0.461659,0.910429,0.466395,0.872704},
        {0.967206,0.490148,0.098120,0.874352,0.635299,0.441357,0.613112,1.064630,0.688734,0.427393,1.028989,0.848207,0.466146,1.027785,0.929248,0.882957,0.382834,0.637389,0.771345,0.486305,0.833892,0.737767,0.788119,0.818671,1.158404,1.016906,0.969773,1.121198,0.755719,0.453527,0.964164,1.031882,0.635883},
        {0.569328,0.932632,0.928599,0.132770,1.239617,0.717628,0.757795,1.170445,0.965284,1.052478,0.893886,0.860692,1.171503,0.290667,0.657038,0.511042,0.633296,0.873754,0.952287,1.222162,0.926269,1.340236,1.013507,1.133354,1.191246,0.957478,0.627110,0.836613,1.035418,0.927244,0.380385,0.590442,0.722390},
        {0.915626,0.367731,0.354739,0.986092,0.391398,0.346543,0.991666,0.650902,0.300930,0.612290,0.814658,0.825270,0.454959,0.982400,0.752290,0.806608,0.536544,0.853342,0.532493,0.320856,0.656786,0.508481,0.552354,0.968410,0.753053,0.654528,0.832998,0.998030,0.421625,0.703616,0.890528,0.943136,0.452022}};
    bool found_error = false;
    int i, j;    
    for (i = 0; i < 36; i++){
        for (j = 0; j < 33; j++){
            if(fabs(distance_matrix[i][j]-crp_distance_matrix[i][j]) > 0.00001){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_cross_distance_matrix() passed" << endl;
    else
        cout << "test_cross_distance_matrix() failed: distance value error at " 
             << i  << "," << j << " ( " << distance_matrix[i][j] << " != " 
             << crp_distance_matrix[i][j] << " )" << endl;  
}

void test_cross_recurrence_matrix(int** crp_recurrence_matrix){
    int recurrence_matrix[36][33] = 
           {{0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1},
            {0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0},
            {0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
            {1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0},
            {0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1},
            {0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0},
            {0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1},
            {0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0},
            {0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,1,0},
            {0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1}};
    bool found_error = false;
    int i,j;
    for(i = 0; i < 36; i++){
        for(j = 0; j < 33; j++){
            if(recurrence_matrix[i][j] != crp_recurrence_matrix[i][j]){
                found_error = true;
                break;
            }
        }
        if(found_error)
            break;
    }
    if(!found_error)
        cout << "test_cross_recurrence_matrix() passed" << endl;
    else
        cout << "test_cross_recurrence_matrix() failed: recurrence value error at " 
             << i  << "," << j << " ( " << recurrence_matrix[i][j] << " != " 
             << crp_recurrence_matrix[i][j] << " )" << endl;    
}

int main(int argc, char** argv) {
    double time_series_1[] = {0.20000000, 0.60800000, 0.90567680, 0.32462007, 
                              0.83311914, 0.52832022, 0.94695227, 0.19088795, 
                              0.58690901, 0.92129793, 0.27553060, 0.75853125, 
                              0.69601406, 0.80399826, 0.59882321, 0.91288909, 
                              0.30218586, 0.80130435, 0.60501961, 0.90808935, 
                              0.31715971, 0.82296382, 0.55363861, 0.93906702, 
                              0.21743658, 0.64660007, 0.86833200, 0.43445986, 
                              0.93367706, 0.23531199, 0.68377297, 0.82166448, 
                              0.55682146, 0.93773102, 0.22188790, 0.65608392, 
                              0.85742368, 0.46454358, 0.94522280, 0.19675130};

    double time_series_2[] = {0.20001000, 0.64002400, 0.92157312, 0.28910442, 
                              0.82209222, 0.58502640, 0.97108205, 0.11232682, 
                              0.39883801, 0.95906501, 0.15703728, 0.52950629, 
                              0.99651751, 0.01388143, 0.05475495, 0.20702737, 
                              0.65666815, 0.90182036, 0.35416159, 0.91492463, 
                              0.31135020, 0.85764502, 0.48836017, 0.99945806, 
                              0.00216660, 0.00864760, 0.03429129, 0.13246159, 
                              0.45966208, 0.99349141, 0.02586492, 0.10078369, 
                              0.36250535, 0.92438088, 0.27960346, 0.80570146, 
                              0.62618647, 0.93630790, 0.23854168};
    int time_series_1_length = 40;
    int time_series_2_length = 39;    
    int dimension = 3;
    int delay_time_series_1 = 2;
    int delay_time_series_2 = 3;
    double threshold = 0.5;
    string norm = "euclidean";
    CrossRecurrencePlot crp(time_series_1, time_series_2, 
                            time_series_1_length, time_series_2_length, 
                            dimension, delay_time_series_1, delay_time_series_2,
                            threshold, norm);
    
    cout << "test_cross_recurrence_plot_euclidean.cpp" << endl << endl;
    test_delay_time_series_1(crp.get_delay_time_series_1());
    test_delay_time_series_2(crp.get_delay_time_series_2());
    test_dimension(crp.get_dimension());
    test_threshold(crp.get_threshold());
    test_norm(crp.get_norm());
    test_time_series_1_length(crp.get_time_series_1_length());
    test_time_series_2_length(crp.get_time_series_2_length());
    test_time_series_1(crp.get_time_series_1());
    test_time_series_2(crp.get_time_series_2());
    test_number_of_vectors_1(crp.get_number_of_vectors_1());
    test_number_of_vectors_2(crp.get_number_of_vectors_2());    
    test_cross_distance_matrix(crp.get_cross_distance_matrix());
    test_cross_recurrence_matrix(crp.get_cross_recurrence_matrix());
    
    return (EXIT_SUCCESS);
}