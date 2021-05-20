#include<iostream>
#include<conio.h>

using ll = long long;

class game
{
    char g[3][3];
    int moves=0;
public:
    game()
        :g{{'1','2','3'},{'4','5','6'},{'7','8','9'}}{}

    void game_board();
    void move(int i);
    char win();
    void start();
};


void game::game_board()
{
    std::system("cls");
    std::cout <<"moves: "<< moves << '\n';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout << g[i][j] ;
            if(j<2)
                std::cout << " | ";
        }
        std::cout<<std::endl;
    }
}

void game::move(int player)
{
    moves++;
    char c=' ';
    if(player==0)
        c='X';
    else
        c='O';

    std::cout <<"player "<<c<< "\nenter the position to place your move: " << '\n';
    int pos;
    std::cin >>pos ;
    int i = (pos-1)/3;
    int j = (pos-1)%3;

    if(g[i][j]=='X' || g[i][j]=='O')
    {
        std::cout << "already filled, enter valid position" << '\n';
        moves++;
        move(player);
    }
    else
    {
        g[i][j]=c;
    }
}

char game::win()
{
    char c=' ';
    auto temp1=g[0][0];
    auto temp2=g[0][3];
    bool check_d1=true;
    bool check_d2=true;
    for(int i=0;i<3;i++)
    {
        char temp=g[i][i];
        bool check_v=true;
        bool check_h=true;
        for(int j=0;j<3;j++)
        {
            if(g[i][j]!=temp)
                check_v = false;
            if(g[j][i]!=temp)
                check_h=false;

        }

        if(check_v || check_h)
        {
            c=temp;
            return c;
        }
        if(temp1!=g[i][i])
            check_d1=false;
        if(temp2!=g[3-i][i])
            check_d2=false;
    }
    if(c==' ')
    {
        if(check_d1)
            c=g[0][0];
        if(check_d2)
            c=g[0][3];
    }

    return c;
}

void game::start()
{
    game_board();
    if(moves>=5)
    {
        char c = win();
        if(moves==9 && c==' ')
        {
            std::cout<<"draw"<<std::endl;
            return;
        }
        if(c!=' ')
        {
            std::cout<<"----------------------------"<<c<<" WINS----------------------------------\n";
            return ;
        }
    }
    int player=moves%2;
    move(player);
    start();
}

int main()
{
    game g;
    g.start();
}
