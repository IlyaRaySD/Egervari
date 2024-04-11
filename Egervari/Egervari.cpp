#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(const vector<vector<int>>& mat) {
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[i].size(); j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

vector<vector<int>> dvoi(const vector<vector<int>>& mat) {
	int max = 0;
	vector<vector<int>> matrix = mat;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] > max) max = matrix[i][j];
		}
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = max - matrix[i][j];
		}
	}

	return matrix;
}

vector<vector<int>> str_stl(const vector<vector<int>>& mat) {
	vector<vector<int>> matrix = mat;
	int sum = 0;
	for (int i = 0; i < matrix.size(); i++) {
		int min = INT_MAX;
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] < min) min = matrix[i][j];
		}
		sum += min;
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] -= min;
		}
	}

	for (int i = 0; i < matrix[0].size(); i++) {
		int min = INT_MAX;
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[j][i] < min) min = matrix[j][i];
		}
		sum += min;
		for (int j = 0; j < matrix.size(); j++) {
			matrix[j][i] -= min;
		}
	}

	cout << "\nSum of min elements: " << sum << endl;
	return matrix;
}

vector<vector<int>> pairs(const vector<vector<int>>& mat) {
	vector<vector<int>> matrix = mat;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) matrix[i][j] = 1;
			else matrix[i][j] = 0;
		}
	}
	return matrix;
}

bool findAssignment(int person, vector<int>& job, const vector<vector<int>>& mat, vector<int>& assigned_jobs, vector<bool>& assigned) {
	for (int j = 0; j < job.size(); j++) {
		if (mat[person][j] == 0 && !assigned[j]) {
			assigned[j] = true;
			if (assigned_jobs[j] == -1 || findAssignment(assigned_jobs[j], job, mat, assigned_jobs, assigned)) {
				assigned_jobs[j] = person;
				return true;
			}
		}
	}
	return false;
}

void hungarianAlgorithm(const vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();

	vector<int> assigned_jobs(n, -1);
	vector<int> job(n);
	for (int i = 0; i < n; i++) job[i] = i;

	for (int person = 0; person < m; person++) {
		vector<bool> assigned(n, false);
		findAssignment(person, job, mat, assigned_jobs, assigned);
	}

	cout << "Assignments:\n";
	for (int j = 0; j < n; j++) {
		if (assigned_jobs[j] != -1) {
			cout << "Person " << assigned_jobs[j] + 1 << " is assigned to Job " << j + 1 << endl;
		}
	}
}

int main() {
	int n, m;
	cout << "\nEnter the value of persons: ";
	cin >> n;
	cout << "\nEnter the value of jobs: ";
	cin >> m;

	vector <vector<int>> A(m, vector<int>(n));

	cout << "\nEnter the elements of matrix A (" << m << 'x' << n << "):\n\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	vector <vector<int>> B = dvoi(A);
	cout << "\nMatrix B:\n";
	print(B);
	B = str_stl(B);
	cout << "\nMatrix B (update) :\n";
	print(B);
	vector <vector<int>> C = pairs(B);
	cout << "\nMatrix C:\n";
	print(C);
	cout << "\n\n\n";
	hungarianAlgorithm(B);
	return 0;
}

