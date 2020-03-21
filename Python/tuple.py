def get_tuple(name,GRno,CPI):
	a=(name,GRno,CPI)
	return a

def show(x):
	print(x)
if __name__ == "__main__":

	for i in range(5):
		a=input("Name:")
		b=input("GR Number:")
		c=input("CPI: ")
		arr[i]=	get_tuple(a,b,c)

	for j in arr:
		show(i)	 
