#include"window.h"

int main() {
    Window<unsigned int> image(0, 2000, 0, 2000);
    Window<double> domain(-2.5, 1.0, -1.75, 1.75);  // (-1.225, -1.22, 0.15, 0.155);
    
    unsigned int iter_max=1000;
    
    
    
    auto start=chrono::steady_clock::now();
    
    mandelbrot(image, domain, iter_max);
    
    auto end  =chrono::steady_clock::now();
    
    cout << "The calculation of the Mandelbrot set took " << chrono::duration<double, milli>(end-start).count()/1000 << " seconds." << newline;
}