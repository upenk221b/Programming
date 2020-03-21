#! /home/upendra/anaconda3/bin/python

import random

def evaluate_pi(n):
	in_circle=0
	in_square=0
	for _ in range(int (n)):
		x=random.uniform(0,1)
		y=random.uniform(0,1)
		distance = x**2+y**2
		if distance <= 1:
			in_circle+=1
		in_square+=1
	print(4*in_circle/in_square)

if __name__ == "__main__":
	num=input("Num : ")
	evaluate_pi(num)
