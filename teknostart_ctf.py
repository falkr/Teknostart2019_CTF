#!/usr/bin/python3
# -*- coding: utf-8 -*-
#Halvor Groven
import sys 
import hashlib
import getopt

current_level = "" 
next_level = ""
taskdict={}
taskslist=[]

def setup():

	global current_level
	global tasks
	global next_level

	#Get opts and do action
	get_opts()

	#Get saved progress
	with open(".level", "r") as level:
		current_level=level.readline().splitlines()[0]
		next_level=str(int(current_level)+1)
	level.close()
	

	#Get current question
	with open(".tasks", 'r') as tasks:
		for line in tasks:
			li = line.strip()
			if not li.startswith("#") and li.strip():
				taskslist.append(li.split(";"))
	for i in taskslist:
		taskdict[str(taskslist.index(i)+1)]=i
	tasks.close()

	#Check if the user has finished all the questions
	if check_finished(current_level, len(taskdict)):
		sys.exit()

def queryuser():
	
	global taskdict
	global current_level
	global next_level

	#Setup variables for current level
	delimeter_string = "\n"+"-"*40+"\n"
	level = taskdict[current_level][0]
	nextlevel = next_level
	question = taskdict[current_level][1]
	correcthash = taskdict[current_level][2]
	example = taskdict[current_level][3]
	levelchecker_needed = taskdict[current_level][4]
	


	#Query the user for an answer
	if len(sys.argv)<2:
		answer="None"
	else:
		answer=str(sys.argv[1])
	print("CURRENT LEVEL: level " + current_level)
	print(delimeter_string)
	print(question+"\n")
	print("%-20s %-20s" %("Example answer:",example))
	print("%-20s %-20s" %("Answer given:",answer))
	answerhash = hashlib.sha256(answer.encode("utf-8")).hexdigest()
	print("%-20s %-20s" %("Hash of answer: ",answerhash))
	print("%-20s %-20s" %("Correct hash:",correcthash))
	if (levelchecker_needed == "true"):
		print("%-20s %-20s" %("Levelchecker:","YES"))
	else: 
		print("%-20s %-20s" %("Levelchecker:","NO"))
	print(delimeter_string)
	
	
	#Check the answer against hash in .task file
	if answerhash == correcthash:
		with open(".level",'w') as levelfile:
			levelfile.write(nextlevel)
		levelfile.close()
		if (check_finished(nextlevel, len(taskdict))):
			sys.exit()
		print("Congratulations, you have been promoted to the next level!\n")
		next_questionprint(nextlevel)
		


def check_finished(current_level, number_of_levels):
	if int(current_level) > number_of_levels:
		print("Congratulations, you finished the game!\nYou can reset the game by running './teknostart_ctf.py --reset'")
		return True

def reset():
	with open(".level",'w') as reset:
		reset.write('1')	
	reset.close()
	print("\nReset completed successfully, you may now play the game again.\n")
	sys.exit()
	return

def help_pls():
	print("\nUsage: ./teknostart_ctf.py [argument]\n\nArguments:\n\n<answer>\tYour answer\n-h, --help\t Display help message and exit\n-r, --reset\tReset the game to level 1\n\n")
	sys.exit()
	return
	
def get_opts():
	argv=sys.argv[1:]
	try:
		opts, args = getopt.getopt(argv, "rh",["reset","help"])
	
		for opt, args in opts:
			if opt in ('-r','--reset'):
				reset()
			elif opt in ('-h','--help'):
				help_pls()
	except getopt.GetoptError:
		help_pls()

def next_questionprint(current_level):
	delimeter_string = "\n"+"-"*40+"\n"
	level = taskdict[current_level][0]
	nextlevel = next_level
	question = taskdict[current_level][1]
	correcthash = taskdict[current_level][2]
	example = taskdict[current_level][3]
	levelchecker_needed = taskdict[current_level][4]

	print("LEVEL: level " + current_level)
	print(delimeter_string)
	print(question+"\n")
	print("%-20s %-20s" %("Example answer:",example))
	print("%-20s %-20s" %("Correct hash:",correcthash))
	if (levelchecker_needed == "true"):
		print("%-20s %-20s" %("Levelchecker:","YES"))
	else: 
		print("%-20s %-20s" %("Levelchecker:","NO"))
	print(delimeter_string)





setup()
queryuser()
