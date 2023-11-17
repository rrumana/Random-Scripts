#include <iostream>
#include <vector>

// simulate the game and see what comes up

/*rules:
  - X starts first
  - X and O alternate turns
  - No overwriting
  - the game ends when:
    - one player gets 3 in a row
    - the board becomes full
*/

/*design:
  - search tree
  - all games are valid
  - leaves are complete games
  - max depth of 9
*/

class Node{
public:
    std::vector<std::vector<int>> grid;
    std::vector<Node *> next;
    bool complete;

    Node() { 
        grid = std::vector<std::vector<int>>(3, std::vector<int>(3,0)); 
        next = std::vector<Node *>(); 
        complete = false;
    }

    Node(std::vector<std::vector<int>> grid) { 
        this->grid = grid;
        next = std::vector<Node *>(); 
        complete = false;
    }

};

void printGrid(std::vector<std::vector<int>> grid){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << grid[i][j];
            if(j < 2){
            std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if(i < 2){
            std::cout << "---------" << std::endl;
        }
    }
}

bool checkGrid(std::vector<std::vector<int>> grid){
    for(int i = 0; i < 3; i++){
        // check row victory
        if(grid[i][0] == 1 && grid[i][1] == 1 && grid[i][2] == 1) return true;
        if(grid[i][0] == 2 && grid[i][1] == 2 && grid[i][2] == 2) return true;
        // check column victory
        if(grid[0][i] == 1 && grid[1][i] == 1 && grid[2][i] == 1) return true;
        if(grid[0][i] == 2 && grid[1][i] == 2 && grid[2][i] == 2) return true;
    }
    // check diagonal victories
    if(grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) return true;
    if(grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1) return true;
    if(grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) return true;
    if(grid[0][2] == 2 && grid[1][1] == 2 && grid[2][0] == 2) return true;

    // check if board is full
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void simulatePlay(struct Node head, int turn){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(head.grid[i][j] == 0){
                Node temp = Node(head.grid);
                temp.grid[i][j] = turn + 1;
                head.next.push_back(&temp);
                if(checkGrid(temp.grid)){
                    if(turn == 0) simulatePlay(temp, 1);
                    else simulatePlay(temp, 0);
                }
            }
        }
    }
}

int countLeaves(struct Node head, int sum){
    for(int i = 0; i < head.next.size(); i++){
        if((*head.next[i]).complete) sum+=1;
        else sum+=countLeaves((*head.next[i]), sum);
    }
}

int buildTree(){
    Node head = Node();
    int turn = 0;
    simulatePlay(head, turn);
    return countLeaves(head, 0);;
}


int main(){
    int num = buildTree();
    std::cout << num << " valid and complete boards." << std::endl;
    return 0;
}

/*
    printGrid(head);
    if(checkComplete(head)) std::cout << "This board is complete." << std::endl;
    else std::cout << "This board is complete." << std::endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                std::cout << (*head.next[x]).grid[i][j];
                if(j < 2){
                    std::cout << " | ";
                }
            }
            std::cout << std::endl;
            if(i < 2){
                std::cout << "---------" << std::endl;
            }
        }

*/