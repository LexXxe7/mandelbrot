#ifndef WINDOW_H
#define WINDOW_H WINDOW_H

#include<iostream>
#include<fstream>
#include<tuple>
#include<memory>
#include<chrono>

using namespace std;

#define newline '\n'

template<class T>
class Window {
    public:
        Window(T x_min, T x_max, T y_min, T y_max) : _x_min(x_min), _x_max(x_max), _y_min(y_min), _y_max(y_max) {}
        
        T x_min() const {return _x_min;}
        T y_min() const {return _y_min;}
        
        T width()  const {return _x_max-_x_min;}
        T height() const {return _y_max-_y_min;}
        T size() const {return width()*height();}
    
    private:
        T _x_min, _x_max, _y_min, _y_max;
};

void iterate(const Window<unsigned int>&, const Window<double>&, const unsigned int, const unique_ptr<unsigned int[]>&);

tuple<unsigned int, unsigned int, unsigned int> colorize(const unsigned int, const unsigned int);

void plot(const Window<unsigned int>&, const unsigned int, const unique_ptr<unsigned int[]>&);

void mandelbrot(const Window<unsigned int>&, const Window<double>&, const unsigned int);

#endif