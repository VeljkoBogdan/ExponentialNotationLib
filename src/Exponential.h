#ifndef EXPNOTATION_H
#define EXPNOTATION_H

#include <string>
#include <cmath>

namespace expnot {

    class Exponential {
    public:
        inline Exponential(double mantissa, long long int exponent);
        inline Exponential();
        inline Exponential operator+(const Exponential &other) const;
        inline Exponential operator-(const Exponential &other) const;
        inline Exponential operator*(const Exponential &other) const;
        inline Exponential operator/(const Exponential &other) const;
        inline std::string toString() const;
        inline void normalize();

    private:
        double mantissa;
        long exponent;
    };

    // --------------------------------------------------------------------------------------------------------
    // ----------------------------------------Implementation--------------------------------------------------
    // --------------------------------------------------------------------------------------------------------

    // Constructor with normalization
    inline Exponential::Exponential(double mantissa, long long exponent) : mantissa(mantissa), exponent(exponent) {
        normalize();
    }

    // Default constructor (zero value)
    inline Exponential::Exponential() : mantissa(0.0), exponent(0) {}

    // Addition operator
    inline Exponential Exponential::operator+(const Exponential &other) const {
        if (exponent > other.exponent) {
            double adjMantissa = mantissa * std::pow(10, exponent - other.exponent) + other.mantissa;
            return Exponential(adjMantissa, other.exponent);
        } else {
            double adjMantissa = mantissa + other.mantissa * std::pow(10, other.exponent - exponent);
            return Exponential(adjMantissa, exponent);
        }
    }

    // Subtraction operator
    inline Exponential Exponential::operator-(const Exponential &other) const {
        if (exponent > other.exponent) {
            double adjMantissa = mantissa - other.mantissa * std::pow(10, other.exponent - exponent);
            return Exponential(adjMantissa, exponent);
        } else {
            double adjMantissa = mantissa * std::pow(10, exponent - other.exponent) - other.mantissa;
            return Exponential(adjMantissa, other.exponent);
        }
    }

    // Multiplication operator
    inline Exponential Exponential::operator*(const Exponential &other) const {
        return Exponential(mantissa * other.mantissa, exponent + other.exponent);
    }

    // Division operator
    inline Exponential Exponential::operator/(const Exponential &other) const {
        return Exponential(mantissa / other.mantissa, exponent - other.exponent);
    }

    // Convert to string
    inline std::string Exponential::toString() const {
        return std::to_string(mantissa) + "e" + std::to_string(exponent);
    }

    // Normalize the mantissa
    inline void Exponential::normalize() {
        if (mantissa == 0.0) {
            exponent = 0;
            return;
        }

        while (std::abs(mantissa) >= 10.0) {
            mantissa /= 10.0;
            exponent++;
        }

        while (std::abs(mantissa) < 1.0 && mantissa != 0.0) {
            mantissa *= 10.0;
            exponent--;
        }
    }

} // namespace expnot

#endif // EXPNOTATION_H
