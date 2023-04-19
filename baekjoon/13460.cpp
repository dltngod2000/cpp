/*문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.*/

#include <iostream>
#include <string>

#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3

using namespace std;

int search(int way, marble R, marble B);
class marble
{
private:
    char color;
    int x, y;

public:
    marble(char cIn);
    char getColor();
    int getX();
    int getY();
    void setX(int xIn);
    void setY(int yIn);
    void move(int way);
};

int search(int way, marble R, marble B)
{
    switch (way)
    {
    case EAST:
        if (R.getX() <= B.getX())
        {
            R.move(EAST);
            B.move(EAST);
        }
        break;
    case WEST:
        if (R.getX() <= B.getX())
        {
            B.move(WEST);
            R.move(WEST);
        }
        break;
    case SOUTH:
        if (R.getY() <= B.getY())
        {
            R.move(SOUTH);
            B.move(SOUTH);
        }
        break;
    case NORTH:
        if (R.getY() <= B.getY())
        {
            B.move(NORTH);
            R.move(NORTH);
        }
        break;

    default:
        break;
    }

    while (true)
    {
        search(EAST, R, B);
        search(WEST, R, B);
        search(SOUTH, R, B);
        search(NORTH, R, B);
    }
}
marble::marble(char cIn)
{
    color = cIn;
}
char marble::getColor()
{
    return color;
}
int marble::getX()
{
    return x;
}
int marble::getY()
{
    return y;
}
void marble::setX(int xIn)
{
    this->x = xIn;
}
void marble::setY(int yIn)
{
    this->y = yIn;
}

void marble::move(int way)
{
    switch (way)
    {
    case EAST:
        /* code */
        break;
    case WEST:
        /* code */
        break;
    case SOUTH:
        /* code */
        break;
    case NORTH:
        /* code */
        break;

    default:
        break;
    }
}
int main()
{
    std::freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    char array[M][N];

    marble RED('R');
    marble BLUE('B');

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> array[i][j];
            cout << array[i][j];
            if (array[i][j] == 'R')
            {
                RED.setX(j);
                RED.setY(i);
            }
            else if (array[i][j] == 'B')
            {
                BLUE.setX(j);
                BLUE.setY(i);
            }
        }
        cout << "\n";
    }
    cout << "RED(" << RED.getX() << ", " << RED.getY() << ")\n"
         << "BLUE(" << BLUE.getX() << ", " << BLUE.getY() << ")\n";
    return 0;
}