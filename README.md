# 42 Push_Swap

Because swap_push isn't as natural

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

> ⚠️ **Warning**: Don't copy/paste anything you don't understand: it's bad for you, and for the school.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

For the stacks with size less than 6 I wrote a simple sort which can be found in the src folder.

In this project I used `Radix` sort as the main algorithm. `Radix` sort is an efficient algorithm to sort non-negative integers
with time complexity O (n). For example, we can sort following list of integers with this algorithm

```
87 487 781 100 101 0 1
```

Imagine there are 10 boxes labeled 0, 1, 2, …, 9

Start from the least significant digit (which is the digit in 1’s place), we put each number into the box which its digit corresponds to.

In the example, 87 has 7 in 1’s place, hence we put it in box 7. 487 also has 7 in 1’s place, so it should be placed in box 7 too (right behind 87) … And we repeat this process until every number is in one of the boxes.

```
box 0    100    0
box 1    781    101    1
box 2
box 3
box 4
box 5
box 6
box 7     87    487
box 8
box 9
```

After that, we connect every number according to the order of boxes.

```
100 0 781 101 1 87 487
```

As we can see, the numbers are sorted according to the digit in 1’s place. For those with the same digit in 1’s place, they’re sorted according to their order in the original list.

We repeat this procedure n times, whiere n is the number of digits of the largest number in the array
(In this case 783 => n = 3).

After doing it n times and connecting numbers after each cycle we will have array sorted.

### Simplify numbers

Instead of dealing with potentially large or negative integers, we assign each number an index based on its relative size. This process is often called "coordinate compression" or "discretization".

   For example, if we have [-5, 100, 2, -10], we'd simplify it to [1, 3, 2, 0].

2. Base-2 representation:
   After simplification, we represent each number in binary (base-2). This allows us to sort using only two stacks, which we'll call A and B.

3. Radix sort adaptation:
   We perform a radix sort, but instead of using 10 buckets (for base-10), we use 2 stacks (for base-2).

4. Sorting process:
   - We start from the least significant bit (rightmost) and move towards the most significant bit (leftmost).
   - For each bit position:
     - If the bit is 0, we move the number to stack B (pb - push to B).
     - If the bit is 1, we rotate stack A (ra - rotate A), keeping the number in A.
   - After processing all numbers for a bit, we move all numbers from B back to A (pa - push to A).
   - We repeat this process for each bit.

### Performance of the Algorithm

My push_swap sorts

    3 numbers with maximum 3 instructions,
    4 numbers with maximum 7 instructions,
    5 numbers with maximum 11 instructions,
    100 numbers with maximum 1084 instructions => 3 points,
    500 numbers with maximum 6785 instructions => 4 points.

The algorith is good enought to pass the project. If the Bonus part is also done the project could get more than 105%.

### Bonus

The bonus part is to write a program named checker, which will get as an argument the stack A formatted as a list of integers. Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press ctrl + d).

If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" else "KO". If checker arguments are invalid it displays Error.

The checker code can be found in the checker.c file in this repository.

## Resources 

You can find some links and books below that might be useful during the project. You can find all the books in resources folder. 
Note that you do not have to read the books completly but you will find a lot of useful information there.

Books

- [Algorithms](https://github.com/42YerevanProjects/42_Push_Swap/tree/master/resources)

Links

- [Push Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
