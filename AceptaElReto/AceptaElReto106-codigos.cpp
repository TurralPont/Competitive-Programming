#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> paises = {{"0", "EEUU"}, {"380", "Bulgaria"} , {"50", "Inglaterra"}, 
											{"539", "Irlanda"}, {"560", "Portugal"}, {"70", "Noruega"},
											{"759", "Venezuela"} , {"850", "Cuba"} , {"890", "India"} };

bool solve(){
  string codigo; cin >> codigo;
  if (codigo == "0") return false;
  int valor = 0;
		for (int i = codigo.length()-1, j = 0; i >= 0; --i, ++j) {
			if(j % 2 == 0) valor += codigo[i] - '0';
			else valor += 3 * (codigo[i] - '0');
		}
		bool correcto = valor % 10 == 0;
		if (correcto) cout << "SI";
		else cout << "NO";
		if (codigo.length() > 8 && correcto) {
			if (codigo.length() < 13) cout << " EEUU";
			else if (paises.count(codigo.substr(0, 1)))
				cout << ' ' << paises[codigo.substr(0, 1)];

			else if (paises.count(codigo.substr(0, 2)))
				cout << ' ' << paises[codigo.substr(0, 2)];

			else if (paises.count(codigo.substr(0, 3)))
				cout << ' ' << paises[codigo.substr(0, 3)];
			else cout << " Desconocido";
		}
		cout << '\n';
  
  return true;
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (solve());
  return 0;
  
}