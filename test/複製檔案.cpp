#include <stdio.h>
#include <io.h>

int copyfile(char *filename,char *copyname);

int main(){
	char filename[1000];
	char copyname[1000];
	
	do{
		printf("請輸入要複製的檔案: ");
		scanf("%s",filename);
		printf("請輸入複製完檔案的檔名: ");
		scanf("%s",copyname);
	}while(!copyfile(filename,copyname));
}

int copyfile(char *filename,char *copyname){
	FILE *firstfile;
	FILE *copyfile;
	
	if((firstfile=fopen( filename , "rb")) == NULL) {
		printf("找不到檔案");
		return 0;
	}
	
	if((copyfile=fopen( copyname , "wb")) == NULL) {
		printf("系統錯誤");
		fclose(firstfile);
		return 0;
	}
	
	char char_firstfile;
	while(fread(&char_firstfile,sizeof(char_firstfile),1,firstfile) != 0) //fread(指向讀取範圍的指標,資料大小,個數,檔案指標) 
  	{
    	fwrite(&char_firstfile,sizeof(char_firstfile),1,copyfile);           //fwrite(指向寫入資料的指標,資料大小,個數,檔案指標)
  	}
  	
  	// 取得檔案代碼&檔案大小(以Byte為單位)        	
  	int fno[2] = {fileno(firstfile),fileno(copyfile)};
  	int fsize[2] = {filelength(fno[0]),filelength(fno[1])}; 		//#include <io.h>
  	
  	printf("%s\t代碼:%d\t檔案大小:%d\n",filename,fno[0],fsize[0]);
  	printf("%s\t代碼:%d\t檔案大小:%d\n",copyname,fno[1],fsize[1]);
  	
	fclose(firstfile);
	fclose(copyfile);
	return 1;
}
