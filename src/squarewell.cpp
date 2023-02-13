#include "squarewell.h"

SquareWell::SquareWell() {
    // These do not need to be re-computed every time step
    coeff = (std::complex<double>*) malloc(count * sizeof(std::complex<double>));
    compute_coeff();

    expect_arr = (double*) malloc(step_size * sizeof(double));

}
SquareWell::~SquareWell() {
    free(coeff);
    free(expect_arr);
}

double SquareWell::psi_x_n(double x, int n) {
    return sqrt(2/l) * sin((x*n*M_PI)/l);
}

// The energy level might need to vary with n
std::complex<double> SquareWell::psi_t_n(double t, int n) {
    using namespace std::complex_literals;
    std::complex<double> energy_state = std::exp(-1i*( (n*n* M_PI*M_PI* h_bar) / ( 2 * mass * l*l )  ) ) * t;
    return energy_state;
}

std::complex<double> SquareWell::psi(double x, double t) {
    std::complex<double> p;

    for(int i = 0; i < step_size; i++){
        p += coeff[i] * psi_x_n(x, i) * psi_t_n(t, i);
    }

    return p;
}

// Compute the expectation values for time step t
void SquareWell::step(double t) {
    for(int i = 0; i < step_size; i++){
        std::complex<double> p = psi(i*dx, t);
        expect_arr[i] += (p.real() + p.imag()) * (p.real() - p.imag());
    }
}

//===SETUP===

double SquareWell::initial_function(double x) {
    return sqrt(30 / pow(l, 5)) * x * ( l - x );
}

// Compute the coefficients where psi(x, 0) using fourier trick
void SquareWell::compute_coeff() {
    //C_n
    for(int i = 0; i < count; i++){
        for(int j = 0; j < step_size; j++){
            coeff[i] += (initial_function(j*dx) * psi_x_n(j*dx, i) ) * dx;
        }
    }
}