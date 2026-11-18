# push_swap

A 42 project: sort a list of integers using two stacks and a limited set of operations, with as few moves as possible.

The program takes a list of integers as arguments and prints the sequence of instructions that sorts them in stack `a`.

## Build

```bash
make
```

## Usage

```bash
./push_swap 3 2 5 1 4
```

Count the moves:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

The program prints `Error` on invalid input (non-numeric values, duplicates, integer overflow) and nothing if the list is already sorted.

## Operations

| Instruction | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of a, b, or both |
| `pa` / `pb` | push the top of one stack onto the other |
| `ra` / `rb` / `rr` | rotate a, b, or both (first element becomes last) |
| `rra` / `rrb` / `rrr` | reverse rotate a, b, or both (last element becomes first) |

## Algorithm

- **2 to 5 numbers:** dedicated small-sort routines that use a minimal number of moves.
- **Larger inputs:** each value is replaced by its index in a sorted copy, then pushed to stack `b` in ranges (chunks). The values are then pushed back to `a` from largest to smallest, rotating `b` in whichever direction is shorter.

## Project structure

```
Push_swap.c           entry point
Push_swap.h           types and prototypes
mandatory/tools/
  parsing.c           argument parsing and validation
  stack.c             stack creation
  instructions*.c     sa, pb, ra, rra...
  sort_small.c        sorting for 2 to 5 numbers
  sorting_algo.c      chunk sort for larger inputs
```
