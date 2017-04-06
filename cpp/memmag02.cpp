#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


float* gen_grades(int n) {

    float* g = new float[n];    

    for (auto i = 0; i < n; i++) *(g + i) = rand() % 100;

    return g;
}


class Students {

    public:

        Students() {

            int n = rand() % 10;

            set_N(n);

            set_G(gen_grades(n));

        }

        Students(int n) {

            set_N(n);
            
            set_G(gen_grades(n));


        }

        Students(int n, float* g) {

            set_N(n);

            set_G(g);

        }

        ~Students() { delete [] G; }

        void set_N(int n) {
            N = n;
        }

        void set_G(float* g) { 
            G = new float[N];
            for (int i = 0; i < N; i++) *(G + i) = *(g + i);
            delete [] g;
        }

        void print_G() {
            cout << "\nPrinting grades:\n";
            for (int i = 0; i < N; i++)
                cout << "Student " << i + 1 << "): " << *(G + i) << endl; 
            cout << endl;
        }


    private:

        int N;
        float* G;

};


int main() {

    srand(time(0));

    Students S1;
    S1.print_G();    

    int n = 3;
    Students S2(n);
    S2.print_G();

    float* g = gen_grades(n);
    Students S3(n, g);
    S3.print_G();

}