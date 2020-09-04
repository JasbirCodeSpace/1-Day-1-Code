<h1>Infix to Postfix</h1>

<p>
You are given an infix expression S of length N. You need to convert the given expression S to its postfix equivalent using stack.

</p>

<h2>Input</h2>
<p>

- The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.

- The first line of each test case contains a single integer N denoting the length of S.

- The second line contains a string S, the infix expression.

</p>

<h2>Output</h2>
<p>
For each test case print a single line containing the postfix equivalent for the given infix expression.
</p>

<h2>Constraints</h2>

- 1 ≤ T ≤ 10

- 1 ≤ N ≤ 10^2

- S contains only uppercase English letters (A...Z), and these characters - (,),+,−,∗,/,^. S is a valid infix expression.

#### Sample Input:

```
2
15
((A+B)*D)^(E-F)
19
A+(B*C-(D/E^F)*G)*H

```

#### Sample Output:

```
AB+D*EF-^
ABC*DEF^/G*-H*+

```
