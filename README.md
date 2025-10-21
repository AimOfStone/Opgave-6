# Opgave-6
Greedy knights tour

This code aims to simulate a greedy Knights Tour algorithm from https://c-programming.aydos.de/week06/knights-tour.html

1. We create a board of size 8x8
2. Find our starting position
3. Shuffle our list of possible moves (without checking if they're legal) using fisher-yates shuffle. This makes every compilation of the code random
4. Check if ANY legal moves exist from the shuffled moves.
   4.1 if any legal moves exist: Mark that square. Repeat from the new square.
   4.2 if no legal moves exist, end
5. return the amount of moves traversed by the simulated knight
6. Repeat for every starting square
7. Output is an 8x8 array of integers.
