#include <iostream>
#include <iomanip>
#include <vector>


// Function
double function(double x) {
    return log(x*x*x + 2);
}

// Left Riemann Sum
double left_riemann(double upper_bound, double lower_bound, int num_rectangles) {
    double spacing = (upper_bound - lower_bound)/static_cast<double>(num_rectangles);
    double sum {0};
    for (int i {0}; i < num_rectangles; i++) {
        sum += spacing * function(lower_bound + spacing * i);
    }
    return sum;
}
double left_riemann(std::vector<std::vector<int>> &table){
    double sum = 0;
    for (int i {0}; i < table.size() - 1; i++) {
        double spacing = table[i + 1][0] - table[i][0];
        sum += spacing * table[i][1];
    }
    return sum;
}

// Right Riemann Sum
double right_riemann(double upper_bound, double lower_bound, int num_rectangles) {
    double spacing = (upper_bound - lower_bound)/static_cast<double>(num_rectangles);
    double sum {0};
    for (int i {0}; i < num_rectangles; i++) {
        sum += spacing * function(lower_bound + spacing * (i + 1));
    }
    return sum;
}
double right_riemann(std::vector<std::vector<int>> &table){
    double sum = 0;
    for (int i {1}; i < table.size(); i++) {
        double spacing = table[i][0] - table[i-1][0];
        sum += spacing * table[i][1];
    }
    return sum;
}

// Midpoint Riemann Sum
double midpoint_riemann(double upper_bound, double lower_bound, int num_rectangles) {
    double spacing = (upper_bound - lower_bound)/static_cast<double>(num_rectangles);
    double sum {0};
    for (int i {0}; i < num_rectangles; i++) {
        sum += spacing * function(lower_bound + spacing/2.0 + (spacing * i));
    }
    return sum;
}
double midpoint_riemann(std::vector<std::vector<int>> &table){
    double sum {0};
    for (int i {}; i < table.size()-2; i+=2){
        double spacing = table[i + 2][0] - table[i][0];
        sum += spacing * table[i+1][1];
    }
    return sum;
}

// Trapezoidal Sum
double trapezoidal(double upper_bound, double lower_bound, int num_trapezoids) {
    double sum = 0;
    double spacing = (upper_bound - lower_bound) / static_cast<double>(num_trapezoids);
    for (int i {0}; i < num_trapezoids; i++) {
        sum += 0.5 * spacing * (function(lower_bound + spacing * i) + function(lower_bound + spacing * (i + 1)));
    }
    return sum;
}
double trapezoidal(std::vector<std::vector<int>> &table){
    double sum = 0;
    for (int i {0}; i < table.size()-1; i++) {
        double spacing = table[i + 1][0] - table[i][0];
        sum += spacing * (table[i][1] + table[i + 1][1]) * 0.5;
    }
    return sum;
}


int main() {
    std::vector<std::vector<int>> table {
            {0, 15},
            {2, 25},
            {4, 35},
            {6, 45},
            {8, 55}
    };

    std::cout << "Trapezoidal: " << std::fixed << std::setprecision(6) << trapezoidal(6, 4, 10) << std::endl;
    std::cout << "Midpoint Riemann: " << std::fixed << std::setprecision(6) << midpoint_riemann(6, 4, 10);

    return 0;
}