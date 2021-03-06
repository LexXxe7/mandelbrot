# Mandelbrot Set

This repo draws the [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set), which is a fractal meaning that it’s made of little replicas of itself. Fractals are fascinating structures and very present in nature too.

<p align="center">
    <img src=images/mandelbrot1.png>
</p>

<p align="center">
    <img src=images/mandelbrot2.png>
</p>

The Mandelbrot set is the set of complex numbers <a href="https://www.codecogs.com/eqnedit.php?latex=c" target="_blank"><img src="https://latex.codecogs.com/gif.latex?c" title="c" /></a> for which the sequence

<p align="center">
    <a href="https://www.codecogs.com/eqnedit.php?latex=\begin{aligned}&space;z_{0}&space;&=&space;0&space;\\&space;z_{n&plus;1}&space;&=&space;z_{n}^2&plus;c&space;\end{aligned}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{aligned}&space;z_{0}&space;&=&space;0&space;\\&space;z_{n&plus;1}&space;&=&space;z_{n}^2&plus;c&space;\end{aligned}" title="\begin{aligned} z_{0} &= 0 \\ z_{n+1} &= z_{n}^2+c \end{aligned}" /></a>
</p>

converges.

Mandelbrot set images may be created by sampling the complex numbers and testing, for each sample point <a href="https://www.codecogs.com/eqnedit.php?latex=c" target="_blank"><img src="https://latex.codecogs.com/gif.latex?c" title="c" /></a>, whether the sequence goes to infinity (in practice — whether it leaves some predetermined bounded neighborhood of <a href="https://www.codecogs.com/eqnedit.php?latex=0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?0" title="0" /></a> after a predetermined number of iterations). Treating the real and imaginary parts of <a href="https://www.codecogs.com/eqnedit.php?latex=c" target="_blank"><img src="https://latex.codecogs.com/gif.latex?c" title="c" /></a> as image coordinates on the complex plane, pixels may then be colored according to how soon the sequence crosses an arbitrarily chosen threshold.
To obtain a continuous image - meaning a smooth transition from color to color - a continuous map between the iteration count and the 3D color space is used. For that map this repo uses 3 smooth, continuous functions that will map every number <a href="https://www.codecogs.com/eqnedit.php?latex=t" target="_blank"><img src="https://latex.codecogs.com/gif.latex?t" title="t" /></a> being the iteration count divided by the chosen threshold. For those 3 functions a slightly modified form of the Bernstein polynomials is used:

<p align="center">
    <a href="https://www.codecogs.com/eqnedit.php?latex=\begin{aligned}&space;r(t)&space;&=&space;\hspace{2.1mm}&space;9.45&space;\hspace{2.1mm}&space;*&space;(1&space;-&space;t)&space;\hspace{1.6mm}&space;*&space;t^{3}&space;\\&space;g(t)&space;&=&space;15.75&space;\hspace{2.1mm}&space;*&space;(1&space;-&space;t)^{2}&space;*&space;t^{2}&space;\\&space;b(t)&space;&=&space;\hspace{2.1mm}&space;8.925&space;*&space;(1&space;-&space;t)^{3}&space;*&space;t&space;\end{aligned}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{aligned}&space;r(t)&space;&=&space;\hspace{2.1mm}&space;9.45&space;\hspace{2.1mm}&space;*&space;(1&space;-&space;t)&space;\hspace{1.6mm}&space;*&space;t^{3}&space;\\&space;g(t)&space;&=&space;15.75&space;\hspace{2.1mm}&space;*&space;(1&space;-&space;t)^{2}&space;*&space;t^{2}&space;\\&space;b(t)&space;&=&space;\hspace{2.1mm}&space;8.925&space;*&space;(1&space;-&space;t)^{3}&space;*&space;t&space;\end{aligned}" title="\begin{aligned} r(t) &= \hspace{2.1mm} 9.45 \hspace{2.1mm} * (1 - t) \hspace{1.6mm} * t^{3} \\ g(t) &= 15.75 \hspace{2.1mm} * (1 - t)^{2} * t^{2} \\ b(t) &= \hspace{2.1mm} 8.925 * (1 - t)^{3} * t \end{aligned}" /></a>
</p>

They are continuous, smooth and have values in the [0, 1) interval.
Finally, for plotting, an image file format called [PPM](https://en.wikipedia.org/wiki/Netpbm_format#PPM_example) is used.

## Overview of Code Structure

* The file "window.h" contains the Window class template and all function prototypes.
* The file "util.cpp" contains all function definitions.
* The file "main.cpp" contains the simulation settings.

## Dependencies for Running Locally

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: [click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc/g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Mandelbrot`
