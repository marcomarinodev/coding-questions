class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def coverPoints(self, A, B):
        prev = (A[0], B[0])
        steps = 0

        for i in range(len(A)):
            if i == 0:
                continue 
            x = A[i]
            y = B[i]

            diffX = abs(prev[0] - x)
            diffY = abs(prev[1] - y)

            prev = (x,y)

            steps += max(diffX, diffY)

        return steps

a = [-7, -13]
b = [1, -5]

print(Solution.coverPoints(a,b))