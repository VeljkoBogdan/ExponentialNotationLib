# Exponential Notation Library (C++)

### A <b style="color: lightblue"> lightweight C++ library </b> for handling exponentially large or small numbers using scientific notation

### Features

- Supports **addition**, **subtraction**, **multiplication** and **division** of exponential numbers
- Automatically normalizes values to maintain scientific notation
- **Header-only** for easy integration (just drag, drop, and include)

### Installation

1. Download, then drag and drop [Exponential.h](https://github.com/VeljkoBogdan/ExponentialNotationLib/blob/master/src/Exponential.h) in the folder of your project
2. Include the header ```#include "Exponential.h"``` in the file where you want to use the library
3. Done!

### Usage

Include the library in the top of the document:
```c++
#include "Exponential.h"
```

To create an exponential number, do:
```c++
expnot::Exponential num(3.5, 20) // 3.5e20
```

To print an exponential number, you can use ```std::cout```:
```c++
std::cout << num << std::endl;
// Output: 3.5e20
```

or you can even convert it to a string:
```c++
std::cout << num.toString() << std::endl;
// Output: 3.5e20
```

Exponential class naturally handles arithmetic operations between each other:
```c++
expnot::Exponential a(1.5, 10);
expnot::Exponential b(1, 9);

auto add = a + b; // 1.6e10
auto sub = a - b; // 1.4e10
auto mul = a * b; // 1.5e19
auto div = a / b; // 1.5e1
```

They each return an ```expnot::Exponential``` object with the normalized results.

Example:
```c++
#include <iostream>
#include "Exponential.h"

int main() {
    // Create exponential numbers
    expnot::Exponential num1(3.5, 20); // 3.5e20
    expnot::Exponential num2(2.1, 19); // 2.1e19

    // Print initial values
    std::cout << "Number 1: " << num1.toString() << std::endl; // Output: 3.5e20
    std::cout << "Number 2: " << num2.toString() << std::endl; // Output: 2.1e19

    // Add the two numbers
    auto sum = num1 + num2;
    std::cout << "Sum: " << sum.toString() << std::endl; // Output: 3.6e20

    // Subtract the two numbers
    auto difference = num1 - num2;
    std::cout << "Difference: " << difference.toString() << std::endl; // Output: 3.4e20

    // Multiply the two numbers
    auto product = num1 * num2;
    std::cout << "Product: " << product.toString() << std::endl; // Output: 7.35e39

    // Divide the two numbers
    auto quotient = num1 / num2;
    std::cout << "Quotient: " << quotient.toString() << std::endl; // Output: 1.66667e1

    return 0;
}

```

<hr>

The file is in a separate ```expnot``` namespace so it won't cause conflicts.<br>
If you don't want to write ```expnot::Exponential``` constantly, do:
```c++
using namespace expnot;
```

Now you can (but is not recommended to) just do:
```c++
Exponential a = Exponential(1.5, 90);
```

### Limitations

- The ```Exponential``` object is limited by the exponent's ```long long``` type, which can go to about **-9,223,372,036,854,775,808**, or **9,223,372,036,854,775,807**
- You don't have to worry about overflow, but the value won't change past the max values!
- Very large or very small values may suffer from precision loss due to floating-point limitations on the mantissa
- These are the largest number:
```
positive:
179769313486231575804128197568503885939002350117941411767545627891801114536396644853619288305177042633935372685103635187
590438437370702292699562517687521668833979406288629832876259672468103520237920172119362601898937975098263032931492834697
13429932049693599732425511693654044437030940398714664210204414967808.000000e9223372036854775807

negative:
-1.797693e-9223372036854775499
```

<hr>

#### Contributions and feedback are very welcome!