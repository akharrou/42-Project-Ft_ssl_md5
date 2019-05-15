# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    unittester.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 09:55:22 by akharrou          #+#    #+#              #
#    Updated: 2019/05/15 08:28:31 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import sys

RED     = '\033[91m'
GREEN   = '\033[92m'
DEFAULT = '\033[0m'

# STATIC INPUT  — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

programA        =  'md5';
programB        =  './a';
programA_Flags  =  '-q';
# programB_Flags  =  '-s';

# DYNAMIC INPUT — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

# try:
# 	programA = os.environ["PROGRAM_A_NAME"]
# except Exception:
# 	programA = str(input("Program A Name: "))
# 	print(f"\nSet variable:\nexport PROGRAM_A_NAME='{programA}'")
# 	print('\n')

# try:
# 	programB = os.environ["PROGRAM_B_NAME"]
# except Exception:
# 	programB = str(input("Program B Name: "))
# 	print(f"\nSet variable:\nexport PROGRAM_B_NAME='{programB}'")
# 	print('\n')

# try:
# 	programA_Flags = os.environ["PROGRAM_A_FLAGS"]
# except Exception:
# 	programA_Flags = str(input(f"{programA} Flags: "))
# 	print(f"\nSet variable:\nexport PROGRAM_A_FLAGS='{programA_Flags}'")
# 	print('\n')

try:
	programB_Flags = os.environ["PROGRAM_B_FLAGS"]
except Exception:
	programB_Flags = str(input(f"{programB} Flags: "))
	print(f"\nSet variable:\nexport PROGRAM_B_FLAGS='{programB_Flags}'")
	print('\n')

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

total_args = len(sys.argv) - 1
width = len(str(total_args))
i = 0
total_trues = 0

argv = iter(sys.argv)
next(argv)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

print(f'================================================================================================================================================================')
print(f'|                                                                                                                                                              |')
print(f'|                                                     GENERAL PROGRAM OUTPUT UNIT-TESTER -- G.U.T                                                    |')
print(f'|                                                                                                                                                              |')
print(f'================================================================================================================================================================')

print('')
print(f' {f"—" * (157 + width)}')
print(f'| {"":{width}} |  {"INPUT:":60}|   {"PROGRAM A:":35}|   {"PROGRAM B:":35}|  {"IDENTICAL":11}|')
print(f'|-{"-" * width}-|{"-" * 62}|{"-" * 38}|{"-" * 38}|{"-" * 13}|')

launch_programA  =  f'{programA} {programA_Flags}'
launch_programB  =  f'{programB} {programB_Flags}'

with open("__output_A__", 'w+') as fd_A:
	with open("__output_B__", 'w+') as fd_B:

		for arg in argv:

			i += 1

			os.system(f'{launch_programA} "{arg}" > __output_A__')
			os.system(f'{launch_programB} "{arg}" > __output_B__')

			fd_A.seek(0)
			programA_output = fd_A.read().rstrip('\n')

			fd_B.seek(0)
			prgramB_output = fd_B.read().rstrip('\n')

			print(f"""| {i:0{width}} |  {f'"{arg}"':60}|   {programA_output:35}|   {prgramB_output:35}| """, end="")

			if (programA_output == prgramB_output):
				print(f'  {f"[{GREEN}TRUE{DEFAULT}]":19}|')
				total_trues += 1
			else:
				print(f'  {f"[{RED}FALSE{DEFAULT}]":18}|')

print(f'|{f"—" * (157 + width)}|')
print(f'[{total_trues} / {i}] identical outputs')
print('========================')
print('© akharrou 2019 -- ;D')
print('========================')

os.remove('__output_A__')
os.remove('__output_B__')

