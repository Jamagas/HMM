
#ifndef __HMM__StateTransitionProbabilityDistributionMatrix__
#define __HMM__StateTransitionProbabilityDistributionMatrix__

class StateTransitionProbabilityDistributionMatrix {

private:
    
    int numberOfStates;
    double **propabilityDistributionMatrix;
    
    StateTransitionProbabilityDistributionMatrix() { }
    
public:
    
    StateTransitionProbabilityDistributionMatrix(int numberOfStates, double **propabilityDistributionMatrix);
    
    double getPropability(int startState, int endState);
    
};

#endif
