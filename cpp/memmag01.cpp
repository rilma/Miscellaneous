/* Memory Management */

#include <iostream>

using namespace std;


int main() {

    int N;
    cout << "\nEnter No. of Students: ";
    cin >> N;

    float* G = new float[N];

    cout << "\nEnter their grades: ";
    for(auto i=0; i<N; i++) cin >> *(G + i);

    cout << "\nPrinting their grades:";
    for(auto i=0; i<N; i++) cout << " " << *(G + i);
    cout << endl;

    float sum = 0.0;
    for(auto i=0; i<N; i++) sum += *(G + i);
    cout << "\nAverage grade: " << sum / (float) N << endl;

    delete [] G;

}
