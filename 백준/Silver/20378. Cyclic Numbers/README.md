# [Silver III] Cyclic Numbers - 20378 

[문제 링크](https://www.acmicpc.net/problem/20378) 

### 성능 요약

메모리: 2156 KB, 시간: 124 ms

### 분류

임의 정밀도 / 큰 수 연산, 사칙연산, 구현, 수학

### 제출 일자

2026년 2월 2일 22:31:02

### 문제 설명

<p>A <em>cyclic number</em> is a positive integer n digits in length which, when multiplied by any integer from 1 to n, yields a "cycle" of the digits of the original number. That is, if you consider the number after the last digit to "wrap around" back to the first digit, the sequence of digits in both numbers will be the same, though they may start at different positions.</p>

<p>For example, the number 142857 is cyclic, as illustrated by the following table:</p>

<ul>
	<li>142857 × 1 = 142857</li>
	<li>142857 × 2 = 285714</li>
	<li>142857 × 3 = 428571</li>
	<li>142857 × 4 = 571428</li>
	<li>142857 × 5 = 714285</li>
	<li>142857 × 6 = 857142</li>
</ul>

<p>Write a program which will determine whether or not numbers are cyclic.</p>

### 입력 

 <p>The input is a list of integers from 2 to 1000 digits in length (preceding zeroes are legal).</p>

### 출력 

 <p>In the output, display each integer and indicate whether or not it is cyclic.</p>

