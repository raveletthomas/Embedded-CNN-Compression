#pragma once

#include <cstdlib> 
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

class Layer {
    public:
        /* Constructors */
        Layer();
        Layer(size_t size);
        Layer(const Layer& other);
        Layer(Layer&& other);

        /* Destructor */
        ~Layer();

        /* Getter functions */
        size_t getSize() const;
        std::vector<double> getData() const;
        double getDataIndex(size_t index) const;

        /* Setter functions */
        void swapData(std::vector<double> newData);
        void setSize(size_t newSize);

        /* Other functions */
        void print() const;
        void printSize() const;

    private:
        size_t _size;
        std::vector<double> _data;
};

size_t computeLayerSize(uint8_t nb_filter, uint8_t nb_channel, uint8_t kern_width);