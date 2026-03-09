//method-1 dfs with extra space
class Solution {
public:
void dfs(unordered_map<int,vector<int>> &adj,vector<bool>&visited,int u)
{
    if(visited[u]) return ;
    visited[u]=1;
    for(int &v:adj[u])
    {
        if(!visited[v]) dfs(adj,visited,v);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {

                if(isConnected[i][j]) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int result=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
            dfs(adj,visited,i);
            result++;
            }
        }
        return result;        
    }
};

//method-2 dfs with no extra sapce
class Solution {
public:
int n;
void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int u)
{
    visited[u]=1;
    for(int v=0;v<n;v++)
    {
        if(!visited[v] && isConnected[u][v]) dfs(isConnected,visited,v);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();
        
        int result=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,visited,i);
                result++;
            }
        }
        return result;        
    }
};

// method -3 bfs with extra space
class Solution {
public:
void BFS(unordered_map<int,vector<int>> &adj,vector<bool>&visited,int u)
{
    queue<int>q;
    q.push(u);
    visited[u]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int &v:adj[u])
        {
            if(!visited[v]) 
            {
                BFS(adj,visited,v);
            }
        }
        
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int result=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                BFS(adj,visited,i);
                result++;
            }
        }
        return result;        
    }
};

//method-4 bfs with out extra space
class Solution {
public:
int n;
void BFS(vector<vector<int>>& isConnected,vector<bool>&visited,int u)
{
    queue<int>q;
    q.push(u);
    visited[u]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int v=0;v<n;v++)
        {
            if(!visited[v] && isConnected[u][v]) 
            {
                BFS(isConnected,visited,v);
            }
        }
        
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        
        int result=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                BFS(isConnected,visited,i);
                result++;
            }
        }
        return result;        
    }
};
