#include <iostream>
#include <algorithm>
using namespace std;

int64_t numbers[1000001];
int64_t segmentTree[4000001];

int64_t makeSegmentTree(int start, int end, int node) {
	int mid;
	if (start == end) {	// ���� ��� ����
		return segmentTree[node] = numbers[start];
	}
	mid = (start + end) / 2;
	return segmentTree[node] = makeSegmentTree(start, mid, node * 2) 
		+ makeSegmentTree(mid + 1, end, node * 2 + 1);
}

int64_t findSum(int start, int end, int node, int left, int right) {
	int mid;
	if (right < start || left > end) {	// ���� ��
		return 0;
	}
	if (left <= start && right >= end) {	// ���� ��
		return segmentTree[node];
	}
	mid = (start + end) / 2;
	return findSum(start, mid, node * 2, left, right) 
		+ findSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int64_t num) {
	int mid;
	if (index < start || index > end) {	// ���� ��
		return;
	}
	segmentTree[node] += num;
	if (start == end) {	// base case
		return;
	}
	mid = (start + end) / 2;
	update(start, mid, node * 2, index, num);
	update(mid + 1, end, node * 2 + 1, index, num);
}

int main() {
	int n, m, k;
	int64_t temp;
	int a, b;
	int64_t c;
	cin >> n >> m >> k;
	// n : ���� ����
	// m : ���� ���� Ƚ��
	// k : ������ �� Ƚ��

	for (int i = 1; i <= n; i++) {
		cin >> temp;
		numbers[i] = temp;
	}

	makeSegmentTree(1, n, 1);

	for (int i = 0; i < m + k; i++) {
		int64_t result;
		cin >> a >> b >> c;

		if (a == 1) {	// b��° ���� c�� �ٲ�
			update(1, n, 1, b, c - numbers[b]);
			numbers[b] = c;
		}
		else if (a == 2) {	// b��° ������ c��° �������� �� ���
			result = findSum(1, n, 1, b, c);
			cout << result << '\n';
		}
	}

	return 0;
}