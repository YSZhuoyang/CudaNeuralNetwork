
#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_

#include "Layer.h"


class NeuralNetwork
{
public:
    NeuralNetwork();
    ~NeuralNetwork();

    void initLayers(
        const unsigned int numInstances,
        const unsigned int numTrainingFeatures,
        const unsigned int numLayers,
        // An array of length which equals to numLayers + 1
        // All except last count include bias
        const unsigned int* architecture,
        cublasHandle_t cublasHandle );
    void train(
        const float* featureMat,
        const unsigned short* classIndexVec,
        const unsigned int maxIter,
        const float learningRate,
        const float costThreshold );

private:
    void forwardProp();
    void backProp( const float learningRate );

    // Does not include input layer
    float* dFeatureMat             = nullptr;
    unsigned short* dClassIndexVec = nullptr;
    // To be deleted
    const unsigned short* classIndexVec  = nullptr;
    Layer* layerArr                = nullptr;
    unsigned int numInstances      = 0;
    unsigned int numTrainingFeas   = 0;
    unsigned short numLayers       = 0;
    unsigned short numHiddenLayers = 0;
};

#endif
