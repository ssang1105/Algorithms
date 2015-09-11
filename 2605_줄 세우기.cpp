#include <iostream>
using namespace std;

int main(void){
	unsigned int n;
	unsigned int arr[101];
	unsigned int result_arr[101];

	cin >> n;

	for (unsigned int i = 1; i <= n; i++) {
		cin >> arr[i];

		for (unsigned int j = n; j> i-arr[i] ; j--)	{
			result_arr[j] = result_arr[j - 1];
		}

		result_arr[i - arr[i]] = i;
	}

	

	for (unsigned int i = 1; i <= n; i++)
		cout << result_arr[i] << " ";

	return 0;


	
}