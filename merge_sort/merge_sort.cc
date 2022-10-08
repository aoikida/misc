#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int> &A, int left, int right) {

    //これ以上分割できない地点
    if (right - left == 1)return;
    int middle = left + (right - left) / 2;

    //左半分をsort
    MergeSort(A, left, middle);
    //右半分をsort
    MergeSort(A, middle, right);

    vector<int> buf;
    for(int i = left; i < middle; ++i) buf.push_back(A[i]);
    for(int i = right - 1; i >= middle; --i) buf.push_back(A[i]);

    //左と右を併合する
    int index_left = 0; //左側の添字
    int index_right = (int)buf.size() - 1; //右側の添字

    for(int i = left; i < right; ++i) {
        //左側採用
        if (buf[index_left] <= buf[index_right]) {
            A[i] = buf[index_left++];
        }
        //右側採用
        else {
            A[i] = buf[index_right--];
        }
    }
}

int main() {

    //入力
    int N = 0;
    vector<int> A(N);
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];

    //マージソート
    MergeSort(A, 0, N);

    //出力
	for (int i = 0; i < N; ++i) cout << A[i] << endl;

	return 0;
}