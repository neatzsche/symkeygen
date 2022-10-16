ins = [
	#
	"rnd 1",
	"rnd 2",
	"rnd 3",
	"rnd 1",
	"rnd 2",
	"addimm 0 2 4",
	"push 0",
	"subimm 2 3 5",
	"push 1",
	"loadi 1 15",
	"loadi 3 13",
	"push 2",
	"sub 2 1 3",
	"rnd 1",
	"sub 3 1 2",
	"push 3",
	"rnd 2",
	"push 2",
	"rnd 1",
	"rnd 1",
	"loadi 3 5",
	"sub 2 1 3",
	"push 2",
	"push 1",
	"rnd 3",
	"loadi 1 5",
	"add 2 1 3",
	"addimm 3 2 0",
	"push 3",
	"rnd 1",
	"rnd 2",
	"rnd 3",
	"rnd 1",
	"rnd 2",
	"addimm 0 2 4",
	"push 0",
	"subimm 2 3 5",
	"push 1",
	"loadi 1 15",
	"loadi 3 13",
	"push 2",
	"sub 2 1 3",
	"rnd 1",
	"sub 3 1 2",
	"push 3",
	"rnd 2",
	"push 2",
	"rnd 1",
	"rnd 1",
	"loadi 3 5",
	"sub 2 1 3",
	"push 2",
	"push 1",
	"rnd 3",
	"loadi 1 5",
	"add 2 1 3",
	"addimm 3 2 0",
	"push 3",


]



cins=[]
xins=[]

def compile_string (instruction):
	op = 0
	reg1 = 0
	reg2 = 0
	reg3 = 0
	ops = instruction.split(" ")	
	print (ops)
	if(ops[0] == "ret"):
		reg3 = ops[1]
	elif(ops[0] == "pop"):
		op = 1
		reg1 = ops[1]
	elif(ops[0] == "sub"):
		op = 2
		reg1 = ops[1]
		reg2 = ops[2]
		reg3 = ops[3]
	elif(ops[0] == "subimm"):
		op = 3
		reg1 = ops[1]
		reg2 =  ops[2]
		reg3 = ops[3]
	elif(ops[0] == "add"):
		op =4
		reg1 = ops[1]
		reg2 = ops[2]
		reg3 = ops[3]
	elif(ops[0] == "addimm"):
		op = 5
		reg1 = ops[1]
		reg2 = ops[2]
		reg3 = ops[3]
	elif(ops[0] == "loadi"):
		op = 6
		reg1 = ops[1]
		reg3 =  ops[2]
	elif(ops[0] == "jne"):
		op = 7
		reg3 =  ops[1]
	elif(ops[0] == "jmp"):
		op = 8
		reg3 =  ops[1]
	elif(ops[0] == "rnd"):    
		op = 9
		reg1 = ops[1]
	elif(ops[0] == "push"):
		op = 10
		reg1 = ops[1]

		
	cin = (op << 16) + (int(reg1) << 12) + (int(reg2) << 8) + int(reg3)
	return cin


for instruction in ins:
	cins.append(compile_string(instruction))




print(cins)