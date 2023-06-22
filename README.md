# MCO2: Applying Stacks and Queues

A major course output for the course on Data Structures and Algorithms (CCDSALG)

Submitted by:
- Deculawan, Ryan Jay D.
- Uy, Samuel Jedidiah A.

Teacher: Anish Shrestha

August 27, 2021

## Introduction

This documentation focuses on the implementation of stacks and queues in the context of a dynamic set of elements. Stacks and queues are essential data structures that allow for the insertion and retrieval of data in a predefined manner. The objective of this project is to convert an infix expression to postfix using a parser function and evaluate it in postfix form. By implementing these concepts, we gain firsthand experience and prepare ourselves for more complex data structures.

## Design and Implementation

The project began with careful planning and proceeded with the implementation of a working stack and queue. A structure was used to store an array of characters and a top attribute for the stack. The parser function and the postfix evaluation function required the most time and involved specifying error handling procedures.

The parser function takes an infix expression and decides whether to store each character in a stack or append it to the postfix expression. The use of pointers eliminates the need to return a value, resulting in a void return type for the parser function.

The postfix evaluation function takes an array of characters representing the postfix expression. It checks each index of the array to determine if it is a digit. If it is, the flag variable from the initialized stack is set to 1. The flag variable helps determine if a number has more than one digit by examining the succeeding indices. The identified number is then pushed to the integer array, and the function proceeds to search for the next value in the postfix expression. When an operator is encountered, the function pops two values, B and A, respectively. Another function is invoked to determine whether the operator is relational or logical. A switch statement is used to evaluate B and A based on the operator. The result is pushed back to the stack, and the function continues searching for the next values or operators. Once there are no more numbers or operators found, the top of the stack, representing the final answer, is returned.

In the main file, the program checks if the evaluated postfix expression is valid. If so, the program prints the value returned by the postfix evaluation function. If the postfix expression is deemed invalid or the final answer has been printed, the program terminates.

## Test Cases and Results

| No. | Description                                     | Input                      | Expected Output             | Actual Output               |
| --- | ----------------------------------------------- | -------------------------- | --------------------------- | --------------------------- |
| 1.1 | Test valid operands                             | 3                          | 3                           | 3                           |
| 1.2 | Parenthesis Precedence                          | ((8+2)/3)                  | 8 2 + 3 /                   | 3                           |
| 1.3 | Number Comparison                               | (5>=3)                     | 5 3 >=                      | 1                           |
| 1.4 | Logical operator                                | (1&&0)                     | 1 0 &&                      | 0                           |
| 1.5 | Multiple Logical Operator with Parenthesis       | (!((2>1)&&(3<2)))          | 2 1 > 3 2 < && !            | 1                           |
| 2.1 | Test invalid operands                            | -4                         | <error message>             | 4 -                         |
| 2.2 | Division by Zero                                | (123/0)                    | 123 0 /                     | Division by zero error!     |
| 2.3 | Using negative numbers in Logical Expressions    | (-1==-1)                   | -1 –1 ==                    | 0                           |
| 3.1 | Test * operator                                 | (5*3)                      | 5 3 *                       | 15                          |
| 3.2 | Multiplying 3-digit operands                    | (942*405)                  | 942 405 *                   | 381510                      |
| 3.3 | Multiple Operators                              | (-2+2^5+(10*5)/2)          | -2 2 5 ^ + 10 5 * 2 / +     | 55                          |

The provided test cases cover various input scenarios. The first set of test cases checks the correctness of the program using valid inputs, including single numbers, parenthesis precedence, number comparison, logical operators, and combinations of logical operators with parenthesis precedence. The second set tests invalid inputs, such as invalid operands, division by zero, and negative numbers in logical expressions. The final set of cases tests arithmetic operations.

Our program can detect invalid inputs and handle multiple-digit operands. It can handle different types of operations in a single equation, whether they are arithmetic, relational, or logical operators.

The program utilizes an integer array to store popped values since character arrays cannot store multiple-digit numbers. A more efficient implementation could involve the use of a linked list. Additionally, the implemented queue data type only supports single-digit character values.

## Conclusions and Recommendations

We successfully implemented the stack and queue data structures using C. With the stack, we created a parser function that converts an infix expression to postfix form. The postfix evaluation function takes the resulting postfix expression and returns the final output. Evaluating expressions is just one of the many applications of a stack, and this hands-on experience will prove useful for tackling more complex problems. It is recommended to use stack or queue implementations when a particular order of operations is required.

## References

- Naik, M. (2020, November 25). How To Implement Queue in C? Queues. Retrieved August 17, 2021, from https://www.edureka.co/blog/queue-in-c/
- Stacks. (2019, February 23). Postfix Evaluation (Single or Multi Digit) using STACK in C. Retrieved August 23, 2021, from https://toprogrammersend.blogspot.com/2019/02/postfix-evaluationsingle-or-multi-digit.html

## Appendix A: Contribution of Members

| Name                | Contributions      |
| ------------------- | ------------------ |
| Deculawan, Ryan Jay | Stack, InputParser, Documentation |
| Uy, Samuel Jedidiah | Queue, InputParser, Documentation |
