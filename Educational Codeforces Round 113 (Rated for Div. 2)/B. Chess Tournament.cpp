#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
    	int n;
    	cin>>n;
    	
    	string s;
    	cin>>s;
    	
    	set<int> twos;
    	for(int i=0; i<n; i++)
    	{
    		if(s[i] == '2')
    		  twos.insert(i);
    	}
    	
    	if(twos.size() == 1 || twos.size() == 2)
    	  cout<<"NO\n";
    	else
    	{
    		cout<<"YES\n";
    		vector<vector<char>> v(n, vector<char>(n, 'X'));
    		for(int i=0; i<n; i++)
    		{
    			for(int j=0; j<n; j++)
    			{
    				if(i==j)
    				 continue;
    				 
    				if(s[i] == '1')
    				{
    					v[i][j] = '=';
    					v[j][i] = '=';
    				}
    				
    			}
    		}
    		
    		int first = *twos.begin();
    		while(twos.size())
    		{
    			int a = *twos.begin(); 
    			twos.erase(twos.begin());
    			if(!twos.size())
    			{
    				v[a][first] = '+';
    				v[first][a] = '-';
    				break;
    			}
    			v[a][*twos.begin()] = '+';
    			v[*twos.begin()][a] = '-';
    		}
    		
    		for(int i=0; i<n; i++)
    		{
    			for(int j=0; j<n; j++)
    			{
    				if (i!=j && v[i][j] == 'X')
    				  cout<<'=';
    				else 
    				  cout<<v[i][j];
    			}
    			cout<<"\n";
    		}
    	}
    }
    return 0;
}
