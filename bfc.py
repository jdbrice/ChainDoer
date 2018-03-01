from subprocess import call
from sys import argv
import os


if len( argv ) < 5 :
	exit()

print "exe :", argv[0]
print "chain Opts :", argv[1]
print "inFile: ", argv[2]
print "jobIndex:", argv[3]
print "jobName: ", argv[4]

chain = argv[1]
infile = argv[2]
jobIndex = int(argv[3])
jobName = argv[4]

if len( argv ) >= 6 :
	nEvents = int(argv[5])
else :
	nEvents = 5000

print "nEvents", nEvents

outfile = "out_" + jobName
logfile = "log_" + jobName

command = "\'$STAR/StRoot/macros/bfc.C({a}, \"{chain}\", \"{inf}\", \"{outf}\")\'".format( a=nEvents, chain=chain, inf=infile, outf=outfile )

print command
os.system( " root4star -b -q -l " + command )




