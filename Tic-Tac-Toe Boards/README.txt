This started as a coding interview question and ended up being a curiosity project.

The purpose of this script is to calculate the number of valid and complete tic tac toe boards, of which there are 5477.

The goal was to avoid brute forcing it and then pruning duplicates and invalid games. It seemed more efficient to build up to 5477 boards instead of pruning the ~400000 possible permutations. My methodology was to guild a tree of possible games where each board state is represented as a node, and has a pointer to each possible successor state. In this way as long as the rules of the game are enforced upon grid creation, all possible boards will be valid from the start. When each grid is created, the program will check if that game is complete. If it is, then no more games need to be played on that branch. Because of this design the leaves of the resulting n-ary tree are the valid and complete games, and we can obtain our answer by traversing the tree and counting the leaves.

This program was indeed efficient, and runtime was very fast. I say "was" because while I was experimenting with the pointers I broke it. I will fix it eventually but the structyure is there.