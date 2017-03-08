#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static char * sub_str(char * src, char * dest, int s_idx, int e_idx);
static inline void asm_sub_str(char *dest, char *src, int s_idx, int count);

int main(){
	char src[20];	
	char * dest = (char *) malloc (20);
	char *dest_asm =  (char *) malloc (20);
	int s_idx, e_idx;

	printf("\n");

	printf("Please Enter the String : ");
	scanf("%s",src);
	printf("Please Enter the Starting index : ");
	scanf("%d",&s_idx);	
	printf("Please Enter the Ending index : ");
	scanf("%d",&e_idx);	
	
	dest = sub_str(dest,src, s_idx,e_idx);
	asm_sub_str(dest_asm,src,  s_idx, e_idx);	
	
	printf("\n");

	printf("Substring(Fn.) from : %s\n",dest);
	printf("Substring(ASM) from : %s\n",dest_asm);

	printf("\n");
	
	if (strcmp(dest,dest_asm) == 0)
	printf("Entered strings are equal.\n");
   	else
        printf("Entered strings are not equal.\n");
	
	printf("\n");

	return 1;
}


static inline char * sub_str(char * dest, char * src, int s_idx, int e_idx){
	int i,j;
	int len = strlen(src);
	if(e_idx<=len){
		for(i = s_idx,j=0; i<e_idx; i++,j++){
			dest[j]=src[i];
		}
		dest[j] = '\0';
	
	}
	return dest;
}

static inline void asm_sub_str(char * dest, char *src, int s_idx, int edix)
{
	int rsrc,rdest,count=0;
	asm volatile(
	"1:lodsb;"
	"inc %6;"
	"cmp %4,%6;"
	"jne 1b;"
	"2:lodsb;"
	"stosb;"
	"inc %6;"
	"cmp %5,%6;"
	"jne 2b;"
	"3:lodsb;"
	"testb %%al,%%al;"
	"jne 3b;"
	"stosb;"
	: "=&S"(rsrc), "=&D" (rdest)
	: "0" (src),"1" (dest),"r" (s_idx),"r" (edix),"r" (count)
	:"%eax"
	);	
}
