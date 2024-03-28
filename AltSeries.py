# Code to numerically compute various sums of alternating series
# to desired accuracy. The aim is to use the Alternating Series
# Remainder Theorem to estimate the error in the sum of the series.

import numpy as np
from scipy.special import factorial
from time import sleep

# Sum for 6a and its tolerance.
sum_a = np.exp(-2) - 1
tol_a = 1.0e-2
# Sum for 6b and its tolerance.
sum_b = 2/9
tol_b = 2.0e-3
# Sum for 7 and its tolerance.
sum_c = np.exp(-1/2)
tol_c = 5.0e-5

# Estimate the required sums via their series expansions.
a_n = lambda n: (-2)**n / factorial(n)
est_sum = 0
# Start the sum at n = 1.
n = 1
while (abs(a_n(n)) > tol_a):
    est_sum += a_n(n)
    print(f'After summing {n} terms, the estimated sum is {est_sum}.')
    n += 1
    sleep(1.0)
print(f'We need {n-1} terms to estimate the sum to within {tol_a}.')
print(f'The last term has absolute value {abs(a_n(n-1))}, which is more than the tolerance.')
print(f'The next term has absolute value {abs(a_n(n))}, which is smaller than the tolerance.')
print(f'The true sum is {sum_a}.')
print(f'The error is {abs(sum_a - est_sum)}!')
sleep(1.0)
# Reset for 6b.
est_sum = 0
b_n = lambda n: (-1) ** (n+1) * n/(2 ** n)
n = 1
while (abs(b_n(n)) > tol_b):
    est_sum += b_n(n)
    print(f'After summing {n} terms, the estimated sum is {est_sum}.')
    n += 1
    sleep(1.0)
print(f'We need {n-1} terms to estimate the sum to within {tol_b}.')
print(f'The last term has absolute value {abs(b_n(n-1))}, which is more than the tolerance.')
print(f'The next term has absolute value {abs(b_n(n))}, which is smaller than the tolerance.')
print(f'The true sum is {sum_b}.')
print(f'The error is {abs(sum_b - est_sum)}!')
sleep(1.0)
# Reset for 7.
est_sum = 0
c_n = lambda n: (-1) ** n /(2 ** n * factorial(n))
# The sum initializes at n = 0 this time.
n = 0
while (abs(c_n(n)) > tol_c):
    est_sum += c_n(n)
    print(f'After summing {n+1} terms, the estimated sum is {est_sum}.')
    n += 1
    sleep(1.0)
print(f'We need {n} terms to estimate the sum to within {tol_c}.')
print(f'The last term has absolute value {abs(c_n(n-1))}, which is more than the tolerance.')
print(f'The next term has absolute value {abs(c_n(n))}, which is smaller than the tolerance.')
print(f'The true sum is {sum_c}.')
print(f'The error is {abs(sum_c - est_sum)}!')