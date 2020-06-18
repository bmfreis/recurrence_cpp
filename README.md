# recurrence_cpp

This scientific software written in C++ computes *Recurrence Plot* (RP), *Cross Recurrence Plot* (CRP), *Joint Recurrence Plot* (JRP) and *Recurrence Quantification Analysis* on commandline of Linux systems. 

### Recurrence Plot

The class *RecurrencePlot* computes:

- State space trajectory reconstruction from single time-series by time-delay embedding
- Distance matrix (using Manhattan, Euclidian or Supremum distance)
- Recurrence matrix

### Cross Recurrence Plot

The class *CrossRecurrencePlot* computes:

- State space trajectory reconstruction from single time-series by time-delay embedding
- Cross distance matrix (using Manhattan, Euclidian or Supremum distance)
- Cross recurrence matrix

### Joint Recurrence Plot

The class *JointRecurrencePlot* computes:

- State space trajectory reconstruction from single time-series by time-delay embedding
- Distance matrix (using Manhattan, Euclidian or Supremum distance)
- Recurrence matrix
- Joint recurrence matrix

### Recurrence Quantification Analysis

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
