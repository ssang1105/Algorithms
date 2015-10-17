#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int tmp;
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++){
		cin >> tmp;
		v.push_back(tmp);
		sum += tmp;
	}

	sort(v.begin(), v.end());
	
	cout << sum / 5 << endl;
	cout << v[v.size() / 2] << endl;
	

	return 0;
}