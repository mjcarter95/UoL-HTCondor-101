import os

pi_estimate = 0
n_computers = 10
output_dir = '{}'.format(os.getcwd())

for i in range(n_computers):
    with open('{}/output{}.txt'.format(output_dir, i), 'r') as f:
        pi_estimate += float(f.readline())

pi_estimate /= n_computers

print('Estimate of pi: {}'.format(pi_estimate))
