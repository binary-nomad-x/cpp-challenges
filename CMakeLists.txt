cmake_minimum_required(VERSION 4.1)
project(learning)

set(CMAKE_CXX_STANDARD 14)

add_executable(learning
        basics/01-welcome-text-on-screen-line.cpp
        basics/02-sum-of-two-numbers.cpp
        basics/03-size-of-fundemental-data-types.cpp
        basics/04-sum-using-variables.cpp
        basics/05-limits-of-integer-types.cpp
        basics/06-primitive-value-limits.cpp
        basics/07-mixed-data-types-and-arithmatic-operators.cpp
        basics/08-overflow-and-underflow-arithmetic.cpp
        basics/09-pre-and-post-increment-and-decrement.cpp
        basics/10-output-formatting-example.cpp
        basics/11-results-of-specific-operations.cpp
        basics/12-add-two-numbers-from-keyboard.cpp
        basics/13-swap-two-numbers.cpp
        basics/14-volume-of-sphere.cpp
        basics/15-volume-of-cube.cpp
        basics/16-volume-of-cylinder.cpp
        basics/17-area-and-perimeter-of-rectangle.cpp
        basics/18-triangle-area-using-herons-formula.cpp
        basics/19-area-and-circumference-of-circle.cpp
        basics/20-celsius-to-fahrenheit-conversion.cpp
        basics/21-fahrenheit-to-celsium.cpp
        basics/22-third-angle-of-triangle.cpp
        basics/23-kilometers-to-miles-conversion.cpp
        basics/24-kelvin-fahrenheit-conversion.cpp
        basics/25-fahrenheit-to-kelvin-conversion.cpp
        basics/26-celsius-to-kelvin-conversion.cpp
        basics/27-scalene-triangle-area-calculation.cpp
        basics/28-quotient-and-remainder.cpp
        basics/29-total-and-average-of-four-numbers.cpp
        basics/30-rectangular-pattern-of-single-digit.cpp
        basics/31-check-number-sign-positive-negative-zero.cpp
        basics/32-divide-two-numbers-print-quotient.cpp
        main.cpp)
