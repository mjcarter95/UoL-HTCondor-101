import sys
import numpy as np

print(sys.argv)
if len(sys.argv) < 2:
    print("Usage {} <n_throws>".format(sys.argv[0]))
    sys.exit()

n_throws = sys.argv[1]
in_circle = 0

# Throw the dart n_throws times
x = np.random.uniform(0, 1, n_throws)
y = np.random.uniform(0, 1, n_throws)

# Check if the dart hit the board
for i in range(0, n_throws):
    if((x[i] * x[i]) + (y[i] * y[i]) <= 1):
        in_circle += 1

# Estimate value of pi
pi_estimate = 4 * in_circle / N

# Write result to output file
with open('output.txt', 'w') as f:
    f.write(pi_estimate)