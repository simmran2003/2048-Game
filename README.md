# 2048-Game
Clone of 2048 Game in C++

The Game 2048 uses the Min-Max algorithm which is a backtracking algorithm in game theory.

The time complexity for this is O(b^m. (where b is the no of moves and m is the depth of the tree)
The space complexity is O(bm).

We need 2 players, one that maximizes the score and one that minimizes it; 
we call them Max and Min.When we play in 2048, we want a big score. So, who is Max? 
We want to maximize our score.And who wants to minimize our score? Well… no one. 
There is the game itself, the computer, that randomly spawns pieces mostly of 2 and 4. 
But, it is not really an adversary, as we actually need those pieces to grow our score. 
And I don’t think the game places those pieces to our disadvantage, it just places them randomly.
But the minimax algorithm requires an adversary. 
So, we will consider Min to be the game itself that places those tiles, and although in the game the tiles are placed randomly, we will consider our Min player as trying to place tiles in the worst possible way for us.

Rules:
You just need to move the tiles, and every time you move one, another tile pops up in a random manner anywhere in the box. 
When two tiles with the same number on them collide with one another as you move them, they will merge into one tile with the sum of the numbers written on them initially.

Commands for the game are as follows:-
n: new game
w: up
s: down 
d: right
a: left 
q: quit
