#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> mat) {
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}

}

vector<vector<int>> dvoi(vector<vector<int>> mat) {
	int max = 0;
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			if (mat[i][j] > max) max = mat[i][j];
		}
	}

	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] = max - mat[i][j];
		}
	}

	return mat;
}

vector<vector<int>> str_stl(vector<vector<int>> mat) {
	for (int i = 0; i < mat.size(); i++) {
		int min = INT_MAX;
		for (int j = 0; j < mat[i].size(); j++) {
			if (mat[i][j] < min) min = mat[i][j];
		}
		for (int j = 0; j < mat[i].size(); j++) {
			mat[i][j] -= min;
		}
	}

	for (int i = 0; i < mat[0].size(); i++) {
		int min = INT_MAX;
		for (int j = 0; j < mat.size(); j++) {
			if (mat[j][i] < min) min = mat[j][i];
		}
		for (int j = 0; j < mat.size(); j++) {
			mat[j][i] -= min;
		}
	}

	return mat;
}

int main() {
	int n, m;
	cout << "\nEnter the value of persons: ";
	cin >> n;
	cout << "\nEnter the value of cpec: ";
	cin >> m;

	vector <vector<int>> mat(m, vector<int>(n));

	cout << "\nEnter the elements of matrix (" << m << 'x' << n << "):\n\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	mat = dvoi(mat);
	mat = str_stl(mat);
	cout << "\n\n\n";
	print(mat);
}

