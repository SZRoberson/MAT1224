/*** Code to numerically compute various sums of alternating series
to desired accuracy. The aim is to use the Alternating Series
Remainder Theorem to estimate the error in the sum of the series.
Converted from the Python version of the same code. ***/

# include <iostream>
# include <cmath>
# include <chrono>
# include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Local functions to generate the needed terms.
double a_n (int n) {
    // As C++ does not have a built in factorial, we use the gamma function.
    // This extends the factorial so that
    // tgamma(n+1) = n! for integers n.
    // See, e.g., the Wikipedia article on the gamma function.
    return pow(-2, n) / tgamma(n+1);
}

double b_n (int n) {
    return pow(-1, n+1) * n/pow(2, n);
}

double c_n (int n) {
    // See the comment in the a_n declaration for use of tgamma.
    return pow(-1, n)/(pow(2, n) * tgamma(n+1));
}

int main() {
    // Sum for 6a and its tolerance.
    double sum_a = exp(-2) - 1.0;
    double tol_a = 1.0e-2;
    // Sum for 6b and its tolerance.
    double sum_b = 2.0/9.0;
    double tol_b = 2.0e-3;
    // Sum for 7 and its tolerance.
    double sum_c = exp(-0.5);
    double tol_c = 5.0e-5;

    // Estimate the required sums via their series expansions.
    double est_sum = 0.0;
    // Start the sum at n = 1.
    int n = 1;
    while(abs(a_n(n)) > tol_a) {
        est_sum += a_n(n);
        cout << "After summing " << n << " terms, the estimated sum is " << est_sum << ".\n";
        n++;
        sleep_for(seconds(1));
    }
    cout << "We need " << n-1 << " terms to get the sum within " << tol_a << ".\n";
    cout << "The last term needed has absolute value " << abs(a_n(n-1)) << 
        " which is more than the tolerance." << endl;
    cout << "The next term has absolute value " << abs(a_n(n)) <<
        " which is less than the tolerance." << endl;
    cout << "The true sum is " << sum_a << "." << endl;
    cout << "The error is " << abs(sum_a - est_sum) << "!" << endl;
    sleep_for(seconds(1));

    // Reset for 6b.
    est_sum = 0.0;
    n = 1;
    while(abs(b_n(n)) > tol_b) {
        est_sum += b_n(n);
        cout << "After summing " << n << " terms, the estimated sum is " << est_sum << ".\n";
        n++;
        sleep_for(seconds(1));
    }
    cout << "We need " << n-1 << " terms to get the sum within " << tol_b << ".\n";
    cout << "The last term needed has absolute value " << abs(b_n(n-1)) << 
        " which is more than the tolerance." << endl;
    cout << "The next term has absolute value " << abs(b_n(n)) <<
        " which is less than the tolerance." << endl;
    cout << "The true sum is " << sum_b << "." << endl;
    cout << "The error is " << abs(sum_b - est_sum) << "!" << endl;
    sleep_for(seconds(1));

    // Reset for 7.
    est_sum = 0.0;
    // This sum starts at zero!
    n = 0;
    while(abs(c_n(n)) > tol_c) {
        est_sum += c_n(n);
        cout << "After summing " << n+1 << " terms, the estimated sum is " << est_sum << ".\n";
        n++;
        sleep_for(seconds(1));
    }
    cout << "We need " << n << " terms to get the sum within " << tol_c << ".\n";
    cout << "The last term needed has absolute value " << abs(c_n(n-1)) << 
        " which is more than the tolerance." << endl;
    cout << "The next term has absolute value " << abs(c_n(n)) <<
        " which is less than the tolerance." << endl;
    cout << "The true sum is " << sum_c << "." << endl;
    cout << "The error is " << abs(sum_c - est_sum) << "!" << endl;
    sleep_for(seconds(1));
    
    return 0;

}