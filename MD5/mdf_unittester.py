# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mdf_unittester.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 09:55:22 by akharrou          #+#    #+#              #
#    Updated: 2019/05/14 12:43:43 by akharrou         ###   ########.fr        #
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
# programA_Flags  =  '-q';
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

try:
	programA_Flags = os.environ["PROGRAM_A_FLAGS"]
except Exception:
	programA_Flags = str(input(f"{programA} Flags: "))
	print(f"\nSet variable:\nexport PROGRAM_A_FLAGS='{programA_Flags}'")
	print('\n')

try:
	programB_Flags = os.environ["PROGRAM_B_FLAGS"]
except Exception:
	programB_Flags = str(input(f"{programB} Flags: "))
	print(f"\nSet variable:\nexport PROGRAM_B_FLAGS='{programB_Flags}'")
	print('\n')

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

print(f'===========================================================================================================================================================')
print(f'|                                                                                                                                                         |')
print(f'|                                                GENERAL PROGRAM OUTPUT UNIT-TESTER -- © akharrou 2019                                                    |')
print(f'|                                                                                                                                                         |')
print(f'===========================================================================================================================================================')

print('')
print(f' ——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————')
print(f'|  {"INPUT:":60}|   {"PROGRAM A OUTPUT:":35}|   {"PROGRAM B OUTPUT:":35}|  {"IDENTICAL":11}|')
print(f'|--------------------------------------------------------------|--------------------------------------|--------------------------------------|-------------|')

argv = iter(sys.argv)
next(argv)

launch_programA  =  f'{programA} {programA_Flags}'
launch_programB  =  f'{programB} {programB_Flags}'

total_tests = 0
total_trues = 0

with open("__output_A__", 'w+') as fd_A:
	with open("__output_B__", 'w+') as fd_B:

		for arg in argv:

			total_tests += 1

			os.system(f'{launch_programA} "{arg}" > __output_A__')
			os.system(f'{launch_programB} "{arg}" > __output_B__')

			fd_A.seek(0)
			programA_output = fd_A.read().rstrip('\n')

			fd_B.seek(0)
			prgramB_output = fd_B.read().rstrip('\n')

			print(f"""|  {f'"{arg}"':60}|   {programA_output:35}|   {prgramB_output:35}| """, end="")

			if (programA_output == prgramB_output):
				print(f'  {f"[{GREEN}TRUE{DEFAULT}]":19}|')
				total_trues += 1
			else:
				print(f'  {f"[{RED}FALSE{DEFAULT}]":18}|')

print(f' ——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————')
print('')
print(f'RESULT: [{total_trues} / {total_tests}]')
print(f'Thank you for using')

os.remove('__output_A__')
os.remove('__output_B__')
