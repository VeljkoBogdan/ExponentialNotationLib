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
        inline Exponential operator*(const int &other) const;
        inline Exponential operator/(const Exponential &other) const;
        inline Exponential operator/(const int &other) const;
        inline friend std::ostream& operator<<(std::ostream& ostream, const Exponential &exp);
        inline std::string toString() const;
        inline void normalize();

    private:
        double mantissa;
        long long exponent;
    };


    // --------------------------------------------------------------------------------------------------------
    // ----------------------------------------Implementation--------------------------------------------------
    // --------------------------------------------------------------------------------------------------------

    // Constructor with normalization
    inline Exponential::Exponential(const double mantissa, const long long exponent) : mantissa(mantissa), exponent(exponent) {
        normalize();
    }

    // Default constructor (zero value)
    inline Exponential::Exponential() : mantissa(0.0), exponent(0) {}

    // Addition operator
    inline Exponential Exponential::operator+(const Exponential &other) const {
        if (exponent > other.exponent) {
            double adjMantissa = mantissa * std::pow(10, exponent - other.exponent) + other.mantissa;
            return {adjMantissa, other.exponent};
        } else {
            double adjMantissa = mantissa + other.mantissa * std::pow(10, other.exponent - exponent);
            return {adjMantissa, exponent};
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
            return {adjMantissa, exponent};
        } else {
            double adjMantissa = mantissa * std::pow(10, exponent - other.exponent) - other.mantissa;
            return {adjMantissa, other.exponent};
        }
    }

    inline Exponential Exponential::operator-(const int &other) const {
        const auto otherExp = Exponential(other, 0);
        return Exponential(mantissa, exponent) - otherExp;
    }

    // Multiplication operator
    inline Exponential Exponential::operator*(const Exponential &other) const {
        return {mantissa * other.mantissa, exponent + other.exponent};
    }

    inline Exponential Exponential::operator*(const int &other) const {
        const auto otherExp = Exponential(other, 0);
        return Exponential(mantissa, exponent) * otherExp;
    }

    // Division operator
    inline Exponential Exponential::operator/(const Exponential &other) const {
        return {mantissa / other.mantissa, exponent - other.exponent};
    }

    inline Exponential Exponential::operator/(const int &other) const {
        const auto otherExp = Exponential(other, 0);
        return Exponential(mantissa, exponent) / otherExp;
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
            if (exponent >= std::numeric_limits<long long>::max() - 1) break;
            mantissa /= 10.0;
            exponent++;
        }

        while (std::abs(mantissa) < 1.0 && mantissa != 0.0) {
            if (exponent <= -std::numeric_limits<long long>::max() + 1) break;
            mantissa *= 10.0;
            exponent--;
        }
    }

} // namespace expnot

#endif // EXPNOTATION_H
