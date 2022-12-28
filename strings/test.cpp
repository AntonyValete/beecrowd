#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Verifica se a string s é uma substring contígua da string t
bool isSubstring(string s, string t) {
  if (s.size() > t.size()) {
    return false;
  }

  for (int i = 0; i <= t.size() - s.size(); i++) {
    bool match = true;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] != t[i + j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return true;
    }
  }

  return false;
}

int main() {
  int n;
  while (cin >> n && n > 0) {
    vector<string> photos(n);
    for (int i = 0; i < n; i++) {
      cin >> photos[i];
    }

    // Cria a matriz de adjacências
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isSubstring(photos[i], photos[j])) {
          adjacencyMatrix[i][j] = 1;
        }
      }
    }

    // Encontra o maior caminho na matriz de adjacências
    vector<int> path(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (adjacencyMatrix[j][i] == 1 && path[i] < path[j] + 1) {
          path[i] = path[j] + 1;
        }
      }
    }

    // Imprime o tamanho do maior caminho
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
      maxLength = max(maxLength, path[i]);
    }
    cout << maxLength << endl;
  }
  return 0;
}