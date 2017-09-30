//
// Created by smith on 9/29/2017.
//

#include <c++/cassert>
#include <iostream>
#include <c++/fstream>
#include "Dense.h"
#include "Activation.h"
#include "../utils.cpp"
using namespace std;


Dense::Dense(ifstream *file) {
    unsigned int tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim0 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim1 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int biasDim0 = tmp;
    kernel.reset(new MultiDimArray({kernelDim0, kernelDim1}));
    biases.reset(new MultiDimArray({biasDim0}));

    //Now we fill the weights.
    fillArray<double>(file, &(kernel->values));
    fillArray<double>(file, &(biases->values));

    //We get the activation.
    activation = getActivation(file);
}


vector<int> Dense::getOutputShapeFor(vector<int> *inputShape) {
    assert(inputShape->size()==1);
    assert((*inputShape)[0] == kernel->shape[0]);
    assert( biases->shape[0] == kernel->shape[1]);

    return std::vector<int>({biases->shape[0]});
}


void Dense::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<biases->shape[0];i++){
        double sum=0;

        for(int j=0; j<in->shape[0];i++)
            sum+= in->values[j] * (*kernel->get(i,j));

        sum+=biases->values[i];
        out->values[i]=sum;
    }

    Activation actLayer(activation);
    actLayer.call(out, out);

}
