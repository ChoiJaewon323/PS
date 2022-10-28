#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> seq;
	int n, s, temp;
	int start, end, result, tempAcc;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		seq.push_back(temp);
	}
	seq.push_back(0);

	start = 0;
	end = 0;
	result = 1000000000;
	tempAcc = seq[end];
	while (end < n) {
		if (tempAcc < s) {	// s���� ���� ��
			end++;
			tempAcc += seq[end];
		}
		else {	// s���� ũ�ų� ���� ��
			result = min(result, end - start + 1);
			// ũ�� ���̱�
			if (start == end) {
				end++;
				tempAcc += seq[end];
			}
			else {
				tempAcc -= seq[start];
				start++;
			}
		}
	}

	if (result == 1000000000) {
		cout << 0 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}