# TicTacToe_MCTS
Discovering MCTS and UCT with TicTacToe. Simple game for fast learning and feedback, also the optimal strategy is known allowing an evaluation of the end result.

The way it works :
We use Monte-Carlo Tree Search in combination with Upper Confidence bounds for exploration.
To teach it we go through playoffs agains itself. At every turn the MCTS algorithm is launched 10 times with that board state as root then the move with the highest
UCB1 is played (possible improvment: exploration really shouldn't be a factor in that selection so only winrate should be considered).
The space of states was simplified through symmetries and rotations as they have no impact on the optimal move. All states that differ only through 
one of these transformations are considered the same state.

To use this method we need to store the number of visits and wins for every state visited by our algorithm;
actually making a tree seemed inneficient as different paths can lead to the same node. We would have, for every state,
to look through this level of the tree to look for an identical state. To do that efficiently we'd make a hash table,
so we just made a hash table. This is possible because the path to a board has no effect, only the state of the board
matters. The issue is we need to recalculate the hash of child nodes every time.

Our "hash-table" stores the information relative to a state at table[smallest_value(state)]. Smallest_value reads the board like a 
number in base 3 (base : { empty, 'X' and 'O'}), it returns the smallest value it can obtain for a given board by rotating or mirroring it.

We've also considered that X always starts, as the game is also invariant by flipping X and O (on the board and who's turn it is), reducing the state space by up to 50%.
There are 8952 possible states, 6045 if we assume X plays first and 849 after reduction through symmetries and rotations.

questions :
optimal C, for how many iterations ?
iterations_per turn ?
child node priority ?
learning from root vs what i do now ?
how to rate all of this, rate against our trained AI, or against all possible games (9! is pretty big) ?
