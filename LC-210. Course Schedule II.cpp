// bfs
class Solution {
public:

   vector<int> topologocalCheck(unordered_map<int,vector<int>>& adj,vector<int> &indegree,int n)
    {
        vector<int>result;
        //2. indegree 0 walo ko push kar do
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) 
            {
                q.push(i);
            }
            
        }
        // simple bfs
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            result.push_back(u);
            for(int v:adj[u])
            {
                indegree[v]--;

                if(indegree[v]==0) 
                {
                    q.push(v);
                }
            }
        }
        if(result.size()==n) return result;
        return {};

    }
 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // make graph and find indegrees.
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);

            indegree[v]++;
        }
       
        

        return topologocalCheck(adj,indegree,numCourses);
        

    }
};

// using dfs
class Solution {
public:
bool hasCycle;
    void dfs(unordered_map<int,vector<int>>& adj,vector<bool> &visited,vector<bool>& inRecursion,stack<int>&st,int u)
    {
        visited[u]=true;
        inRecursion[u]=true;

        for(int v:adj[u])
        {
            if(inRecursion[v] ==true)
            {
                hasCycle=true;
                return;
            } 
            if(!visited[v] )
             dfs(adj,visited,inRecursion,st,v);
        }
        st.push(u);
        inRecursion[u]=false;
    }
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         // make graph .
         hasCycle=false;
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses,0);
        vector<bool> inRecursion(numCourses,0);
        stack<int>st;

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
                dfs(adj,visited,inRecursion,st,i) ;
        }

        if(hasCycle) return { };
        
        vector<int>result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
        
    }
};
