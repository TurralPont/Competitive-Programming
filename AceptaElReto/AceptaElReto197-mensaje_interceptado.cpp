#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isVocal(char c){
	return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}

bool solve() {
	string linea;
	getline(cin, linea);
	if (!cin) return false;

	cout << linea << " => ";

	queue<char> cola;
	stack<char> aux;
	int i = 0;

	for (char c : linea){
			if (i % 2 == 0) cola.push(c);
			else aux.push(c);
			++i;
	}
	while (!aux.empty()){
		cola.push(aux.top());
		aux.pop();
	}

	while (!cola.empty()){
		if (isVocal(cola.front())){
			while (!aux.empty()){
				cout << aux.top();
				aux.pop();
			}
			cout << cola.front();
		}
		else{
			aux.push(cola.front());
		}
		cola.pop();
	}

	while (!aux.empty()){
		cout << aux.top();
		aux.pop();
	}

	cout << '\n';
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (solve());
	return 0;
}