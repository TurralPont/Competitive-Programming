  for (int i=0; i<impares.size()-1; ++i){
      cout << i << '\n';
      if (impares[i+1] - impares[i] != 2){
        cout << "NO\n";
        return;
      }
    }