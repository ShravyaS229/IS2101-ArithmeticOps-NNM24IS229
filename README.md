# IS2101-ArithmeticOps-NNM24IS229
# IS2101-ArithmeticOps-<USN>

## Description
This repository contains C programs implementing low-level arithmetic algorithms:

- **Sequential (Shift-Add) Multiplication** (Signed integers using 2's complement)
- **Restoring Division Algorithm**
- **Non-Restoring Division Algorithm**

These programs simulate hardware-level arithmetic operations step-by-step to help students understand how signed integer multiplication and division are handled in binary.

---

## Folder Structure
Sequential_Multiplication.c
 Restoring_Algorithm.c
 NonRestoring_Algorithm.c
 README.md
 images/ (Screenshots of program outputs)
 ## Compile ans Run
 gcc ShiftAddMultiplication.c -o ShiftAddMultiplication
./ShiftAddMultiplication

gcc RestoringDivision.c -o RestoringDivision
./RestoringDivision

gcc Non_Restoring_Algorithm.c -o NonRestoring
./NonRestoring
## Inputs and Outputs

### Sequential Multiplication
- **Input:** Multiplicand (integer), Multiplier (integer)  
- **Output:** Product (integer) with step-by-step shift-add process  

### Restoring Division
- **Input:** Dividend (positive integer), Divisor (positive integer)  
- **Output:** Quotient, Remainder, with step-by-step trace of accumulator and quotient bits  

### Non-Restoring Division
- **Input:** Dividend (positive integer), Divisor (positive integer)  
- **Output:** Quotient, Remainder, with step-by-step trace of accumulator and quotient bits
- ## Sample Outputs

### Sequential Multiplication
![Sequential Multiplication Output](images/sequential_output.jpg)

### Restoring Division
![Restoring Division Output](images/restoring_division_output.jpg)

### Non-Restoring Division
![Non-Restoring Division Output](images/non_restoring_division_output.jpg)

