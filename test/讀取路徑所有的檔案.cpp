#include <windows.h>
#include <iostream>

void show(char *str,char *dir,int index);

void SetColor(unsigned short ForeColor,unsigned short BackGroundColor){
 HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));
}

int main()
{	
	while(1){
		char file[1000000];
		printf("請輸入路徑");
		scanf("%s",file);
		//show("J:\\北科大\\微處理機\\GitHub\\anime\\*","anime",0);
		show(file,"",0);
	}
	
}

void show(char *str,char *dir,int index){
	char buffer;
    WIN32_FIND_DATA data;
	HANDLE hFind = FindFirstFile(str, &data);
    if ( hFind != INVALID_HANDLE_VALUE ) {
        do {
        	char filename[1000];
        	sprintf(filename,"%s",data.cFileName);
        	if(filename[0] == '.')
        		continue;
        	for(int loopnum2 = 0;loopnum2 < index;loopnum2++){
        		printf("\t");
        	}
        	
        	//偵測副檔名 
        	char filename_[1000];
        	filename_[0] = '\0';
        	for(int loopnum1 = strlen(filename)-1;loopnum1 >=0;loopnum1--){
        		if(filename[loopnum1] == '.'){
        			break;
        		}else if(loopnum1 == 0){
        			filename_[0] = '\0';
        			break;
        		}
        		sprintf(filename_,"%s",filename+loopnum1);
        	}
        	if(filename_[0] == '\0')
        		SetColor(9,0);
        	else{
        		//printf("偵測中....\n");
        		char check_text[100][10] = {"txt","cpp","h","exe","dll","o","zip","html","css","js","php","end;"};
				int check_text_index = -1;
				for(int loopnum1 = 0;check_text_index == -1;loopnum1++){
					char end_text[] = "end;";
					for(int loopnum2 = 0;loopnum2 <= strlen(end_text)+1;loopnum2++){
						if(check_text[loopnum1][loopnum2] == end_text[loopnum2]){
							if(end_text[loopnum2] == '\0')
								check_text_index = loopnum1;
						}else
							break;
					} 
				}
	        	int mode = -1;
				for(int loopnum1 = 0;loopnum1 < check_text_index && mode == -1;loopnum1++){
					if(strlen(check_text[loopnum1]) == strlen(filename_))
						for(int loopnum2 = 0;loopnum2 < strlen(check_text[loopnum1]);loopnum2++){
					    	if(check_text[loopnum1][loopnum2] != filename_[loopnum2]){
					    		break;
							}else if(loopnum2 == strlen(check_text[loopnum1])-1){
								mode = loopnum1;
								break;
							}
						}
				}
				
				std::cout << "-" << dir << "\\";
				
				switch(mode){
	        		case	0:
	        			SetColor(15,0);
	        			break;
	        		case	1:
	        			SetColor(14,0);
	        			break;
	        		case	2:
	        			SetColor(10,0);
	        			break;
	        		case	3:
	        			SetColor(12,0);
	        			break;
	        		case	4:
	        			SetColor(7,12);
	        			break;
	        		case	5:
	        			SetColor(8,0);
	        			break;
	        		case	6:
	        			SetColor(7,10);
	        			break;
	        		case	7:
	        			SetColor(1,7);
	        			break;
	        		case	8:
	        			SetColor(2,7);
	        			break;
	        		case	9:
	        			SetColor(5,7);
	        			break;
	        		case	10:
	        			SetColor(4,7);
	        			break;
	        		default:
	        			SetColor(7,0);
	        	}
			}
        	
            std::cout << filename;
            SetColor(7,0);
            std::cout << "　"<< std::endl;
            //偵測是否為資料夾 
            for(int loopnum1 = 0;filename[loopnum1] != '\0';loopnum1++){
            	if(filename[loopnum1] == '.'){
            		break;
            	}else{
            		char file[1000];
            		sprintf(file,"%s",str);
            		file[strlen(str)-1] = '\0';
            		sprintf(file,"%s%s\\*",file,data.cFileName);
            		//printf("%s\n",file);
            		show(file,data.cFileName,index+1);
            		break;
            	}
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
}
