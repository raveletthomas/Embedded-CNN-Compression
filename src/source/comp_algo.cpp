#include "comp_algo.h"

void compressionRLE(Layer& input) {

    /* Initialisation of variables */
    size_t N = input.getSize();

    double actual_element;
    double next_element;
    size_t counter;
    size_t i = 0;
    size_t j = 0;

    /* Initialisation of the temporary output
    the maximum possible size of tmp is 2*N if each value is unique in the input data */
    std::vector<double> tmp;

    /* Main loop */
    for (i = 0; i < N; i++) {

        // Updating variables 
        counter = i;
        actual_element = input.getData()[counter];
        next_element = input.getData()[counter + 1];

        // Checking the number of successive equals values
        while (actual_element == next_element) {
            actual_element = next_element;
            counter++;
            next_element = input.getData()[counter + 1];
        }

        // Updating output vector and indices
        tmp.push_back(counter - i + 1);
        tmp.push_back(input.getData()[i]);

        j += 2;
        i = counter;
    }

    /* Updating the input layer */
    input.swapData(tmp); // Swapping the data pointers
    input.setSize(j); // At the end of the computation, j is equal to the lenght of tmp 

}

void decompressionRLE(Layer& input) {
    /* Declaring variables */
    size_t N = input.getSize();
    size_t iteration_number;
    double value;
    size_t count = 0;

    /* Declaring the output vector */
    std::vector<double> output;

    /* Main loop */
    for (size_t i = 0; i < N - 1; i += 2) {

        // Getting information about the encoding
        iteration_number = input.getDataIndex(i);
        value = input.getDataIndex(i + 1);

        // Updating the output vector
        for (size_t j = count; j < count + iteration_number; j++) {
            output.push_back(value);
        }

        // Updating the counter
        count += iteration_number;

    }

    /* Updating the layer */
    input.swapData(output); // Swapping the data pointers
    input.setSize(count); // At the end of the computation, count is equal to the lenght of tmp 

}