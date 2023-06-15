#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;

int board[4][4];
int dirLine[]={1,0,-1,0};
int dirColumn[]={0,1,0,-1};

pair<int,int> generateUnocupiedPosition()
{
    int occupied = 1,line,column;
    while(occupied)
    {
        line = rand() % 4;
        column = rand() % 4;
        if(board[line][column]==0)
            occupied=0;
    }
    return make_pair(line,column);
}
void addPiece()
{
    pair<int,int> pos = generateUnocupiedPosition();
    board[pos.first][pos.second]=2;
}
void newGame()
{
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        board[i][j]=0;
    }
    addPiece();
    
}

void printUI()
{
    
    system("clear");
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        if(board[i][j]==0)
            cout <<setw(4)<<".";
        else
            cout<<setw(4)<<board[i][j];
        cout<<endl;

    }
    cout<<"n: new game, w:up, s:down, d:right, a:left, q:quit"<<endl;
}

bool canDoMOve(int line,int column,int nextLine,int nextColumn)
{
    if(nextLine<0 || nextColumn<0 || nextLine >= 4 || 
    nextColumn >= 4 || (board[line][column]!= board[nextLine][nextColumn] 
    && board[nextLine][nextColumn]!=0))
        return false;
    return true;
}

void applyMove(int direction)
{
    int startLine =0, startColumn=0,lineStep=1, columnStep=1;
    if(direction == 0)
    {
        startLine = 3;
        lineStep = -1;
    }
    if(direction == 1)
    {
        startColumn = 3;
        columnStep = -1;
    }
    int movePossible,canAddPiece=0;
    do{
        movePossible = 0;
    
        for(int i=startLine; i>=0 && i<4; i+= lineStep)
            for(int j=startColumn; j>=0 && j<4; j+= columnStep)
            {
                int nextI=i+dirLine[direction],nextJ=j+dirColumn[direction];
                // cout<<i<<" "<<j<<" "<<nextI<<" "<<nextJ<<endl;
                if(board[i][j] && canDoMOve(i,j,nextI,nextJ))
                {
                    board[nextI][nextJ]+=board[i][j];
                    board[i][j]=0;
                    movePossible = canAddPiece = 1;
                }
            }
    }while(movePossible);
        if(canAddPiece)
            addPiece();
    

}

int main()
{
    char commandToDir[128];
    commandToDir['s']=0;
    commandToDir['d']=1;
    commandToDir['w']=2;
    commandToDir['a']=3;
    newGame();
    while(true)
    {
        printUI();
        char command;
        cin>>command;
        if(command == 'n')
            newGame();
        else if(command == 'q')
            break;
        else
        {
            int currentDirection = commandToDir[command];
            applyMove(currentDirection);
        }
    }
    return 0;
}