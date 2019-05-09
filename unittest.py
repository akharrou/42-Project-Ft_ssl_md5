
import csv
import os

testfile = 'msg_digests.csv'
with open(testfile, 'r') as csvfile:

	file = csv.reader(csvfile)

	print('================================= File Contents =================================\n')
	for line in file:
		print(f'{line[1]} ——> {line[0]}')
	print('\n=================================================================================\n')
#
	# print('================================= TEST =================================\n')
#
	# for line in file:
#
		# msg     =  f'"{line[0]}"'
		# digest  =  f'"{line[1]}"'
#
		# os.system(f'./ft_ssl sha256 -s {msg} > digest_A')
		# os.system(f'echo {msg} > digest_B')
		# os.system('diff digest_A digest_B')
#
	# print('\n======================================================================\n')
