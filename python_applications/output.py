import os

pi_estimate = 0
output_dir = '{}/job/output'.format(os.getcwg())

for output_file in os.listdir(output_dir):
    with open('{}/{}'.format(os.listdir(output_dir), output_file), 'r') as f:
        pi_estimate = f.readline()

print('Estimate of pi: {}'.format(pi_estimate))