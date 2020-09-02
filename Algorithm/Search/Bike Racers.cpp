#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// Constants for Maximum Flow problem for graph with UPPER - 2 vertices.
#define UPPER 502
#define SOURCE 500
#define SINK 501

struct point
{
    int x, y;
    
    point(int x, int y)
    { this->x = x; this->y = y; }

    long long squared_distance(point b)
    { 
        long long dx = x - b.x, dy = y - b.y;
        return dx * dx + dy * dy;
    }
};

struct segment
{
    // a and b are indices referring to points in a list.
    int a, b;
    long long length;

    segment(int a, int b, long long length)
    { this->a = a; this->b = b; this->length = length; }

    bool operator < (const segment &s) const
    { return length < s.length; }
};

struct edge 
{
    int v, index;

    edge(int v, int index)
    { this->v = v; this->index = index; }
};

int flow[UPPER][UPPER];
int capacity[UPPER][UPPER];
vector<edge> graph[UPPER];

/**
 * Get N points from standard input.
 */
vector<point> get_points(int N)
{
    vector<point> points;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(point(x, y));
    }
    return points;
}

void build_complete_bipartite_graph_capacity(int N, int M)
{
    // Add a capacity from SOURCE to every vertex in set of size N.
    for (int i = 0; i < N; ++i)
        capacity[SOURCE][i] = 1;
    // Add a capacity from every vertex in set of size N to every vertex in set of size M.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            capacity[i][j + N] = 1;
    // Add a capacity from every vertex in set of size M to SINK.
    for (int j = 0; j < M; ++j)
        capacity[j + N][SINK] = 1;
}

/**
 * BFS through a bipartite graph starting from vertex start, ignoring all edges with 
 * indices >= cutoff.
 */
bool bfs(int start, int N, int cutoff, vector<int> &parents)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); ++i)
        {
            if (graph[v][i].index >= cutoff)
                break;
            int w = graph[v][i].v;
            // Ignore all vertices that we have seen before.
            if (parents[w] != -1)
                continue;
            // Add to the queue if there is capacity for a flow.
            if (capacity[v][w] - flow[v][w] > 0)
            {
                parents[w] = v;
                q.push(w);
            }
            // If vertex w >= N, then it is part of the bipartite graph connected to the SINK. If it 
            // does not have a flow to SINK, then we found an augmenting path.
            if (w >= N && capacity[w][SINK] - flow[w][SINK] > 0)
            {
                parents[SINK] = w;
                return true;
            }
        }
    }
    return false;
}

/**
 * Compute the maxflow of a bipartite graph, ignoring all edges with indices >= cutoff.
 */ 
int bipartite_maxflow(int N, int cutoff)
{
    int cur_flow = 0;
    for (int i = 0; i < N; ++i)
    {
        vector<int> parents(UPPER, -1);
        // Let's define the parent of SOURCE as SOURCE. 
        parents[SOURCE] = SOURCE;
        parents[i] = SOURCE;
        // If we cannot find an augmenting path, then continue on to the next vertex from SOURCE.
        if (!bfs(i, N, cutoff, parents))
            continue;
        int w = SINK;
        while (parents[w] != w)
        {
            flow[parents[w]][w] += 1;
            flow[w][parents[w]] -= 1;
            w = parents[w];
        }
        cur_flow++;
    }
    return cur_flow;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<point> bikers = get_points(N);
    vector<point> bikes = get_points(M);

    // Build a list of line segments sorted by length to binary search on.
    vector<segment> segments;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            segments.push_back(segment(i, j, bikers[i].squared_distance(bikes[j])));
    sort(segments.begin(), segments.end());

    // Build a graph of bikers and bikes s.t. the adjacency list is ordered by the distance between
    // a biker and a bike. Shift the index for a bike by the number of bikers N.
    for (int i = 0; i < segments.size(); ++i)
    {
        graph[segments[i].a].push_back(edge(segments[i].b + N, i));
        graph[segments[i].b + N].push_back(edge(segments[i].a, i));
    }

    build_complete_bipartite_graph_capacity(N, M);

    // Binary search for the length of a segment that is the shortest length to match at least K 
    // bikers and bikes.
    int left = 0, right = segments.size();
    while (left < right)
    {
        memset(flow, 0, sizeof(flow));
        int mid = left + (right - left) / 2;

        // Get a lower and upper bound on the segments with the same length as mid.
        int lower = mid, upper = mid;
        while (lower > 0 && segments[lower].length == segments[lower - 1].length)
            lower--;
        while (upper < segments.size() - 1 && segments[upper].length == segments[upper + 1].length)
            upper++;

        int maxflow = bipartite_maxflow(N, upper + 1);
        if (maxflow < K) 
            left = upper + 1;
        else 
            right = lower;
    }
    cout << segments[left].length << endl;
    return 0;
}
