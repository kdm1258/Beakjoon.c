//////////////////////////////님아 S UJ타입 테스트 해야댐 exit만들기 sra srai함보기 에러처리 trace 파일 만들기  .o도 어케 확인해봐봐
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//label저장 구조체
typedef struct{
	char label[32];
	int address;
}  LabelTable;
LabelTable labels[1010];
//Instruct 저장 구조체
typedef struct{
	char oper[50];
	char operand1[50];
	char operand2[50];
	char operand3[50];
	//int address;
} InstTable;

char output_filename[256];
InstTable insts[10101];
int insts_cnt = 0;
int label_cnt = 0;
int pc = 1000;
int reg[32]; 
int Mem[1024];
FILE *output;
void R_typeInst(int,int,int,int,int,int);
void Add(int, int, int);
void Sub(int, int, int);
void And(int, int, int);
void Or(int, int, int);
void Xor(int, int, int);
void Sll(int, int, int);
void Srl(int, int, int);
void Sra(int, int, int);
void I_typeInst(int,int,int,int,int);
void Addi(int, int, int);
void Andi(int, int, int);
void Ori(int, int, int);
void Xori(int, int, int);
void Slli(int, int, int);
void Srli(int, int, int);
void Srai(int, int, int);
void Lw(int, int, int);
void Jalr(int, int, int);
void S_typeInst(int, int, int, int, int);
void Sw(int, int, int);
void SB_typeInst(int, int, int, int, int);
void Beq(int, int, int);
void Bne(int, int, int);
void Bge(int, int, int);
void Blt(int, int, int);
void UJ_typeInst(int, int, int);
void Jal(int, const char[50]);
//label Table 추가 함수
void add_label(const char *label, int address){
	strcpy(labels[label_cnt].label, label);
	labels[label_cnt].address = address;
	label_cnt++;
}
//label Table 검색 함수
int find_label(const char *label){
	char label1[50] = {0};
	for(int i = 0 ; label[i] ; i++){
		label1[i] = tolower(label[i]);
	}
	for(int i = 0 ; i < label_cnt ; i++){
		if(strcmp(labels[i].label, label1) == 0) return labels[i].address;
	}
	return -1;
}
//instTable 추가함수
void add_inst(char oper[50], char operand1[50], char operand2[50], char operand3[50]){
	strcpy(insts[insts_cnt].oper, oper);
	strcpy(insts[insts_cnt].operand1, operand1);
	strcpy(insts[insts_cnt].operand2, operand2);
	strcpy(insts[insts_cnt].operand3, operand3);
	
	if (!(strcmp(oper,"add"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);	
		Add(rd,rs1,rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sub"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sub(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"and"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		And(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"or"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Or(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"xor"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Xor(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sll"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sll(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"srl"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Srl(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sra"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sra(rd, rs1, rs2);
		return 0;
	}
	//I-type
	else if(!(strcmp(oper,"addi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Addi(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"andi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Andi(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"ori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Ori(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"xori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Xori(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"slli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		
		//if (shamt>31){ return 1;}//shamt는 최대 31
		Slli(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"srli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srli(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"srai"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srai(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"lw"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Lw(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"jalr"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Jalr(rd,rs1,imm12);
		return 0;
	}
	//S-type
	else if(!(strcmp(oper,"sw"))){
		int rs2 = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Sw(rs1, rs2, imm12);
		return 0;
	}
	//SB-type
	else if(!(strcmp(oper,"beq"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Beq(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"bne"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Bne(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"bge"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Bge(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"blt"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Blt(rs1, rs2, imm12);
		return 0;
	}
	//UJ-type
	else if(!(strcmp(oper,"jal"))){
		int rd = atoi(&operand1[1]);
		Jal(rd, operand3);
		return 0;
	}
	//Exit
	else if(!(strcmp(oper,"exit"))){
		fprintf(output, "11111111111111111111111111111111\n");	
		return -1;
	}
	return 1;	
	
	insts_cnt++;
}
void Make_Binary(int val, FILE *output) { // 파일 포인터를 인자로 받음
    for (int i = 31; i >= 0; i--) {
        fprintf(output, "%d", (val >> i) & 1); // 출력 파일로 이진수 기록
    }
    fprintf(output, "\n");
}
//file 파싱,  label list, Inst list 추가
void parse_line(const char *line){
	char tmp[256] = {0};
	char label[50] = {0};	//label
	char oper[50] = {0};  //연산자 배열
	char operand1[50] = {0};
	char operand2[50] = {0};
	char operand3[50] = {0};
	strcpy(tmp, line);

	//공백제거
	char *token = strtok(tmp," \t\n");
	if (!token) return;
	
	//token의 마지막 문자가 :일 경우 label로 인식
	if(token[strlen(token)-1]==':'){
		strncpy(label, token, strlen(token)-1);
		for(int i = 0 ; label[i] ; i++){ 
			label[i] = tolower(label[i]);
		}
		add_label(label, pc);
		printf("Label : %s Add : %d\n",labels[label_cnt-1].label, labels[label_cnt-1].address);
		return;
	}
	//label이 아닌경우 instruct Table에 저장
	if (token != NULL){
		for(int i = 0 ; token[i] ; i++){
			oper[i] = tolower(token[i]);
		}
		if(!strcmp(oper, "exit")){
			add_inst(oper,operand1, operand2, operand3);
		}
		else{
			token = strtok(NULL, " \t\n,()");
			strcpy(operand1, token);
			token = strtok(NULL, " \t\n,()");
			strcpy(operand2, token);
			token = strtok(NULL, " \t\n,()");
			strcpy(operand3, token);
			add_inst(oper, operand1, operand2, operand3);
		}
		pc+=4;	//label저장시 address얻기 위함 
	}
	//printf("//%s : %s : %s : %s//\n",oper, operand1, operand2, operand3);
}
int inst_calc(const InstTable instTable){
	char oper[50]= {0}; strcpy(oper,instTable.oper);
	char operand1[50] = {0}; strcpy(operand1, instTable.operand1);
	char operand2[50] = {0}; strcpy(operand2, instTable.operand2);
	char operand3[50] = {0}; strcpy(operand3, instTable.operand3);
	//연산자별 기계어 변환
	//R-type
	if (!(strcmp(oper,"add"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);	
		reg[rd] = reg[rs1] + reg[rs2];
		printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
		pc += 4;
		//Add(rd,rs1,rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sub"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		reg[rd] = reg[rs1] - reg[rs2];
		printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
		pc+=4;
		//Sub(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"and"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		And(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"or"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Or(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"xor"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Xor(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sll"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sll(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"srl"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Srl(rd, rs1, rs2);
		return 0;
	}
	else if(!(strcmp(oper,"sra"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int rs2 = atoi(&operand3[1]);
		Sra(rd, rs1, rs2);
		return 0;
	}
	//I-type
	else if(!(strcmp(oper,"addi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Addi(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"andi"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Andi(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"ori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Ori(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"xori"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Xori(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"slli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		
		//if (shamt>31){ return 1;}//shamt는 최대 31
		Slli(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"srli"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srli(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"srai"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int shamt = atoi(&operand3[0]);
		Srai(rd,rs1,shamt);
		return 0;
	}
	else if(!(strcmp(oper,"lw"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Lw(rd,rs1,imm12);
		return 0;
	}
	else if(!(strcmp(oper,"jalr"))){
		int rd = atoi(&operand1[1]);
		int rs1 = atoi(&operand2[1]);
		int imm12 = atoi(&operand3[0]);
		Jalr(rd,rs1,imm12);
		return 0;
	}
	//S-type
	else if(!(strcmp(oper,"sw"))){
		int rs2 = atoi(&operand1[1]);
		int rs1 = atoi(&operand3[1]);
		int imm12 = atoi(&operand2[0]);
		Sw(rs1, rs2, imm12);
		return 0;
	}
	//SB-type
	else if(!(strcmp(oper,"beq"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Beq(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"bne"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Bne(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"bge"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Bge(rs1, rs2, imm12);
		return 0;
	}
	else if(!(strcmp(oper,"blt"))){
		int rs1 = atoi(&operand1[1]);
		int rs2 = atoi(&operand2[1]);
		int label_address = find_label(operand3);
		
	printf("///label pc : %d\n", label_address);
		 if (label_address == -1) { // 라벨이 없으면 에러 처리
        		return 1;
    		}
    		
		int imm12 = label_address - pc;
		Blt(rs1, rs2, imm12);
		return 0;
	}
	//UJ-type
	else if(!(strcmp(oper,"jal"))){
		int rd = atoi(&operand1[1]);
		Jal(rd, operand3);
		return 0;
	}
	//Exit
	else if(!(strcmp(oper,"exit"))){
		fprintf(output, "11111111111111111111111111111111\n");	
		return -1;
	}
	return 1;	//해당하는 명령어 없을 시 에러 code = 1

}
///////////////////////////////////////////////////////// R-type Inst//////////////////////////////////////////////////////////////////
void R_typeInst(int rd, int rs1, int rs2, int opcode, int func3, int func7){
	unsigned int outinst = (func7)<<25 | (rs2<<20) | (rs1<<15) | (func3<<12) | (rd<<7) | opcode;
	Make_Binary(outinst, output);
}
void Add(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b000;
	const int func7 = 0b0000000;
	pc+=4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);

}
void Sub(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b000;
	const int func7 = 0b0100000;
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void And(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b111;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] & reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void Or(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b110;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] | reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void Xor(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b100;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] ^ reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void Sll(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b001;
	const int func7 = 0b0000000;
	reg[rd] = reg[rs1] << reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void Srl(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b101;
	const int func7 = 0b0000000;
	reg[rd] = (unsigned)reg[rs1] >> reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
void Sra(int rd, int rs1, int rs2){
	const int opcode = 0b0110011;
	const int func3 = 0b101;
	const int func7 = 0b0100000;
	reg[rd] = reg[rs1] >> reg[rs2];
	printf("%d %d %d\n",reg[rd],reg[rs1],reg[rs2]);
	pc += 4;
	R_typeInst(rd, rs1, rs2, opcode, func3, func7);
}
///////////////////////////////////////////////////////// I-type Inst//////////////////////////////////////////////////////////////////
void I_typeInst(int rd, int rs1, int opcode, int func3, int imm12){
	unsigned int outinst = (imm12<<20) | (rs1<<15) | (func3<<12) | (rd<<7) | opcode;
	Make_Binary(outinst, output);
	//fwrite(&outinst, sizeof(outinst), 1, output);

}
void Addi(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b000;
	reg[rd] = reg[rs1] + imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
void Andi(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b111;
	reg[rd] = reg[rs1] & imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
void Ori(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b110;
	reg[rd] = reg[rs1] | imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
void Xori(int rd, int rs1, int imm12){
	const int opcode = 0b0010011;
	const int func3 = 0b100;
	reg[rd] = reg[rs1] ^ imm12;
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
void Slli(int rd, int rs1, int shamt){
	const int opcode = 0b0010011;
	const int func3 = 0b001;
	reg[rd] = reg[rs1] << shamt;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
void Srli(int rd, int rs1, int shamt){
	const int opcode = 0b0010011;
	const int func3 = 0b101;
	reg[rd] = (unsigned)reg[rs1] >> shamt;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
void Srai(int rd, int rs1, int shamt){
	const int opcode = 0b0010011;
	const int func3 = 0b101;
	reg[rd] = reg[rs1] >> shamt;
	printf("%d %d %d\n",reg[rd],reg[rs1], shamt);
	shamt = shamt | 0b010000000000;
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, shamt);
}
void Lw(int rd, int rs1, int imm12){
	const int opcode = 0b0000011;
	const int func3 = 0b010;
	reg[rd] = Mem[reg[rs1] + imm12];
	printf("%d %d %d\n",reg[rd],reg[rs1], imm12);
	pc += 4;
	I_typeInst(rd, rs1, opcode, func3, imm12);
}
void Jalr(int rd, int rs1, int imm12){
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
	Make_Binary(outinst, output);
	//fwrite(&outinst, sizeof(outinst), 1, output);
}
void Sw(int rs1, int rs2, int imm12){
	const int opcode = 0b0100011;
	const int func3 = 0b010;
	Mem[reg[rs1] + imm12] = reg[rs2];
	printf("%d %d %d\n",reg[rs1],reg[rs2], imm12);
	pc += 4;
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
	Make_Binary(outinst, output);
	//fwrite(&outinst, sizeof(outinst), 1, output);
}
void Beq(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b000;
	if(reg[rs1] == reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	//SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
void Bne(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b001;
	if(reg[rs1] != reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
void Bge(int rs1, int rs2, int imm12){
	const int opcode = 0b1100011;
	const int func3 = 0b101;
	if(reg[rs1] >= reg[rs2]){pc += imm12;}
	else {pc += 4;}
	printf("%d %d %d\n",reg[rs1], reg[rs2], imm12);
	SB_typeInst(rs1, rs2, opcode, func3, imm12);
}
void Blt(int rs1, int rs2, int imm12){
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
	int imm10_1 = imm20 & 0b1111111111;
	unsigned int outinst = (imm_20<<31) | (imm10_1<<21) | (imm_11<<20) | (imm19_12<<12) | (rd<<7) | opcode;
	Make_Binary(outinst, output);
	//fwrite(&outinst, sizeof(outinst), 1, output);
}
void Jal(int rd, const char label[50]){////////////////그 rd가 0아니면 어케함
	int imm20 = find_label(label) - pc;
	const int opcode = 0b1101111;
	if(rd!=0){reg[rd] = pc + 4 ;} //rd = x0일때는 리턴주소저장x
	pc = pc + imm20;
	printf("%d %d\n",reg[rd], imm20);
	UJ_typeInst(rd, opcode, imm20);
}

int main(void){
	FILE *input;
    	FILE *trace_file; // .trace 파일 포인터
	char input_filename[256];
	char trace_filename[256];
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

		memset(labels, 0, sizeof(labels));
		memset(insts, 0, sizeof(insts));
		memset(reg, 0, sizeof(reg));
		memset(Mem, 0, sizeof(Mem));
		insts_cnt = 0;
		label_cnt = 0;
		pc = 1000;
		for(int i = 1 ; i<=6 ; i++) reg[i] = i; //register x1~x6 초기화
		
		// .o 파일 생성
		strncpy(output_filename,input_filename, strlen(input_filename)-2);
		output_filename[strlen(input_filename)-2] = '\0';
		strcat(output_filename, ".o");
		output = fopen(output_filename, "w");
		
		// .trace 파일 생성
		strncpy(trace_filename, input_filename, strlen(input_filename) - 2);
		trace_filename[strlen(input_filename) - 2] = '\0';
		strcat(trace_filename, ".trace");
		trace_file = fopen(trace_filename, "w");
		
		while (fgets(line, sizeof(line),input) != NULL){
			parse_line(line);
		}
		for(int i = 0 ; i < insts_cnt; i++){
			printf("%s %s %s %s\n",insts[i].oper,insts[i].operand1, insts[i].operand2, insts[i].operand3);
		}
		//실행
		int success = 1;
		pc = 1000;
		while((pc-1000)/4 < insts_cnt){
	printf("PC: %d, Insts_Cnt: %d, Current Inst: %d\n", pc, insts_cnt, (pc - 1000) / 4);
			
			// PC 이동 기록
           		fprintf(trace_file, "%d\n", pc);
           		int flag = inst_calc(insts[(pc-1000)/4]);
           		//printf("flag : %d\n",flag);
			if(flag==1){ //1반환시 에러로 인식하고 반복문 탈출
				success = 0;
				break;
			}
			else if(flag == -1){	//exit처리
				break;
			}	
		}
		if(success){
			fclose(output);
			fclose(trace_file);
		}
		else{
			printf("Syntax Error!\n");
        		fclose(output); // 기존 파일 저장 중단
			fclose(trace_file);
		   	remove(output_filename); // .o 파일 삭제
		   	remove(trace_filename); // .trace 파일 삭제
		}
		fclose(input);
	}
}
