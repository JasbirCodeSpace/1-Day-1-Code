<h1>Multiple of 3</h1>

<p>
Consider a very long K-digit number N with digits d0, d1, ..., dK-1 (in decimal notation; d0 is the most significant and dK-1 the least significant digit). This number is so large that we can't give it to you on the input explicitly; instead, you are only given its starting digits and a way to construct the remainder of the number.

Specifically, you are given d0 and d1; for each i ≥ 2, di is the sum of all preceding (more significant) digits, modulo 10 — more formally, the following formula must hold:

<img src="https://discuss.codechef.com/upfiles/latex_ee2df4815ab422dc8e52161db77bfe06.png" width="250"/>
Determine if N is a multiple of 3.

</p>

<h2>Input</h2>
<p>

- The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.

- The first and only line of each test case contains three space-separated integers K, d0 and d1.

    </p>

<h2>Output</h2>
<p>
For each test case, print a single line containing the string "YES" (without quotes) if the number N is a multiple of 3 or "NO" (without quotes) otherwise.
</p>

<h2>Constraints</h2>

- 1 ≤ T ≤ 1000

- 2 ≤ K ≤ 1012

- 1 ≤ d0 ≤ 9

- 0 ≤ d1 ≤ 9

#### Sample Input:

```
3
5 3 4
13 8 1
760399384224 5 1

```

#### Sample Output:

```
NO
YES
YES

```

#### Explanation:

<p>

- Example case 1: The whole number N is 34748, which is not divisible by 3, so the answer is NO.

- Example case 2: The whole number N is 8198624862486, which is divisible by 3, so the answer is YES.

</p>
