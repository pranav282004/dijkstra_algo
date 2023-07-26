#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>>
#include <utility>  
using namespace std;

class DJK{
    private:
        unordered_map<int,list<pair<int,int>>> adj_distances;
        set<pair<int,int>> checking;
	    unordered_map<int,int> final_distances;
    public:
        vector<int> make_dsk(vector<vector<int>> &vecs,int vertices,int edges){
            for(size_t y = 0;y<edges;y++){
                int v = vecs[y][0];
                int u = vecs[y][1];

                adj_distances[u].push_back(make_pair(v,vecs[y][2]));
                adj_distances[v].push_back(make_pair(u,vecs[y][2]));

            }

	    for(size_t x=0;x<vertices;x++){
	    		
		    final_distances[x] = INT_MAX;
	   }

	   //final_distances[(0);

	   checking.insert(make_pair(0,0));
	   
	   while(!checking.empty()){

	   	auto dist_payload = *(checking.begin());

		int node = dist_payload.first;

		int _distance = dist_payload.second;

		checking.erase(checking.begin());

		for(auto p:adj_distances[node]){
		
			if(_distance + p.second < final_distances[p.first]){
				
				
				//auto px = checking.find(make_pair());
				
				final_distances[p.first] = _distance + p.second;

                checking.insert(make_pair(p.first,final_distances[p.first]));

			
			}
			

		
		}

	   
	   }
       vector<int> to_return;
       for(auto x:final_distances){
            to_return.push_back(x.second);
       }
	    return to_return;
        }
};

int main(){

    DJK dd;
    vector<vector<int>> g;
    vector<int> x = dd.make_dsk(g,4,5);

    for (int _g : x){
        cout<<_g<<endl;
    }
    /*for(size_t d = 0;d<10;d++){
        list<pair<int,int>> _temp;
        for(size_t nes = 0;nes<5;nes++){
            _temp.push_front(make_pair(nes,nes+1));
        }
        s[d] = _temp;
    }

*/

    /*unordered_map<string,int> s;
    list<string> ff{"This","is","string"};
    int64_t counter = 0;
    for(auto p:ff){
        s[p] = counter;
        counter++;
    }

    for(auto pf:s){
        cout << pf.first << " " << pf.second;
    }*/
    
   /* vector<int64_t> s;

    for(size_t x = 0;x<=10;x++){
        s.push_back(x);
    }
    for(auto d = s.begin(); d!=s.end();d++){
        cout << *d << endl;
    }*/

    return 0;
}
