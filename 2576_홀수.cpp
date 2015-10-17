#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	vector<int> v;
	int tmp;
	for (int i = 0; i < 7; i++){
		cin >> tmp;
		if (tmp%2==1)
			v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];

	cout << sum << endl;
	cout << v[0] << endl;

		
	return 0;
}