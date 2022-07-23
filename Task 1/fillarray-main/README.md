# FillArray

Filling a two-dimensional array with consequtive integers.  
In the example, the array is filled with rows from left to right.
We start filling in from the top left corner.

Example for the array 3 x 4:

       1   2   3   4
       5   6   7   8
       9  10  11  12

The solution consist of three projects:
* _FillArrayLib_ - library containing `fillArray` function,
* _FillArrayUnitTest_ - unit test for `fillArray` function,
* _FillArrayApp_ - sample aplication calling `fillArray` function.

## Task 1
* Implement the `displayArray` function.
* Verify the `fillArray` function by:
  * executing unit tests,
  * running the `FillArrayApp` application,
  * run and Debug selected test.

## Task 2

Modification of the way of filling the array.
Each student implements one filling method.  
You should:
* **first** modify the unit tests according to the array filling method,
* modify the implementation of the `fillArray` function,
* verify correctness of the `fillArray` function using wtitten unit tests.

Ways of fillings an array:
* start from one corner (NW, NE, SW, SE),
* fill array diagonally,
  * all diagonals up (DIAG UP),
  * all diagonals down (DIAG DOWN),
* fill array horizontally alternately (HOR)
* fill array vertically alternately (VER)


### Example: NE DIAG DOWN 3x4

       7   4   2   1
      10   8   5   3
      12  11   9   6

### Example: SW DIAG UP 4x4

      10  13  15  16
       6   9  12  14
       3   5   8  11
       1   2   4   7

### Example: SW HOR 4x4

      16  15  14  13
       9  10  11  12
       8   6   6   5
       1   2   3   4

### Example: NW VER 4x4

       1   2   3   4
       8   7   6   5
       9  10  11  12
      16  15  14  13

Tip: For diagonal filling, divide the array into three areas and fill each area separately.