S = input();
A = int(S.split(' ')[0])
B = int(S.split(' ')[1])
N = int(S.split(' ')[2])

for i in range(2,N+1):
A,B = B,B**2+A

print(A)