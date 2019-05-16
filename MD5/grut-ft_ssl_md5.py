# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grut-ft_ssl_md5.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 09:55:22 by akharrou          #+#    #+#              #
#    Updated: 2019/05/15 14:39:47 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

try:

	import os
	import sys

	# COLORIZATION — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	RED        = '\033[31m'
	GREEN      = '\033[32m'
	BLUE       = '\033[94m'

	DEFAULT    = '\033[0m'
	ITALTIC    = '\033[3m'
	UNDELRINED = '\033[4m'
	BACKGROUND = '\033[0m'
	STRIPS     = BLUE

	# TITLES — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	FILENAME='grut-ft_ssl_md5.py'
	EDITION='ft_ssl_md5 Edition'

	# USAGE & MANUAL — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	def usage():
		print(f'usage: python3 {FILENAME} [-f {UNDELRINED}file{DEFAULT} ... | {UNDELRINED}input_argument{DEFAULT} ...]')
		sys.exit(1)

	def manual():
		print(f'{UNDELRINED}Coming soon...{DEFAULT}')
		sys.exit(1)

	# FLAG HANDLING — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	if (len(sys.argv) < 2        or
		sys.argv[1] == '-h'      or
		sys.argv[1] == '--help'  or
		sys.argv[1] == ''):

		usage()

	elif (sys.argv[1] == '-m'        or
		sys.argv[1] == '-man'      or
		sys.argv[1] == '-manual'   or
		sys.argv[1] == '--manual'):

		manual()

	elif (sys.argv[1] == '-f'):

		if (len(sys.argv[2:]) < 1):
			usage()

		try:

			arguments = []
			sys.argv = sys.argv[2:]
			for argsFile in sys.argv:

				try:

					with open(argsFile, 'r') as fd:
						arguments.extend(fd.readlines())

				except Exception:
					print('Invalid Input File')

		except Exception as e:
			usage()

	else:
		arguments = sys.argv[1:]

	# DYNAMIC INPUT — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	try:
		launch_command_programA = os.environ["LAUNCH_PROGRAM_A"]
	except Exception:
		launch_command_programA = str(input("[LAUNCH COMMAND -- Program_A] (w/out arguments): "))
		print(f"\nSet variable:\nexport LAUNCH_PROGRAM_A='{launch_command_programA}'")
		print('\n')

	try:
		launch_command_programB = os.environ["LAUNCH_PROGRAM_B"]
	except Exception:
		launch_command_programB = str(input("[LAUNCH COMMAND -- Program_B] (w/out arguments): "))
		print(f"\nSet variable:\nexport LAUNCH_PROGRAM_B='{launch_command_programB}'")
		print('\n')

	# HEADER — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	print(f'{STRIPS}{f"=" * (199)}')
	print(f'|{DEFAULT}{BACKGROUND}{f" " * (197)}{DEFAULT}{STRIPS}|')
	print(f'|{DEFAULT}{BACKGROUND}{f" " * (80)}⚜️  {DEFAULT}GENERALIZED RAMBO UNIT-TESTER ™️{DEFAULT}{BACKGROUND}  ⚜️{f" " * (80)}{DEFAULT}{STRIPS}|')
	print(f'|{DEFAULT}{BACKGROUND}{f" " * int(194 / 2 - int(len(EDITION) / 2))}~ {ITALTIC}{EDITION}{DEFAULT}{BACKGROUND} ~{f" " * (int(194 / 2 - int(len(EDITION) / 2)) - 1 - (len(EDITION) % 2))}{DEFAULT}{STRIPS}|')
	print(f'|{DEFAULT}{BACKGROUND}{f" " * (197)}{DEFAULT}{STRIPS}|')
	print(f'{STRIPS}{f"=" * (199)}{DEFAULT}')

	print(f'\nProgram A Launch Command: {launch_command_programA}')
	print(f'Program B Launch Command: {launch_command_programB}')
	print('')

	# BODY — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	FILE_A='__output_A__'
	FILE_B='__output_B__'

	def GRUTBody__ft_ssl_md5(program_A, program_B):

		i = 0
		total_trues = 0
		total_args = len(arguments)
		width = len(str(total_args))

		print(f' {f"—" * (197 + width)}')
		print(f'| {"":{width}} |  {"INPUT:":100}|   {"PROGRAM A:":35}|   {"PROGRAM B:":35}|  {"IDENTICAL":11}|')
		print(f'|-{"-" * width}-|{"-" * 102}|{"-" * 38}|{"-" * 38}|{"-" * 13}|')

		with open(f"{FILE_A}", 'w+') as fd_A:
			with open(f"{FILE_B}", 'w+') as fd_B:

				for arg in arguments:

					arg = arg.strip('\n').replace('\t', '    ')

					i += 1
					os.system(f'{program_A} "{arg}" > {FILE_A}')
					os.system(f'{program_B} "{arg}" > {FILE_B}')

					fd_A.seek(0)
					programA_output = fd_A.readline().rstrip('\n')

					fd_B.seek(0)
					programB_output = fd_B.readline().rstrip('\n')

					print(f"""| {i:0{width}} |  {f'"{arg}"':100}|   {programA_output:35}|   {programB_output:35}| """, end="")

					if (programA_output == programB_output):
						print(f'  {f"[{GREEN}TRUE{DEFAULT}]":19}|')
						total_trues += 1
					else:
						print(f'  {f"[{RED}FALSE{DEFAULT}]":19}|')

		print(f'|{f"—" * (197 + width)}|')
		print(f'[{total_trues} / {i}] identical outputs ‼️ ')

		os.remove(f'{FILE_A}')
		os.remove(f'{FILE_B}')


	GRUTBody__ft_ssl_md5(launch_command_programA, launch_command_programB)

	# FOOTER — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — #

	print(f'️\n{UNDELRINED}Share if you found it useful !{DEFAULT} :: G.R.U.T -- © 2019 akharrou 🤩')
	print('')

except Exception as e:
	print(f'{UNDELRINED}\n\n🚨  Please Report the Issue ! 🚨{DEFAULT}  :: G.R.U.T -- © 2019 akharrou 😓\n\n')
	print(f'{UNDELRINED}GRUT ISSUE:{DEFAULT} (copy paste and report (or dm me @akharrou) the issue)\n{ITALTIC}')
	raise e
