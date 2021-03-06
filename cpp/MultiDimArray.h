//
// Created by smith on 9/29/2017.
//

#ifndef CPP_MULTIDIMARRAY_H
#define CPP_MULTIDIMARRAY_H

#include <iostream>
#include <vector>

class MultiDimArray {

    // Custom c++ version of a numpy array.
    public:

    explicit MultiDimArray(std::vector<int> dims);
    std::vector<float> values;
    std::vector<int> shape;
    void fillArray(std::ifstream *file);
    float get(int dim0) const;
    float get(int dim0, int dim1) const;
    float get(int dim0, int dim1, int dim2) const;
    float get(int dim0, int dim1, int dim2, int dim3) const;

    void set(float newValue, int dim0);
    void set(float newValue, int dim0, int dim1);
    void set(float newValue, int dim0, int dim1, int dim2);
    void set(float newValue, int dim0, int dim1, int dim2, int dim3);

    // To check any access issue.
    void checkBounds(const std::vector<int>& dims);
};


#endif //CPP_MULTIDIMARRAY_H
