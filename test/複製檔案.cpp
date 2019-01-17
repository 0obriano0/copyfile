#include <stdio.h>
#include <io.h>

int copyfile(char *filename,char *copyname);

int main(){
	char filename[1000];
	char copyname[1000];
	
	do{
		printf("�п�J�n�ƻs���ɮ�: ");
		scanf("%s",filename);
		printf("�п�J�ƻs���ɮת��ɦW: ");
		scanf("%s",copyname);
	}while(!copyfile(filename,copyname));
}

int copyfile(char *filename,char *copyname){
	FILE *firstfile;
	FILE *copyfile;
	
	if((firstfile=fopen( filename , "rb")) == NULL) {
		printf("�䤣���ɮ�");
		return 0;
	}
	
	if((copyfile=fopen( copyname , "wb")) == NULL) {
		printf("�t�ο��~");
		fclose(firstfile);
		return 0;
	}
	
	char char_firstfile;
	while(fread(&char_firstfile,sizeof(char_firstfile),1,firstfile) != 0) //fread(���VŪ���d�򪺫���,��Ƥj�p,�Ӽ�,�ɮ׫���) 
  	{
    	fwrite(&char_firstfile,sizeof(char_firstfile),1,copyfile);           //fwrite(���V�g�J��ƪ�����,��Ƥj�p,�Ӽ�,�ɮ׫���)
  	}
  	
  	// ���o�ɮץN�X&�ɮפj�p(�HByte�����)        	
  	int fno[2] = {fileno(firstfile),fileno(copyfile)};
  	int fsize[2] = {filelength(fno[0]),filelength(fno[1])}; 		//#include <io.h>
  	
  	printf("%s\t�N�X:%d\t�ɮפj�p:%d\n",filename,fno[0],fsize[0]);
  	printf("%s\t�N�X:%d\t�ɮפj�p:%d\n",copyname,fno[1],fsize[1]);
  	
	fclose(firstfile);
	fclose(copyfile);
	return 1;
}
