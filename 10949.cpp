/*Turn LCS to 2D LIS - other's implementation*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int LCS(string s1, string s2) {//Robinson-Schensted-Knuth Algorithm, s1比較短, s2比較長
	vector<int> charTable[128];
	for(int i=0;i<s2.length();i++)
		charTable[s2[i]].push_back(i);

	vector<int> lisStr;
	lisStr.push_back(-1);

	for(int i=0;i<s1.length();i++)
		for(int j=charTable[s1[i]].size()-1;j>=0;j--)
			if(charTable[s1[i]][j] > lisStr.back())//able to add more character
				lisStr.push_back(charTable[s1[i]][j]);
			else
				*lower_bound(lisStr.begin(),lisStr.end(),charTable[s1[i]][j]) = charTable[s1[i]][j];
    return lisStr.size()-1;
}


int main(){
    int caseNum;
    cin>>caseNum;
    for(int cn=1;cn<=caseNum;cn++){
        int row,column;
        cin>>row>>column;

        string grid[row];
        for(int i=0;i<row;i++)
            cin>>grid[i];

        string child1,child2;

        int s1,x1,y1,
            s2,x2,y2;

        cin>>s1>>x1>>y1;
        x1--;y1--;
        for(int i=0;i<s1;i++){
            child1.push_back(grid[x1][y1]);
            char c;
            cin>>c;
            switch(c){
                case 'N':
                    x1--;break;
                case 'E':
                    y1++;break;
                case 'W':
                    y1--;break;
                case 'S':
                    x1++;break;
            }
        }
		child1.push_back(grid[x1][y1]);

        cin>>s2>>x2>>y2;
        x2--;y2--;
        for(int i=0;i<s2;i++){
            child2.push_back(grid[x2][y2]);
            char c;
            cin>>c;
            switch(c){
                case 'N':
                    x2--;break;
                case 'E':
                    y2++;break;
                case 'W':
                    y2--;break;
                case 'S':
                    x2++;break;
            }
        }
		child2.push_back(grid[x2][y2]);

		int maxStrLen ;
		if(s1>s2)maxStrLen = LCS(child1,child2);
		else maxStrLen = LCS(child2,child1);

		cout<<"Case "<<cn<<": "<<child1.length()-maxStrLen<<" "<<child2.length()-maxStrLen<<"\n";

    }

}



