#include "labirynt.h"

int xmove[9] = {0, 0,+1, 0, 0, 0, 0, 0,-1};
int ymove[9] = {0,-1, 0, 0,+1, 0, 0, 0, 0};

// maze[i][j] -- j w pionie; i w poziomie np. maze[15][0] - prawy gorny rog
Labirynt::Labirynt()
{
int size = 17;
maze.resize(size);
for (int i=0;i<size;i++)    //zadeklarowanie dlugosci wektorow gridu
    {
        maze[i].resize(size);
    }

for(int i = 0;i<size-1;i++)
    for(int j=0;j<size-1;j++)
        {
            SetCell(i,j,1,1,0);
        }
                            //-----------------------------------------

for(int i=0; i<size-1;i++)
    {

        SetCell(i,0,3,1,0);     //gorny rzad
        SetCell(i,size-1,0,3,0);//dolny rzad
        SetCell(0,i,1,3,0);     //lewa kolumna
        SetCell(size-1,i,3,0,0);//prawa kolumna
    }

SetCell(0,0,3,3,0); //lewy gorny rog
SetCell(0,size-1,0,3,0);// lewy dolny
SetCell(size-1,0,3,0,0);// prawy gorny
SetCell(size-1,size-1,0,0,0);// prawy dolny
//                                                          koniec przygotowania podstawowej siatki
//                                                          start tworzenia przejsc
CreateLabirynt(size-2,size-2);


}


void Labirynt::CreateLabirynt(int _i, int _j)
    {

        std::vector<int> path;
        int size = int(maze.size())-2;
        if(_i>size ||_j>size) return;
        int a = _i;
        int b = _j;
        bool xd = 1;
        eDir Dir;
        while(xd) {
        //poczatek petli

        Dir=GetDir(a,b,maze);
        if(Dir!=Dir_inv)
            {
                ChangeCellVisited(a,b);
                path.push_back(a);
                path.push_back(b);
                if(ymove[Dir]>0)
                    {
                        a++;
                        ChangeCellCelling(a,b);
                    }
                if(ymove[Dir]<0)
                    {
                        ChangeCellCelling(a,b);
                        a--;
                    }
                if(xmove[Dir]>0)
                    {
                        b++;
                        ChangeCellWall(a,b);
                    }
                if(xmove[Dir]<0)
                    {
                        ChangeCellWall(a,b);
                        b--;
                    }
            }else
            {
                ChangeCellVisited(a,b);
                if(!path.empty()){
                b = path.back();
                path.pop_back();
                a= path.back();
                path.pop_back();}
                else xd=0;
            }
}

for(int h = 0;h<50;h++)
    {
        RemoveRandomCell();
    }
setEnd();
    }

std::vector<std::vector<cell>> Labirynt::GetMaze()
{
    return maze;
}
void Labirynt::setEnd()
    {

        bool out = 1;
        while(out){
                for(int i=1;i<6;i++)
                    {
                        for(int j=1;j<7;j++)
                            if(maze[i][j].topwall+maze[i][j].leftwall+maze[i+1][j].topwall+maze[i][j+1].leftwall==3)
                                {
                                    if(maze[i][j].topwall)maze[i][j].typeTop=1;
                                    if(maze[i][j].leftwall)maze[i][j].typeLeft=1;
                                    if(maze[i+1][j].topwall)maze[i+1][j].typeTop=1;
                                    if(maze[i][j+1].leftwall)maze[i][j+1].typeLeft=1;
                                    out=0;
                                    return;
                                }
                        if(out==0) return;
                    }
        if(maze[2][2].topwall==1){ maze[2][2].typeTop=1;maze[3][2].topwall=0;}
        else if(maze[3][2].topwall==1){ maze[3][2].typeTop=1;maze[2][2].topwall=0;}
        else{
            maze[2][2].typeTop=1;maze[3][2].topwall=0;maze[2][2].topwall=1;
            }

        maze[2][2].leftwall=1;
        maze[2][3].leftwall=1;

        maze[2][2].typeLeft=1;
        maze[2][3].typeLeft=1;
        out=0;
            }

    }

int Labirynt::GetRandom(int x)
    {

        return (std::rand()%x);

    }
bool Labirynt::ValidDir(eDir Dir, int i, int j, std::vector<std::vector<cell>> maze)
    {
       int size = int(maze.size())-1;
       int newy = i + ymove[Dir];
       int newx = j + xmove[Dir];
       if(!Dir||newx<0||newy<0||newx>size-1||newy>size-1||maze[newy][newx].visited==1) return 0;
       return 1;
    }
eDir Labirynt::GetDir(int i, int j, std::vector<std::vector<cell>> maze){
        eDir Dir = eDir(1<<GetRandom(4));
        while(1){
            for (int x=0;x<4;x++)
                {
                    if(ValidDir(Dir,i,j,maze)) return eDir(Dir);
                    Dir = eDir(Dir<<1);
                    if(Dir>Dir_Left) Dir=Dir_up;
                }
            return Dir_inv;
        }
    }
void Labirynt::SetCell(int i, int j, int top, int left, /*int right, int bot,*/ bool vist)
{
    maze[i][j].topwall=top;
    maze[i][j].leftwall=left;
    maze[i][j].visited = vist;
}
void Labirynt::ChangeCellWall(int i, int j)
    {
        maze[i][j].leftwall = 0;
    }
void Labirynt::ChangeCellCelling(int i, int j)
    {
        maze[i][j].topwall = 0;
    }
void Labirynt::ChangeCellVisited(int i, int j)
    {
        maze[i][j].visited = 1;
    }
void Labirynt::RemoveRandomCell(){
        int size = maze.size();
        int i = GetRandom(size-1)+1;
        int j = GetRandom(size-1)+1;
        if(GetRandom(2)==1)
            {
        if(maze[i][j].topwall!=3)
            {
                maze[i][j].topwall=0;
            }
            }else
            {
                if(maze[i][j].leftwall!=3)
                    {
                        maze[i][j].leftwall=0;
                    }
            }
    }
