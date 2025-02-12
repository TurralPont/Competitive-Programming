#include <iostream>

using namespace std;

int main() {
    int numero; cin >> numero;
    while (numero >= 0) {
      bool aux= true;

      while (numero > 0) {
        if (numero % 2 != 0) { 
          cout << "NO\n"; aux = false;
          break;
        }
        numero = numero / 10;
      } 
      if (aux) cout << "SI\n";
      cin >> numero;
    }
    return 0;
}
