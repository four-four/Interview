TODO

/*
269. 火星词典 Hard

现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。

假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。

您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

示例 1：

输入:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

输出: "wertf"
示例 2：

输入:
[
  "z",
  "x"
]

输出: "zx"
示例 3：

输入:
[
  "z",
  "x",
  "z"
] 

输出: "" 

解释: 此顺序是非法的，因此返回 ""。
注意：

你可以默认输入的全部都是小写字母
假如，a 的字母排列顺序优先于 b，那么在给定的词典当中 a 定先出现在 b 前面
若给定的顺序是不合法的，则返回空字符串即可
若存在多种可能的合法字母顺序，请返回其中任意一种顺序即可
*/

class Solution {
public:
        string alienOrder(vector<string>& words) {
        if(words.size()==1){
            sort(words[0].begin(),words[0].end());
            string ans;
            for(int i=0;i<words[0].size();++i){
                if(!i || words[0][i] != words[0][i-1]){
                    ans += words[0][i];
                }
            }
            return ans;
        }
        vector<vector<int>> grid(256,vector<int>(256,0));
        vector<int> has(256,0);
        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                int k=0;
                const int len=min(words[i].size(),words[j].size());
                while(k < len){
                    int a=words[i][k];
                    int b=words[j][k];
                    ++has[a];
                    ++has[b];
                    if(a != b){
                        grid[a][b]=1;
                        break;
                    }
                    ++k;
                }
                int nk=k;
                while(k < words[i].size()) ++has[words[i][k++]];
                while(nk < words[j].size()) ++has[words[j][nk++]];
            }
        }
       
        vector<int> vis(256,0);
        vector<int> path(256);
        int cur=256;
        for(int i=0;i<256;++i){
            if(has[i] && !vis[i]){
                bool rt=dfs(grid,has,vis,path,cur,i);
                if(!rt) return "";
            }
        }
        string ans;
        while(cur < 256){
            ans += path[cur++];
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& grid,
             vector<int>& has,
             vector<int>& vis,
             vector<int>& path,
             int& cur,
             int u){
        vis[u]=-1;
        for(int v=0;v<grid[u].size();++v){
            if(!has[v] || !grid[u][v]) continue;
            if(vis[v] < 0) return false;
            else if(!vis[v] && !dfs(grid,has,vis,path,cur,v)) return false;
        }
        path[--cur]=u;
        vis[u]=1;
        return true;
    }
};