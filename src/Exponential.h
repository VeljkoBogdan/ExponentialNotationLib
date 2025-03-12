#ifndef EXPNOTATION_H
#define EXPNOTATION_H

#include <string>
#include <cmath>
#include <iostream>

namespace expnot {

    class Exponential {
    public:
        inline Exponential(double mantissa, long long int exponent);
        inline Exponential();
        inline Exponential operator+(const Exponential &other) const;
        inline Exponential operator+(const int &other) const;
        inline Exponential operator-(const Exponential &other) const;
        inline Exponential operator-(const int &other) const;
        inline Exponential operator*(const Exponential &other) const;
        inline Exponential operator/(const Exponential &other) const;
        inline friend std::ostream& operator<<(std::ostream& ostream, const Exponential &exp);
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

    inline Exponential Exponential::operator+(const int &other) const {
        const auto otherExp = Exponential(other, 0);
        return Exponential(mantissa, exponent) + otherExp;
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

    inline Exponential Exponential::operator-(const int &other) const {
        const auto otherExp = Exponential(other, 0);
        return Exponential(mantissa, exponent) - otherExp;
    }

    // Multiplication operator
    inline Exponential Exponential::operator*(const Exponential &other) const {
        return Exponential(mantissa * other.mantissa, exponent + other.exponent);
    }

    // Division operator
    inline Exponential Exponential::operator/(const Exponential &other) const {
        return Exponential(mantissa / other.mantissa, exponent - other.exponent);
    }

    // Insertion operator
    inline std::ostream & operator<<(std::ostream& ostream, const Exponential &exp) {
        ostream << exp.toString();
        return ostream;
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
