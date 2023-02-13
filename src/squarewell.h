#ifndef PHY_GRAPHICS_SQUAREWELL_H
#define PHY_GRAPHICS_SQUAREWELL_H

#import <iostream>
#import <iomanip>
#import <cmath>
#import <complex>

#import "imgui.h"

class SquareWell;

namespace PhyG{
    bool DrawSquareWell(){
        static bool p_open = true;

        // Construct on the stack
        static SquareWell sqw;

        if(p_open){
            sqw.step(2);

            ImGui::Begin("Scene View", &p_open, 0);
            ImGui::PlotLines("", (float*) sqw.expect_arr, 1000, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(0, 120.0f));
            ImGui::End();
        }

        return p_open;
    }
}

class SquareWell{
public:
    SquareWell();
    ~SquareWell();

    //Sum of principle wave functions
    std::complex<double> psi(double x, double t);
    void step(double t);

    std::complex<double> *coeff;
    double* expect_arr;

    //Length of the square well.
    int l = 2;

private:
    // Principle wave functions
    double psi_x_n(double x, int n);
    std::complex<double> psi_t_n(double t, int n);
    double psi_x_initial();

    double initial_function(double x);

    //Computer coefficients of first n wave functions
    void compute_coeff();

    //Constants
    const int h_bar = 1;
    const double mass = 1;

    //Number of wave functions in superposition
    int count = 50;

    const int step_size = 1000;

    //Space differential
    const double dx = l / step_size;
};


#endif //PHY_GRAPHICS_SQUAREWELL_H
