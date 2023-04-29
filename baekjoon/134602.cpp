#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 10;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int N, M;
char board[MAX_N][MAX_N + 1];
bool visited[MAX_N][MAX_N][MAX_N][MAX_N];

struct Ball
{
    int x, y;
};

struct State
{
    Ball red, blue;
    int depth;
};

bool move(Ball &ball, int dir)
{
    int nx = ball.x + dx[dir];
    int ny = ball.y + dy[dir];
    int moved = 0;
    while (board[nx][ny] != '#' && board[nx][ny] != 'O')
    {
        ball.x = nx;
        ball.y = ny;
        nx += dx[dir];
        ny += dy[dir];
        moved = 1;
    }
    if (board[nx][ny] == 'O')
    {
        ball.x = nx;
        ball.y = ny;
        return true;
    }
    return moved;
}

int bfs(Ball red, Ball blue)
{
    queue<State> q;
    memset(visited, false, sizeof(visited));
    q.push({red, blue, 0});
    visited[red.x][red.y][blue.x][blue.y] = true;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        if (cur.depth >= 10)
            break;
        for (int i = 0; i < 4; i++)
        {
            Ball next_red = cur.red;
            Ball next_blue = cur.blue;
            bool red_in_goal = move(next_red, i);
            bool blue_in_goal = move(next_blue, i);
            if (blue_in_goal)
                continue;
            if (red_in_goal)
                return cur.depth + 1;
            if (next_red.x == next_blue.x && next_red.y == next_blue.y)
            {
                int red_dist = abs(next_red.x - cur.red.x) + abs(next_red.y - cur.red.y);
                int blue_dist = abs(next_blue.x - cur.blue.x) + abs(next_blue.y - cur.blue.y);
                if (red_dist > blue_dist)
                {
                    next_red.x -= dx[i];
                    next_red.y -= dy[i];
                }
                else
                {
                    next_blue.x -= dx[i];
                    next_blue.y -= dy[i];
                }
            }
            if (visited[next_red.x][next_red.y][next_blue.x][next_blue.y])
                continue;
            visited[next_red.x][next_red.y][next_blue.x][next_blue.y] = true;
            q.push({next_red, next_blue, cur.depth + 1});
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    Ball red = {0, 0};
    Ball blue = {0, 0};
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                red = {i, j};
            }
            else if (board[i][j] == 'B')
            {
                blue = {i, j};
            }
        }
    }
    int ans = bfs(red, blue);
    cout << ans;
    return 0;
}
