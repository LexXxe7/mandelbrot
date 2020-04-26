#include"window.h"

void iterate(const Window<unsigned int> &image, const Window<double> &domain, const unsigned int iter_max, const unique_ptr<unsigned int[]> &iterations) {
    double x0, y0, x, y, rsquare, isquare, zsquare;
    unsigned int iter;
    
    // Looping over each pixel from image
    int index=0;
    for (int i=0; i<image.width(); i++)
        for (int j=0; j<image.height(); j++) {
            // Converting pixel coordinate to the complex domain
            x0=static_cast<double>(i)/image.width()*domain.width()+domain.x_min();
            y0=static_cast<double>(j)/image.height()*domain.height()+domain.y_min();
            
            x=y=rsquare=isquare=zsquare=0.0;
            
            iter=0;
            
            // Checking if point is in the set or escapes to infinity
            while ((rsquare+isquare<=4.0) && (iter<iter_max)) {
                x=rsquare-isquare+x0;
                y=zsquare-rsquare-isquare+y0;
                
                rsquare=x*x;
                isquare=y*y;
                zsquare=(x+y)*(x+y);
                
                iter++;
            }
            
            iterations[index++]=iter;
        }
}

tuple<unsigned int, unsigned int, unsigned int> colorize(const unsigned int iter_max, const unsigned int iter) {
    double t=static_cast<double>(iter)/static_cast<double>(iter_max);
    
    // Using modified Bernstein polynomials to calculate r, g, b
    unsigned int r=static_cast<unsigned int>(9.45*(1-t)*t*t*t*255);
    unsigned int g=static_cast<unsigned int>(15.75*(1-t)*(1-t)*t*t*255);
    unsigned int b=static_cast<unsigned int>(8.925*(1-t)*(1-t)*(1-t)*t*255);
    
    return make_tuple(r, g, b);
}

void plot(const Window<unsigned int> &image, const unsigned int iter_max, const unique_ptr<unsigned int[]> &iterations) {
    tuple<unsigned int, unsigned int, unsigned int> color;
    
    // Saving the result as an image
    ofstream fractal("mandelbrot.ppm");
    fractal << "P3" << newline << image.width() << ' ' << image.height() << " 255" << newline;
    
    for (int index=0; index<image.size(); index++) {
        color=colorize(iter_max, iterations[index]);
        
        fractal << get<0>(color) << ' ' << get<1>(color) << ' ' << get<2>(color) << newline;
    }
    
    fractal.close();
}

void mandelbrot(const Window<unsigned int> &image, const Window<double> &domain, const unsigned int iter_max) {
    unique_ptr<unsigned int[]> iterations(new unsigned int [image.size()]);
    
    iterate(image, domain, iter_max, iterations);
    
    plot(image, iter_max, iterations);
}