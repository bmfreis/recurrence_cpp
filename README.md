# recurrence_cpp

This scientific software written in C++ computes *Recurrence Plot* (RP), *Cross Recurrence Plot* (CRP), *Joint Recurrence Plot* (JRP) and *Recurrence Quantification Analysis* on commandline of Linux systems. 

### Recurrence Plot

*Recurrence Plot (RP) * is a visualisation of a square matrix, in which the matrix elements correspond to those times at which a state of a dynamical system recurs. The RP reveals all the times when the phase space trajectory of the dynamical system visits roughly the same area in the phase space. [1,3]

The class *RecurrencePlot* computes:
- State space trajectory reconstruction from single time-series by time-delay embedding
- Distance matrix (using Manhattan, Euclidian or Supremum distance)
- Recurrence matrix

### Cross Recurrence Plot

*Cross Recurrence Plot (CRP)* is a graph which shows all those times at which a state in one dynamical system occurs simultaneously in a second dynamical system. With other words, the CRP reveals all the times when the phase space trajectory of the first system visits roughly the same area in the phase space where the phase space trajectory of the second system is. [3]

The class *CrossRecurrencePlot* computes:
- State space trajectory reconstruction from single time-series by time-delay embedding
- Cross distance matrix (using Manhattan, Euclidian or Supremum distance)
- Cross recurrence matrix

### Joint Recurrence Plot

*Joint Recurrence Plot (JRP)* is a graph which shows all those times at which a recurrence in one dynamical system occurs simultaneously with a recurrence in a second dynamical system. [3]

The class *JointRecurrencePlot* computes:
- State space trajectory reconstruction from single time-series by time-delay embedding
- Distance matrix (using Manhattan, Euclidian or Supremum distance)
- Recurrence matrix
- Joint recurrence matrix

### Recurrence Quantification Analysis

*Recurrence Quantification Analysis (RQA)* is a method which quantifies the number and duration of recurrences of a dynamical system presented by its state space trajectory. [2,3,4,5]

The class *RecurrenceQuantificationAnalysis* computes:
- Diagonal frequency distribution - P(l)
- Vertical frequency distribution - P(v) 
- White vertical frequency distribution - P(w) 
- Recurrence rate - RR 
- Determinism - DET 
- Average diagonal line length - L
- Longest diagonal line length - Lmax 
- Divergence - DIV
- Entropy diagonal lines - Lentr 
- Laminarity - LAM
- Average vertical line length - V 
- Longest vertical line length - Vmax 
- Entropy vertical lines - Ventr
- Average white vertical line length - W 
- Longest white vertical line length - Wmax 
- Entropy white vertical lines - Wentr
- Ratio determinism recurrence rate - DET/RR
- Ratio laminarity determinism - LAM/DET

### Remarks

Tested on 
- Ubuntu: 18.04, 20.04
- g++: 7.5.0, 9.3.0


### References

[1](https://www.doi.org/10.1209/0295-5075/4/9/004) J.-P. Eckmann, S. Oliffson Kamphorst, D. Ruelle: Recurrence Plots of Dynamical Systems, Europhysics Letters, 4(9), 973–977p. (1987)

[2](https://www.doi.org/10.1103/PhysRevE.66.026702) N. Marwan, N. Wessel, U. Meyerfeldt, A. Schirdewan, J. Kurths: Recurrence Plot Based Measures of Complexity and its Application to Heart Rate Variability Data, Physical Review E, 66(2), 026702p. (2002)

[3](http://www.recurrence-plot.tk) N. Marwan, M. C. Romano, M. Thiel, J. Kurths: Recurrence Plots for the Analysis of Complex Systems, Physics Reports, 438(5-6), 237-329p. (2007)

[4](https://www.doi.org/10.1152/jappl.1994.76.2.965) C. L. Webber, Jr., J. P. Zbilut: Dynamical assessment of physiological systems and states using recurrence plot strategies, Journal of Applied Physiology, 76(2), 965-973p. (1994)

[5](https://www.doi.org/10.1016/0375-9601(92)90426-M) J. P. Zbilut, C. L. Webber, Jr.: Embeddings and delays as derived from quantification of recurrence plots, Physics Letters A, 171(3–4), 199–203p. (1992)
