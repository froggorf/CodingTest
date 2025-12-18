#include <iostream>
#include <algorithm>
std::string S, T;

bool Func(std::string& Str, bool bRight) {
	if (Str == T) {
		return true;
	}

	if (Str.length() >= T.length()) {
		return false;
	}

	std::string Str1;
	std::string Str2;

	// 1. 맨뒤 A 추가
	if (bRight) {
		Str1 = Str + "A";
	}
	else {
		Str1 = "A" + Str;
	}

	if (Func(Str1, bRight)) {
		return true;
	}
	
	// 2. 문자열 뒤집고 뒤에 B추가
	if (bRight) {
		bRight = false;
		Str2 = "B" + Str;
	}
	else {
		bRight = true;
		Str2 = Str + "B";
	}
	if (Func(Str2, bRight)) {
		return true;
	}
	
	return false;
}

bool Func2(const std::string& Str) {
	if (Str == S) {
		return true;
	}

	if (Str.length() <= S.length()) {
		return false;
	}

	if (Str[Str.length() - 1] == 'A') {
		if (Func2(Str.substr(0, Str.length() - 1))) {
			return true;
		}
	}
	else {
		std::string SSS = Str.substr(0, Str.length() - 1);
		std::reverse(SSS.begin(), SSS.end());
		if (Func2(SSS)) {
			return true;
		}
	}
	
	return false;

}

// 단순 구현은 시간초과
// bRight 를 놓고
// 

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> S >> T;
	if (Func2(T)) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}
}