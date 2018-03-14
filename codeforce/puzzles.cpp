//http://codeforces.com/problemset/problem/337/A

#include <iostream>
#include <algorithm>


using namespace std;

int main(void)
{
	size_t numStudents,numPuzzles;
	size_t* pieces;
	while(cin >> numStudents >> numPuzzles){
		pieces = new size_t[numPuzzles];
		for (size_t i = 0; i < numPuzzles; ++i) {
			cin >> pieces[i];
		}
		sort(pieces,pieces+numPuzzles);
		int best = pieces[numStudents-1]-pieces[0];
		for(size_t i=1;i<=numPuzzles-numStudents;++i){
			int now = pieces[i+numStudents-1]-pieces[i];
			best = best<now?best:now;
			//cout << pieces[i+numStudents-1] << '\t' <<pieces[i] << endl;
		}
		//for(size_t i=0;i<numPuzzles;i++)
			//cout << pieces[i] << '\t';
		//cout << endl <<best << endl;
		cout << best << endl;
		delete []pieces;
	}
	return 0;
}
