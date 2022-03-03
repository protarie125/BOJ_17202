#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<pair<char, char>, char> table;

char addChar(char c1, char c2) {
	const auto& v1 = c1 - '0';
	const auto& v2 = c2 - '0';
	const auto& v3 = (v1 + v2) % 10;

	return static_cast<char>(v3 + '0');
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	auto ans = vector<char>{};
	for (int i = 0; i < 8; ++i) {
		ans.push_back(a[i]);
		ans.push_back(b[i]);
	}

	auto n = ans.size();
	while (2 < n)
	{
		auto next = vector<char>(n - 1, '\0');
		for (int i = 0; i < n - 1; ++i) {
			const auto& c1 = ans[i];
			const auto& c2 = ans[i + 1];

			if (table.end() == table.find({ c1, c2 })) {
				table.insert({ {c1, c2}, addChar(c1, c2) });
			}

			next[i] = table[{c1, c2}];
		}

		ans = next;
		n -= 1;
	}

	cout << ans[0] << ans[1];

	return 0;
}