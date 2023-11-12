#include "layer.h"

/*** Constructors ***/

Layer::Layer() {
    _size = 0;
    _data = {};
}

Layer::Layer(size_t size) {

    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, 1);

    this->_size = size;
    
    for (size_t i = 0; i < size; i++) {
        this->_data.push_back(distribution(rng)); 
    }

}

Layer::Layer(const Layer& other) {
    
    this->_size = other.getSize();
    
    for (size_t i = 0; i < _size; i++) {
        this->_data[i] = other.getData()[i]; // Copying the data array into the new arrray
    }
}

Layer::Layer(Layer&& other) {
    std::swap(other._size, this->_size);
    std::swap(other._data, this->_data);
}

/*** Destructor ***/

Layer::~Layer() {
}

/*** Getter functions ***/

size_t Layer::getSize() const { return _size; }
std::vector<double> Layer::getData() const { return _data; }
double Layer::getDataIndex(size_t index) const { return _data[index]; }

/*** Setter functions ***/

void Layer::swapData(std::vector<double> newData) {
    std::swap(_data, newData);
}

void Layer::setSize(size_t newSize) {
    _size = newSize;
}

/*** Other functions ***/

void Layer::print() const {
    std::cout << "Size : " <<_size << std::endl;

    for (int i = 0; i < _size; i++) {
        std::cout << _data[i] << " / ";
    }
    std::cout << std::endl;

}

void Layer::printSize() const { std::cout << "Size : " <<_size << std::endl; }

size_t computeLayerSize(uint8_t nb_filter, uint8_t nb_channel, uint8_t kern_width) {
    return nb_filter * (kern_width * kern_width * nb_channel + 1);
}