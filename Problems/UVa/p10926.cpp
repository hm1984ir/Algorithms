
#import<random>
#import<vector>
#import<list>
#import<queue>
#import<iostream>

using namespace std;

enum class color_type {white, gray, black};

int bfs(int root, vector<vector<bool>> adjacencyList){
    vector<color_type> colors;

    for(auto row : adjacencyList){
        colors.push_back(color_type::white);
    }

    queue<int> q;
    q.push(root);
    colors[root] = color_type::gray;

    int child_count = -1;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        colors[current_node] = color_type::gray;
        for(int index = 0; index < adjacencyList[current_node].size();index++){
            if(adjacencyList[current_node][index] && colors[index] == color_type::white){
                q.push(index);
            }
        }

        child_count ++;
    }

    return child_count;

}

int main(){
    vector<vector<bool>> lst{{false, true, false},
			     {false, false, true},
			     {false, false, false}};

   
    int max_dependency = 0;
    int max_index = -1;

    for(int i = 0; i<lst.size(); i++){
        int dependency = bfs(i,lst);
        if(dependency > max_dependency){
            max_index = i;
            max_dependency = dependency;
        }
    }

    cout << "max_index : " << max_index <<"  max_dependency : " << max_dependency;
    return 0;

}




