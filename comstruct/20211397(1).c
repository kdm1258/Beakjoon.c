//////////////////////////////님아 S SB UJ타입 테스트 해야댐
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int reg[32]; 
int pc;
int Mem[1024];
FILE *output;
void R_typeInst(int,int,int,int,int,int);
int Add(int, int, int);
int Sub(int, int, int);
int And(int, int, int);
int Or(int, int, int);
int Xor(int, int, int);
int Sll(int, int, int);
int Srl(int, int, int);
int Sra(int, int, int);
void I_typeInst(int,int,int,int,int);
int Addi(int, int, int);
int Andi(int, int, int);
int Ori(int, int, int);
int Xori(int, int, int);
int Slli(int, int, int);
int Srli(int, int, int);
int Srai(int, int, int);
int Lw(int, int, int);
int Jalr(int, int, int);
void S_typeInst(int, int, int, int, int);
int Sw(int, int, int);
void SB_typeInst(int, int, int, int, int);
int Beq(int, int, int);
int Bne(int, int, int);
int Bge(int, int, int);
int Blt(int, int, int);
void UJ_typeInst(int, int, int);
int Jal(int, int);
void Make_Binary(int val){
	for(int i= 31 ; i>= 0 ;i--){
		printf("%d",(val>>i)&1);
	}
		printf("\n");
}
void Inst_Class(char *line){
	char *token;
	char oper[50];  //연산자 배열
	char operand1[50], operand2[50], operand3[50];
	//토큰화 및 연산자 입력
	/*
	token = strtok(line," \t,");
	if(token != NULL){
		for(int i = 0 ; token[i] ; i++){
			oper[i] = tolower(token[i]);
		}
	}*/
	sscanf(line, "%s %[^,], %[^,(] %*[,(] %[^)\n]", oper, operand1, operand2, operand3);
	for(int i = 0 ; oper[i] ; i++) oper[i] = tolower(oper[i]);
	printf("%s %s %s %s\n",oper, operand1, operand2, operand3);
	
	//연산자별 기계어 변환
	//R-type
	if (!(strcmp(oper,"add"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Add(rd,rs1,rs2);
	}
	else if(!(strcmp(oper,"sub"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sub(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"and"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		And(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"or"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Or(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"xor"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Xor(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"sll"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sll(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"srl"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Srl(rd, rs1, rs2);
	}
	else if(!(strcmp(oper,"sra"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sra(rd, rs1, rs2);
	}
	//I-type
	else if(!(strcmp(oper,"addi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Addi(rd,rs1,imm12);
	}
	else if(!(strcmp(oper,"andi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Andi(rd,rs1,imm12);
	}
	else if(!(strcmp(oper,"ori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Ori(rd,rs1,imm12);
	}
	else if(!(strcmp(oper,"xori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Xori(rd,rs1,imm12);
	}
	else if(!(strcmp(oper,"slli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Slli(rd,rs1,shamt);
	}
	else if(!(strcmp(oper,"srli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srli(rd,rs1,shamt);
	}
	else if(!(strcmp(oper,"srai"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srai(rd,rs1,shamt);
	}
	else if(!(strcmp(oper,"lw"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Lw(rd,rs1,imm12);
	}
	else if(!(strcmp(oper,"jalr"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Jalr(rd,rs1,imm12);
	}
	//S-type
	else if(!(strcmp(oper,"sw"))){
		int rs2 = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Sw(rs1, rs2, imm12);
	}
	//SB-type
	else if(!(strcmp(oper,"beq"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Beq(rs1, rs2, imm12);
	}
	else if(!(strcmp(oper,"bne"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Bne(rs1, rs2, imm12);
	}
	else if(!(strcmp(oper,"bge"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Bge(rs1, rs2, imm12);
	}
	else if(!(strcmp(oper,"blt"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Blt(rs1, rs2, imm12);
	}
	//UJ-type
	else if(!(strcmp(oper,"jal"))){
		int rd = atoi(&operand1[1]);
		int imm20 = atoi(&operand2[0]);
		Jal(rd, imm20);
	}

}
///////////////////////////////////////////////////////// R-type Inst//////////////////////////////////////////////////////////////////
void R_typeInst(int rd, int rs1, int rs2, int opcode, int func3, int func7){
	unsigned int outinst = (func7)<<25 | (rs2<<20) | (rs1<<15) | (func3<<12) | (rd<<7) | opcode;
	Make_Binary(outinst);
	fwrite(&outinst, sizeof(outinst), 1, output);
}
int Add(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b000;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] + reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Sub(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b000;
	const int func7 = 0b0100000;
	reg[rd] = reg[rs1] - reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int And(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b111;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] & reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Or(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b110;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] | reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Xor(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b100;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] ^ reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Sll(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b001;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] << reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Srl(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b101;
	const int func7 = 0b0000000;
	reg[rd] = (unsigned)reg[rs1] >> reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
int Sra(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b101;
	const int func7 = 0b0100000;
	reg[rd] = reg[rs1] >> reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
///////////////////////////////////////////////////////// I-type Inst//////////////////////////////////////////////////////////////////
void I_typeInst(int rd, int rs1, int opcode, int func3, int imm12){
	unsigned int outinst = (imm12<<20) | (rs1<<15) | (func3<<12) | (rd<<7) | opcode;
	Make_Binary(outinst);
	fwrite(&outinst, sizeof(outinst), 1, output);
}
int Addi(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b000;
	reg[rd] = reg[rs1] + imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
int Andi(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b111;
	reg[rd] = reg[rs1] & imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
int Ori(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b110;
	reg[rd] = reg[rs1] | imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
int Xori(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b100;
	reg[rd] = reg[rs1] ^ imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
int Slli(int rd, int rs1, int shamt){
	if (shamt>31){ printf("Syntax Error!!\n"); return 0;}
	const int opcode = 0b0010011;
	const int func3 = 0b001;
	reg[rd] = reg[rs1] << shamt;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
int Srli(int rd, int rs1, int shamt){
	const int opcode = 0b0010011;
	const int func3 = 0b101;
	reg[rd] = (unsigned)reg[rs1] >> shamt;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
int Srai(int rd, int rs1, int shamt){
	const int opcode = 0b0010011;
	const int func3 = 0b101;
	reg[rd] = reg[rs1] >> shamt;
	shamt = shamt | 0b010000000000;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
int Lw(int rd, int rs1, int imm12){
	const int opcode = 0b0000011;
	const int func3 = 0b010;
	reg[rd] = Mem[reg[rs1] + imm12];
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
int Jalr(int rd, int rs1, int imm12){
	const int opcode = 0b1100111;
	const int func3 = 0b000;
	if(rd!=0){reg[rd] = pc + 4 ;} //rd = x0일때는 리턴주소저장x
	pc = (reg[rs1] + imm12) & (~1);
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
///////////////////////////////////////////////////////// S-type Inst//////////////////////////////////////////////////////////////////
void S_typeInst(int rs1, int rs2, int opcode, int func3, int imm12){
	int imm11_5 = imm12>>5;
	int imm4_0 = imm12 & 0b11111;
	unsigned int outinst = (imm11_5<<25) | (rs2<<20) | (rs1<<15) | (func3<<12) | (imm4_0<<7) | opcode;
	Make_Binary(outinst);
	fwrite(&outinst, sizeof(outinst), 1, output);
}
int Sw(int rs1, int rs2, int imm12){
	const int opcode = 0b0100011;
	const int func3 = 0b010;
	Mem[reg[rs1] + imm12] = reg[rs2];
	printf("%d %d %d\n",reg[rs1],reg[rs2], imm12);
	S_typeInst(rs1, rs2, opcode, func3, imm12);
}
///////////////////////////////////////////////////////// SB-type Inst//////////////////////////////////////////////////////////////////
void SB_typeInst(int rs1, int rs2, int opcode, int func3, int imm12){
	imm12 = imm12>>1;
	int imm_12 = imm12 >> 11;
	int imm_11 = imm12 & 0b10000000000; imm_11 = imm_11 >> 10;
	int imm10_5 = imm12 & 0b01111110000; imm10_5 = imm10_5 >> 4;
	int imm4_1 = imm12 & 0b00000001111;
	unsigned int outinst = (imm_12<<31) | (imm10_5<<25) | (rs2<<20) | (rs1<<15) | (func3<<12) | (imm4_1<<8) | (imm_11<<7) | opcode;
	Make_Binary(outinst);
	fwrite(&outinst, sizeof(outinst), 1, output);
}
int Beq(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b000;
	if(reg[rs1] == reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
int Bne(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b001;
	if(reg[rs1] != reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
int Bge(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b101;
	if(reg[rs1] >= reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
int Blt(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b100;
	if(reg[rs1] < reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
///////////////////////////////////////////////////////// UJ-type Inst//////////////////////////////////////////////////////////////////
void UJ_typeInst(int rd, int opcode, int imm20){
	imm20 = imm20>>1;
	int imm_20 = imm20 >> 19;
	int imm_11 = imm20 & 0b10000000000; imm_11 = imm_11 >> 10;
	int imm19_12 = imm20 & 0b1111111100000000000; imm19_12 >> 11;
	int imm10_1 = imm20 $0b1111111111;
	unsigned int outinst = (imm_20<<31) | (imm10_5<<21) | (imm_11<<20) | (imm19_12<<12) | (rd<<7) | opcode;
	Make_Binary(outinst);
	fwrite(&outinst, sizeof(outinst), 1, output);
}
int Jal(int rd, int imm20){////////////////imm20에 함수명드간거 구현해라
	const int opcode = 0b1101111;
	if(rd!=0){reg[rd] = pc + 4 ;} //rd = x0일때는 리턴주소저장x
	pc = pc + imm20;
	printf("%d %d\n",reg[rd], imm20);
	UJ_typeInst(rd, opcode, imm20);
}

int main(void){
	FILE *input;
	char input_filename[256];
	char output_filename[256];
	char line[256];

	//*.s file 한줄씩 불러오기
	while(1){
		printf("Enter Input File Name: ");
		scanf("%s", input_filename);
		if(!strcmp(input_filename, "terminate")){
			return 0;
		}
		input = fopen(input_filename, "r");

		if(input == NULL){
			printf("Input file does not exist!!\n");
			continue;
		}
		for(int i = 1 ; i<=6 ; i++) reg[i] = i; //register x1~x6 초기화

		strncpy(output_filename,input_filename, strlen(input_filename)-2);
		output_filename[strlen(input_filename)-2] = '\0';
		strcat(output_filename, ".o");
		output = fopen(output_filename, "wb");
		while (fgets(line, sizeof(line),input) != NULL){
			Inst_Class(line);
		}
		fclose(input);
		fclose(output);
	}
}
