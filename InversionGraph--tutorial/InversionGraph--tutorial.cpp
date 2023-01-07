#include <iostream>
#include <vector>

using namespace std;

int solve() {
	int n;

	cin >> n;

	vector<pair<int, int>> stack;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		stack.push_back(make_pair(input, input));

		if (i > 0) {
			while ((stack.rbegin() + 1)->second > stack.rbegin()->first) {
				(stack.rbegin() + 1)->first = min(stack.rbegin()->first, (stack.rbegin() + 1)->first);
				(stack.rbegin() + 1)->second = max(stack.rbegin()->second, (stack.rbegin() + 1)->second);
				stack.pop_back();

				if (stack.size() == 1) break;
			}
		}
	}

	return stack.size();
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cout << solve() << endl;;
	}
}