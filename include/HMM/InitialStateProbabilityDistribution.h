
#ifndef __HMM__InitialStateProbabilityDistribution__
#define __HMM__InitialStateProbabilityDistribution__

class InitialStateProbabilityDistribution {
    
private:
    
    int numberOfStates;
    double *propabilityDistribution;
    
    InitialStateProbabilityDistribution() { }
    
public:
    
    InitialStateProbabilityDistribution(int numberOfStates, double *propabilityDistribution);
    
    int getNumberOfStates();
    double getPropability(int state);
    
};

#endif
