<h1>Point Of Impact</h1>

<p>
You are playing a Billiards-like game on an N×N table, which has its four corners at the points {(0,0),(0,N),(N,0), and (N,N)}. You start from a coordinate (x,y), (0 < x < N,0 < y < N) and shoot the ball at an angle 45∘ with the horizontal. On hitting the sides, the ball continues to move with the same velocity and ensuring that the angle of incidence is equal to the angle of reflection with the normal, i.e, it is reflected with zero frictional loss. On hitting either of the four corners, the ball stops there and doesn’t move any further.

Find the coordinates of the point of collision, when the ball hits the sides for the Kth time. If the ball stops before hitting the sides K times, find the coordinates of the corner point where the ball stopped instead.

</p>

<h2>Input</h2>
<p>

- The first line of the input contains an integer T, the number of testcases.

- Each testcase contains a single line of input, which has four space separated integers - N, K, x, y, denoting the size of the board, the number of collisions to report the answer for, and the starting coordinates.

</p>

<h2>Output</h2>
<p>
For each testcase, print the coordinates of the ball when it hits the sides for the Kth time, or the coordinates of the corner point if it stopped earlier.
</p>

<h2>Constraints</h2>

- 1 ≤ T ≤ 10^5

- 2 ≤ N ≤ 10^9

- 1 ≤ K ≤ 10^9

<h2>Example</h2>

#### Input:

```
2
5 5 4 4
5 2 3 1

```

#### Output:

```
5 5
3 5

```

#### Explanation:

<p>
Sample Case 1 :
We are given a 5 by 5 board. We shoot the ball from coordinates (4,4), and we need to find its coordinates after it has collided with sides 5 times. However, after shooting, the ball goes directly to the corner (5,5), and stops there. So we report the coordinates (5,5).

![Sample Case 1](https://codechef_shared.s3.amazonaws.com/download/Images/JAN21/BILLRD/BILLRD_1.png)

</p>

<p>
Sample Case 2 :
We are given a 5 by 5 board. We shoot the ball from the coordinates (3,1), and we need to find its coordinates after it has collided with the sides twice. After shooting, it first hits the right side at (5,3), and then the top side at (3,5). So, we report (3,5).

![Sample Case 2](https://codechef_shared.s3.amazonaws.com/download/Images/JAN21/BILLRD/BILLRD_2.png)

</p>
