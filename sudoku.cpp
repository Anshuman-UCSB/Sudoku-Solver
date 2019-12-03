#include <iostream>
#include <cmath>
using namespace std;
typedef int** brd;

int** example = new int*[9]{
new int[9]{1,2,3,4,5,6,7,8,9},
new int[9]{2,3,4,5,6,7,8,9,1},
new int[9]{3,4,5,6,7,8,9,1,2},
new int[9]{4,5,6,7,8,9,1,2,3},
new int[9]{5,6,7,8,9,1,2,3,4},
new int[9]{6,7,8,9,1,2,3,4,5},
new int[9]{7,8,9,1,2,3,4,5,6},
new int[9]{8,9,1,2,3,4,5,6,7},
new int[9]{9,1,2,3,4,5,6,7,8}
};
void printBoard(brd board){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(board[i][j]==0){
                cout<<" -";
            }
            else
                cout<< " "<<board[i][j];
            if(j%3==2)
                cout<<" ";
        }
        cout<<endl;
        if(i%3==2)
            cout<<endl;    
    }
}

/**

 - - 9 - - 7 - 4 -
 - 7 1 - 2 - - - 5
 - 4 - - - - - 3 9
 - - - - - 8 - - -
 - - - 4 6 - - - -
 - - 2 1 9 - 8 - -
 - 6 - - - - 4 - -
 - 9 - 2 8 6 5 - -
 5 - - - - - - - -

**/
void initializeBoard (brd board);

void pause(){
    int trash;
    cout<<"pausing\n";
    cin >>trash;
}

brd fillBoard (brd board);
brd solveBoard (brd board);
bool checkBoard (brd board);

int main(){    

    
    int** board = new int*[9];
    for(int i = 0;i<9;i++){
        board[i]=new int[9];
    }
    initializeBoard(board);
    printBoard(board);

    brd solved = solveBoard(board);
    printBoard(solved);
}

void initializeBoard (brd board){
    board[0][2] = 9;
    board[0][5] = 7;
    board[0][7] = 4;
    
    board[1][1] = 7;
    board[1][2] = 1;
    board[1][4] = 2;
    board[1][8] = 5;

    board[2][1] = 4;
    board[2][7] = 3;
    board[2][8] = 9;

    board[3][5] = 8;

    board[4][3] = 3;
    board[4][4] = 4;

    board[5][2] = 2;
    board[5][3] = 1;
    board[5][4] = 9;
    board[5][6] = 8;

    board[6][1] = 6;
    board[6][6] = 4;

    board[7][1] = 9;
    board[7][3] = 2;
    board[7][4] = 8;
    board[7][5] = 6;
    board[7][6] = 5;

    board[8][0] = 5;

}

brd fillBoard (brd board){
    
    int** ret = new int*[9];
    for(int i = 0;i<9;i++){
        ret[i]=new int[9];
    }

    for(int i =0;i<9;i++){
        int* temp = new int[10];
        for (int j = 0;j<9;j++){
            ret[i][j]=board[i][j];
            if(ret[i][j]==0){
                for(int k=1;k<9;k++){
                    temp[k]==0;
                }
                for(int k=1;k<9;k++){
                    temp[ret[i][j]]=1;
                }
                int randm = 0;
                while(temp[randm]){
                    randm = rand()%9+1;
                }
                ret [i][j] = randm;
                temp[randm] = 1;
                //cout<<"Filling out unique square.. "<<rand()<<endl;
            }
        }
    }

    return ret;
}

//assume no 0 in board
bool checkBoard (brd board){
    
    double prod;
    // for(int i = 0 ;i<9;i++){
    //     prod = 1*2*3*4*5*6*7*8*9;
    //     for(int j = 0; j<9;j++){
    //         prod/=board[i][j];
    //     }
    //     if (prod-1>-0.05&&prod-1<0.05){
    //         cout<< "Invalid horizontal.. "<<prod<<endl;
    //         return false;
    //     }
    // }
    printBoard(board);
    for(int i = 0 ;i<9;i++){
        prod = 1*2*3*4*5*6*7*8*9;
        for(int j = 0; j<9;j++){
            pause();
            cout<<"board: "<<board[j][i]<<endl;
            if(board[j][i]!=0){
                prod = prod / board[j][i];
            }
        }
        if (prod!=1){
            cout<<"Invalid vertical.. "<<prod-1<<endl;
            
            return false;
        }
    }

    cout<<"Found correct board!"<<endl;

    return true;
}

brd solveBoard (brd board){
    brd temp = fillBoard(board);
    //printBoard(temp);
    int iter = 1;
    while(!checkBoard(board)){
        iter++;
        temp = fillBoard(board);
    }
    cout<<"\nSolved board with "<<iter<<" tries."<<endl;
    return temp;
}