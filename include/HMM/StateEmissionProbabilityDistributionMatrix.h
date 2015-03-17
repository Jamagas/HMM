
#ifndef __HMM__StateEmissionProbabilityDistributionMatrix__
#define __HMM__StateEmissionProbabilityDistributionMatrix__

class StateEmissionProbabilityDistributionMatrix {
    
private:
    
    int numberOfStates;
    double **propabilityDistributionMatrix;
    
    StateEmissionProbabilityDistributionMatrix() { }
    
public:
    
    StateEmissionProbabilityDistributionMatrix(int numberOfStates, double **propabilityDistributionMatrix);
    
    double getPropability(int state, int observation);
    
};

#endif
