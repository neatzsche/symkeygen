#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
glibc 2.30, Ubuntu 64bit
How to use password:
$ openssl enc -aes256 -k {PASSWORD} -in secret.txt -out secret.bin
*/

unsigned regs[4];
int program[] ={593920, 598016, 602112, 593920, 598016, 328196, 655360, 205573, 659456, 397327, 405517, 663552, 139523, 593920, 143618, 667648, 598016, 663552, 593920, 593920, 405509, 139523, 663552, 659456, 602112, 397317, 270595, 340480, 667648, 593920, 598016, 602112, 593920, 598016, 328196, 655360, 205573, 659456, 397327, 405517, 663552, 139523, 593920, 143618, 667648, 598016, 663552, 593920, 593920, 405509, 139523, 663552, 659456, 602112, 397317, 270595, 340480, 667648};
char stack[33] ="";
	
int pc = 0;

int ins = 0;
int reg1 = 0;
int reg2 = 0;
int reg3 = 0;
int imm = 0;

int fl = 0;
int sp = 0;


void decode(int instr)
{
  ins  = (instr & 0xF0000) >> 16;
  reg1 = (instr & 0xF000 ) >>  12;
  reg2 = (instr & 0xF00  ) >>  8;
  reg3 = (instr & 0xF   );
  imm  = (instr & 0xFF  );
}

int running = 1;

int fetch(){
	return program [pc++];
}

void eval()
{
	switch (ins)
	{
		case 0:
			//ret
			running = 0;	
			break;
		case 1:
			//pop
			regs[reg1] = (int)stack[sp--];
			fl = 0;
			break;
		case 2:
			//sub
			regs[reg1] = regs[reg2] - regs[reg3];
			fl = regs[reg1];
			break;
		case 3:
			//subimm
			regs[reg1] = regs[reg2] - imm;
			fl = regs[reg1];
			break;
		case 4:
			//add
			regs[reg1] = regs[reg2] + regs[reg3];
			fl = 0;
			break;
		case 5:
			//addimm
			regs[reg1] = regs[reg2] + imm;
			fl =0;
			break;
		case 6:
			//loadi
			regs[reg1] = imm;
			fl = 0;
		case 7:
			//jne
			if (fl != 0){
			pc = imm;
			}
			fl = 0;	
			break;
		case 8:
			//jmp
			pc = imm;
			fl =0;
			break;
		case 9:
			//rand
            regs[reg1] = ((rand() % 16) +70);
			break;
        case 10:
            //push
            stack[sp++] = (char)regs[reg1];
			fl = 0;
			
	}
}

int run(){
	while(running){
		int instr = fetch();	
		decode(instr);
		eval();
		}
	return imm;
}


int main (int argc, char **argv) {
   
	int i, n;
	time_t t;
    n = 32;
    
   for (int j =1655173080; j<1655173379; j++){   
       int pc = 0;

ins = 0;
reg1 = 0;
int reg2 = 0;
int reg3 = 0;
int imm = 0;

int fl = 0;
int sp = 0;
        t = (time_t) j;
        srand((unsigned) time(&t));
        run();
        printf("%s\n", stack); 

   return(0);
   }
}